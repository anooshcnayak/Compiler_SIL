%{	

	#define INF 1000
	// Headers
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
	#include "tree.h"
	
	// Symbol Table
	//int v[26];
	
	struct Gsymbol *head, *tail, *dummy, *temp;
	
	extern FILE* yyin;

	// Function Prototypes

	void yyerror(char *);
	
	struct node* makenode (int x);
	struct node* combine(int, int, ...);
	void assign_val(char *, int);
	void read_val(char*);
	void assign_val2(struct node*, int);
	void read_val2(struct node*);
	void write_val(int);
	int eval(struct node*);
	void freenode(struct node*);
	void Ginstall(char *, dataType, int);
	struct Gsymbol *Glookup(char *);
	struct Gsymbol* newnode(char *, dataType, int);
%}

%union { int num; char *name; struct node* nodePtr; };
%start pgm
%token <num> NUM
%token <name> ID
%token READ
%token WRITE
%token EXIT
%token IF
%token ELSE
%token THEN
%token ENDIF
%token WHILE
%token DO
%token ENDWHILE
%token DECL
%token ENDDECL
%token INTEGER
%token BOOLEAN
%type <nodePtr> expr statement statements
%nonassoc IFX
%nonassoc ELSE
%left '<' '>' GE LE EQ NE
%left '+' '-'
%left '*'
%nonassoc UMINUS

%%

pgm	  : GDefblock statements EXIT ';'						{ eval($2); exit(0); 			}
	;
statements: statement											{ $$ = $1; }
		  | statements statement								{ $$ = combine(';', 2, $1, $2); }
	;
statement : ID '=' expr ';'		 							{ $$ = combine('=', 2, makename($1), $3); }
	;
statement : ID '[' NUM ']' '=' expr ';'		 				{ $$ = combine('=', 3, makename($1), makenode($3), $6); }
	;
statement : READ '(' ID ')' ';'  							{ $$ = combine(READ, 1, makename($3)); }
	;
statement : READ '(' ID '[' NUM ']' ')' ';'  				{ $$ = combine(READ, 1, makearray($3, makenode($5))); }
	;
statement : READ '(' ID '[' ID ']' ')' ';'  				{ $$ = combine(READ, 1, makearray($3, makename($5))); }
	;
statement : WRITE '(' expr ')' ';' 							{ $$ = combine(WRITE, 1, $3); }
	;
statement : WRITE '(' ID '[' NUM ']' ')' ';' 				{ $$ = combine(WRITE, 1, makearray($3, makenode($5))); }
	;
statement : WRITE '(' ID '[' ID ']' ')' ';' 				{ $$ = combine(WRITE, 1, makearray($3, makename($5))); }
	;
statement : IF '(' expr ')' THEN statements ENDIF ';' 			{ $$ = combine(IF, 2, $3, $6); }
	;	
statement : IF '(' expr ')' THEN statements ELSE statements ENDIF ';' { $$ = combine(IF, 3, $3, $6, $8); }
	;
statement : WHILE '(' expr ')' DO statements ENDWHILE ';' 			 { $$ = combine(WHILE, 2, $3, $6); }
	;

GDefblock : DECL GDefList ENDDECL {}
	;
GDefList :				  {}
		 | GDefList GDecl {}
	;
GDecl : INTEGER GId GIdList     {}
	;
GIdList : ';'
		| ',' GId GIdList 		{}
	;
GId : ID						{ Ginstall($1, integer, 1);  }
	| ID '[' NUM ']'			{ Ginstall($1, integer, $3); }
	;
expr : NUM    		 			{ $$ = makenode($1); }
	 | ID  			 			{ $$ = makename($1); }
	 | ID '[' NUM ']'  			{ $$ = makearray($1, makenode($3)); }
	 | ID '[' ID ']'  			{ $$ = makearray($1, makename($3)); }
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

int main(int argc, char *argv[]) {
	
	if(argc >= 2)
		yyin = fopen(argv[1], "r");
	else {
		printf("Straight Line Program Interpreter v1.0 \n");
		printf("Type 'exit;' to Exit From The Program\n");	
		printf(">>> ");		
	}
	
	head = tail = NULL;

	yyparse();
	
	if(argc >= 2) fclose(yyin);
	
	return 0;
}

void yyerror(char *string) {
	
	printf("%s\n", string);
}

struct node* makenode (int x) {
	
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->type = constant;
	p->value = x;
	
	return p;
}

struct node* makename(char *n) {
	
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->type = identifier;
	p->name = n;
	
	return p;
}


struct node* makearray (char *ch, struct node* p) {

	struct node *res = (struct node *)malloc(sizeof(struct node));
	res->type = array;
		
	res->childs = (struct node **)malloc((sizeof(struct node *))*2);
	
	res->childs[0] = makename(ch);
	res->childs[1] = p;

