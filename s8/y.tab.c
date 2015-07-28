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
#line 40 "main.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int num; char *name; struct node* nodePtr; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 66 "y.tab.c"

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
#define TR 262
#define FAL 263
#define BEG 264
#define EN 265
#define RET 266
#define IF 267
#define ELSE 268
#define THEN 269
#define ENDIF 270
#define WHILE 271
#define DO 272
#define ENDWHILE 273
#define DECL 274
#define MAIN 275
#define ENDDECL 276
#define INTEGER 277
#define BOOLEAN 278
#define IFX 279
#define GE 280
#define LE 281
#define EQ 282
#define NE 283
#define UMINUS 284
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    8,   10,   10,   11,   11,    5,    5,    4,    4,
    9,    6,    7,    3,    3,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,
};
static const short yylen[] = {                            2,
    2,    3,    0,    2,    3,    3,    1,    3,    1,    4,
    7,    4,    3,    1,    2,    4,    7,    5,    8,    8,
    5,    8,    8,    8,   10,    8,    1,    1,    1,    1,
    4,    4,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,
};
static const short yydefred[] = {                         0,
    3,    0,    0,    0,    0,    1,    2,    0,    0,    4,
    0,    0,    0,    0,    0,    0,    0,    0,    5,    6,
    0,    0,    8,    0,   10,    0,    0,    0,    0,    0,
    0,    0,   14,    0,   11,    0,    0,    0,    0,    0,
    0,    0,   15,    0,    0,   27,    0,   29,   30,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   12,    0,
    0,   33,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   16,    0,    0,    0,    0,    0,    0,   13,
    0,    0,    0,   37,    0,    0,    0,    0,    0,    0,
    0,    0,   34,    0,    0,   18,    0,    0,   21,    0,
    0,    0,   31,   32,    0,    0,    0,    0,    0,    0,
   17,    0,    0,    0,    0,    0,    0,    0,   19,   20,
   22,   23,    0,   24,   26,    0,   25,
};
static const short yydgoto[] = {                          2,
   52,   33,   34,   13,   14,   27,   44,    3,    6,    4,
   10,
};
static const short yysindex[] = {                      -251,
    0,    0, -237, -177, -226,    0,    0, -204, -204,    0,
   40,   -3,   48,   35,   45,   67, -141, -204,    0,    0,
   -1,   32,    0, -135,    0,  -64,    6,  -26,   93,   95,
   99,  100,    0, -110,    0, -102,  -37, -114,  -25,  -37,
  -37,  -98,    0, -101,   85,    0,   88,    0,    0,  -37,
  -37,   64,  -16,  106,  -36,  -31,   -9,  127,    0,  129,
 -241,    0,   -4,  -37,  -37,  -37,  -37,  -37,  -37,  -37,
  -37,  -37,    0, -187,  132, -139,  139,  -70,  -72,    0,
  -37,  108,  109,    0,  120,  120,  120,  120,  120,  120,
  162,  162,    0,  112,  113,    0,  115,  116,    0,  -64,
  -64,   68,    0,    0,  169,  170,  171,  172,  -83, -113,
    0,  155,  156,  157,  158,  -64,  159,  160,    0,    0,
    0,    0,  -78,    0,    0,  163,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   53,  164,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -41,    0,    0,    0,
    0,    0,    0,    1,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   19,   23,   27,   31,   36,   43,
    7,   14,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -15,   72,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  102,   28,   20,    0,    4,    0,    0,    0,    0,    0,
    0,
};
#define YYTABLESIZE 355
static const short yytable[] = {                         28,
   28,   28,   51,   28,   77,   72,   70,   50,   71,   78,
   72,   70,   15,   71,   51,   82,   83,   28,   28,   50,
   28,   23,    1,   64,   75,   65,   31,   31,   64,   31,
   65,   79,   72,   70,   37,   71,   84,   72,   70,    5,
   71,   28,   28,   28,   31,   28,   31,   35,   11,   35,
   64,   35,   65,   12,   36,   64,   36,   65,   36,   38,
   28,   43,   28,   39,   36,   35,   35,   40,   35,   94,
   95,   41,   36,   36,   74,   36,   42,   38,   38,   16,
   38,   39,   39,   43,   39,   40,   40,   17,   40,   41,
   41,   18,   41,   19,   42,   42,    9,   42,    7,    8,
    9,   43,   43,   20,   43,   72,   70,   21,   71,   72,
   70,    9,   71,   32,   32,   22,   32,   97,   98,  109,
  110,   24,   73,   64,   25,   65,  111,   64,   26,   65,
   35,   32,   38,   32,   39,  123,   43,   43,   40,   41,
   55,   56,   57,   53,   28,   29,   30,   28,   29,   30,
   43,   62,   63,   31,   45,   42,   31,   32,   58,  118,
   32,   72,   70,   59,   71,   85,   86,   87,   88,   89,
   90,   91,   92,   93,   28,   29,   30,   60,   61,   28,
   29,   30,  102,   31,  116,   80,  117,   32,   31,   81,
   96,  126,   32,   28,   29,   30,   76,   99,  100,  101,
  103,  104,   31,   72,  105,  106,   32,  107,  108,  112,
  113,  114,  115,  119,  120,  121,  122,  124,  125,   46,
   47,  127,    7,    0,   48,   49,    0,    0,    0,    0,
    0,   46,   54,    0,    0,    0,   48,   49,   28,   28,
   28,   28,    0,   66,   67,   68,   69,    0,   66,   67,
   68,   69,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   31,   31,   31,   31,    0,    0,
   66,   67,   68,   69,    0,   66,   67,   68,   69,    0,
   28,   28,   28,   28,    0,    0,   35,   35,   35,   35,
    0,    0,    0,   36,   36,   36,   36,    0,   38,   38,
   38,   38,   39,   39,   39,   39,   40,   40,   40,   40,
   41,   41,   41,   41,    0,   42,   42,   42,   42,    0,
    0,    0,   43,   43,   43,   43,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   66,   67,   68,   69,   66,   67,   68,
   69,   32,   32,   32,   32,
};
static const short yycheck[] = {                         41,
   42,   43,   40,   45,   41,   42,   43,   45,   45,   41,
   42,   43,    9,   45,   40,  257,  258,   59,   60,   45,
   62,   18,  274,   60,   41,   62,   42,   43,   60,   45,
   62,   41,   42,   43,   61,   45,   41,   42,   43,  277,
   45,   41,   42,   43,   60,   45,   62,   41,  275,   43,
   60,   45,   62,  258,   41,   60,   43,   62,   45,   41,
   60,   34,   62,   41,   91,   59,   60,   41,   62,  257,
  258,   41,   59,   60,   91,   62,   41,   59,   60,   40,
   62,   59,   60,   41,   62,   59,   60,   91,   62,   59,
   60,   44,   62,   59,   59,   60,   44,   62,  276,  277,
  278,   59,   60,   59,   62,   42,   43,   41,   45,   42,
   43,   59,   45,   42,   43,  257,   45,  257,  258,  100,
  101,  123,   59,   60,   93,   62,   59,   60,  264,   62,
  125,   60,   40,   62,   40,  116,  109,  110,   40,   40,
   39,   40,   41,  258,  258,  259,  260,  258,  259,  260,
  123,   50,   51,  267,  257,  266,  267,  271,  257,  273,
  271,   42,   43,  265,   45,   64,   65,   66,   67,   68,
   69,   70,   71,   72,  258,  259,  260,   93,   91,  258,
  259,  260,   81,  267,  268,   59,  270,  271,  267,   61,
   59,  270,  271,  258,  259,  260,   91,   59,  269,  272,
   93,   93,  267,   42,   93,   93,  271,   93,   93,   41,
   41,   41,   41,   59,   59,   59,   59,   59,   59,  257,
  258,   59,   59,   -1,  262,  263,   -1,   -1,   -1,   -1,
   -1,  257,  258,   -1,   -1,   -1,  262,  263,  280,  281,
  282,  283,   -1,  280,  281,  282,  283,   -1,  280,  281,
  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  280,  281,  282,  283,   -1,   -1,
  280,  281,  282,  283,   -1,  280,  281,  282,  283,   -1,
  280,  281,  282,  283,   -1,   -1,  280,  281,  282,  283,
   -1,   -1,   -1,  280,  281,  282,  283,   -1,  280,  281,
  282,  283,  280,  281,  282,  283,  280,  281,  282,  283,
  280,  281,  282,  283,   -1,  280,  281,  282,  283,   -1,
   -1,   -1,  280,  281,  282,  283,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  280,  281,  282,  283,  280,  281,  282,
  283,  280,  281,  282,  283,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 284
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",
"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",
0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"NUM","ID","READ","WRITE","EXIT","TR","FAL","BEG","EN",
"RET","IF","ELSE","THEN","ENDIF","WHILE","DO","ENDWHILE","DECL","MAIN",
"ENDDECL","INTEGER","BOOLEAN","IFX","GE","LE","EQ","NE","UMINUS",
};
static const char *yyrule[] = {
"$accept : pgm",
"pgm : GDefblock Mainblock",
"GDefblock : DECL GDefList ENDDECL",
"GDefList :",
"GDefList : GDefList GDecl",
"GDecl : INTEGER GIdList ';'",
"GDecl : BOOLEAN GIdList ';'",
"GIdList : GId",
"GIdList : GId ',' GIdList",
"GId : ID",
"GId : ID '[' NUM ']'",
"Mainblock : INTEGER MAIN '(' ')' '{' body '}'",
"body : BEG statements ret EN",
"ret : RET NUM ';'",
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
"expr : NUM",
"expr : ID",
"expr : TR",
"expr : FAL",
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
#line 127 "main.y"

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
#line 749 "y.tab.c"

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
#line 71 "main.y"
	{ exit(0); }
break;
case 2:
#line 73 "main.y"
	{}
break;
case 3:
#line 75 "main.y"
	{}
break;
case 4:
#line 76 "main.y"
	{}
break;
case 5:
#line 78 "main.y"
	{ create_list(integer, yystack.l_mark[-1].nodePtr); }
break;
case 6:
#line 79 "main.y"
	{ create_list(boolean, yystack.l_mark[-1].nodePtr); }
break;
case 7:
#line 81 "main.y"
	{ yyval.nodePtr = yystack.l_mark[0].nodePtr; }
break;
case 8:
#line 82 "main.y"
	{ yyval.nodePtr = combine(',', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 9:
#line 84 "main.y"
	{ yyval.nodePtr = makename(yystack.l_mark[0].name);  }
break;
case 10:
#line 85 "main.y"
	{ yyval.nodePtr = makearray(yystack.l_mark[-3].name, makenode(yystack.l_mark[-1].num)); }
break;
case 11:
#line 87 "main.y"
	{ eval(yystack.l_mark[-1].nodePtr); }
break;
case 12:
#line 89 "main.y"
	{ yyval.nodePtr = combine(BEG, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[-1].nodePtr); }
break;
case 13:
#line 91 "main.y"
	{ yyval.nodePtr = combine(RET, 1, makenode(yystack.l_mark[-1].num)); }
break;
case 14:
#line 93 "main.y"
	{ yyval.nodePtr = yystack.l_mark[0].nodePtr; }
break;
case 15:
#line 94 "main.y"
	{ yyval.nodePtr = combine(';', 2, yystack.l_mark[-1].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 16:
#line 96 "main.y"
	{ yyval.nodePtr = combine('=', 2, makename(yystack.l_mark[-3].name), yystack.l_mark[-1].nodePtr); }
break;
case 17:
#line 97 "main.y"
	{ yyval.nodePtr = combine('=', 3, makename(yystack.l_mark[-6].name), makenode(yystack.l_mark[-4].num), yystack.l_mark[-1].nodePtr); }
break;
case 18:
#line 98 "main.y"
	{ yyval.nodePtr = combine(READ, 1, makename(yystack.l_mark[-2].name)); }
break;
case 19:
#line 99 "main.y"
	{ yyval.nodePtr = combine(READ, 1, makearray(yystack.l_mark[-5].name, makenode(yystack.l_mark[-3].num))); }
break;
case 20:
#line 100 "main.y"
	{ yyval.nodePtr = combine(READ, 1, makearray(yystack.l_mark[-5].name, makename(yystack.l_mark[-3].name))); }
break;
case 21:
#line 101 "main.y"
	{ yyval.nodePtr = combine(WRITE, 1, yystack.l_mark[-2].nodePtr); }
break;
case 22:
#line 102 "main.y"
	{ yyval.nodePtr = combine(WRITE, 1, makearray(yystack.l_mark[-5].name, makenode(yystack.l_mark[-3].num))); }
break;
case 23:
#line 103 "main.y"
	{ yyval.nodePtr = combine(WRITE, 1, makearray(yystack.l_mark[-5].name, makename(yystack.l_mark[-3].name))); }
break;
case 24:
#line 104 "main.y"
	{ yyval.nodePtr = combine(IF, 2, yystack.l_mark[-5].nodePtr, yystack.l_mark[-2].nodePtr); }
break;
case 25:
#line 105 "main.y"
	{ yyval.nodePtr = combine(IF, 3, yystack.l_mark[-7].nodePtr, yystack.l_mark[-4].nodePtr, yystack.l_mark[-2].nodePtr); }
break;
case 26:
#line 106 "main.y"
	{ yyval.nodePtr = combine(WHILE, 2, yystack.l_mark[-5].nodePtr, yystack.l_mark[-2].nodePtr); }
break;
case 27:
#line 108 "main.y"
	{ yyval.nodePtr = makenode(yystack.l_mark[0].num); }
break;
case 28:
#line 109 "main.y"
	{ yyval.nodePtr = makename(yystack.l_mark[0].name); }
break;
case 29:
#line 110 "main.y"
	{ yyval.nodePtr = makebool(1); }
break;
case 30:
#line 111 "main.y"
	{ yyval.nodePtr = makebool(0); }
break;
case 31:
#line 112 "main.y"
	{ yyval.nodePtr = makearray(yystack.l_mark[-3].name, makenode(yystack.l_mark[-1].num)); }
break;
case 32:
#line 113 "main.y"
	{ yyval.nodePtr = makearray(yystack.l_mark[-3].name, makename(yystack.l_mark[-1].name)); }
break;
case 33:
#line 114 "main.y"
	{ yyval.nodePtr = combine(UMINUS, 1, yystack.l_mark[0].nodePtr); }
break;
case 34:
#line 115 "main.y"
	{ yyval.nodePtr = combine('*', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 35:
#line 116 "main.y"
	{ yyval.nodePtr = combine('+', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 36:
#line 117 "main.y"
	{ yyval.nodePtr = combine('-', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 37:
#line 118 "main.y"
	{ yyval.nodePtr = yystack.l_mark[-1].nodePtr; }
break;
case 38:
#line 119 "main.y"
	{ yyval.nodePtr = combine('<', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 39:
#line 120 "main.y"
	{ yyval.nodePtr = combine('>', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 40:
#line 121 "main.y"
	{ yyval.nodePtr = combine(GE, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 41:
#line 122 "main.y"
	{ yyval.nodePtr = combine(LE, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 42:
#line 123 "main.y"
	{ yyval.nodePtr = combine(EQ, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 43:
#line 124 "main.y"
	{ yyval.nodePtr = combine(NE, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
#line 1127 "y.tab.c"
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
