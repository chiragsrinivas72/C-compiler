#!/bin/bash

lex lex_file.l
yacc -d yacc_file.y
gcc lex.yy.c y.tab.c -ll -w
./a.out < input.c