	return res;
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

void assign_val(char *n, int val) {
	
	dummy = Glookup(n);
	
	if(dummy != NULL) {
	
		*(dummy->ptr) = val;
		//printf("%s value is: %d\n", n, val);
		return;
	}
	else {
	
		printf("%s not declared.\n", dummy->name);
		exit(1);
	}
}

void assign_val2(struct node* p, int val) {
	
	dummy = Glookup(p->childs[0]->name);
	
	if(dummy != NULL) {
	
		if(p->childs[1]->value < dummy->size) {
			
			dummy->ptr[p->childs[1]->value] = val; 
			return;
		}
		
		printf("%s Array Out of bounds error: %d", dummy->name, p->childs[1]->value);
		exit(1);
	}
	else {
		printf("%s not declared", p->childs[0]->name);
		exit(1);
	}

}


void read_val(char *n) {
	
	dummy = Glookup(n);
	int temp;
	
	if(dummy != NULL) {
	
		scanf("%d", &temp);
		*(dummy->ptr) = temp;
	}
	else {
	
		printf("%s not declared", n);
		exit(1);
	}
}

void read_val2(struct node* p) {
	
	int x, ind;
	dummy = Glookup(p->childs[0]->name);
	
	if(dummy != NULL) {

		if(p->childs[1]->type == constant) {

			if(p->childs[1]->value < dummy->size)
				ind = p->childs[1]->value;
			else {
				printf("%s Array Out of bounds error: %d", dummy->name, p->childs[1]->value);
				exit(1);
			}
		}
		else {

			temp = Glookup(p->childs[1]->name);
			if(temp != NULL) ind = *(temp->ptr); else {printf("%s not declared.\n", temp->name); exit(1);}
		}

		scanf("%d", &x);
		dummy->ptr[ind] = x; 
		return;
	}
	else {
		printf("%s not declared", p->childs[0]->name);
		exit(1);
	}

}


void write_val(int val) {

	printf("%d\n", val);
}

void write_val1(struct node* p, int val) {

	dummy = Glookup(p->childs[0]->name);
	if(dummy != NULL) {
		if(val < dummy->size)
			write_val(dummy->ptr[val]);
		else {
			printf("%s Value out of bound: Array. Value: %d\n", p->name, val);
			exit(1);
		}
	}
	else {
			printf("%s not Declared.\n", p->name);
			exit(1);
	}


}

int array_eval(char *n, int ind) {

	dummy = Glookup(n);

	if(dummy != NULL) {
		if(ind < dummy->size)
			return dummy->ptr[ind];
		else {
			printf("Value out of bound: Array.\n");
			exit(1);
		}
	}
	else {
			printf("%s not Declared.\n", n);
			exit(1);
	}
}

int eval(struct node *p) {
	
	if(p == NULL) return 0;

	switch(p->type) {

		case constant: 		return p->value;
		case identifier:	dummy = Glookup(p->name);
							if(dummy != NULL) return *(dummy->ptr); else {printf("%s not declared.\n", p->name); exit(1);}
		case array		:   return array_eval(p->childs[0]->name, eval(p->childs[1]));
		case operation:		

			switch(p->oper) {
				case ';': 	eval(p->childs[0]); eval(p->childs[1]); return 0;
				case IF:	if(eval(p->childs[0])) eval(p->childs[1]); else if(p->ops > 2) eval(p->childs[2]); return 0;
				case WHILE: while(eval(p->childs[0])) { eval(p->childs[1]); } return 0;
				case '+': 	return (eval(p->childs[0])+eval(p->childs[1]));
				case '-': 	return (eval(p->childs[0])-eval(p->childs[1]));				
				case '*': 	return (eval(p->childs[0])*eval(p->childs[1]));
				case '=': 	if(p->childs[0]->type == identifier)
								assign_val(p->childs[0]->name, eval(p->childs[1]));
							else if(p->childs[0]->type == array)
								assign_val2(p->childs[0], eval(p->childs[1]));
							return 0;
				case UMINUS:return -eval(p->childs[0]);
				case READ:	if(p->childs[0]->type == identifier)
								read_val(p->childs[0]->name); 
							else if(p->childs[0]->type == array)
								read_val2(p->childs[0]);
							return 0;
				case WRITE:	if(p->childs[0]->type == array) {
								p = p->childs[0];
								write_val(array_eval(p->childs[0]->name, eval(p->childs[1])));
							}
							else
								write_val(eval(p->childs[0]));
							return 0;
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

struct Gsymbol* newnode(char *name, dataType t, int sz) {

	struct Gsymbol* pr = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	
	pr->name = name;
	pr->type = t;
	pr->size = sz;

	if(sz < 0) {
		printf("size of the array declared as negative.\n");
		 exit(0);
	}
	pr->ptr = (int*)malloc(sizeof(int)*sz);
	
	return pr;
}

struct Gsymbol *Glookup(char *n) {

	struct Gsymbol *temp = head;
	
	while(temp != NULL) {
		
		if(strcmp(temp->name, n) == 0)
			return temp;
		temp = temp->next;
	}
	
	return NULL;
}

void Ginstall(char *name, dataType t, int sz) {

	if (Glookup(name) != NULL) {
		printf("%s already declared.\n", name);
		exit(0);
	}
	
	if(head == NULL) {
		
		head = tail = newnode(name, t, sz);
		return;
	}

	tail->next = newnode(name, t, sz);
	tail = tail->next;
}
