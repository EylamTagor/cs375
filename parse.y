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
#include <string.h>
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

program    :  PROGRAM IDENTIFIER LPAREN idlist RPAREN SEMICOLON lblock DOT { parseresult = makeprogram($2, $4, $7); }
             ;
  statement  :  BEGINBEGIN statement endpart
                                       { $$ = makeprogn($1,cons($2, $3)); }
             |  IF expr THEN statement endif   { $$ = makeif($1, $2, $4, $5); }
             |  assignment
             |  FOR assignment TO expr DO statement { $$ = makefor(1, $1, $2, $3, $4, $5, $6); }
             |  funcall
             | REPEAT stlist UNTIL expr { $$ = makerepeat($1, $2, $3, $4); }
             | NUMBER COLON statement { $$ = dolabel($1, $2, $3); }
             | GOTO NUMBER { $$ = dogoto($1, $2); }
             ;
  endpart    :  SEMICOLON statement endpart    { $$ = cons($2, $3); }
             |  END                            { $$ = NULL; }
             ;
  endif      :  ELSE statement                 { $$ = $2; }
             |  /* empty */                    { $$ = NULL; }  %prec thenthen
             ;
  assignment :  variable ASSIGN expr           { $$ = binop($2, $1, $3); }
             ;
  expr       :  expr EQ simpleexpr {$$ = binop($2, $1, $3); }
             |  expr NE simpleexpr {$$ = binop($2, $1, $3); }
             |  expr GT simpleexpr {$$ = binop($2, $1, $3); }
             |  expr LT simpleexpr {$$ = binop($2, $1, $3); }
             |  expr GE simpleexpr {$$ = binop($2, $1, $3); }
             |  expr LE simpleexpr {$$ = binop($2, $1, $3); }
             |  expr IN simpleexpr {$$ = binop($2, $1, $3); }
             |  simpleexpr
             ;
  term       :  term TIMES factor              { $$ = binop($2, $1, $3); }
             |  term DIVIDE factor { $$ = binop($2, $1, $3); }
             |  term DIV factor { $$ = binop($2, $1, $3); }
             |  term MOD factor { $$ = binop($2, $1, $3); }
             |  term AND factor { $$ = binop($2, $1, $3); }
             |  factor
             ;
  factor     :  LPAREN expr RPAREN             { $$ = $2; }
             |  variable
             |  NUMBER
             |  STRING
             |  NIL
             |  NOT factor { $$ = unaryop($1, $2); }
             |  funcall
             ;
  variable   : IDENTIFIER { $$ = findid($1); }
             | variable POINT { $$ = dopoint($1, $2); }
             | variable DOT IDENTIFIER { $$ = reducedot($1, $2, $3); }
             | variable mergelist
             ;

  mergelist  : LBRACKET expr_list RBRACKET { $$ = arrayref($1, NULL, $2, NULL); }

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
  type    : simpletype
          | POINT IDENTIFIER { $$ = instpoint($1, $2); }
          | RECORD field_list END { $$ = instrec($1, $2); }
          | ARRAY LBRACKET simtypelist RBRACKET OF type { $$ = instarray($3, $6); }
          ;
  simpletype :  IDENTIFIER   { $$ = findtype($1); }
            ;  /* $1->symtype returns type */

  block    : BEGINBEGIN statement endpart
              { $$ = makeprogn($1,cons($2, $3)); }
  
  funcall  : IDENTIFIER LPAREN expr_list RPAREN { $$ = makefuncall($2, $1, $3); }
          ;

  expr_list: expr COMMA expr_list { $$ = cons($1, $3); }
           | expr
           ;

  cblock   : CONST constspecs tblock { $$ = $3; }
           | tblock
           ;

  tblock   : TYPE typespecs vblock { $$ = $3; }
           | vblock
           ;

  constant : IDENTIFIER
           | PLUS IDENTIFIER { $$ = unaryop($1, $2); }
           | MINUS IDENTIFIER { $$ = unaryop($1, $2); }
           | NUMBER
           | PLUS NUMBER { $$ = unaryop($1, $2); }
           | MINUS NUMBER { $$ = unaryop($1, $2); }
           | STRING
           ;

  const_def: IDENTIFIER EQ constant { instconst($1, $3); }

  constspecs: const_def SEMICOLON constspecs
            | const_def SEMICOLON
            ;

  typespecs : IDENTIFIER EQ TYPE typespecs
            | IDENTIFIER EQ TYPE
            ;

  stlist    : statement SEMICOLON stlist { $$ = cons($1, $3); }
            | statement { $$ = $1; }
            ;

  simpleexpr: term
            | PLUS term { $$ = unaryop($1, $2); }
            | MINUS term { $$ = unaryop($1, $2); }
            | simpleexpr PLUS term { $$ = binop($2, $1, $3); }
            | simpleexpr MINUS term { $$ = binop($2, $1, $3); }
            | simpleexpr OR term { $$ = binop($2, $1, $3); }
            ;

  field_list: idlist COLON type { instfields($1, $3); }
            | idlist COLON type SEMICOLON field_list { instfields($1, $3); $$ = nconc($1, $5); }
            ;

  lblock    : LABEL labellist SEMICOLON cblock { $$ = $4; }
            | cblock
            ;

  labellist : NUMBER COMMA labellist { instlabel($1); }
            | NUMBER { instlabel($1); }
            ;

  simtypelist: simtype COMMA simtype { $$ = cons($1, $3); }
            | simtype { $$ = $1; }
            ;

  simtype   : IDENTIFIER { $$ = findtype($1); }
            | constant DOTDOT constant { $$ = instdotdot($1, $2, $3); }
            | LPAREN idlist RPAREN { $$ = instenum($2); }

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

 int label_table[50];

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

    /* TYPE INFERENCE */
    TOKEN tok_fixed;

    if (lhs->basicdt == INTEGER) {
      if (rhs->basicdt == INTEGER) {
        // both are ints
        op->basicdt = INTEGER;
      } else if (rhs->basicdt == REAL) {
        // lhs is int, rhs is real
      
        // if assign op -> fix rhs
        if (op->whichval == ASSIGNOP) {
          tok_fixed = makefix(rhs);
          op->basicdt = INTEGER;
          lhs->link = tok_fixed;
        } else {
          // if any other op -> becomes real
          tok_fixed = makefloat(lhs);
          op->basicdt = REAL;
          op->operands = tok_fixed;
          tok_fixed->link = rhs;
        }
      }
    } else if (lhs->basicdt == REAL) {
      op->basicdt = REAL;

      // if both are real do nothing
      if (rhs->basicdt == INTEGER) {
        tok_fixed = makefloat(rhs);
        lhs->link = tok_fixed;
      }
    }

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

  // int const
  if (sym->kind == CONSTSYM && sym->basicdt == INTEGER) {
    tok->basicdt = INTEGER;
    tok->intval = sym->constval.intnum;
    tok->tokentype = NUMBERTOK;
  }

  // real number const
  else if (sym->kind == CONSTSYM && sym->basicdt == REAL) {
    tok->basicdt = REAL;
    tok->realval = sym->constval.realnum;
    tok->tokentype = NUMBERTOK;
  }

  // not const
  else if ( typ->kind == BASICTYPE ||
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

  return tok;
}

