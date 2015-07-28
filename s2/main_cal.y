%{

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

%}

%token DIGIT
%left '+'
%left '*'

%%

start: expr '\n' { $$ = $1; int n = eval($$); printf("Result: %d\n", n); exit(0); }
	;

expr: 	DIGIT { $$ = $1; }
	  | '(' expr ')' { $$ = $2; }
	  |	expr '+' expr { $2->left = $1; $2->right = $3; $$ = $2; }
   	  | expr '*' expr { $2->left = $1; $2->right = $3; $$ = $2; }
	;

%%

void yyerror(char *s) { printf("Syntax Error\n"); }

int eval(struct node *s) {

	if(s->flag == 0) return s->val;
	else if(s->op == '+') return (eval(s->left)+eval(s->right));
	else return (eval(s->left)*eval(s->right));

}

int main() {

	yyparse();

	return 0;
}

