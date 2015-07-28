%{

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "tree.h"

YYSTYPE yylval;

void yyerror(char *);


%}

number [0-9]+

%%

{number}  {

		yylval = (struct node *)malloc(sizeof(struct node));
		yylval->val = atoi(yytext);
		yylval->flag= 0;
		yylval->left = yylval->right = NULL;
		return DIGIT;
	 }

[+*] 	{

		yylval = (struct node *)malloc(sizeof(struct node));
		yylval->op = *yytext;
		yylval->flag= 1;
		yylval->left = yylval->right = NULL;
		return *yytext;
	}

[()\n] { return *yytext; }

[ \t] ;

. yyerror("Syntax Error");


%%

int yywrap() { return 1; }
