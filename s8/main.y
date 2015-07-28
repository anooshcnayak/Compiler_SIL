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
	void assign_val(char *, struct retnode);
	void read_val(char*);
	void assign_val2(struct node*, struct retnode);
	void read_val2(struct node*);
	void write_val(int);
	struct retnode eval(struct node*);
	void freenode(struct node*);
	void Ginstall(char *, dataType, int);
	struct Gsymbol *Glookup(char *);
	struct Gsymbol* newnode(char *, dataType, int);
	void error1();
	void error2(char *n);
	void error3(char *n);
	void error4(char *n);
%}

%union { int num; char *name; struct node* nodePtr; };
%start pgm
%token <num> NUM
%token <name> ID
%token READ
%token WRITE
%token EXIT
%token TR FAL BEG EN RET
%token IF
%token ELSE
%token THEN
%token ENDIF
%token WHILE
%token DO
%token ENDWHILE
%token DECL
%token MAIN
%token ENDDECL
%token INTEGER
%token BOOLEAN


%type <nodePtr> expr statement statements GId GIdList body ret
%nonassoc IFX
%nonassoc ELSE
%left '<' '>' GE LE EQ NE
%left '+' '-'
%left '*'
%nonassoc UMINUS

%%
		
pgm	  : GDefblock Mainblock												{ exit(0); }
	;
GDefblock : DECL GDefList ENDDECL {}
	;
GDefList :				  {}
		 | GDefList GDecl {}
	;
GDecl : INTEGER GIdList ';'     { create_list(integer, $2); }
	  | BOOLEAN GIdList ';' 	{ create_list(boolean, $2); }
	;
GIdList : GId 					{ $$ = $1; }
		| GId ',' GIdList 		{ $$ = combine(',', 2, $1, $3); }
	;
GId : ID						{ $$ = makename($1);  }
	| ID '[' NUM ']'			{ $$ = makearray($1, makenode($3)); }
	;
Mainblock : INTEGER MAIN '(' ')' '{' body '}'							{ eval($6); }
	;
body	:  BEG statements ret EN 										{ $$ = combine(BEG, 2, $2, $3); }
	;
ret 	:  RET NUM ';'													{ $$ = combine(RET, 1, makenode($2)); }
	;
statements: statement													{ $$ = $1; }
		  | statements statement										{ $$ = combine(';', 2, $1, $2); }
	;
statement : ID '=' expr ';'		 										{ $$ = combine('=', 2, makename($1), $3); }
		  | ID '[' NUM ']' '=' expr ';'		 							{ $$ = combine('=', 3, makename($1), makenode($3), $6); }
		  | READ '(' ID ')' ';'  										{ $$ = combine(READ, 1, makename($3)); }
		  | READ '(' ID '[' NUM ']' ')' ';'  							{ $$ = combine(READ, 1, makearray($3, makenode($5))); }
		  | READ '(' ID '[' ID ']' ')' ';'  							{ $$ = combine(READ, 1, makearray($3, makename($5))); }
		  | WRITE '(' expr ')' ';' 										{ $$ = combine(WRITE, 1, $3); }
		  | WRITE '(' ID '[' NUM ']' ')' ';' 							{ $$ = combine(WRITE, 1, makearray($3, makenode($5))); }
		  | WRITE '(' ID '[' ID ']' ')' ';' 							{ $$ = combine(WRITE, 1, makearray($3, makename($5))); }
		  | IF '(' expr ')' THEN statements ENDIF ';' 					{ $$ = combine(IF, 2, $3, $6); }
		  | IF '(' expr ')' THEN statements ELSE statements ENDIF ';' 	{ $$ = combine(IF, 3, $3, $6, $8); }
		  | WHILE '(' expr ')' DO statements ENDWHILE ';' 			 	{ $$ = combine(WHILE, 2, $3, $6); }
	;
expr : NUM    		 			{ $$ = makenode($1); }
	 | ID  			 			{ $$ = makename($1); }
	 | TR 						{ $$ = makebool(1); }
	 | FAL						{ $$ = makebool(0); }
	 | ID '[' expr ']'  			{ $$ = makearray($1, makenode($3)); }
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

struct node* makebool(int val) {

	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->type = boole;
	p->value = val;
	
	return p;	
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

void assign_val(char *n, struct retnode res) {
	
	dummy = Glookup(n);
	
	if(dummy != NULL) {

		if(dummy->type != res.type) error1();
	
		*(dummy->ptr) = res.val;
		//printf("%s value is: %d\n", n, val);
		return;
	}
	else {
	
		printf("%s not declared.\n", dummy->name);
		exit(1);
	}
}

void assign_val2(struct node* p, struct retnode res) {
	
	dummy = Glookup(p->childs[0]->name);
	
	if(dummy != NULL) {
		
		if(dummy->type != res.type) error1();

		if(p->childs[1]->value < dummy->size) {
			
			dummy->ptr[p->childs[1]->value] = res.val; 
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
	
		printf("%s not declared. here", n);
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
			else error3(dummy->name);
		}
		else {
			temp = Glookup(p->childs[1]->name);

			if(temp->type != integer) error2(dummy->name);

			if(temp != NULL) ind = *(temp->ptr); else error4(temp->name);
		}

		scanf("%d", &x);
		dummy->ptr[ind] = x; 
		return;
	}
	else error4(p->childs[0]->name);

}


void write_val(int val) {

	printf("%d\n", val);
}

int array_eval(char *n, struct retnode res) {

	dummy = Glookup(n);

	if(dummy != NULL) {

		if(res.type != integer) error2(dummy->name);

		if(res.val < dummy->size)
			return dummy->ptr[res.val];
		else error3(dummy->name);
	}
	else error4(n);
}

struct retnode make_ret(int val, dataType t) {

