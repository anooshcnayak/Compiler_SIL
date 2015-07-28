#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "main.y"
	

	#define INF 1000
	/* Headers*/
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
	#include "tree.h"
	
	/* Symbol Table*/
	/*int v[26];*/
	
	struct Gsymbol *head, *tail, *dummy, *temp;
	
	extern FILE* yyin;

	/* Function Prototypes*/

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
#line 36 "main.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int num; char *name; struct node* nodePtr; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 62 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NUM 257
#define ID 258
#define READ 259
#define WRITE 260
#define EXIT 261
#define IF 262
#define ELSE 263
#define THEN 264
#define ENDIF 265
#define WHILE 266
#define DO 267
#define ENDWHILE 268
#define DECL 269
#define ENDDECL 270
#define INTEGER 271
#define BOOLEAN 272
#define IFX 273
#define GE 274
#define LE 275
#define EQ 276
#define NE 277
#define UMINUS 278
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    3,    3,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    4,    5,    5,    6,    8,    8,
    7,    7,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,
};
static const short yylen[] = {                            2,
    4,    1,    2,    4,    7,    5,    8,    8,    5,    8,
    8,    8,   10,    8,    3,    0,    2,    3,    1,    3,
    1,    4,    1,    1,    4,    4,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,
};
static const short yydefred[] = {                         0,
   16,    0,    0,    0,    0,    0,    0,    0,    0,    2,
    0,   15,    0,   17,    0,    0,    0,    0,    0,    0,
    0,    3,    0,    0,   23,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    0,   19,    0,   18,
    0,   27,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    4,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   31,    0,    0,    0,    0,    0,
    0,    0,    0,   28,    0,    0,    0,    6,    0,    0,
    9,    0,    0,   22,   20,   25,   26,    0,    0,    0,
    0,    0,    0,    0,    5,    0,    0,    0,    0,    0,
    0,    0,    7,    8,   10,   11,    0,   12,   14,    0,
   13,
};
static const short yydgoto[] = {                          2,
   29,   10,   11,    3,    4,   14,   24,   40,
};
static const short yysindex[] = {                      -256,
    0,    0,  -54, -254,    9,   35,   40,   48,   52,    0,
 -110,    0, -238,    0,  -37, -208, -204,   -5,  -37,  -37,
   12,    0,    3,   57,    0,    6,  -37,  -37,   64,   15,
  -26,    8,  -36,  -31,   -9,    0, -145,    0, -238,    0,
 -137,    0,   -4,  -37,  -37,  -37,  -37,  -37,  -37,  -37,
  -37,  -37,    0,   61, -117,   59, -115,   66, -135, -136,
   62,   57,   67,   69,    0,  -20,  -20,  -20,  -20,  -20,
  -20,   91,   91,    0,  -37,   82,   84,    0,   85,   86,
    0,  -54,  -54,    0,    0,    0,    0,   68,  113,  116,
  118,  120,  -75,  -86,    0,  122,  127,  130,  133,  -54,
  134,  139,    0,    0,    0,    0,  -63,    0,    0,  141,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   60,    0,    0,  -41,    0,    0,    0,    0,
    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   19,   23,   27,   31,   36,
   43,    7,   14,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -15,   72,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const short yygindex[] = {                         0,
  119,   51,   53,    0,    0,    0,  162,  145,
};
#define YYTABLESIZE 349
static const short yytable[] = {                         24,
   24,   24,   28,   24,   58,   52,   50,   27,   51,   59,
   52,   50,    1,   51,   56,   12,   13,   24,   24,   23,
   24,   52,   50,   44,   51,   45,   25,   25,   44,   25,
   45,   60,   52,   50,   28,   51,   65,   52,   50,   27,
   51,   24,   24,   24,   25,   24,   25,   29,   30,   29,
   44,   29,   45,   31,   30,   44,   30,   45,   30,   32,
   24,   22,   24,   33,   55,   29,   29,   34,   29,   15,
   36,   35,   30,   30,   17,   30,   36,   32,   32,   18,
   32,   33,   33,   37,   33,   34,   34,   19,   34,   35,
   35,   20,   35,   37,   36,   36,   41,   36,   57,   16,
   39,   37,   37,   21,   37,   52,   50,   54,   51,   52,
   50,   61,   51,   26,   26,   38,   26,   78,   21,   63,
   64,   75,   53,   44,   81,   45,   95,   44,   82,   45,
   83,   26,   52,   26,   93,   94,   33,   34,   35,   76,
   77,   79,   80,   22,   22,   42,   43,    5,    6,    7,
   21,    8,  107,   96,   84,    9,   97,   22,   98,   86,
   99,   87,   66,   67,   68,   69,   70,   71,   72,   73,
   74,    5,    6,    7,   89,    8,   90,   91,   92,    9,
  103,  102,    5,    6,    7,  104,    8,  100,  105,  101,
    9,  106,  108,   88,    5,    6,    7,  109,    8,  111,
   62,  110,    9,    5,    6,    7,   85,    8,    0,    0,
    0,    9,    0,    0,    0,    0,    0,    0,    0,   25,
   26,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   24,   24,   24,   24,    0,   46,   47,   48,
   49,    0,   46,   47,   48,   49,    0,    0,    0,    0,
    0,   25,   32,    0,    0,    0,    0,    0,   25,   25,
   25,   25,    0,    0,   46,   47,   48,   49,    0,   46,
   47,   48,   49,    0,   24,   24,   24,   24,    0,    0,
   29,   29,   29,   29,    0,    0,    0,   30,   30,   30,
   30,    0,   32,   32,   32,   32,   33,   33,   33,   33,
   34,   34,   34,   34,   35,   35,   35,   35,    0,   36,
   36,   36,   36,    0,    0,    0,   37,   37,   37,   37,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   46,   47,   48,
   49,   46,   47,   48,   49,   26,   26,   26,   26,
};
static const short yycheck[] = {                         41,
   42,   43,   40,   45,   41,   42,   43,   45,   45,   41,
   42,   43,  269,   45,   41,  270,  271,   59,   60,  258,
   62,   42,   43,   60,   45,   62,   42,   43,   60,   45,
   62,   41,   42,   43,   40,   45,   41,   42,   43,   45,
   45,   41,   42,   43,   60,   45,   62,   41,  257,   43,
   60,   45,   62,  258,   41,   60,   43,   62,   45,   41,
   60,   11,   62,   41,   91,   59,   60,   41,   62,   61,
   59,   41,   59,   60,   40,   62,   41,   59,   60,   40,
   62,   59,   60,   41,   62,   59,   60,   40,   62,   59,
   60,   40,   62,   91,   59,   60,   91,   62,   91,   91,
   44,   59,   60,   44,   62,   42,   43,   93,   45,   42,
   43,  257,   45,   42,   43,   59,   45,   59,   59,  257,
  258,   61,   59,   60,   59,   62,   59,   60,  264,   62,
  267,   60,   42,   62,   82,   83,   18,   19,   20,  257,
  258,  257,  258,   93,   94,   27,   28,  258,  259,  260,
  261,  262,  100,   41,   93,  266,   41,  107,   41,   93,
   41,   93,   44,   45,   46,   47,   48,   49,   50,   51,
   52,  258,  259,  260,   93,  262,   93,   93,   93,  266,
   59,  268,  258,  259,  260,   59,  262,  263,   59,  265,
  266,   59,   59,   75,  258,  259,  260,   59,  262,   59,
   39,  265,  266,  258,  259,  260,   62,  262,   -1,   -1,
   -1,  266,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  274,  275,  276,  277,   -1,  274,  275,  276,
  277,   -1,  274,  275,  276,  277,   -1,   -1,   -1,   -1,
   -1,  257,  258,   -1,   -1,   -1,   -1,   -1,  274,  275,
  276,  277,   -1,   -1,  274,  275,  276,  277,   -1,  274,
  275,  276,  277,   -1,  274,  275,  276,  277,   -1,   -1,
  274,  275,  276,  277,   -1,   -1,   -1,  274,  275,  276,
  277,   -1,  274,  275,  276,  277,  274,  275,  276,  277,
  274,  275,  276,  277,  274,  275,  276,  277,   -1,  274,
  275,  276,  277,   -1,   -1,   -1,  274,  275,  276,  277,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  276,
  277,  274,  275,  276,  277,  274,  275,  276,  277,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",
"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",
0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"NUM","ID","READ","WRITE","EXIT","IF","ELSE","THEN","ENDIF",
"WHILE","DO","ENDWHILE","DECL","ENDDECL","INTEGER","BOOLEAN","IFX","GE","LE",
"EQ","NE","UMINUS",
};
static const char *yyrule[] = {
"$accept : pgm",
"pgm : GDefblock statements EXIT ';'",
"statements : statement",
"statements : statements statement",
"statement : ID '=' expr ';'",
"statement : ID '[' NUM ']' '=' expr ';'",
"statement : READ '(' ID ')' ';'",
"statement : READ '(' ID '[' NUM ']' ')' ';'",
"statement : READ '(' ID '[' ID ']' ')' ';'",
"statement : WRITE '(' expr ')' ';'",
"statement : WRITE '(' ID '[' NUM ']' ')' ';'",
"statement : WRITE '(' ID '[' ID ']' ')' ';'",
"statement : IF '(' expr ')' THEN statements ENDIF ';'",
"statement : IF '(' expr ')' THEN statements ELSE statements ENDIF ';'",
"statement : WHILE '(' expr ')' DO statements ENDWHILE ';'",
"GDefblock : DECL GDefList ENDDECL",
"GDefList :",
"GDefList : GDefList GDecl",
"GDecl : INTEGER GId GIdList",
"GIdList : ';'",
"GIdList : ',' GId GIdList",
"GId : ID",
"GId : ID '[' NUM ']'",
"expr : NUM",
"expr : ID",
"expr : ID '[' NUM ']'",
"expr : ID '[' ID ']'",
"expr : '-' expr",
"expr : expr '*' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : '(' expr ')'",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr EQ expr",
"expr : expr NE expr",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 122 "main.y"

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
#line 662 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 64 "main.y"
	{ eval(yystack.l_mark[-2].nodePtr); exit(0); 			}
break;
case 2:
#line 66 "main.y"
	{ yyval.nodePtr = yystack.l_mark[0].nodePtr; }
break;
case 3:
#line 67 "main.y"
	{ yyval.nodePtr = combine(';', 2, yystack.l_mark[-1].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 4:
#line 69 "main.y"
	{ yyval.nodePtr = combine('=', 2, makename(yystack.l_mark[-3].name), yystack.l_mark[-1].nodePtr); }
break;
case 5:
#line 71 "main.y"
	{ yyval.nodePtr = combine('=', 3, makename(yystack.l_mark[-6].name), makenode(yystack.l_mark[-4].num), yystack.l_mark[-1].nodePtr); }
break;
case 6:
#line 73 "main.y"
	{ yyval.nodePtr = combine(READ, 1, makename(yystack.l_mark[-2].name)); }
break;
case 7:
#line 75 "main.y"
	{ yyval.nodePtr = combine(READ, 1, makearray(yystack.l_mark[-5].name, makenode(yystack.l_mark[-3].num))); }
break;
case 8:
#line 77 "main.y"
	{ yyval.nodePtr = combine(READ, 1, makearray(yystack.l_mark[-5].name, makename(yystack.l_mark[-3].name))); }
break;
case 9:
#line 79 "main.y"
	{ yyval.nodePtr = combine(WRITE, 1, yystack.l_mark[-2].nodePtr); }
break;
case 10:
#line 81 "main.y"
	{ yyval.nodePtr = combine(WRITE, 1, makearray(yystack.l_mark[-5].name, makenode(yystack.l_mark[-3].num))); }
break;
case 11:
#line 83 "main.y"
	{ yyval.nodePtr = combine(WRITE, 1, makearray(yystack.l_mark[-5].name, makename(yystack.l_mark[-3].name))); }
break;
case 12:
#line 85 "main.y"
	{ yyval.nodePtr = combine(IF, 2, yystack.l_mark[-5].nodePtr, yystack.l_mark[-2].nodePtr); }
break;
case 13:
#line 87 "main.y"
	{ yyval.nodePtr = combine(IF, 3, yystack.l_mark[-7].nodePtr, yystack.l_mark[-4].nodePtr, yystack.l_mark[-2].nodePtr); }
break;
case 14:
#line 89 "main.y"
	{ yyval.nodePtr = combine(WHILE, 2, yystack.l_mark[-5].nodePtr, yystack.l_mark[-2].nodePtr); }
break;
case 15:
#line 92 "main.y"
	{}
break;
case 16:
#line 94 "main.y"
	{}
break;
case 17:
#line 95 "main.y"
	{}
break;
case 18:
#line 97 "main.y"
	{}
break;
case 20:
#line 100 "main.y"
	{}
break;
case 21:
#line 102 "main.y"
	{ Ginstall(yystack.l_mark[0].name, integer, 1);  }
break;
case 22:
#line 103 "main.y"
	{ Ginstall(yystack.l_mark[-3].name, integer, yystack.l_mark[-1].num); }
break;
case 23:
#line 105 "main.y"
	{ yyval.nodePtr = makenode(yystack.l_mark[0].num); }
break;
case 24:
#line 106 "main.y"
	{ yyval.nodePtr = makename(yystack.l_mark[0].name); }
break;
case 25:
#line 107 "main.y"
	{ yyval.nodePtr = makearray(yystack.l_mark[-3].name, makenode(yystack.l_mark[-1].num)); }
break;
case 26:
#line 108 "main.y"
	{ yyval.nodePtr = makearray(yystack.l_mark[-3].name, makename(yystack.l_mark[-1].name)); }
break;
case 27:
#line 109 "main.y"
	{ yyval.nodePtr = combine(UMINUS, 1, yystack.l_mark[0].nodePtr); }
break;
case 28:
#line 110 "main.y"
	{ yyval.nodePtr = combine('*', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 29:
#line 111 "main.y"
	{ yyval.nodePtr = combine('+', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 30:
#line 112 "main.y"
	{ yyval.nodePtr = combine('-', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 31:
#line 113 "main.y"
	{ yyval.nodePtr = yystack.l_mark[-1].nodePtr; }
break;
case 32:
#line 114 "main.y"
	{ yyval.nodePtr = combine('<', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 33:
#line 115 "main.y"
	{ yyval.nodePtr = combine('>', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 34:
#line 116 "main.y"
	{ yyval.nodePtr = combine(GE, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 35:
#line 117 "main.y"
	{ yyval.nodePtr = combine(LE, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 36:
#line 118 "main.y"
	{ yyval.nodePtr = combine(EQ, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 37:
#line 119 "main.y"
	{ yyval.nodePtr = combine(NE, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
#line 1012 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
