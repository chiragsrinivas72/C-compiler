%{
    #include<string.h>
    #include<stdio.h>
    int line = 0;
    #define YYSTYPE char *
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
[ \t\n] {yylval = strdup(yytext);}
"switch"    {yylval = strdup(yytext);return SWITCH;}
"case"  {yylval = strdup(yytext); return CASE;}
"default"   {yylval = strdup(yytext); return DEFAULT;}
":" {yylval = strdup(yytext);return T_colon;}
"?" {yylval = strdup(yytext);return T_ques;}
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
\".*\" {yylval = strdup(yytext);return STRING;}
\'.\'   {yylval = strdup(yytext);return CHARACTER;}
"<" {yylval = strdup(yytext);return T_lt;}
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
"("     {yylval = strdup(yytext);return T_op;}
")"     {yylval = strdup(yytext);return T_cp;}
"["     {yylval = strdup(yytext);return T_ob;}
"]"     {yylval = strdup(yytext);return T_cb;}
"{"     {yylval = strdup(yytext);return T_cop;}
"}"     {yylval = strdup(yytext);return T_ccp;}
","     {yylval = strdup(yytext);return T_comma;}
"[]"    {yylval = strdup(yytext);return T_dims;}
.    return yytext[0];

%%
static void single_line_comment(void)
{
    char c;
    while((c=input()) !='\n')
    {
        ;
    }
}

static void multi_line_comment(void)
{
    int c;
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
    }
    yyerror("Unfinished comment");
}