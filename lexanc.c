/* lex1.c         14 Feb 01; 31 May 12; 11 Jan 18       */

/* This file contains code stubs for the lexical analyzer.
   Rename this file to be lexanc.c and fill in the stubs.    */

/* Copyright (c) 2018 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "lexan.h"

/* This file will work as given with an input file consisting only
   of integers separated by blanks:
   make lex1
   lex1
   12345 123    345  357
   */

/* Checks if a character (represented by int) is considered whitespace. */
bool iswhitespace(int c) {
  return c == ' ' || c == '\n' || c == '\t';
}

/* Skip blanks, comments and whitespace. */

void skipblanks ()
  {
      int c;
      while ((c = peekchar()) != EOF && (iswhitespace(c) || c == '{' || (c == '(' && peek2char() == '*'))) {
          if iswhitespace(c)
              getchar();
          else {
              if c == '{'
                  while ((c = peekchar()) != EOF && c != '}')
                      getchar();

              else if c == '()' && peek2char() == '*'
                  int d = peek2char();
                  
                  while(d != EOF && c != '*' && d != ')') {
                      getchar();
                      c = peekchar();
                      d = peek2char();
                  }
          }
      }

      /* skip everything between { and } */
      
      /* skip everything between (* and *) */
    }

/* Get identifiers and reserved words */
// TODO
TOKEN identifier (TOKEN tok)
  {
    }

// TODO
TOKEN getstring (TOKEN tok)
  {
    }

// TODO
TOKEN special (TOKEN tok)
  {
    }

/* Get and convert unsigned numbers of all types. */
TOKEN number (TOKEN tok)
  { long num;
    int  c, charval;
    num = 0;
    while ( (c = peekchar()) != EOF
            && CHARCLASS[c] == NUMERIC)
      {   c = getchar();
          charval = (c - '0');
          num = num * 10 + charval;
        }
    tok->tokentype = NUMBERTOK;
    tok->basicdt = INTEGER;
    tok->intval = num;
    return (tok);
  }

