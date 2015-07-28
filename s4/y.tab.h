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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int num; int index; struct node* nodePtr; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
