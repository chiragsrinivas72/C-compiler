#!/bin/bash

lex lex_file.l
yacc yacc_file.y
gcc y.tab.c -ll -w
./a.out < invalid.c
