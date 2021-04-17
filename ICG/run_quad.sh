#!/bin/bash

lex icg_quad.l
yacc icg_quad_switch.y
gcc y.tab.c -ll -w
./a.out < input.c
