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
#include <stdlib.h>
#include <stdbool.h> // for bool return value of iswhitespace()
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "lexan.h"

#define MAX_SIZE 16
#define MAX_SPECIAL_SIZE 3

static char* operators[]  = {" ", "+", "-", "*", "/", ":=", "=", "<>", "<", "<=",
                          ">=", ">",  "^", ".", "and", "or", "not", "div",
                          "mod", "in", "if", "goto", "progn", "label",
                          "funcall", "aref", "program", "float"};
static char *delimiters[] = { " ", ",", ";", ":", "(", ")", "[", "]",
                           ".."} ; // removed space prefix from printtoken.c's version
static char *reswords[] = { " ", "array", "begin", "case", "const", "do",
                           "downto", "else", "end", "file", "for",
		           "function", "goto", "if", "label", "nil",
                           "of", "packed", "procedure", "program", "record",
                           "repeat", "set", "then", "to", "type",
		           "until", "var", "while", "with" };


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
TOKEN identifier (TOKEN tok)
  {
    int c;
    char id[MAX_SIZE]; // 16 bits: 15 and 1 for null terminator

    // if alpha char, proceed
    if ((c = peekchar()) != EOF && CHARCLASS[c] == ALPHA) {
        // read it in, allowing numbers too
        int i;
        for (i = 0; (c = peekchar()) != EOF && i < MAX_SIZE - 1 && (CHARCLASS[c] == ALPHA || CHARCLASS[c] == NUMERIC); i++) {
            id[i] = getchar();
        }

        // make sure id is null-terminated
        id[i] = 0;
        
        // check if reserved word using ptr arithmetic        
        for (char** rw = reswords; rw < reswords + sizeof(reswords) / sizeof(void *); rw++) {
            if (strcmp(id, *rw) == 0) {
                // found reserve word
                tok->tokentype = RESERVED;
                tok->whichval = (rw - reswords);
                return tok;
            }
        }

        // check if operator using ptr arithmetic
        for (char** op = operators; op < operators + sizeof(operators) / sizeof(void *); op++) {
            if (strcmp(id, *op) == 0) {
                // found operator
                tok->tokentype = OPERATOR;
                tok->whichval = (op - operators);
                return tok;
            }
        }

        // otherwise, it is a regular identifier
        tok->tokentype = IDENTIFIERTOK;
        strcpy(tok->stringval, id);
    }

    return tok;
    }

/* Reads in a string, validates it, and converts it to a token, returning the result. */
TOKEN getstring (TOKEN tok)
  {
    int c;
    char s[MAX_SIZE]; // 16 bits: 15 and 1 for null terminator

    // if starts with '\'', proceed
    if ((c = peekchar()) != EOF && c== '\'') {
        getchar(); // skip starting '\''

        int d; // for double quotes check

        int i;
        for (i = 0; (c = peekchar()) != EOF && i < MAX_SIZE - 1 && (c != '\'' || (d = peek2char()) == '\''); i++) {
            // if double quote, only add one by skipping 1 char
            if (c == '\'' && d == '\'') {
                getchar();
            }

            s[i] = getchar();
        }

        // make sure s is null-terminated
        s[i] = 0;

        // skip ending '\''
        getchar();

        // set token properties
        tok->tokentype = STRINGTOK;
        strcpy(tok->stringval, s);
    }

    return tok;
    }

/* Reads in a special character, classifies it as a delimiter or operator, and returns it. */
TOKEN special (TOKEN tok)
  {
    int c;
    char s[MAX_SPECIAL_SIZE]; // 3 bits: 2 and 1 for null terminator

    if ((c = peekchar()) != EOF) {
        int i;
        for (i = 0; (c = peekchar()) != EOF && i < MAX_SPECIAL_SIZE - 1 && CHARCLASS[c] == SPECIAL; i++) {
            s[i] = getchar();
        }

        // make sure s is null-terminated
        s[i] = 0;

        // check if delimiter using ptr arithmetic        
        for (char** dl = delimiters; dl < delimiters + sizeof(delimiters) / sizeof(void *); dl++) {
            if (strcmp(s, *dl) == 0) {
                // found delimiter
                tok->tokentype = DELIMITER;
                tok->whichval = (dl - delimiters);
                return tok;
            }
        }

        // check if operator using ptr arithmetic
        for (char** op = operators; op < operators + sizeof(operators) / sizeof(void *); op++) {
            if (strcmp(s, *op) == 0) {
                // found operator
                tok->tokentype = OPERATOR;
                tok->whichval = (op - operators);
                return tok;
            }
        }

        // otherwise, this is an error
        exit(1);
    }

    return tok;
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
