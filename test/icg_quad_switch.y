%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>

  void print_message();
  int top=-1;
  void yyerror(char *);
  extern FILE *yyin;
  #define YYSTYPE char*
  typedef struct quadruples
  {
    char *op;
    char *arg1;
    char *arg2;
    char *res;
  }quad;
  int quadlen = 0;
  quad q[100];
%}

%start S
%token ID NUM T_lt T_gt T_lteq T_gteq T_neq T_noteq T_eqeq T_and T_or T_incr T_decr T_not T_eq  INT CHAR FLOAT VOID H MAINTOK INCLUDE BREAK CONTINUE IF ELSE COUT STRING PRINTF T_ques T_colon T_op T_cp T_ob T_cb T_cop T_ccp T_comma T_dims FLNUM CHARACTER SWITCH CASE DEFAULT

%token T_pl T_min T_mul T_div
%left T_lt T_gt
%left T_pl T_min
%left T_mul T_div

%%
S
    : START {print_message();}
    ;

START
    : INCLUDE T_lt H T_gt MAIN
    ;

MAIN
    : VOID MAINTOK BODY
    | INT MAINTOK BODY
    ;

BODY
    : T_cop C T_ccp
    ;

C
    : C statement ';'
    | C LOOPS
    | statement ';'
    | LOOPS
    | error ';'   {yyerrok; yyclearin; }
    ;

LOOPS
    : IF_COND   {if3();}
    | IF_COND ELSE_COND
    | STMT_SWITCH
    ;

IF_COND
    : IF T_op COND T_cp {ifelse1();} LOOPBODY
    ;

ELSE_COND
    : ELSE LOOPBODY{ifelse3();}
    ;

STMT_SWITCH	
    : SWITCH{switch_start();} T_op EXP T_cp T_cop SWITCHBODY T_ccp{switch_end();}
	;

SWITCHBODY	
    : CASES   
	| CASES DEFAULTSTMT
	;

CASES 
    : CASE NUM {push();} T_colon {case_start();} C BREAKSTMT
	| 
	;

BREAKSTMT
    : BREAK{case_end();} ';' CASES
	| {case_end_without_break();}CASES 
	;

DEFAULTSTMT 
    : DEFAULT T_colon C DE{default_end();}
	;

DE 	: BREAK ';'
	|
	;

TERNARY_EXPR
    :  T_op TERNARY_COND T_cp {ternary1();} T_ques statement{ternary2();} T_colon statement{ternary3();}
    ;

LOOPBODY
  	: T_cop LOOPC T_ccp
  	| ';'
  	| statement ';'
  	;

LOOPC
    : LOOPC statement ';'
    | LOOPC LOOPS
    | statement ';'
    | LOOPS
    ;

statement
    : ASSIGN_EXPR
    | EXP
    | TERNARY_EXPR
    | PRINT
    ;

TERNARY_COND  : T_B {codegen_assigna();}
              | T_B T_and{codegen_assigna();} TERNARY_COND
              | T_B {codegen_assigna();}T_or TERNARY_COND
              | T_not T_B{codegen_assigna();}
              ;

T_B : T_V T_eq{push();}T_eq{push();} LIT
    | T_V T_gt{push();}T_F
    | T_V T_lt{push();}T_F
    | T_V T_not{push();} T_eq{push();} LIT
    | T_op T_B T_cp
    | T_V {pushab();}
    ;

T_F : T_eq{push();}LIT
    | LIT{pusha();}
    ;

COND  : B {codegen_assigna();}
      | B T_and{codegen_assigna();} COND
      | B {codegen_assigna();}T_or COND
      | T_not B{codegen_assigna();}
      ;

B : V T_eq{push();}T_eq{push();} LIT
  | V T_gt{push();}F
  | V T_lt{push();}F
  | V T_not{push();} T_eq{push();} LIT
  |T_op B T_cp
  | V {pushab();}
  ;

F : T_eq{push();}LIT
  | LIT{pusha();}
  ;

V : ID{push();}

T_V : ID{pushx();}

ASSIGN_EXPR
    : LIT {push();} T_eq {push();} EXP {codegen_assign();}
    | TYPE LIT {push();} T_eq {push();} EXP {codegen_assign();}
    | TYPE LIT {push();} T_dims T_eq {push();} STRING{push(); codegen_assign();}
    | TYPE LIT {push();} T_ob NUM T_cb T_eq {push();} STRING{push(); codegen_assign();}
    ;

EXP
	: ADDSUB
	| EXP T_lt {push();} ADDSUB {codegen();}
	| EXP T_gt {push();} ADDSUB {codegen();}
	;

ADDSUB
    : TERM
    | EXP T_pl {push();} TERM {codegen();}
    | EXP T_min {push();} TERM {codegen();}
    ;

TERM
	: FACTOR
    | TERM T_mul {push();} FACTOR {codegen();}
    | TERM T_div {push();} FACTOR {codegen();}
    ;

FACTOR
	: LIT
	| T_op EXP T_cp
  	;

PRINT
    : PRINTF T_op STRING T_cp
    ;

LIT
    : ID {push();}
    | NUM {push();}
    | FLNUM {push();}
    | CHARACTER {push();}
    ;

TYPE
    : INT
    | CHAR
    | FLOAT
    ;

%%

#include "lex.yy.c"
#include<ctype.h>
char st[100][100];

char i_[2]="0";
int temp_i=0;
char tmp_i[3];
char temp[2]="t";
int label[20];
int lnum=0;
int ltop=0;
int switchlabel[10];
int switch_lbl = 0;
int chk = 0;

