/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
#define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
<<<<<<< HEAD
#define YYTOKENTYPE
enum yytokentype
{
  ID = 258,
  NUM = 259,
  CHARACTER = 260,
  FLNUM = 261,
  T_lt = 262,
  T_gt = 263,
  T_lteq = 264,
  T_gteq = 265,
  T_neq = 266,
  T_eqeq = 267,
  T_pl = 268,
  T_min = 269,
  T_mul = 270,
  T_div = 271,
  T_and = 272,
  T_or = 273,
  T_incr = 274,
  T_decr = 275,
  T_not = 276,
  T_eq = 277,
  INT = 278,
  CHAR = 279,
  FLOAT = 280,
  VOID = 281,
  H = 282,
  MAINTOK = 283,
  INCLUDE = 284,
  BREAK = 285,
  CONTINUE = 286,
  IF = 287,
  ELSE = 288,
  PRINTF = 289,
  STRING = 290,
  SWITCH = 291,
  CASE = 292,
  DEFAULT = 293,
  T_dims = 294,
  T_op = 295,
  T_cp = 296,
  T_ob = 297,
  T_cb = 298,
  T_cop = 299,
  T_ccp = 300,
  T_comma = 301
};
=======
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    NUM = 259,
    CHARACTER = 260,
    FLNUM = 261,
    T_lt = 262,
    T_gt = 263,
    T_lteq = 264,
    T_gteq = 265,
    T_neq = 266,
    T_eqeq = 267,
    T_pl = 268,
    T_min = 269,
    T_mul = 270,
    T_div = 271,
    T_and = 272,
    T_or = 273,
    T_incr = 274,
    T_decr = 275,
    T_not = 276,
    T_eq = 277,
    INT = 278,
    CHAR = 279,
    FLOAT = 280,
    VOID = 281,
    H = 282,
    MAINTOK = 283,
    INCLUDE = 284,
    BREAK = 285,
    CONTINUE = 286,
    IF = 287,
    ELSE = 288,
    PRINTF = 289,
    STRING = 290,
    SWITCH = 291,
    CASE = 292,
    DEFAULT = 293,
    T_dims = 294,
    T_op = 295,
    T_cp = 296,
    T_ob = 297,
    T_cb = 298,
    T_cop = 299,
    T_ccp = 300,
    T_comma = 301
  };
>>>>>>> e0f15208ae0714f5e49e264cf51c85f61da4cd09
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define CHARACTER 260
#define FLNUM 261
#define T_lt 262
#define T_gt 263
#define T_lteq 264
#define T_gteq 265
#define T_neq 266
#define T_eqeq 267
#define T_pl 268
#define T_min 269
#define T_mul 270
#define T_div 271
#define T_and 272
#define T_or 273
#define T_incr 274
#define T_decr 275
#define T_not 276
#define T_eq 277
#define INT 278
#define CHAR 279
#define FLOAT 280
#define VOID 281
#define H 282
#define MAINTOK 283
#define INCLUDE 284
#define BREAK 285
#define CONTINUE 286
#define IF 287
#define ELSE 288
#define PRINTF 289
#define STRING 290
#define SWITCH 291
#define CASE 292
#define DEFAULT 293
#define T_dims 294
#define T_op 295
#define T_cp 296
#define T_ob 297
#define T_cb 298
#define T_cop 299
#define T_ccp 300
#define T_comma 301

/* Value type.  */
#if !defined YYSTYPE && !defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
#define YYSTYPE_IS_TRIVIAL 1
#define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

int yyparse(void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
