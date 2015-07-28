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
	int v[26];
	
	/* Function Prototypes*/

	void yyerror(char *);
	
	struct node* makenode (char ch, int x);
	struct node* combine(int, int, ...);
	void assign_val(int, int);
	void read_val(int );
	void write_val(int);
	int eval(struct node*);
	void freenode(struct node*);
#line 27 "main.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int num; int index; struct node* nodePtr; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 53 "y.tab.c"

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
#define THEN 263
#define ENDIF 264
#define WHILE 265
#define DO 266
#define ENDWHILE 267
#define IFX 268
#define ELSE 269
#define GE 270
#define LE 271
#define EQ 272
#define NE 273
#define UMINUS 274
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    2,    2,    2,    2,    2,    2,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,
};
static const short yylen[] = {                            2,
    1,    2,    3,    4,    5,    5,    8,   10,    8,    1,
    1,    2,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,
};
static const short yydefred[] = {                         0,
   10,   11,    0,    0,    0,    0,    0,    0,    0,    0,
    1,    0,    0,    0,    0,   12,    0,    0,    2,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   16,    3,    0,    0,    0,    0,    0,
    0,    0,    0,   13,    0,    0,    0,    0,    0,    4,
    5,    6,    0,    0,    0,    0,    0,    0,    0,    7,
    0,    9,    0,    8,
};
static const short yydgoto[] = {                          9,
   10,   11,
};
static const short yysindex[] = {                        97,
    0,    0,  -37,  -32,  -27,  -25,   67,   67,   88,   48,
    0,   67,   67,   67,   67,    0,  -31,  -43,    0,   67,
   67,   67,   67,   67,   67,   67,   67,   67,   67,   -9,
   -4,    1,    7,    0,    0,   71,   71,   71,   71,   71,
   71,  -20,  -20,    0,   61,  -42,  -19, -236, -238,    0,
    0,    0,   97,   97,  -10,  -39,  -14,   97,  -12,    0,
   79,    0,   -2,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   13,   18,   23,   27,   35,
   40,  -41,  -36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const short yygindex[] = {                        12,
  133,   83,
};
#define YYTABLESIZE 362
static const short yytable[] = {                         14,
    8,   14,   12,   14,   15,    7,   15,   13,   15,   34,
   28,   26,   14,   27,   15,   35,   51,   14,   14,   14,
   14,   28,   15,   15,   15,   15,   53,   54,   20,    8,
   21,   46,   28,   26,    7,   27,   47,   28,   26,   52,
   27,   48,   28,   26,   60,   27,   62,   49,   28,   26,
   20,   27,   21,   17,    0,   20,   64,   21,   18,    0,
   20,    0,   21,   19,   55,   56,   20,   20,   21,   61,
    0,   17,   17,   17,   17,   21,   18,   18,   18,   18,
   22,   19,   19,   19,   19,   20,   20,   20,   20,   28,
   26,   19,   27,   21,   21,   21,   21,    0,   22,   22,
   22,   22,   28,   26,    0,   27,    8,   20,   29,   21,
    0,    7,   28,   26,    0,   27,    0,    0,    8,   50,
   20,    0,   21,    7,    0,    0,    0,    8,    0,    0,
    0,    0,    7,    0,    0,    0,    8,   19,   19,   16,
   17,    7,    0,   19,   30,   31,   32,   33,    0,    0,
    0,    0,   36,   37,   38,   39,   40,   41,   42,   43,
   44,   45,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    2,    3,
    4,   18,    5,    0,    0,    6,    0,   59,   14,   14,
   14,   14,    0,   15,   15,   15,   15,    0,   22,   23,
   24,   25,    0,    0,    0,    0,    1,    2,    3,    4,
   18,    5,    0,   57,    6,    0,    0,    0,   58,    0,
   22,   23,   24,   25,    0,   22,   23,   24,   25,    0,
   22,   23,   24,   25,    0,    0,   22,   23,   24,   25,
    0,    0,   17,   17,   17,   17,    0,   18,   18,   18,
   18,    0,   19,   19,   19,   19,   20,   20,   20,   20,
    0,    0,    0,    0,   21,   21,   21,   21,    0,   22,
   22,   22,   22,    0,    0,    0,    0,   22,   23,   24,
   25,    0,    0,    1,    2,    0,    0,    0,    0,    0,
   22,   23,   24,   25,    0,    1,    2,    3,    4,   18,
    5,    0,   63,    6,    1,    2,    3,    4,   18,    5,
    0,    0,    6,    1,    2,    3,    4,    0,    5,    0,
    0,    6,
};
static const short yycheck[] = {                         41,
   40,   43,   40,   45,   41,   45,   43,   40,   45,   41,
   42,   43,   40,   45,   40,   59,   59,   59,   60,   61,
   62,   42,   59,   60,   61,   62,  263,  266,   60,   40,
   62,   41,   42,   43,   45,   45,   41,   42,   43,   59,
   45,   41,   42,   43,   59,   45,   59,   41,   42,   43,
   60,   45,   62,   41,   -1,   60,   59,   62,   41,   -1,
   60,   -1,   62,   41,   53,   54,   60,   41,   62,   58,
   -1,   59,   60,   61,   62,   41,   59,   60,   61,   62,
   41,   59,   60,   61,   62,   59,   60,   61,   62,   42,
   43,    9,   45,   59,   60,   61,   62,   -1,   59,   60,
   61,   62,   42,   43,   -1,   45,   40,   60,   61,   62,
   -1,   45,   42,   43,   -1,   45,   -1,   -1,   40,   59,
   60,   -1,   62,   45,   -1,   -1,   -1,   40,   -1,   -1,
   -1,   -1,   45,   -1,   -1,   -1,   40,   55,   56,    7,
    8,   45,   -1,   61,   12,   13,   14,   15,   -1,   -1,
   -1,   -1,   20,   21,   22,   23,   24,   25,   26,   27,
   28,   29,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,   -1,   -1,  265,   -1,  267,  270,  271,
  272,  273,   -1,  270,  271,  272,  273,   -1,  270,  271,
  272,  273,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,   -1,  264,  265,   -1,   -1,   -1,  269,   -1,
  270,  271,  272,  273,   -1,  270,  271,  272,  273,   -1,
  270,  271,  272,  273,   -1,   -1,  270,  271,  272,  273,
   -1,   -1,  270,  271,  272,  273,   -1,  270,  271,  272,
  273,   -1,  270,  271,  272,  273,  270,  271,  272,  273,
   -1,   -1,   -1,   -1,  270,  271,  272,  273,   -1,  270,
  271,  272,  273,   -1,   -1,   -1,   -1,  270,  271,  272,
  273,   -1,   -1,  257,  258,   -1,   -1,   -1,   -1,   -1,
  270,  271,  272,  273,   -1,  257,  258,  259,  260,  261,
  262,   -1,  264,  265,  257,  258,  259,  260,  261,  262,
   -1,   -1,  265,  257,  258,  259,  260,   -1,  262,   -1,
   -1,  265,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 274
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",
"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"NUM","ID","READ","WRITE","EXIT","IF","THEN","ENDIF","WHILE","DO",
"ENDWHILE","IFX","ELSE","GE","LE","EQ","NE","UMINUS",
};
static const char *yyrule[] = {
"$accept : statements",
"statements : statement",
"statements : statements statement",
"statements : statements EXIT ';'",
"statement : expr '=' expr ';'",
"statement : READ '(' expr ')' ';'",
"statement : WRITE '(' expr ')' ';'",
"statement : IF '(' expr ')' THEN statements ENDIF ';'",
"statement : IF '(' expr ')' THEN statements ELSE statements ENDIF ';'",
"statement : WHILE '(' expr ')' DO statements ENDWHILE ';'",
"expr : NUM",
"expr : ID",
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
#line 82 "main.y"

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


#line 418 "y.tab.c"

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
#line 50 "main.y"
	{ yyval.nodePtr = yystack.l_mark[0].nodePtr; }
break;
case 2:
#line 51 "main.y"
	{ yyval.nodePtr = combine(';', 2, yystack.l_mark[-1].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 3:
#line 52 "main.y"
	{ yyval.nodePtr = yystack.l_mark[-2].nodePtr; eval(yystack.l_mark[-2].nodePtr); exit(0);  }
break;
case 4:
#line 54 "main.y"
	{ yyval.nodePtr = combine('=', 2, yystack.l_mark[-3].nodePtr, yystack.l_mark[-1].nodePtr); }
break;
case 5:
#line 56 "main.y"
	{ yyval.nodePtr = combine(READ, 1, yystack.l_mark[-2].nodePtr); }
break;
case 6:
#line 58 "main.y"
	{ yyval.nodePtr = combine(WRITE, 1, yystack.l_mark[-2].nodePtr); }
break;
case 7:
#line 60 "main.y"
	{ yyval.nodePtr = combine(IF, 2, yystack.l_mark[-5].nodePtr, yystack.l_mark[-2].nodePtr); }
break;
case 8:
#line 62 "main.y"
	{ yyval.nodePtr = combine(IF, 3, yystack.l_mark[-7].nodePtr, yystack.l_mark[-4].nodePtr, yystack.l_mark[-2].nodePtr); }
break;
case 9:
#line 64 "main.y"
	{ yyval.nodePtr = combine(WHILE, 2, yystack.l_mark[-5].nodePtr, yystack.l_mark[-2].nodePtr); }
break;
case 10:
#line 67 "main.y"
	{ yyval.nodePtr = makenode('n', yystack.l_mark[0].num); }
break;
case 11:
#line 68 "main.y"
	{ yyval.nodePtr = makenode('c', yystack.l_mark[0].index); }
break;
case 12:
#line 69 "main.y"
	{ yyval.nodePtr = combine(UMINUS, 1, yystack.l_mark[0].nodePtr); }
break;
case 13:
#line 70 "main.y"
	{ yyval.nodePtr = combine('*', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 14:
#line 71 "main.y"
	{ yyval.nodePtr = combine('+', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 15:
#line 72 "main.y"
	{ yyval.nodePtr = combine('-', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 16:
#line 73 "main.y"
	{ yyval.nodePtr = yystack.l_mark[-1].nodePtr; }
break;
case 17:
#line 74 "main.y"
	{ yyval.nodePtr = combine('<', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 18:
#line 75 "main.y"
	{ yyval.nodePtr = combine('>', 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr);}
break;
case 19:
#line 76 "main.y"
	{ yyval.nodePtr = combine(GE, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 20:
#line 77 "main.y"
	{ yyval.nodePtr = combine(LE, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 21:
#line 78 "main.y"
	{ yyval.nodePtr = combine(EQ, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
case 22:
#line 79 "main.y"
	{ yyval.nodePtr = combine(NE, 2, yystack.l_mark[-2].nodePtr, yystack.l_mark[0].nodePtr); }
break;
#line 712 "y.tab.c"
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
