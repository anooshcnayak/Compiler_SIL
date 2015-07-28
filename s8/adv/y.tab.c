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
	extern int linecount;

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
	void error1();
	void error2(char *n);
	void error3(char *n);
	void error4(char *n);
#line 41 "main.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int num; char *name; struct node* nodePtr; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 67 "y.tab.c"

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
#define AN 267
#define ORR 268
#define IF 269
#define ELSE 270
#define THEN 271
#define ENDIF 272
#define WHILE 273
#define DO 274
#define ENDWHILE 275
#define DECL 276
#define MAIN 277
#define ENDDECL 278
#define INTEGER 279
#define BOOLEAN 280
#define IFX 281
#define GE 282
#define LE 283
#define EQ 284
#define NE 285
#define UMINUS 286
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    9,   11,   11,   12,   12,    5,    5,    4,    4,
   10,    6,    7,    3,    3,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,
};
static const short yylen[] = {                            2,
    2,    3,    0,    2,    3,    3,    1,    3,    1,    4,
    7,    4,    3,    1,    2,    4,    4,    7,    7,    5,
    8,    5,    8,   10,    8,    1,    1,    4,    2,    3,
    3,    3,    3,    1,    1,    3,    3,    3,    3,    3,
    3,    3,    3,
};
static const short yydefred[] = {                         0,
    3,    0,    0,    0,    0,    1,    2,    0,    0,    4,
    0,    0,    0,    0,    0,    0,    0,    0,    5,    6,
    0,    0,    8,    0,   10,    0,    0,    0,    0,    0,
    0,    0,   14,    0,   11,    0,    0,    0,    0,    0,
    0,    0,   15,    0,   26,    0,    0,    0,    0,   34,
   35,    0,    0,    0,    0,    0,    0,    0,    0,   12,
    0,   29,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   16,    0,    0,   17,    0,    0,    0,
    0,    0,   13,    0,   33,    0,    0,   30,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   20,   22,
    0,    0,   28,    0,    0,    0,    0,    0,   18,   19,
    0,    0,    0,    0,   21,    0,   23,   25,    0,   24,
};
static const short yydgoto[] = {                          2,
   56,   33,   34,   13,   14,   27,   44,   53,    3,    6,
    4,   10,
};
static const short yysindex[] = {                      -249,
    0,    0, -244,  -95, -232,    0,    0, -209, -209,    0,
   33,  -32,   35,   10,   12,   46, -181, -209,    0,    0,
  -12,   -8,    0, -175,    0,  -83,  -28,  -24,   59,   64,
   78,   92,    0, -102,    0,  -34,    2, -123,  -34,    2,
    2, -112,    0, -128,    0,   56,  -34,  -34,   32,    0,
    0,   -9,  -46,  -26,   86,    1,  -38,  -33,   89,    0,
  -34,    0,  137,  -34,  -34,  -34,  104,  -34,  -34,  -34,
  -34,  -34,  -34,    0,    2,    2,    0,  -34,  107,  109,
  -90,  -87,    0,   53,    0,  127,  127,    0,    2,   81,
   81,   81,   81,   81,   81, -105, -105,   58,    0,    0,
  -83,  -83,    0,   -4,   -5,  131, -120, -139,    0,    0,
  129,  -83,  130,  132,    0,  -99,    0,    0,  133,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -27,  134,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -41,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -36,  -31,    0,    0,  -11,
   23,   25,   27,   29,   31,  -19,   19,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
   44,  -14,   42,    0,    7,    0,    0,   66,    0,    0,
    0,    0,
};
#define YYTABLESIZE 299
static const short yytable[] = {                         27,
   27,   27,   81,   27,   31,   48,   31,   82,   31,   32,
   47,   32,   77,   32,   79,   15,    9,   27,   27,   43,
   27,   42,   31,   31,   23,   31,    1,   32,   32,   36,
   32,    9,   66,   64,    5,   65,   37,   66,   64,   42,
   65,   48,   66,   64,   11,   65,   47,   36,   12,   74,
   68,   27,   69,  110,  109,   68,   31,   69,   17,   43,
   68,   32,   69,   37,   78,   38,   36,   39,   19,   40,
   20,   41,   16,   66,   64,   22,   65,   43,   18,   49,
   52,   37,   55,   38,   25,   39,   21,   40,   26,   41,
   62,   63,   43,   43,   66,   64,   35,   65,   38,   66,
   64,   43,   65,   39,   84,   57,   58,   86,   87,   88,
   24,   90,   91,   92,   93,   94,   95,   40,   28,   29,
   30,   98,   66,   64,   67,   65,   80,   66,   64,   31,
   65,   41,  104,   32,   54,  114,   60,   28,   29,   30,
   96,   97,  107,  108,   59,  103,   61,   83,   31,  112,
  106,  113,   32,  116,  105,   28,   29,   30,   28,   29,
   30,   75,   76,   42,   89,   99,   31,  100,   66,   31,
   32,  111,  119,   32,   28,   29,   30,   85,   66,   64,
  101,   65,    7,    8,    9,   31,  102,  115,  117,   32,
  118,  120,    7,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   75,   76,   45,   46,    0,   27,   27,    0,   75,   76,
   31,   31,    0,   75,   76,   32,   32,    0,    0,    0,
   27,   27,   27,   27,    0,   31,   31,   31,   31,    0,
   32,   32,   32,   32,    0,   36,   36,    0,   45,   46,
    0,   75,   76,   50,   51,    0,    0,    0,    0,    0,
    0,    0,   70,   71,   72,   73,    0,   70,   71,   72,
   73,    0,   70,   71,   72,   73,    0,    0,    0,   37,
   37,   38,   38,   39,   39,   40,   40,   41,   41,
};
static const short yycheck[] = {                         41,
   42,   43,   41,   45,   41,   40,   43,   41,   45,   41,
   45,   43,   59,   45,   41,    9,   44,   59,   60,   34,
   62,   41,   59,   60,   18,   62,  276,   59,   60,   41,
   62,   59,   42,   43,  279,   45,   61,   42,   43,   59,
   45,   40,   42,   43,  277,   45,   45,   59,  258,   59,
   60,   93,   62,   59,   59,   60,   93,   62,   91,   41,
   60,   93,   62,   41,   91,   41,   91,   41,   59,   41,
   59,   41,   40,   42,   43,  257,   45,   59,   44,   36,
   37,   59,   39,   59,   93,   59,   41,   59,  264,   59,
   47,   48,  107,  108,   42,   43,  125,   45,   40,   42,
   43,  116,   45,   40,   61,   40,   41,   64,   65,   66,
  123,   68,   69,   70,   71,   72,   73,   40,  258,  259,
  260,   78,   42,   43,   93,   45,   41,   42,   43,  269,
   45,   40,   89,  273,  258,  275,  265,  258,  259,  260,
   75,   76,  101,  102,  257,   93,   91,   59,  269,  270,
   93,  272,  273,  112,   89,  258,  259,  260,  258,  259,
  260,  267,  268,  266,   61,   59,  269,   59,   42,  269,
  273,   41,  272,  273,  258,  259,  260,   41,   42,   43,
  271,   45,  278,  279,  280,  269,  274,   59,   59,  273,
   59,   59,   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  267,  268,  257,  258,   -1,  267,  268,   -1,  267,  268,
  267,  268,   -1,  267,  268,  267,  268,   -1,   -1,   -1,
  282,  283,  284,  285,   -1,  282,  283,  284,  285,   -1,
  282,  283,  284,  285,   -1,  267,  268,   -1,  257,  258,
   -1,  267,  268,  262,  263,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  282,  283,  284,  285,   -1,  282,  283,  284,
  285,   -1,  282,  283,  284,  285,   -1,   -1,   -1,  267,
  268,  267,  268,  267,  268,  267,  268,  267,  268,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 286
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
"RET","AN","ORR","IF","ELSE","THEN","ENDIF","WHILE","DO","ENDWHILE","DECL",
"MAIN","ENDDECL","INTEGER","BOOLEAN","IFX","GE","LE","EQ","NE","UMINUS",
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
"statement : ID '=' relexpr ';'",
"statement : ID '[' expr ']' '=' expr ';'",
"statement : ID '[' expr ']' '=' relexpr ';'",
"statement : READ '(' ID ')' ';'",
"statement : READ '(' ID '[' expr ']' ')' ';'",
"statement : WRITE '(' expr ')' ';'",
"statement : IF '(' relexpr ')' THEN statements ENDIF ';'",
"statement : IF '(' relexpr ')' THEN statements ELSE statements ENDIF ';'",
"statement : WHILE '(' relexpr ')' DO statements ENDWHILE ';'",
"expr : NUM",
"expr : ID",
"expr : ID '[' expr ']'",
"expr : '-' expr",
"expr : expr '*' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : '(' expr ')'",
"relexpr : TR",
"relexpr : FAL",
"relexpr : expr '<' expr",
"relexpr : expr '>' expr",
"relexpr : expr GE expr",
"relexpr : expr LE expr",
"relexpr : expr EQ expr",
"relexpr : expr NE expr",
"relexpr : relexpr AN relexpr",
"relexpr : relexpr ORR relexpr",

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
#line 130 "main.y"

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

void assign_val(char *n, int val) {
	
	dummy = Glookup(n);
	
	if(dummy != NULL) {
		*(dummy->ptr) = val;
		return;
	}
	else error4(dummy->name);
}

void assign_val2(struct node* p, int val) {
	
	struct Gsymbol *ldummy = Glookup(p->childs[0]->name);
	int dum;

	if(dummy != NULL) {

		dum = eval(p->childs[1]);

		if(dum < ldummy->size) {
			
			ldummy->ptr[dum] = val;
			//printf("assigning now: %s[%d] = %d", dummy->name, dum.val, res.val); 
			return;
		}
		
		error3(ldummy->name);
	}
	else error4(p->childs[0]->name);

}


void read_val(char *n) {
	
	dummy = Glookup(n);
	int temp;
	
	if(dummy != NULL) {
	
		scanf("%d", &temp);
		*(dummy->ptr) = temp;
	}
	else error4(n);
}

void read_val2(struct node* p) {
	
	int x, ind;
	dummy = Glookup(p->childs[0]->name);
	
	if(dummy != NULL) {

		ind = eval(p->childs[1]);

		scanf("%d", &x);
		dummy->ptr[ind] = x; 
		return;
	}
	else error4(p->childs[0]->name);

}


void write_val(int val) {

	printf("%d\n", val);
}

int array_eval(char *n, int val) {

	dummy = Glookup(n);

	if(dummy != NULL)
			return dummy->ptr[val];
	else error4(n);
}

// struct retnode make_ret(int val, dataType t) {

// 	struct retnode res;
// 	res.val = val;
// 	res.type = t;

// 	return res;
// }

void error1() {

	printf("Type mismatch. Line: %d\n", linecount);
	exit(1);
}

void error2(char *n) {

	printf("%s Array indexing not an INT. Line: %d\n", n, linecount);
	exit(1);
}

void error3(char *n) {
	printf("%s Value out of bound: Array. Line: %d\n", n, linecount);
	exit(1);
}

void error4(char *n) {
	printf("%s not Declared. Line: %d\n", n, linecount);
	exit(1);
}

int array_check(struct node* p) {
	
	struct Gsymbol *ldummy = Glookup(p->childs[0]->name);

	if(ldummy != NULL) {

		check(p->childs[1], 1);

		if(p->childs[1]->value < ldummy->size) {
			return ((ldummy->type == integer) ? 1 : 0);
		}
		else error3(ldummy->name);
	}
	else error4(p->childs[0]->name);
}

int check(struct node* p, int t) {

	if(p == NULL) return integer;

	switch(p->type) {

		case constant: 		return 1;
		case identifier:	dummy = Glookup(p->name);
							if(dummy != NULL) return ((dummy->type == integer) ? 1 : 0); else error4(p->name);
		case array		:   return array_check(p);
		case operation:		

			switch(p->oper) {
				case '+': 	if (check(p->childs[0], t) == t && check(p->childs[1], t) == t) return t; else {printf("here\n"); error1(); }
				case '-': 	if (check(p->childs[0], t) == t && check(p->childs[1], t) == t) return t; else error1();			
				case '*': 	if (check(p->childs[0], t) == t && check(p->childs[1], t) == t) return t; else error1();
				case '<': 	if (check(p->childs[0], 1) == 1 && check(p->childs[1], 1) == 1) return 1; else error1();
				case '>': 	if (check(p->childs[0], 1) == 1 && check(p->childs[1], 1) == 1) return 1; else error1();
				case GE: 	if (check(p->childs[0], 1) == 1 && check(p->childs[1], 1) == 1) return 1; else error1();
				case LE: 	if (check(p->childs[0], 1) == 1 && check(p->childs[1], 1) == 1) return 1; else error1();
				case EQ: 	if (check(p->childs[0], 1) == 1 && check(p->childs[1], 1) == 1) return 1; else error1();
				case NE: 	if (check(p->childs[0], 1) == 1 && check(p->childs[1], 1) == 1) return 1; else error1();
				case AN: 	if (check(p->childs[0], t) == 0 && check(p->childs[1], t) == 0) return 0; else error1();
				case ORR: 	if (check(p->childs[0], t) == 0 && check(p->childs[1], t) == 0) return 0; else error1();
			}
	}
}

// int check(struct node* l, struct node *r) {

// 	if(eval(l).type == integer && eval(r).type == integer)
// 		return 1;
// 	else
// 		return 0;
// }


int eval(struct node *p) {
	
	if(p == NULL) return 0;

	switch(p->type) {

		case constant	: 	return p->value;
		case identifier :	dummy = Glookup(p->name);
							if(dummy != NULL) return (*(dummy->ptr)); else error4(p->name);
		case boole 		:	return p->value;
		case array		:   return array_eval(p->childs[0]->name, eval(p->childs[1]));
		case operation:		

			switch(p->oper) {
				case BEG:	eval(p->childs[0]); eval(p->childs[1]); return 0;
				case RET: 	eval(p->childs[0]); return 0;
				case ';': 	eval(p->childs[0]); eval(p->childs[1]); return 0;
				case IF :	if(eval(p->childs[0])) eval(p->childs[1]); else if(p->ops > 2) eval(p->childs[2]); return 0;
				case WHILE: while(eval(p->childs[0])) { eval(p->childs[1]); } return 0;
				case '+': 	return eval(p->childs[0])+eval(p->childs[1]);
				case '-': 	return eval(p->childs[0])-eval(p->childs[1]);
				case '*': 	return eval(p->childs[0])*eval(p->childs[1]);
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
				case '<': 	return eval(p->childs[0]) < eval(p->childs[1]);
				case '>': 	return eval(p->childs[0]) > eval(p->childs[1]);
				case GE: 	return eval(p->childs[0]) >= eval(p->childs[1]);
				case LE: 	return eval(p->childs[0]) <= eval(p->childs[1]);
				case EQ: 	return eval(p->childs[0]) == eval(p->childs[1]);
				case NE: 	return eval(p->childs[0]) != eval(p->childs[1]);
				case AN: 	return eval(p->childs[0]) && eval(p->childs[1]);					
				case ORR: 	return eval(p->childs[0]) || eval(p->childs[1]);						
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
#line 731 "y.tab.c"

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
#line 72 "main.y"
	{ exit(0); }
break;
case 2:
#line 74 "main.y"
	{}
break;
case 3:
#line 76 "main.y"
	{}
break;
case 4:
#line 77 "main.y"
	{}
break;
case 5:
#line 79 "main.y"
	{ create_list(integer, yystack.l_mark[-1].nodePtr); }
break;
case 6:
#line 80 "main.y"
	{ create_list(boolean, yystack.l_mark[-1].nodePtr); }
break;
case 7:
#line 82 "main.y"
	{ yyval.nodePtr = yystack.l_mark[0].nodePtr; }
break;
case 8:
#line 83 "main.y"
	{ yyval.nodePtr = combine(',', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 9:
#line 85 "main.y"
	{ yyval.nodePtr = makename(yystack.l_mark[0].name);  }
break;
case 10:
#line 86 "main.y"
	{ yyval.nodePtr = makearray(yystack.l_mark[-3].name, makenode(yystack.l_mark[-1].num)); }
break;
case 11:
#line 88 "main.y"
	{ eval(yystack.l_mark[-1].nodePtr); }
break;
case 12:
#line 90 "main.y"
	{ yyval.nodePtr = combine(BEG, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[-1].nodePtr); }
break;
case 13:
#line 92 "main.y"
	{ yyval.nodePtr = combine(RET, 1, makenode(yystack.l_mark[-1].num)); }
break;
case 14:
#line 94 "main.y"
	{ yyval.nodePtr = yystack.l_mark[0].nodePtr; }
break;
case 15:
#line 95 "main.y"
	{ yyval.nodePtr = combine(';', 2, yystack.l_mark[-1].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 16:
#line 97 "main.y"
	{ yyval.nodePtr = combine('=', 2, makename(yystack.l_mark[-3].name), yystack.l_mark[-1].nodePtr); check(yystack.l_mark[-1].nodePtr, check(makename(yystack.l_mark[-3].name), 1)); }
break;
case 17:
#line 98 "main.y"
	{ yyval.nodePtr = combine('=', 2, makename(yystack.l_mark[-3].name), yystack.l_mark[-1].nodePtr); check(yystack.l_mark[-1].nodePtr, check(makename(yystack.l_mark[-3].name), 1)); }
break;
case 18:
#line 99 "main.y"
	{ yyval.nodePtr = combine('=', 2, makearray(yystack.l_mark[-6].name, yystack.l_mark[-4].nodePtr), yystack.l_mark[-1].nodePtr); check(yystack.l_mark[-1].nodePtr, array_check(makearray(yystack.l_mark[-6].name, yystack.l_mark[-4].nodePtr))); }
break;
case 19:
#line 100 "main.y"
	{ yyval.nodePtr = combine('=', 2, makearray(yystack.l_mark[-6].name, yystack.l_mark[-4].nodePtr), yystack.l_mark[-1].nodePtr); check(yystack.l_mark[-1].nodePtr, array_check(makearray(yystack.l_mark[-6].name, yystack.l_mark[-4].nodePtr))); }
break;
case 20:
#line 101 "main.y"
	{ yyval.nodePtr = combine(READ, 1, makename(yystack.l_mark[-2].name)); check(makename(yystack.l_mark[-2].name), 1); }
break;
case 21:
#line 102 "main.y"
	{ yyval.nodePtr = combine(READ, 1, makearray(yystack.l_mark[-5].name, yystack.l_mark[-3].nodePtr)); array_check(makearray(yystack.l_mark[-5].name, yystack.l_mark[-3].nodePtr)); }
break;
case 22:
#line 103 "main.y"
	{ yyval.nodePtr = combine(WRITE, 1, yystack.l_mark[-2].nodePtr); check(yystack.l_mark[-2].nodePtr, 1); }
break;
case 23:
#line 104 "main.y"
	{ yyval.nodePtr = combine(IF, 2, yystack.l_mark[-5].nodePtr, yystack.l_mark[-2].nodePtr); check(yystack.l_mark[-5].nodePtr, 0);  }
break;
case 24:
#line 105 "main.y"
	{ yyval.nodePtr = combine(IF, 3, yystack.l_mark[-7].nodePtr, yystack.l_mark[-4].nodePtr, yystack.l_mark[-2].nodePtr); check(yystack.l_mark[-7].nodePtr, 0); }
break;
case 25:
#line 106 "main.y"
	{ yyval.nodePtr = combine(WHILE, 2, yystack.l_mark[-5].nodePtr, yystack.l_mark[-2].nodePtr); check(yystack.l_mark[-5].nodePtr, 0); }
break;
case 26:
#line 108 "main.y"
	{ yyval.nodePtr = makenode(yystack.l_mark[0].num); }
break;
case 27:
#line 109 "main.y"
	{ yyval.nodePtr = makename(yystack.l_mark[0].name); }
break;
case 28:
#line 110 "main.y"
	{ yyval.nodePtr = makearray(yystack.l_mark[-3].name, yystack.l_mark[-1].nodePtr); }
break;
case 29:
#line 111 "main.y"
	{ yyval.nodePtr = combine(UMINUS, 1, yystack.l_mark[0].nodePtr); }
break;
case 30:
#line 112 "main.y"
	{ yyval.nodePtr = combine('*', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 31:
#line 113 "main.y"
	{ yyval.nodePtr = combine('+', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 32:
#line 114 "main.y"
	{ yyval.nodePtr = combine('-', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 33:
#line 115 "main.y"
	{ yyval.nodePtr = yystack.l_mark[-1].nodePtr; }
break;
case 34:
#line 117 "main.y"
	{ yyval.nodePtr = makebool(1); }
break;
case 35:
#line 118 "main.y"
	{ yyval.nodePtr = makebool(0); }
break;
case 36:
#line 119 "main.y"
	{ yyval.nodePtr = combine('<', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 37:
#line 120 "main.y"
	{ yyval.nodePtr = combine('>', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 38:
#line 121 "main.y"
	{ yyval.nodePtr = combine(GE, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 39:
#line 122 "main.y"
	{ yyval.nodePtr = combine(LE, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 40:
#line 123 "main.y"
	{ yyval.nodePtr = combine(EQ, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 41:
#line 124 "main.y"
	{ yyval.nodePtr = combine(NE, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 42:
#line 125 "main.y"
	{ yyval.nodePtr = combine(AN, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 43:
#line 126 "main.y"
	{ yyval.nodePtr = combine(ORR, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
#line 1109 "y.tab.c"
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