	struct retnode res;
	res.val = val;
	res.type = t;

	return res;
}

void error1() {

	printf("Type mismatch.\n");
	exit(1);
}

void error2(char *n) {

	printf("%s Array indexing not an INT\n", n);
	exit(1);
}

void error3(char *n) {
	printf("%s Value out of bound: Array.\n", n);
	exit(1);
}

void error4(char *n) {
	printf("%s not Declared.\n", n);
	exit(1);
}

int check(struct node* l, struct node *r) {

	if(eval(l).type == integer && eval(r).type == integer)
		return 1;
	else
		return 0;
}


struct retnode eval(struct node *p) {

		if(p == NULL) return make_ret(0, integer);

	switch(p->type) {

		case constant	: 	return make_ret(p->value, integer);
		case identifier :	dummy = Glookup(p->name);
							if(dummy != NULL) return make_ret(*(dummy->ptr), dummy->type); else error4(p->name);
		case boole 		:	return make_ret(p->value, boolean);
		case array		:   if(eval(p->childs[1]).type == integer)
								return make_ret(array_eval(p->childs[0]->name, eval(p->childs[1])), integer);
							else error1();
		case operation:		

			switch(p->oper) {
				case BEG:	eval(p->childs[0]); eval(p->childs[1]); return make_ret(0, integer);
				case RET: 	eval(p->childs[0]); return make_ret(0, integer);
				case ';': 	eval(p->childs[0]); eval(p->childs[1]); return make_ret(0, integer);
				case IF:	if(eval(p->childs[0]).val) eval(p->childs[1]); else if(p->ops > 2) eval(p->childs[2]); return make_ret(0, integer);
				case WHILE: while(eval(p->childs[0]).val) { eval(p->childs[1]); } return make_ret(0, integer);
				case '+': 	if(check(p->childs[0], p->childs[1]))
								return make_ret(eval(p->childs[0]).val+eval(p->childs[1]).val, integer);
							else error1();
				case '-': 	if(check(p->childs[0], p->childs[1]))
								return make_ret(eval(p->childs[0]).val-eval(p->childs[1]).val, integer);
							else error1();
				case '*': 	if(check(p->childs[0], p->childs[1]))
								return make_ret(eval(p->childs[0]).val*eval(p->childs[1]).val, integer);
							else error1();
				case '=': 	if(p->childs[0]->type == identifier)
								assign_val(p->childs[0]->name, eval(p->childs[1]));
							else if(p->childs[0]->type == array)
								assign_val2(p->childs[0], eval(p->childs[1]));
							return make_ret(0, integer);
				case UMINUS:return make_ret(-eval(p->childs[0]).val, eval(p->childs[0]).type);
				case READ:	if(p->childs[0]->type == identifier)
								read_val(p->childs[0]->name); 
							else if(p->childs[0]->type == array)
								read_val2(p->childs[0]);
							return make_ret(0, integer);
				case WRITE:	if(p->childs[0]->type == array) {
								p = p->childs[0];
								write_val(array_eval(p->childs[0]->name, eval(p->childs[1])));
							}
							else
								write_val(eval(p->childs[0]).val);
							return make_ret(0, integer);
				case '<': 	if(check(p->childs[0], p->childs[1]))
								return make_ret(eval(p->childs[0]).val < eval(p->childs[1]).val, boolean);
							else error1();
				case '>': 	if(check(p->childs[0], p->childs[1]))
								return make_ret(eval(p->childs[0]).val > eval(p->childs[1]).val, boolean);
							else error1();
				case GE: 	if(check(p->childs[0], p->childs[1]))
								return make_ret(eval(p->childs[0]).val >= eval(p->childs[1]).val, boolean);
							else error1();	
				case LE: 	if(check(p->childs[0], p->childs[1]))
								return make_ret(eval(p->childs[0]).val <= eval(p->childs[1]).val, boolean);
							else error1();
				case EQ: 	if(check(p->childs[0], p->childs[1]))
								return make_ret(eval(p->childs[0]).val == eval(p->childs[1]).val, boolean);
							else error1();
				case NE: 	if(check(p->childs[0], p->childs[1]))
								return make_ret(eval(p->childs[0]).val != eval(p->childs[1]).val, boolean);
							else error1();
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

void create_list(dataType t, struct node* p) {

	if(p == NULL) return;

	switch(p->type) {

		case operation:  create_list(t, p->childs[0]); create_list(t, p->childs[1]); return;
		case identifier: Ginstall(p->name, t, 1);	return;
		case array: 	 Ginstall(p->childs[0]->name, t, p->childs[1]->value); return;
	}
}