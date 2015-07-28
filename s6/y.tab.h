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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int num; char *name; struct node* nodePtr; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
