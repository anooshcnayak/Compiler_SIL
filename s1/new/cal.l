%{

#include "y.tab.h"
#include <cstdio>
#include <cstdlib>
int yylval;

%}

number [0-9]+

/* Rules Here */

%%

{number} { yylval = atoi(yytext); return DIGIT; }
[+*()\n] { return *yytext; }
[ \t] {}

%%

int yywrap() { return 1; }

