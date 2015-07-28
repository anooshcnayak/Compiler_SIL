%{

#include "tree.h"
#include "y.tab.h"

%}

number [0-9]+

%%

{number} 	{ yylval.num = atoi(yytext); return NUM; }
[a-z]		{ yylval.index = yytext[0]-'a'; return ID;  }
[-=+*();<>]	return yytext[0];
">="		{return GE;}
"<="		return LE;
"=="		return EQ;
"!="		return NE;
"read" 		return READ;
"write" 	return WRITE;
"exit"		return EXIT;
"if"		return IF;
"then"		return THEN;
"endif" 	return ENDIF;
"while"		return WHILE;
"do"		return DO;
"endwhile"	return ENDWHILE;
[ \t]+ 		;
[\n]		{ printf(">>> "); }
.		yyerror("Unexpected Character");


%%

int yywrap() { return 1; }