/* makes structures for the for statement in Pascal
    assignment: assignment statement such as := i 1  */
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr,
              TOKEN tokc, TOKEN statement) {
  // make label
  TOKEN label = makelabel();
  asg->link = label;

  TOKEN tok_body = makeprogn(talloc(), statement);
  
  TOKEN tok_leop = makeop(LEOP);
  TOKEN tok_incr = makeop(PLUSOP);
  TOKEN tok_assign = makeop(ASSIGNOP);

  TOKEN ifs = makeif(talloc(), tok_leop, tok_body, NULL);

  TOKEN identifiers[3];

  for (int i = 0; i < 3; i++) {
    identifiers[i] = talloc();
    identifiers[i] = copytok(asg->operands);
  }

  tok = makeprogn(tok, asg);

  identifiers[0]->link = endexpr;
  tok_leop->operands = identifiers[0];

  tok_leop->link = tok_body;

  identifiers[2]->link = makenum(1);
  tok_incr->operands = identifiers[2];

  identifiers[1]->link = tok_incr;
  tok_assign->operands = identifiers[1];

  // goto
  TOKEN tok_goto = makegoto(labelnumber - 1);
  tok_assign->link = tok_goto;

  // connect final links of tree
  statement->link = tok_assign;

  ifs->operands = tok_leop;

  label->link = ifs;
  return tok;
}

/* makefuncall makes a FUNCALL operator and links it to the fn and args.
   tok is a (now) unused token that is recycled. */
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args) {
  if (strcmp(fn->stringval, "new") == 0) {
    tok = makeop(ASSIGNOP);
    tok->operands = args;

    TOKEN funcall = makeop(FUNCALLOP);
    funcall->operands = fn;
    args->link = funcall;

    fn->link = makeintc(searchst(args->stringval)->datatype->datatype->datatype->size);
  } else {
    tok = makeop(FUNCALLOP);
    tok->operands = fn;


    tok->basicdt = searchst(fn->stringval)->datatype->basicdt;
    fn->link = args;
  }

  return tok;
}

