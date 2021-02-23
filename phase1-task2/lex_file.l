%{
    #include<string.h>
    #include<stdio.h>
    #include "y.tab.h"
    int line = 0;
    int count=1;
    #define YYSTYPE char *
    #define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;
    static void single_line_comment(void);
    static void multi_line_comment(void);
%}

alpha [A-Za-z_]
digit [0-9]
floating [+-]?([0-9]*[.])?[0-9]+
%option yylineno
%%
"//"    {single_line_comment();}
"/*"    { multi_line_comment(); }
[ \t] {yylval = strdup(yytext);}
[ \n] {yylval = strdup(yytext); count+=1;}
"switch"    {yylval = strdup(yytext);return SWITCH;}
"case"  {yylval = strdup(yytext); return CASE;}
"default"   {yylval = strdup(yytext); return DEFAULT;}
"if" {yylval = strdup(yytext);return IF;}
"else" {yylval = strdup(yytext);return ELSE;}
"printf" {yylval = strdup(yytext);return PRINTF;}
"break" {yylval = strdup(yytext);return BREAK;}
"continue" {yylval = strdup(yytext);return CONTINUE;}
"int" {yylval = strdup(yytext);return INT;}
"float" {yylval = strdup(yytext);return FLOAT;}
"char" {yylval = strdup(yytext);return CHAR;}
"void" {yylval = strdup(yytext);return VOID;}
"#include" {yylval = strdup(yytext);return INCLUDE;}
"main()" {yylval = strdup(yytext);return MAINTOK;}
{digit}+    {yylval = strdup(yytext);return NUM;}
{digit}+.{digit}+ {yylval = strdup(yytext);return FLOAT;}
{alpha}({alpha}|{digit})* {yylval = strdup(yytext);return ID;}
{alpha}({alpha}|{digit})*"\.h"?  {yylval = strdup(yytext);return H;}
{floating} {yylval = strdup(yytext);return FLNUM;}
\".*\"  {yylval = strdup(yytext);return STRING;}
\'.\'   {yylval = strdup(yytext);return CHARACTER;}
"<"     {yylval = strdup(yytext);return T_lt;}
">"     {yylval = strdup(yytext);return T_gt;}
"="     {yylval = strdup(yytext);return T_eq;}
"<="    {yylval = strdup(yytext);return T_lteq;}
">="    {yylval = strdup(yytext);return T_gteq;}
"=="    {yylval = strdup(yytext);return T_eqeq;}
"!="    {yylval = strdup(yytext);return T_neq;}
"+"     {yylval = strdup(yytext);return T_pl;}
"-"     {yylval = strdup(yytext);return T_min;}
"*"     {yylval = strdup(yytext);return T_mul;}
"/"     {yylval = strdup(yytext);return T_div;}
"++"    {yylval = strdup(yytext);return T_incr;}
"--"    {yylval = strdup(yytext);return T_decr;}
"!"     {yylval = strdup(yytext);return T_neq;}
"||"    {yylval = strdup(yytext);return T_or;}
"&&"    {yylval = strdup(yytext);return T_and;}


.    return yytext[0];

%%

static void single_line_comment(void)
{
    char c;
    while((c=input()) !='\n')
    {
        ;
    }
    count++;
}

static void multi_line_comment(void)
{
    int c;
    int flag=0;
    while ((c = input()) != 0)
    {
        if (c == '*')
        {
            c=input();
            if (c == '/')
                return;

            if (c == 0)
                break;
        }
        if(c==10)
            count++;
    }
    yyerror("Unfinished comment");
}

int yywrap(void){
    return 1;
}