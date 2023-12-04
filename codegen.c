/* codgen.c       Generate Assembly Code for x86         07 May 18   */

/* Copyright (c) 2018 Gordon S. Novak Jr. and The University of Texas at Austin
    */

/* Starter file for CS 375 Code Generation assignment.           */
/* Written by Gordon S. Novak Jr.                  */

/* This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License (file gpl.text) for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "symtab.h"
#include "lexan.h"
#include "genasm.h"
#include "codegen.h"
#include "pprint.h"

void genc(TOKEN code);

/* Set DEBUGGEN to 1 for debug printouts of code generation */
#define DEBUGGEN 0

int nextlabel;    /* Next available label number */
int stkframesize;   /* total stack frame size */
int regs[REGISTERS]; /* List of all registers */

int inttable[64], realtable[64], ptrtable[64], jumptable[64];

/* Top-level entry for code generator.
   pcode    = pointer to code:  (program foo (output) (progn ...))
   varsize  = size of local storage in bytes
   maxlabel = maximum label number used so far

Add this line to the end of your main program:
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
The generated code is printed out; use a text editor to extract it for
your .s file.
         */

void gencode(TOKEN pcode, int varsize, int maxlabel)
  {   TOKEN name, code;
      name = pcode->operands;
      code = name->link->link;
      nextlabel = maxlabel + 1;
      stkframesize = asmentry(name->stringval,varsize);
      genc(code);
      asmexit(name->stringval);

      // initializing tables
      for (int i = PLUSOP; i <= DIVIDEOP; ++i) {
        inttable[i] = i + 3;
        realtable[i] = i + 12;

        if (i != DIVIDEOP) {
          ptrtable[i] = i + 19;
        }
      }

      inttable[ANDOP] = ANDL;
      inttable[OROP] = ORL;
      
      for (int i = EQOP; i <= GTOP; ++i) {
        inttable[i] = CMPL;
        realtable[i] = CMPSD;
        ptrtable[i] = CMPQ;
      }

      realtable[NOTOP] = NEGSD;

      ptrtable[NOTOP] = NOTQ;
      ptrtable[OROP] = ORQ;

      jumptable[GEOP] = JGE;
      jumptable[GTOP] = JG;
      jumptable[LEOP] = JLE;
      jumptable[LTOP] = JL;
      jumptable[EQOP] = JE;
      jumptable[NEOP] = JNE;
  }

/* Trivial version: always returns RBASE + 0 */
/* Get a register.   */
/* Need a type parameter or two versions for INTEGER or REAL */
int getreg(int kind)
  {
    /*     ***** fix this *****   */
    int base = RBASE;
    int max = RMAX;
    if (kind != 1) {
      base = FBASE;
      max = FMAX;
    }

    for (int i = base; i <= max; ++i) {
      if (!regs[i]) {
        regs[i] = 1;
        return i;
      }
    }

    return -1;
  }

/* Trivial version */
/* Generate code for arithmetic expression, return a register number */
int genarith(TOKEN code)
  {   int num, reg;
      int reg1 = -1;
     if (DEBUGGEN)
       { printf("genarith\n");
	 dbugprinttok(code);
       };
      switch ( code->tokentype )
       { case NUMBERTOK:
            switch (code->basicdt)
            { case INTEGER:
                num = code->intval;
                reg = getreg(1);
                if ( num >= MINIMMEDIATE && num <= MAXIMMEDIATE )
                  asmimmed(MOVL, num, reg);
                  break;
              case REAL:
                  /*     ***** fix this *****   */
                  reg = getreg(WORD);
                  makeflit(value, nextlabel + 1);
                  asmldflit(MOVSD, nextlabel + 1, reg);
                  ++nextlabel;
                  break;
            }
	          break;
        case IDENTIFIERTOK:
          /*     ***** fix this *****   */
          int type = code->basicdt == REAL ? 2 : 1;
          reg = getreg(type);
          int instr = code->basicdt == INTEGER ? MOVL : (code->basicdt == REAL ? MOVSD : MOVQ);
          asmld(instr, code->symentry->offset - stkframesize, code->stringval);
	        break;
        case OPERATOR:
          /*     ***** fix this *****   */
          switch (code->whichval) {
            case FIXOP:
            case FLOATOP:
              reg = code->whichval == FIXOP ? getreg(1) : getreg(2);
              reg1 = genarith(code->operands);
              asmfix(reg1, reg);
              regs[reg1] = 0;
              break;
            case FUNCALLOP:
              reg = genfun(code);
              break;
            case AREFOP:
              reg = genaref(code, reg1);
              break;
            default:
              switch (code->basicdt) {
                case INTEGER:
                  reg = genarith(code->operands);
                  if (code->operands->link) {
                    reg1 = genarith(code->operands->link);
                    if (funcallin(code->operands->link)) {
                      asmsttemp(reg);
                      asmldtemp(reg);
                    }
                    
                    asmrr(inttable[code->whichval], reg1, reg);
                  } else {
                    reg1 = getreg(2);
                    asmfneg(reg, reg1);
                    reg = reg1;
                  }

                  regs[reg1] = 0;
                  break;
                case REAL:
                  reg = genarith(code->operands);
                  if (code->operands->link) {
                    reg1 = genarith(code->operands->link);
                    if (funcallin(code->operands->link)) {
                      asmsttemp(reg);
                      asmldtemp(reg);
                    }
                    
                    asmrr(realtable[code->whichval], reg1, reg);
                  } else {
                    reg1 = getreg(2);
                    asmfneg(reg, reg1);
                    reg = reg1;
                  }

                  regs[reg1] = 0;
                  break;
                default:
                  return -1;
              }
          }
          break;
       };
     return reg;
    }


