/* lex1.c         14 Feb 01; 31 May 12; 11 Jan 18       */
/*  Eylam Tagor
    et23634
    8/26/2023 */

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
#include <stdbool.h> // for bool return value of iswhitespace()
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

/* Skip to the end of a {...} comment */
void skipbracketcomment(int c) {
    while ((c = peekchar()) != EOF && c != '}') {
        getchar();
    }
}

/* Skip to the end of a (*...*) comment */
void skipstarcomment(int c, int d) {
    while ((c = peekchar()) != EOF && (d = peek2char()) != EOF && (c != '*' || d != ')')) {
        getchar();
    }
}

/* Skip blanks, comments and whitespace. */
void skipblanks ()
  {
      int c;

      while ((c = peekchar()) != EOF) {
          if (iswhitespace(c)) { // if encountered whitespace char, skip
              getchar();
          } else if (c == '{') { // if encoutered '{' comment, go to after its end

              // get to start of comment content
              getchar();

              skipbracketcomment(c);

              // skip ending '}'
              getchar();
          } else if (c == '(') { // if encountered '(*' comment, go to after its end
              int d;
              d = peek2char();

              // get to start of comment content
              getchar();
              getchar();

              if (d == '*') {
                  skipstarcomment(c, d);
              }

              // skip ending '*)'
              getchar();
              getchar();
          } else { // not a blank -> used for a token
              break;
          }
      }
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
