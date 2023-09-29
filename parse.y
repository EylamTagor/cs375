%{     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 08 Jul 22   */

/* Copyright (c) 2022 Gordon S. Novak Jr. and
   The University of Texas at Austin. 
   
   
   
   Eylam Tagor
   et23634
   09/27/2023*/

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12;
   30 Jul 13; 25 Jul 19 ; 28 Feb 22 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "pprint.h"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;

%}

/* Order of tokens corresponds to tokendefs.c; do not change */

%token IDENTIFIER STRING NUMBER   /* token types */

%token PLUS MINUS TIMES DIVIDE    /* Operators */
%token ASSIGN EQ NE LT LE GE GT POINT DOT AND OR NOT DIV MOD IN

%token COMMA                      /* Delimiters */
%token SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET DOTDOT

%token ARRAY BEGINBEGIN           /* Lex uses BEGIN */
%token CASE CONST DO DOWNTO ELSE END FILEFILE FOR FUNCTION GOTO IF LABEL NIL
%token OF PACKED PROCEDURE PROGRAM RECORD REPEAT SET THEN TO TYPE UNTIL
%token VAR WHILE WITH

%right thenthen ELSE // Same precedence, but "shift" wins.

%%

program    :  PROGRAM IDENTIFIER LPAREN idlist RPAREN SEMICOLON vblock DOT { parseresult = makeprogram($2, $4, $7); }
             ;
  statement  :  BEGINBEGIN statement endpart
                                       { $$ = makeprogn($1,cons($2, $3)); }
             |  IF expr THEN statement endif   { $$ = makeif($1, $2, $4, $5); }
             |  assignment
             |  FOR assignment TO expr DO statement { $$ = makefor(1, $1, $2, $3, $4, $5, $6); }
             |  funcall
             ;
  endpart    :  SEMICOLON statement endpart    { $$ = cons($2, $3); }
             |  END                            { $$ = NULL; }
             ;
  endif      :  ELSE statement                 { $$ = $2; }
             |  /* empty */                    { $$ = NULL; }  %prec thenthen
             ;
  assignment :  variable ASSIGN expr           { $$ = binop($2, $1, $3); }
             ;
  expr       :  expr PLUS term                 { $$ = binop($2, $1, $3); }
             |  term 
             ;
  term       :  term TIMES factor              { $$ = binop($2, $1, $3); }
             |  factor
             ;
  factor     :  LPAREN expr RPAREN             { $$ = $2; }
             |  variable
             |  NUMBER
             |  STRING
             ;
  variable   : IDENTIFIER
             ;

  idlist   :  IDENTIFIER COMMA idlist
                          { $$ = cons($1, $3); }
         |  IDENTIFIER    { $$ = cons($1, NULL); }
         ;
  vblock   :  VAR varspecs block       { $$ = $3; }
          |  block
          ;
  varspecs :  vargroup SEMICOLON varspecs
          |  vargroup SEMICOLON
          ;
  vargroup :  idlist COLON type
                              { instvars($1, $3); }
          ;
  type     :  simpletype
          |  ;
  simpletype :  IDENTIFIER   { $$ = findtype($1); }
            ;  /* $1->symtype returns type */

  block    : BEGINBEGIN statement endpart
              { $$ = makeprogn($1,cons($2, $3)); }
  
  funcall  : IDENTIFIER LPAREN expr_list RPAREN { $$ = makefuncall($2, $1, $3); }
          ;

  expr_list: expr COMMA expr_list { $$ = cons($1, $3); }
           | expr
           ;

%%

/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG           0             /* set bits here for debugging, 0 = off  */
#define DB_CONS         1             /* bit to trace cons */
#define DB_BINOP        2             /* bit to trace binop */
#define DB_MAKEIF       4             /* bit to trace makeif */
#define DB_MAKEPROGN    8             /* bit to trace makeprogn */
#define DB_PARSERES    16             /* bit to trace parseresult */
#define DB_MAKEPROGRAM 32             /* bit to trace makeprogram */
#define DB_MAKEFOR     64             /* bit to trace makefor */

 int labelnumber = 0;  /* sequential counter for internal label numbers */

   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");
         dbugprinttok(item);
         dbugprinttok(list);
       };
    return item;
  }

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
  { op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */
    if (DEBUG & DB_BINOP)
       { printf("binop\n");
         dbugprinttok(op);
         dbugprinttok(lhs);
         dbugprinttok(rhs);
       };
    return op;
  }

TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
  {  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
     return tok;
   }

TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
     return tok;
   }

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

/* makes tree for top-level prog */
TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {
  TOKEN tok = makeop(PROGRAMOP);
  tok->operands = name;

  TOKEN progtok = makeprogn(talloc(), args);
  name->link = progtok;
  progtok->link = statements;

  if (DEBUG & DB_MAKEPROGRAM)
       { printf("makeprogram\n");
         dbugprinttok(name);
         dbugprinttok(args);
         dbugprinttok(statements);
       };
  return tok;
}

/* Make a token into an integer constant */
TOKEN fillintc(TOKEN tok, int num) 
  {  
     tok->tokentype = NUMBERTOK;
     tok->basicdt = INTEGER;
     tok->intval = num;
     tok->link = NULL;
     return tok;
   }

/* Make an integer constant token */
TOKEN makeintc(int num) { return fillintc(talloc(), num); }