/* instconst installs a constant in the symbol table */
void  instconst(TOKEN idtok, TOKEN consttok) {
  SYMBOL sym = insertsym(idtok->stringval);
  sym->basicdt = consttok->basicdt;
  sym->kind = CONSTSYM;

  if (sym->basicdt == INTEGER) {
    // int so size 4
    sym->size = 4;
    sym->constval.intnum = consttok->intval;
  } else {
    // real so size 8
    sym->size = 8;
    sym->constval.realnum = consttok->realval;
  }
}

/* makerepeat makes structures for a repeat statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr) {
  TOKEN label = makelabel();
  TOKEN tok_body = makeprogn(tokb, statements);
  label->link = tok_body;

  TOKEN tok_goto = makegoto(labelnumber - 1);
  TOKEN tok_done = makeprogn(talloc(), NULL);
  tok_done->link = tok_goto;

  TOKEN tok_if = makeif(talloc(), expr, tok_done, tok_goto);
  tok = makeprogn(tok, label);

  tok_body->link = tok_if;
  
  return tok;
}

/* unaryop links a unary operator op to one operand, lhs */
TOKEN unaryop(TOKEN op, TOKEN lhs) {
  op->operands = lhs;
  lhs->link = NULL;
  return op;
}

/* makefloat forces the item tok to be floating, by floating a constant
   or by inserting a FLOATOP operator */
TOKEN makefloat(TOKEN tok) {
  TOKEN tok_float;

  if (tok->tokentype == NUMBERTOK) {
    tok->basicdt = REAL;
    tok->realval = (double) tok->intval;
    tok_float = tok;
  } else { // (float ...)
    tok_float = makeop(FLOATOP);
    tok_float->operands = tok;
  }

  return tok_float;
}

/* makefix forces the item tok to be integer, by truncating a constant
   or by inserting a FIXOP operator */
TOKEN makefix(TOKEN tok) {
  TOKEN tok_fix = makeop(FIXOP);
  tok_fix->operands = tok;
  return tok_fix;
}

/* instfields will install type in a list idlist of field name tokens:
   re, im: real    put the pointer to REAL in the RE, IM tokens.
   typetok is a token whose symtype is a symbol table pointer.
   Note that nconc() can be used to combine these lists after instrec() */
TOKEN instfields(TOKEN idlist, TOKEN typetok) {
  SYMBOL symtype = typetok->symtype;
  TOKEN curr = idlist;

  while(curr) {
    curr->symtype = symtype;
    curr = curr->link;
  }

  return idlist;
}

/* dolabel is the action for a label of the form   <number>: <statement>
   tok is a (now) unused token that is recycled. */
TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement) {
  int i = 0;
  while (i < labelnumber && label_table[i] != labeltok->intval) {
    ++i;
  }

  i = i == labelnumber ? -1 : i;

  TOKEN tokprogn = makeop(PROGNOP);
  TOKEN toklabel = makeop(LABELOP);
  TOKEN toki = makeintc(i);

  toklabel->operands = toki;
  toklabel->link = statement;

  tokprogn->operands = toklabel;

  return (!tokprogn || !toklabel || !toki) ? NULL : tokprogn;
}

/* instlabel installs a user label into the label table */
void  instlabel (TOKEN num) {
  label_table[labelnumber] = num->intval;
  ++labelnumber;
}

/* nconc concatenates two token lists, destructively, by making the last link
   of lista point to listb.
   (nconc '(a b) '(c d e))  =  (a b c d e)  */
/* nconc is useful for putting together two fieldlist groups to
   make them into a single list in a record declaration. */
/* nconc should return lista, or listb if lista is NULL. */
TOKEN nconc(TOKEN lista, TOKEN listb) {
  if (!lista || !listb) {
    return NULL;
  }

  // fencepost
  TOKEN tok = lista, curr = tok->link;

  while (curr) {
    tok = curr;
    curr = curr->link;
  }

  return tok;
}

/* dogoto is the action for a goto statement.
   tok is a (now) unused token that is recycled. */
TOKEN dogoto(TOKEN tok, TOKEN labeltok) {
  int i = 0;
  while (i < labelnumber && label_table[i] != labeltok->intval) {
    ++i;
  }

  i = i == labelnumber ? -1 : i;

  return makegoto(i);
}

/* instrec will install a record definition.  Each token in the linked list
   argstok has a pointer its type.  rectok is just a trash token to be
   used to return the result in its symtype */
TOKEN instrec(TOKEN rectok, TOKEN argstok) {
  SYMBOL record = symalloc();
  record->kind = RECORDSYM;
  record->datatype = argstok->symtype;

  // another fencepost
  int size = wordaddress(argstok->symtype->size, 8);
  while(argstok->link) {
    argstok->symtype->link = argstok->link->symtype;

    argstok->link->symtype->offset = size;    
    size += wordaddress(argstok->link->symtype->size, 8);

    argstok = argstok->link;
  }

  record->size = size;
  rectok->symtype = record;
  return rectok;
}

