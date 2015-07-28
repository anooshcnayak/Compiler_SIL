%{	

	#define INF 1000
	// Headers
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	// Data
	int variables[26];

	// Function Prototypes

	void yyerror(char *);
	
%}

%union { int num; char id; };
%start line
%token <num> NUM
%token <id> ID
%token READ
%token WRITE
%token EXIT
%type <num> expr
%left '+'
%left '*'

%%

line :		
	 | line statement
	 | line EXIT ';' { exit(0); }
	;
statement : ID '=' expr ';'		 	{ assign_val($1, $3); }
	; 
statement : READ '(' ID ')' ';'  	{ read_val($3); }
	;
statement : WRITE '(' expr ')' ';' 	{ write_val($3); }
	;
expr : expr '+' expr { $$ = $1 + $3; }
	 | expr '*' expr { $$ = $1 * $3; }
	 | '(' expr ')'  { $$ = $2; }
	 | NUM  		 { $$ = $1; }
	 | ID  			 { $$ = get_val($1); }
	 | EXIT ';' 	 { exit(0); }
	;	
%%

void yyerror(char *string) {
	
	printf("%s\n", string);
}

int get_val(char ch) {
	
	if(variables[ch-'a'] == INF) {
		printf("Variable %c not defined.\n", ch);
		exit(0);
	}

	return variables[ch-'a'];
}

void assign_val(char c, int val) {

	variables[c-'a'] = val;
}

void read_val(char c) {

	int val;
	scanf("%d", &val);
	variables[c-'a'] = val;
}

void write_val(int val) {

	printf("%d\n", val);
}


int main() {
	
	int i;
	for(i = 0; i < 26; i++) variables[i] = INF;

	printf("Straight Line Program Interpreter v1.0 \n");
	printf("Type 'exit;' to Exit From The Program\n");	
	printf(">>> ");
	yyparse();
	
	return 0;
}