/* Make an identifier token */
TOKEN makeid(char name[])
  {  TOKEN tok; int i;
     tok = (TOKEN) talloc();
     tok->tokentype = IDENTIFIERTOK;
     tok->link = NULL;
     for (i=0; i<16; i++)
          tok->stringval[i] = name[i];
     return tok;
   }

/* Make an operator token */
TOKEN makeop(int op)
  {  TOKEN tok;
     tok = (TOKEN) talloc();
     tok->tokentype = OPERATOR;
     tok->link = NULL;
     tok->operands = NULL;
     tok->whichval = op;
     return tok;
   }


/* install variables in symbol table */
void instvars(TOKEN idlist, TOKEN typetok)
  {  SYMBOL sym, typesym; int align;
     typesym = typetok->symtype;
     align = alignsize(typesym);
     while ( idlist != NULL )   /* for each id */
       {  sym = insertsym(idlist->stringval);
          sym->kind = VARSYM;
          sym->offset =     /* "next" */
              wordaddress(blockoffs[blocknumber],
                          align);
          sym->size = typesym->size;
          blockoffs[blocknumber] =   /* "next" */
                         sym->offset + sym->size;
          sym->datatype = typesym;
          sym->basicdt = typesym->basicdt;
          idlist = idlist->link;
        };
  }

TOKEN findid(TOKEN tok) { /* the ID token */
  SYMBOL sym = searchst(tok->stringval);
  tok->symentry = sym;
  SYMBOL typ = sym->datatype;
  tok->symtype = typ;
  if ( typ->kind == BASICTYPE ||
      typ->kind == POINTERSYM)
      tok->basicdt = typ->basicdt;
  return tok;
   }

/* determines data type of token */
TOKEN findtype(TOKEN tok) {
  SYMBOL sym = searchst(tok->stringval);
  tok->symtype = sym;
  return tok;
}

/* Make a new token that is a copy of the given token. borrowed from subst.c */
TOKEN copytok(TOKEN origtok)
  {  TOKEN tok; int i;
     tok = (TOKEN) talloc();
     tok->tokentype = origtok->tokentype;
     tok->basicdt  = origtok->basicdt;
     tok->symtype   = origtok->symtype;
     tok->symentry  = origtok->symentry;
     for (i=0; i<16; i++)
          tok->stringval[i] = origtok->stringval[i];
     return tok;
   }

TOKEN makegoto(int label) {
  TOKEN tok = makeop(GOTOOP);
  TOKEN ops_tok = talloc();
  ops_tok->tokentype = NUMBERTOK;
  ops_tok->basicdt = INTEGER;
  ops_tok->intval = label;
  tok->operands = ops_tok;
  return tok;
}

TOKEN makenum(int number) {
  TOKEN tok = talloc();
  tok->intval = number;
  tok->basicdt = INTEGER;
  tok->tokentype = NUMBERTOK;

  return copytok(tok);
}

TOKEN makelabel() {
  TOKEN tok = talloc();
  tok->operands = makenum(labelnumber++);
  tok->whichval = LABELOP;
  tok->tokentype = OPERATOR;

  return copytok(tok);
}

/* makes structures for the for statement in Pascal
    assignment: assignment statement such as := i 1  */
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr,
              TOKEN tokc, TOKEN statement) {
  // make label
  TOKEN tok_label = makeop(LABELOP);
  int current_labelnum = labelnumber;
  TOKEN label_tok = talloc();
	fillintc(label_tok, labelnumber);
	TOKEN labelnum = label_tok;
	labelnumber = current_labelnum + 1;
  tok_label->operands = labelnum;
  labelnum->link = NULL;

  TOKEN tok_assign = makeop(ASSIGNOP);
  TOKEN tok_incr = makeop(PLUSOP);
  TOKEN tok_decr = makeop(MINUSOP); // for downto loops

  tok_assign->link = makegoto(current_labelnum);

  // loop body & condition
  TOKEN tok_less_eq_op = makeop(LEOP);
  TOKEN tok_inside_statements = makeprogn(talloc(), statement);
  TOKEN ifs = makeif(talloc(), tok_less_eq_op, tok_inside_statements, NULL);

  TOKEN tok_ids[3];

  for (int i = 0; i < 3; i++) {
    tok_ids[i] = copytok(asg->operands);
  }

  tok_less_eq_op->operands = tok_ids[0];

  // match tokens with right positions to set up condition
  tok_ids[0]->link = endexpr;

  tok_ids[1]->link = tok_incr;
  tok_assign->operands = tok_ids[1];

  tok_ids[2]->link = fillintc(talloc(), 1);
  tok_incr->operands = tok_ids[2];

  statement->link = tok_assign;
  tok_less_eq_op->link = tok_inside_statements;
  tok_label->link = ifs;

  if (DEBUG & DB_MAKEFOR)
       { printf("cons\n");
         dbugprinttok(tok);
         dbugprinttok(asg);
         dbugprinttok(statement);
       };

  return tok;
}

/* makefuncall makes a FUNCALL operator and links it to the fn and args.
   tok is a (now) unused token that is recycled. */
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args) {
  tok = makeop(FUNCALLOP);
  tok->operands = fn;

  fn->link = args;

  return tok;
}

int main(void)          /*  */
  { int res;
    initsyms();
    res = yyparse();
    printst();       /* to shorten, change to:  printstlevel(1);  */
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
    /* uncomment following to call code generator. */
     /* 
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
 */
  }
