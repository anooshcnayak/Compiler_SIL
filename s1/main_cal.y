%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

%}

%token DIGIT
%left '+' '-'
%left '*'

%%

start: expr '\n' { printf("Result: %d\n", $1); exit(0); }
	;

expr:	expr '+' expr { $$ = $1 + $3; }
	  | expr '*' expr	{ $$ = $1 * $3; }
	  | '(' expr ')'  { $$ = $2; }
	  | DIGIT		{ $$ = $1; }
	;
%%

void yyerror(char *s) { printf("%s\n", s); }


int main() {

	yyparse();
	return 0;
}