/* insttype will install a type name in symbol table.
   typetok is a token containing symbol table pointers. */
void  insttype(TOKEN typename, TOKEN typetok) {
  SYMBOL type = searchins(typename->stringval);
  type->datatype = typetok->symtype;
  type->kind = TYPESYM;
  type->size = typetok->symtype->size;
  type->basicdt = typetok->symtype->basicdt;
}

/* instpoint will install a pointer type in symbol table */
TOKEN instpoint(TOKEN tok, TOKEN typename) {
  SYMBOL ptr = symalloc();
  ptr->basicdt = POINTER;
  ptr->kind = POINTERSYM;
  ptr->datatype = searchins(typename->stringval);
  ptr->size = 8;

  tok->symtype = ptr;
  return tok;
}

/* instarray installs an array declaration into the symbol table.
   bounds points to a SUBRANGE symbol table entry.
   The symbol table pointer is returned in token typetok. */
TOKEN instarray(TOKEN bounds, TOKEN typetok) {
  TOKEN bound = bounds;
  SYMBOL prev = NULL;

  int lower_bound = bound->symtype->lowbound, upper_bound = bound->symtype->highbound;
  while (bound) {
    lower_bound = bound->symtype->lowbound;
    upper_bound = bound->symtype->highbound;

    SYMBOL array = symalloc();
    array->kind = ARRAYSYM;
    array->size = searchst(typetok->stringval)->size * (upper_bound - lower_bound + 1);

    if (searchst(typetok->stringval)) {
      array->datatype = searchst(typetok->stringval);
    }

    if (prev != NULL) {
      array->datatype = typetok->symtype;
      array->size = prev->size * (upper_bound - lower_bound + 1);
    }

    prev = array;
    typetok->symtype = array;

    bound = bound->link;
    array->lowbound = lower_bound;
    array->highbound = upper_bound;
  }

  return typetok;
}

/* instdotdot installs a .. subrange in the symbol table.
   dottok is a (now) unused token that is recycled. */
TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok) {
  return makesubrange(dottok, lowtok->intval, hightok->intval);
}

/* makesubrange makes a SUBRANGE symbol table entry, puts the pointer to it
   into tok, and returns tok. */
TOKEN makesubrange(TOKEN tok, int low, int high) {
  SYMBOL sub = symalloc();
  sub->basicdt = INTEGER;
  sub->kind = SUBRANGE;

  sub->lowbound = low;
  sub->highbound = high;

  sub->size = 4;

  tok->symtype = sub;
  return tok;
}

/* instenum installs an enumerated subrange in the symbol table,
   e.g., type color = (red, white, blue)
   by calling makesubrange and returning the token it returns. */
TOKEN instenum(TOKEN idlist) {
  int size = -1;
  
  TOKEN idlist_copy = copytok(idlist);
  while (idlist_copy) {
    instconst(idlist_copy, makeintc(size++));
    idlist_copy = idlist_copy->link;
  }

  return makesubrange(idlist, 0, size);
}

/* dopoint handles a ^ operator.  john^ becomes (^ john) with type record
   tok is a (now) unused token that is recycled. */
TOKEN dopoint(TOKEN var, TOKEN tok) {
  tok->operands = var;
  return tok;
}

/* arrayref processes an array reference a[i]
   subs is a list of subscript expressions.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) {
  int lower_bound = arr->symtype->lowbound, upper_bound = arr->symtype->highbound;
  int size = arr->symtype->size / (upper_bound + lower_bound - 1);

  TOKEN sizetok = makeintc(-size);
  sizetok->link = makeop(TIMESOP);
  sizetok->link->operands = makeintc(size);
  if (!subs->link) {
    sizetok->link->operands->link = subs;
  } else {
    sizetok->link->operands->link = copytok(subs);
    sizetok->link->operands->link->link = NULL;
  }

  TOKEN plustok = makeop(PLUSOP);
  plustok->operands = sizetok;

  TOKEN subarray_ref_tok = makearef(arr, plustok, tokb);
  subarray_ref_tok->symtype = arr->symtype->datatype;

  if (!subs->link) {
    return makearef(arr, plustok, tokb);
  }

  return arrayref(subarray_ref_tok, tok, subs->link, tokb);
}

/* reducedot handles a record reference.
   dot is a (now) unused token that is recycled. */
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {
  SYMBOL curr = var->symentry->datatype->datatype;
  while(curr && strcmp(field->stringval, curr->namestring)) {
    curr = curr->link;
  }

  var->symentry = curr;
  return makearef(var, makeintc(curr->offset), dot);
}

/* makearef makes an array reference operation.
   off is be an integer constant token
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok) {
  TOKEN areftok = makeop(AREFOP);
  var->link = off;
  areftok->operands = var;
  return areftok;
}

int main(void)
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
