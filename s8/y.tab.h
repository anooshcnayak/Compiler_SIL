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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int num; char *name; struct node* nodePtr; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