int main(int argc,char *args[])
{

  yyin = fopen(args[1],"r");
  switch_lbl = -1;
  chk = 0;

  if(!yyparse())  //yyparse-> 0 if success
  {
    printf("Parsing Complete\n");
    printf("---------------------Quadruples-------------------------\n\n");
    printf("Operator \t Arg1 \t\t Arg2 \t\t Result \n");
    int i;
    for(i=0;i<quadlen;i++)
    {
        printf("%-8s \t %-8s \t %-8s \t %-6s \n",q[i].op,q[i].arg1,q[i].arg2,q[i].res);
    }
  }
  else
  {
    printf("Parsing failed\n");
  }

  fclose(yyin);
  return 0;
}
void print_message()
{
    if(chk != 1)
        printf("\n\nNo Syntax Errors Detected.\n");
}
void yyerror(char *s)
{ 
    printf("Error : %s at %d \n",yytext,yylineno);
    chk = 1;
}

push()
{
    strcpy(st[++top],yytext);
}
pusha()
{
    strcpy(st[++top],"  ");
}
pushx()
{
    strcpy(st[++top],"x ");
}
pushab()
{
    strcpy(st[++top],"  ");
    strcpy(st[++top],"  ");
    strcpy(st[++top],"  ");
}

codegen()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);

    q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,st[top-1]);
    strcpy(q[quadlen].arg1,st[top-2]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;

    top-=2;
    strcpy(st[top],temp);

    temp_i++;
}
codegen_assigna()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = %s %s %s %s\n",temp,st[top-3],st[top-2],st[top-1],st[top]);

    if(strlen(st[top])==1)
    {
        
        char t[20];
        strcpy(t,st[top-2]);
        strcat(t,st[top-1]);
        q[quadlen].op = (char*)malloc(sizeof(char)*strlen(t));
        q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-3]));
        q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
        q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
        strcpy(q[quadlen].op,t);
        strcpy(q[quadlen].arg1,st[top-3]);
        strcpy(q[quadlen].arg2,st[top]);
        strcpy(q[quadlen].res,temp);
        quadlen++;
        
    }
    else
    {
        q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-2]));
        q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-3]));
        q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top-1]));
        q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
        strcpy(q[quadlen].op,st[top-2]);
        strcpy(q[quadlen].arg1,st[top-3]);
        strcpy(q[quadlen].arg2,st[top-1]);
        strcpy(q[quadlen].res,temp);
        quadlen++;
    }
    top-=4;

    temp_i++;
    strcpy(st[++top],temp);
}

codegen_umin()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = -%s\n",temp,st[top]);

    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"-");
    strcpy(q[quadlen].arg1,st[top-2]);
    strcpy(q[quadlen].res,temp);
    quadlen++;

    top--;
    strcpy(st[top],temp);
    temp_i++;
}
codegen_assign()
{
    printf("%s = %s\n",st[top-3],st[top]);

    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    strcpy(q[quadlen].op,"=");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,st[top-3]);
    quadlen++;

    top-=2;
}
switch_start()
{
    ++switch_lbl;
}

case_start()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);

    printf("%s = %s == %s\n",temp,st[top-1],st[top]);
    strcpy(st[++top],temp);

    q[quadlen].op = (char*)malloc(sizeof(char)*strlen("=="));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"==");
    strcpy(q[quadlen].arg1,st[top-1]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;

    temp_i++;

    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);

    printf("%s = not %s\n",temp,st[top]);

    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;

    printf("if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

    temp_i++;
    label[++ltop]=lnum;
    top-=2;

}

case_end()
{
    printf("goto next%d\n\n",switch_lbl);

    q[quadlen].op = (char*)malloc(sizeof(char)*10);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*10);
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",switch_lbl);
    char l[]="next";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;

    int x = lnum;
    printf("L%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*10);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*10);
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;

    label[++ltop]=lnum;
    ++lnum;
}
case_end_without_break()
{
    int x = lnum;
    printf("\nL%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*10);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*10);
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;

    label[++ltop]=lnum;
    ++lnum;
}

default_end()
{
    printf("goto next%d\n",switch_lbl);

    q[quadlen].op = (char*)malloc(sizeof(char)*10);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*10);
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",switch_lbl);
    char l[]="next";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;
}

switch_end()
{
    int x = switch_lbl;
    printf("\nnext%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*10);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*10);
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="next";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;
}

if1()
{
    lnum++;
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = not %s\n",temp,st[top]);

    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;

    printf("if %s goto L%d\n",temp,lnum);

    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,st[top-2]);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

    temp_i++;
    label[++ltop]=lnum;
}

if3()
{
    int y;
    y=label[ltop--];
    printf("L%d: \n",y);

    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

    lnum++;
}

ifelse1()
{
    lnum++;
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = not %s\n",temp,st[top]);

    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;

    printf("if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

    temp_i++;
    label[++ltop]=lnum;
}

ifelse2()
{
    int x;
    lnum++;
    x=label[ltop--];
    printf("goto L%d\n",lnum);

    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;

    printf("L%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;

    label[++ltop]=lnum;
}

ifelse3()
{
    int y;
    y=label[ltop--];
    printf("L%d: \n",y);

    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

    lnum++;
}

ternary1()
{
    lnum++;
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = not %s\n",temp,st[top]);

    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;

    printf("if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

    temp_i++;
    label[++ltop]=lnum;
}

ternary2()
{
    int x;
    lnum++;
    x=label[ltop--];
    printf("goto L%d\n",lnum);

    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;

    printf("L%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;

    label[++ltop]=lnum;
}

ternary3()
{
    int y;
    y=label[ltop--];
    printf("L%d: \n",y);

    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
    lnum++;
}
