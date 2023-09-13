%{    /* lex2.l -- partial lex specification for Pascal   06 Oct 21 */

/* Copyright (c) 2021 Gordon S. Novak Jr. and The University of Texas at Austin
   */
/* 22 Jul 13; 20 Feb 19; 16 Sep 20
   */

/* This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, see <http://www.gnu.org/licenses/>. */

/* To use:
        make lex2
        lex2
        x < 3.14            */

/* This file will work as given on a simple input such as:
   if i<j then x := 3.14

   Copy this file to lexan.l and expand it for your assignment.
   Use:
        make lexer
        lexer <graph1.pas
   */

/* Eylam Tagor
   et23634
   09/12/2023
   */

#include <ctype.h>
#include <string.h>
#include "token.h"
#include "lexan.h"

int maketoken(int type, int which);
int install_id();
int install_fnum();
int yywrap();

int install_inum(); // for unsigned ints
int install_string(); // for strings

/* If the lex yytext buffer turns out to be too small to hold comments,
   add the following lines:
 #undef YYLMAX
 #define YYLMAX 256
 */

TOKEN talloc();

extern TOKEN yylval;    /* This is the type of the lexical analyzer result */

%}

/* regular definitions */

delim    [ \t\n]
ws       {delim}+
letter   [A-Za-z]
digit    [0-9]
id       {letter}({letter}|{digit})*
fnumber  {digit}+(\.{digit}+)?([eE][+\-]?{digit}+)?

inumber  {digit}+
string   \'([^\']*\'\'[^\']*)*'

%%

{ws}      { /* no action and no return */ }
if        {return(maketoken(RESERVED, IF));}
then      {return(maketoken(RESERVED, THEN));}
else      {return(maketoken(RESERVED, ELSE));}
begin     {return(maketoken(RESERVED, BEGINBEGIN));}
end       {return(maketoken(RESERVED, END));}
{id}      {return(install_id());}
{fnumber} {return(install_fnum());}
"<"       {return(maketoken(OPERATOR, LT));}
"<="      {return(maketoken(OPERATOR, LE));}
"="       {return(maketoken(OPERATOR, EQ));}
"<>"      {return(maketoken(OPERATOR, NE));}
">"       {return(maketoken(OPERATOR, GT));}
">="      {return(maketoken(OPERATOR, GE));}
":="      {return(maketoken(OPERATOR, ASSIGN));}
"."       {return(maketoken(OPERATOR, DOT));}
";"       {return(maketoken(DELIMITER, SEMICOLON));}

{inumber} {return(install_inum());}
{string}  {return(install_string());}

"+"       {return(maketoken(OPERATOR, PLUS));}
"-"       {return(maketoken(OPERATOR, MINUS));}
"*"       {return(maketoken(OPERATOR, TIMES));}
"/"       {return(maketoken(OPERATOR, DIVIDE));}
"^"       {return(maketoken(OPERATOR, POINT));}
and       {return(maketoken(OPERATOR, AND));}
or        {return(maketoken(OPERATOR, OR));}
not       {return(maketoken(OPERATOR, NOT));}
div       {return(maketoken(OPERATOR, DIV));}
mod       {return(maketoken(OPERATOR, MOD));}
in        {return(maketoken(OPERATOR, IN));}
goto      {return(maketoken(RESERVED, GOTO));}
label     {return(maketoken(RESERVED, LABEL));}
program   {return(maketoken(RESERVED, PROGRAM));}

","       {return(maketoken(DELIMITER, COMMA));}
":"       {return(maketoken(DELIMITER, COLON));}
"("       {return(maketoken(DELIMITER, LPAREN));}
")"       {return(maketoken(DELIMITER, RPAREN));}
"["       {return(maketoken(DELIMITER, LBRACKET));}
"]"       {return(maketoken(DELIMITER, RBRACKET));}
".."      {return(maketoken(DELIMITER, DOTDOT));}

