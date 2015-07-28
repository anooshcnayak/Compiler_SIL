%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YYSTYPE char *

char* assign_ptr(char, char *, char *);
void yyerror(char *); 

%}

%token DIGIT
%token EXIT
%start line
%right '+'
%right '*'

%%

line	: expr ';' 		  { printf("%s\n", $1); } 
		| line expr ';'	  { printf("%s\n", $2); } 
		| line EXIT ';'	  {	exit(0); }
 		;

expr  : 	DIGIT { $$ = $1; }
	  | 	'(' expr ')'  { $$ = $2; }
	  |		expr '+' expr { $$ = assign_ptr('+', $1, $3); }
   	  | 	expr '*' expr { $$ = assign_ptr('*', $1, $3); }
	;

%%

int main() {
	

	printf("Infix to PostFix Conversion\n");
	printf("Type 'exit;' to Exit\n");
	printf(">>> ");
	yyparse();

	return 0;
}

char* assign_ptr(char ch, char *l, char *r) {
	int i, j;
	int size = 8 + strlen(l) + strlen(r);
	char *p = (char *)malloc(sizeof(char)*size);
	
	p[0] = ch;p[1] = ' ';
	
	for(i = 2, j = 0; j < strlen(l); i++, j++) p[i] = l[j];

	p[i++] = ' ';

	for(j = 0; j < strlen(r); i++, j++) p[i] = r[j];
	
	p[i++] = ' ';
	p[i] = '\0';
	return p;
}

void yyerror(char *s) { printf("Syntax Error\n"); }
