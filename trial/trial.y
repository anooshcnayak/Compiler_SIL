%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[100000], top;

%}

%token DIGIT
%right '+'
%right '*'

%%

start: expr '\n' { printf("%s\n", $1); exit(0); }
	;

expr  :  DIGIT { stack[top++] = $1; }
	  | '(' expr ')' { $$ = $2; }+
	  | expr '+' expr { $$ = strcat(strcat("+", $1), $3); }
   	  | expr '*' expr { $$ = strcat(strcat("*", $1), $3); }
	;

%%

void yyerror(char *s) { printf("Syntax Error\n"); }

int main() {

	yyparse();

	return 0;
}

