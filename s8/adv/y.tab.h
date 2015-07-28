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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int num; char *name; struct node* nodePtr; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
