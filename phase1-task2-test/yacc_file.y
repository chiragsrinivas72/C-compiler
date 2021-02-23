%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE char *
int yylex();
void yyerror(char *);
void print_table();
void increment_scope();
void decrement_scope();
void insert(char* token,char type,char* value,char* datatype,int line_no);
extern FILE *yyin;
extern char *yytext;
extern int yylineno;

typedef struct symbol_table
{
    char name[31];
    char type;
    char *value;
    char *datatype;
    int line_no;
    int scope;
}symbol_table_node;

int no_of_entries = 0;
symbol_table_node symbol_table[100];
int scope = 0;

%}
%token ID NUM CHARACTER FLNUM T_lt T_gt T_lteq T_gteq T_neq T_eqeq T_pl T_min T_mul T_div T_and T_or T_incr T_decr T_not T_eq INT CHAR FLOAT VOID H MAINTOK INCLUDE BREAK CONTINUE IF ELSE PRINTF STRING SWITCH CASE DEFAULT  T_dims T_op T_cp T_ob T_cb T_cop T_ccp T_comma

%%
S
      : START {printf("No syntax errors detected!\n");}
      ;

START
      : INCLUDE T_lt H T_gt MAIN
      ;

MAIN
      : VOID MAINTOK T_op T_cp BODY {insert($2,'F',NULL,"void",@1.last_line);}
      | INT MAINTOK T_op T_cp BODY  {insert($2,'F',NULL,"int",@1.last_line);}
      ;

BODY
      : COP C CCP
      ;

C
      : C statement ';'
      | C LOOPS
      | statement ';'
      | LOOPS
      ;

LOOPS
      : IF T_op COND T_cp LOOPBODY
      | IF T_op COND T_cp LOOPBODY ELSE LOOPBODY
      | STMT_SWITCH
      ;

STMT_SWITCH	
      : SWITCH T_op COND T_cp COP SWITCHBODY CCP
	;
SWITCHBODY	
      : CASES   
	| CASES DEFAULTSTMT
	;

CASES 
      : CASE NUM ':' C BREAKSTMT
	| 
	;

BREAKSTMT
      : BREAK ';' CASES
	| CASES 
	;

DEFAULTSTMT : DEFAULT ':' C DE  
				;

DE 	: BREAK ';'
	|
	;

LOOPBODY
  	  : COP C CCP
  	  | ';'
  	  | statement ';'
  	  ;
COP   : T_cop {increment_scope();}
      ;

CCP   : T_ccp {decrement_scope();}

statement
      : ASSIGN_EXPR
      | ARITH_EXPR
      | TERNARY_EXPR
      | PRINT
      ;

COND
      : LIT RELOP LIT
      | LIT
      | LIT RELOP LIT bin_boolop LIT RELOP LIT
      | un_boolop T_op LIT RELOP LIT T_cp
      | un_boolop LIT RELOP LIT
      | LIT bin_boolop LIT
      | un_boolop T_op LIT T_cp
      | un_boolop LIT
      ;

ASSIGN_EXPR
      : ID T_eq ARITH_EXPR
      | TYPE ID T_eq ARITH_EXPR {insert($2,'I',$4,$1,@1.last_line);}
      | TYPE ID {insert($2,'I',NULL,$1,@1.last_line);}
      | TYPE ID T_dims T_eq STRING {insert($2,'I',$5,$1,@1.last_line);}
      | TYPE ID T_ob NUM T_cb T_eq STRING {insert($2,'I',$7,$1,@1.last_line);}
      ;

ARITH_EXPR
      : LIT
      | LIT bin_arop ARITH_EXPR
      | LIT bin_boolop ARITH_EXPR
      | LIT un_arop
      | un_arop ARITH_EXPR
      | un_boolop ARITH_EXPR
      ;

TERNARY_EXPR
      : T_op COND T_cp '?' statement ':' statement
      ;

PRINT
      : PRINTF T_op STRING T_cp
      ;
LIT
      : ID
      | NUM
      | FLNUM
      | CHARACTER
      ;
TYPE
      : INT
      | CHAR
      | FLOAT
      ;
RELOP
      : T_lt
      | T_gt
      | T_lteq
      | T_gteq
      | T_neq
      | T_eqeq
      ;

bin_arop
      : T_pl
      | T_min
      | T_mul
      | T_div
      ;

bin_boolop
      : T_and
      | T_or
      ;

un_arop
      : T_incr
      | T_decr
      ;

un_boolop
      : T_not
      ;


%%

#include "lex.yy.c"

void yyerror(char* s)
{
  printf("Line %d - %s \n",count,s);
  exit(0);
}
void increment_scope()
{
      scope+=1;
}
void decrement_scope()
{
      scope-=1;
}
void insert(char* token,char type,char* value,char* datatype,int line_no)
{
      //to make sure multiple declarations are not allowed
      for(int i=0;i<no_of_entries;++i)
      {
            if(symbol_table[i].scope == scope && strcmp(symbol_table[i].name,token)==0)
            {
                  yyerror("Multiple declarations not allowed");
            }
      }

      //to take the first 32 characters if the length of indentifier > 32
	int n = strlen(token);
	if(n>31)
		n=31;
	strncpy(symbol_table[no_of_entries].name,token,32);

	symbol_table[no_of_entries].type=type;

    if(value==NULL)
        symbol_table[no_of_entries].value=NULL;
    else
	{
		char* temp = malloc(strlen(value));
		strcpy(temp,value);
            symbol_table[no_of_entries].value=temp;
	}
        
      if(datatype==NULL)
            symbol_table[no_of_entries].datatype=NULL;
      else
            symbol_table[no_of_entries].datatype=datatype;
      symbol_table[no_of_entries].line_no = line_no;
      symbol_table[no_of_entries].scope =scope;
        
    no_of_entries++;
}

void print_table()
{
	printf("Number of entries in the symbol table = %d\n\n",no_of_entries);
    printf("-----------------------------------Symbol Table-----------------------------------\n\n");
    printf("S.No\t Token_name\t Type\t DataType\t Value\t\t LineNumber\t Scope\n");
	for(int i=0;i<no_of_entries;++i)
	{
		printf("%d\t %s\t\t %c\t %s\t\t %s\t\t %d\t\t %d\n",i+1,symbol_table[i].name,symbol_table[i].type,symbol_table[i].datatype,symbol_table[i].value,symbol_table[i].line_no,symbol_table[i].scope);
	}
}

int main(int argc, char* args[])
{
  yyin=fopen(args[1],"r");
  yyparse();
  print_table();
  return 0;
}
