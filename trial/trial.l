%{

#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


%}

number [0-9]+

/* Rules Here */

%%

{number} 	return DIGIT;
[+*()] 		return *yytext;
[ \t\n]		;

%%

int yywrap() { return 1; }



