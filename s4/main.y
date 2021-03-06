%{	

	#define INF 1000
	// Headers
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
	#include "tree.h"
	
	// Symbol Table
	int v[26];
	
	// Function Prototypes

	void yyerror(char *);
	
	struct node* makenode (char ch, int x);
	struct node* combine(int, int, ...);
	void assign_val(int, int);
	void read_val(int );
	void write_val(int);
	int eval(struct node*);
	void freenode(struct node*);
%}

%union { int num; int index; struct node* nodePtr; };
%start statements
%token <num> NUM
%token <index> ID
%token READ
%token WRITE
%token EXIT
%token IF
%token THEN
%token ENDIF
%token WHILE
%token DO
%token ENDWHILE
%type <nodePtr> expr statement statements
%nonassoc IFX
%nonassoc ELSE
%left '<' '>' GE LE EQ NE
%left '+' '-'
%left '*'
%nonassoc UMINUS

%%

statements: statement											{ $$ = $1; }
		  | statements statement								{ $$ = combine(';', 2, $1, $2); }
		  | statements EXIT ';' 								{ $$ = $1; eval($1); exit(0);  }
	
statement : expr '=' expr ';'		 							{ $$ = combine('=', 2, $1, $3); }
	; 
statement : READ '(' expr ')' ';'  								{ $$ = combine(READ, 1, $3); }
	;
statement : WRITE '(' expr ')' ';' 								{ $$ = combine(WRITE, 1, $3); }
	;
statement : IF '(' expr ')' THEN statements ENDIF ';' 			{ $$ = combine(IF, 2, $3, $6); }
	;	
statement : IF '(' expr ')' THEN statements ELSE statements ENDIF ';' { $$ = combine(IF, 3, $3, $6, $8); }
	;
statement : WHILE '(' expr ')' DO statements ENDWHILE ';' 			 { $$ = combine(WHILE, 2, $3, $6); }
	;

expr : NUM    		 			{ $$ = makenode('n', $1); }
	 | ID  			 			{ $$ = makenode('c', $1); }
	 | '-' expr %prec UMINUS 	{ $$ = combine(UMINUS, 1, $2); }
	 | expr '*' expr 			{ $$ = combine('*', 2, $1, $3);}
	 | expr '+' expr 			{ $$ = combine('+', 2, $1, $3);}
	 | expr '-' expr 			{ $$ = combine('-', 2, $1, $3);}	 
	 | '(' expr ')'  			{ $$ = $2; }
	 | expr '<' expr 			{ $$ = combine('<', 2, $1, $3);}
	 | expr '>' expr 			{ $$ = combine('>', 2, $1, $3);}
	 | expr GE expr	 			{ $$ = combine(GE, 2, $1, $3); }
	 | expr LE expr  			{ $$ = combine(LE, 2, $1, $3); }
	 | expr EQ expr	 			{ $$ = combine(EQ, 2, $1, $3); }
	 | expr NE expr	 			{ $$ = combine(NE, 2, $1, $3); }
	;
%%

int main() {
	
	int i;
	for(i = 0; i < 26; i++) v[i] = INF;
	
	printf("Straight Line Program Interpreter v1.0 \n");
	printf("Type 'exit;' to Exit From The Program\n");	
	printf(">>> ");
	yyparse();
	
	return 0;
}

void yyerror(char *string) {
	
	printf("%s\n", string);
}

struct node* makenode (char ch, int x) {
	
	struct node *p = (struct node *)malloc(sizeof(struct node));
	if(ch == 'n') {
		p->type = constant;
		p->value = x;
	}
	else {
		p->type = identifier;
		p->index = x;
	}
	return p;
}

struct node* combine(int token, int nops, ...) {

	va_list lst; int i;
	struct node* p = (struct node *)malloc(sizeof(struct node));
	p->childs = (struct node **)malloc(sizeof(struct node *)*nops);

	p->type = operation;
	p->oper = token;
	p->ops = nops;

	va_start(lst, nops);

	for(i = 0; i < nops; i++)
		p->childs[i] = va_arg(lst, struct node *);	
	va_end(lst);
	
	return p;
}

void assign_val(int i, int val) {

	v[i] = val;
}

void read_val(int i) {

	int val;
	scanf("%d", &val);
	v[i] = val;
}

void write_val(int val) {

	printf("%d\n", val);
}


int eval(struct node *p) {
	
	if(p == NULL) return 0;

	switch(p->type) {

		case constant: 		return p->value;
		case identifier:	return v[p->index];
		case operation:		

			switch(p->oper) {
				case ';': 	eval(p->childs[0]); eval(p->childs[1]); return 0;
				case IF:	if(eval(p->childs[0])) eval(p->childs[1]); else if(p->ops > 2) eval(p->childs[2]); return 0;
				case WHILE: while(eval(p->childs[0])) { eval(p->childs[1]); } return 0;
				case '+': 	return (eval(p->childs[0])+eval(p->childs[1]));
				case '-': 	return (eval(p->childs[0])-eval(p->childs[1]));				
				case '*': 	return (eval(p->childs[0])*eval(p->childs[1]));
				case '=': 	assign_val(p->childs[0]->index, eval(p->childs[1])); return 0;
				case UMINUS:return -eval(p->childs[0]);
				case READ:	read_val(p->childs[0]->index); return 0;
				case WRITE:	write_val(eval(p->childs[0])); return 0;
				case '<': 	return (eval(p->childs[0]) < eval(p->childs[1]));
				case '>': 	return (eval(p->childs[0]) > eval(p->childs[1]));
				case GE: 	return (eval(p->childs[0]) >= eval(p->childs[1]));
				case LE: 	return (eval(p->childs[0]) <= eval(p->childs[1]));
				case EQ: 	return (eval(p->childs[0]) == eval(p->childs[1]));
				case NE: 	return (eval(p->childs[0]) != eval(p->childs[1]));
			}
	}
}

void freenode(struct node *p) {

int i;

for(i = 0; i < p->ops; i++) freenode(p->childs[i]);

free(p);
}


