%{

#include "tree.h"
#include "y.tab.h"


char* mkname();

%}

number [0-9]+

%%

{number} 	{ yylval.num = atoi(yytext); return NUM; }
[-=+*();<>,\[\]]	return yytext[0];
">="		{return GE;}
"<="		return LE;
"=="		return EQ;
"!="		return NE;
"read" 		return READ;
"write" 	return WRITE;
"exit"		return EXIT;
"if"		return IF;
"else" 		return ELSE;
"decl" 		return DECL;
"enddecl"	return ENDDECL;
"then"		return THEN;
"endif" 	return ENDIF;
"integer"   return INTEGER;
"boolean" 	return BOOLEAN;
"while"		return WHILE;
"do"		return DO;
"endwhile"	return ENDWHILE;
[A-Za-z][A-Za-z]*	{ yylval.name = (char *)malloc(sizeof(char)*(yyleng+1));
						int i;
					    for(i = 0; i < yyleng; i++) yylval.name[i] = yytext[i];
						yylval.name[i] = '\0';
						return ID;  
					}
[ \t]+ 		;
[\n]		{  }
.		yyerror("Unexpected Character");

%%

int yywrap() { return 1; }

