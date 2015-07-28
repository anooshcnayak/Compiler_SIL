%{

#include "tree.h"
#include "y.tab.h"

int linecount = 0;


char* mkname();

%}

number [0-9]+

%%

{number} 	{ yylval.num = atoi(yytext); return NUM; }
[-=+*();><,\[\]{}]	return yytext[0];
">="		{return GE;}
"<="		return LE;
"=="		return EQ;
"!="		return NE;
"main"		return MAIN;
"read" 		return READ;
"write" 	return WRITE;
"exit"		return EXIT;
"begin"		return BEG;
"end"		return EN;
"return"	return RET;
"if"		return IF;
"else" 		return ELSE;
"decl" 		return DECL;
"enddecl"	return ENDDECL;
"then"		return THEN;
"endif" 	return ENDIF;
"integer"   return INTEGER;
"and" 		return AN;
"or"		return ORR;
"boolean" 	return BOOLEAN;
"while"		return WHILE;
"do"		return DO;
"endwhile"	return ENDWHILE;
"true"		return TR;
"false"		return FAL;
[A-Za-z][A-Za-z]*	{ yylval.name = (char *)malloc(sizeof(char)*(yyleng+1));
						int i;
					    for(i = 0; i < yyleng; i++) yylval.name[i] = yytext[i];
						yylval.name[i] = '\0';
						return ID;  
					}
[ \t]+ 		;
[\n]		{ linecount++; }
.		yyerror("Unexpected Character");

%%

int yywrap() { return 1; }