/* Generate code for a Statement from an intermediate-code form */
void genc(TOKEN code)
  {  TOKEN tok, lhs, rhs;
     int reg, offs;
     SYMBOL sym;
     if (DEBUGGEN)
       { printf("genc\n");
	 dbugprinttok(code);
       };
     if ( code->tokentype != OPERATOR )
        { printf("Bad code token");
	  dbugprinttok(code);
	};
     switch ( code->whichval )
       { case PROGNOP:
	   tok = code->operands;
	   while ( tok != NULL )
	     {  genc(tok);
		tok = tok->link;
	      };
	   break;
	 case ASSIGNOP:                   /* Trivial version: handles I := e */
	   lhs = code->operands;
	   rhs = lhs->link;
	   reg = genarith(rhs);              /* generate rhs into a register */
	   sym = lhs->symentry;              /* assumes lhs is a simple var  */
	   offs = sym->offset - stkframesize; /* net offset of the var   */
           switch (code->basicdt)            /* store value into lhs  */
             {  case INTEGER:
                  asmst(MOVL, reg, offs, lhs->stringval);
                  break;
                  /* ...  */
                case REAL:
                  asmst(MOVSD, reg, offs, lhs->stringval);
                  break;
             };
           break;
	 case FUNCALLOP:
     genfun(code);  
	   break;
	 case GOTOOP:
     asmjump(JMP, code->operands->intval);
	   break;
	 case LABELOP:
     asmlabel(code->operands->intval);
	   break;
	 case IFOP:
     asmjump(jumptable[code->operands->whichval], nextlabel);
     ++nextlabel;

     if (code->operands->link->link) {
      genc(code->operands->link->link);
     }

     asmjump(JMP, nextlabel);
     asmlabel(nextlabel - 1);
     ++nextlabel;

     genc(code->operands->link);
     asmlabel(nextlabel - 1);

	   break;
	 };
  }

/* Generate code for array references and pointers */
/* In Pascal, a (^ ...) can only occur as first argument of an aref. */
/* If storereg < 0, generates a load and returns register number;
   else, generates a store from storereg. */
int genaref(TOKEN code, int storereg) {
    int reg = genarith(code->operands->link);
    asmop(CLTQ);
}

/* Generate code for a function call */
int genfun(TOKEN code) {
    SYMBOL s = searchst(code->operands->stringval);

    int n = 0;
    TOKEN curr = code->operands->link;
    while (curr) {
        ++n;
        genarith(curr);
        curr = curr->link;
    }

    asmcall(code->operands->stringval);
    return s->datatype->basicdt == INTEGER ? EAX : (s->datatype->basicdt == REAL ? XMM0 : RAX);
}

/* test if there is a function call within code: 1 if true, else 0 */
int funcallin(TOKEN code) {
    if (!code->whichval && !code->link) {
        return 0;
    }

    TOKEN curr = code->link;
    while (curr) {
        if (curr->whichval == FUNCALLOP) {
            return 1;
        }

        curr = curr->link;
    }

    return 0;
}

