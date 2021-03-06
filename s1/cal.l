%option noyywrap
%{

#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YYSTYPE char *

extern YYSTYPE yylval;

%}

number [0-9]+

/* Rules Here */

%%

{number} { yylval = (char *)malloc(sizeof(char)*(yyleng+1));
	   int i;
	   for(i = 0; i < yyleng; i++) yylval[i] = yytext[i];
	   yylval[i] = '\0';
	   return DIGIT; 
	 }
[+*();] 	return *yytext;
[ \t] 		;
[\n]		printf(">>> ");
"exit" 		return EXIT;

%%