array     {return(maketoken(RESERVED, ARRAY));}
case      {return(maketoken(RESERVED, CASE));}
const     {return(maketoken(RESERVED, CONST));}
do        {return(maketoken(RESERVED, DO));}
downto    {return(maketoken(RESERVED, DOWNTO));}
file      {return(maketoken(RESERVED, FILEFILE));}
for       {return(maketoken(RESERVED, FOR));}
function  {return(maketoken(RESERVED, FUNCTION));}
nil       {return(maketoken(RESERVED, NIL));}
of        {return(maketoken(RESERVED, OF));}
packed    {return(maketoken(RESERVED, PACKED));}
procedure {return(maketoken(RESERVED, PROCEDURE));}
record    {return(maketoken(RESERVED, RECORD));}
repeat    {return(maketoken(RESERVED, REPEAT));}
set       {return(maketoken(RESERVED, SET));}
to        {return(maketoken(RESERVED, TO));}
type      {return(maketoken(RESERVED, TYPE));}
until     {return(maketoken(RESERVED, UNTIL));}
var       {return(maketoken(RESERVED, VAR));}
while     {return(maketoken(RESERVED, WHILE));}
with      {return(maketoken(RESERVED, WITH));}

"{"       { while (input() != '}'); }

"(*"      {
            int c;

            l1:
            while ((c = input()) != '*');

            if ((c = input()) != ')') {
               unput(c);
               goto l1;
            }
          }

%%

/* Note that lex always returns two values:
   1. "What is it?": a small integer such as NUMBER that indicates the
      kind of item that was found; this is the return() value.
   2. The value itself.  This is yylval, which points to a TOKEN.   */

/* Make simple tokens. */
int maketoken(int type, int which)
  {
  yylval = talloc();  /* Make new token, set yylval to point to it */
  yylval->tokentype = type;
  if (type == RESERVED)
     yylval->whichval = which - RESERVED_BIAS;
     else if (type == OPERATOR)
             yylval->whichval = which - OPERATOR_BIAS;
             else if (type == DELIMITER)
                     yylval->whichval = which - DELIMITER_BIAS;
                     else yylval->whichval = which;
  return(which);
  }

int install_id()
 { int i, c, n;
  yylval = talloc();  /* Make new token, set yylval to point to it */
  yylval->tokentype = IDENTIFIERTOK;
  n = yyleng;            /* number of characters */
  if ( n > 15 ) n = 15;
  for (i = 0; i < n ; i++)
   { c = yytext[i];
          /* if (islower(c)) c = toupper(c); */ /* to raise to upper case */
     yylval->stringval[i] = c;
    };
  yylval->stringval[n] = '\0';
          /* printf("id  %10s   n = %4d\n", yytext, n); */
  return(IDENTIFIER);
 }

int install_fnum() {  /* Note -- you may use sscanf for this assignment. */
  float fnum;
  yylval = talloc();   /* Make new token, set yylval to point to it */
  yylval->tokentype = NUMBERTOK;
  yylval->basicdt = REAL;
       /* printf("num %10s   n = %4d\n",yytext,yyleng); */
  sscanf(yytext, "%f", &fnum);
  yylval->realval = fnum;
  return(NUMBER);
 }

int install_inum() {
  unsigned int inum;
  yylval = talloc();   /* Make new token, set yylval to point to it */
  yylval->tokentype = NUMBERTOK;
  yylval->basicdt = INTEGER;
  sscanf(yytext, "%d", &inum); /* read in int with standard C library call */
  yylval->intval = inum;
  return(NUMBER);
 }

 int install_string()
 {
   int i, c, n;
   int size = 0; /* Size of chars actually added to string */

   yylval = talloc(); /* Make new token, set yylval to point to it */
   yylval->tokentype = STRINGTOK;
   yylval->basicdt = STRINGTYPE;
   
   n = yyleng; /* Number of characters */

   i = 1; /* skip starting quote */
   while (i < n - 1 && size < 15) { /* until either char stream runs out (minus ending quote) or stringval hits max length */
      printf("%c", yytext[i]);
      c = yytext[i];

      if (i < n - 2 && c == '\'' && yytext[i + 1] == '\'') { /* double quote, skip first one */
         i++;
      } else {
         /* Read in one char */
         yylval->stringval[i] = c;
         size++;
      }

      i++;
   }

   yylval->stringval[size] = '\0';

   return (STRING);
 }

int yywrap() {  return(1);  }       /* lex may need this. */
