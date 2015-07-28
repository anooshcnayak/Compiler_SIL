%option noyywrap
%{

#define INF 1000
#include <stdio.h>
#include "y.tab.h"

extern YYSTYPE yylval;

%}

number [1-9][0-9]*

%%

{number} 	{ yylval.num = atoi(yytext); return NUM; }
[a-z] 		{ yylval.id = yytext[0]; return ID; }
[=+*();]	return yytext[0];
"read" 		return READ;
"write" 	return WRITE;
"exit"		return EXIT;
[ \t]+ 		;
[\n]		{ printf(">>> "); }
.		yyerror("Unexpected Character");
%%
