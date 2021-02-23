%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE char *
int yylex();
void yyerror(char *);
void print_table();
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
}symbol_table_node;

int no_of_entries = 0;
symbol_table_node symbol_table[100];

%}
%token ID NUM CHARACTER FLNUM T_lt T_gt T_lteq T_gteq T_neq T_eqeq T_pl T_min T_mul T_div T_and T_or T_incr T_decr T_not T_eq INT CHAR FLOAT VOID H MAINTOK INCLUDE BREAK CONTINUE IF ELSE PRINTF STRING SWITCH CASE DEFAULT

%%
S
      : START {printf("No syntax errors detected!\n");}
      ;

START
      : INCLUDE T_lt H T_gt MAIN
      ;

MAIN
      : VOID MAINTOK '(' ')' BODY {insert($2,'F',NULL,"void",@1.last_line);}
      | INT MAINTOK '(' ')' BODY  {insert($2,'F',NULL,"int",@1.last_line);}
      ;

BODY
      : '{' C '}'
      ;

C
      : C statement ';'
      | C LOOPS
      | statement ';'
      | LOOPS
      ;

LOOPS
      : IF '(' COND ')' LOOPBODY
      | IF '(' COND ')' LOOPBODY ELSE LOOPBODY
      | STMT_SWITCH
      ;

STMT_SWITCH	
      : SWITCH '(' COND ')' '{' SWITCHBODY '}'
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
  	  : '{' C '}'
  	  | ';'
  	  | statement ';'
  	  ;

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
      | un_boolop '(' LIT RELOP LIT ')'
      | un_boolop LIT RELOP LIT
      | LIT bin_boolop LIT
      | un_boolop '(' LIT ')'
      | un_boolop LIT
      ;

ASSIGN_EXPR
      : ID T_eq ARITH_EXPR
      | TYPE ID T_eq ARITH_EXPR {insert($2,'I',$4,$1,@1.last_line);}
      | TYPE ID {insert($2,'I',NULL,$1,@1.last_line);}
      | TYPE ID'['']' T_eq STRING {insert($2,'I',$6,$1,@1.last_line);}
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
      : '(' COND ')' '?' statement ':' statement
      ;

PRINT
      : PRINTF '(' STRING ')'
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

void yyerror(char* s){
  printf("Line %d - %s \n",count,s);
  exit(0);
}

void insert(char* token,char type,char* value,char* datatype,int line_no)
{
      //to make sure multiple declarations are not allowed
      for(int i=0;i<no_of_entries;++i)
      {
            if(strcmp(symbol_table[i].name,token)==0)
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
        
    no_of_entries++;
}

void print_table()
{
	printf("Number of entries in the symbol table = %d\n\n",no_of_entries);
    printf("-----------------------------------Symbol Table-----------------------------------\n\n");
    printf("S.No\t Token_name\t Type\t DataType\t Value\t LineNumber\n");
	for(int i=0;i<no_of_entries;++i)
	{
		printf("%d\t %s\t\t %c\t %s\t\t %s\t %d\n",i+1,symbol_table[i].name,symbol_table[i].type,symbol_table[i].datatype,symbol_table[i].value,symbol_table[i].line_no);
	}
}

int main(int argc, char* args[])
{
  yyin=fopen(args[1],"r");
  yyparse();
  print_table();
  return 0;
}
