typedef union{
	class ParseTree *pt;
} YYSTYPE;
#define	IDENTIFIER	257
#define	CONSTANT	258
#define	STRING_LITERAL	259
#define	SIZEOF	260
#define	CONSTANT_INT	261
#define	CONSTANT_FLOAT	262
#define	CONSTANT_CHAR	263
#define	PTR_OP	264
#define	INC_OP	265
#define	DEC_OP	266
#define	LEFT_OP	267
#define	RIGHT_OP	268
#define	LE_OP	269
#define	GE_OP	270
#define	EQ_OP	271
#define	NE_OP	272
#define	AND_OP	273
#define	OR_OP	274
#define	MUL_ASSIGN	275
#define	DIV_ASSIGN	276
#define	MOD_ASSIGN	277
#define	ADD_ASSIGN	278
#define	SUB_ASSIGN	279
#define	LEFT_ASSIGN	280
#define	RIGHT_ASSIGN	281
#define	AND_ASSIGN	282
#define	XOR_ASSIGN	283
#define	OR_ASSIGN	284
#define	TYPE_NAME	285
#define	TYPEDEF	286
#define	EXTERN	287
#define	STATIC	288
#define	AUTO	289
#define	REGISTER	290
#define	CHAR	291
#define	SHORT	292
#define	INT	293
#define	LONG	294
#define	SIGNED	295
#define	UNSIGNED	296
#define	FLOAT	297
#define	DOUBLE	298
#define	CONST	299
#define	VOLATILE	300
#define	VOID	301
#define	STRUCT	302
#define	UNION	303
#define	ENUM	304
#define	ELLIPSIS	305
#define	CASE	306
#define	DEFAULT	307
#define	IF	308
#define	ELSE	309
#define	SWITCH	310
#define	WHILE	311
#define	DO	312
#define	FOR	313
#define	GOTO	314
#define	CONTINUE	315
#define	BREAK	316
#define	RETURN	317
#define	BOOL	318
#define	COMPLEX	319
#define	IMAGINARY	320
#define	INLINE	321
#define	RESTRICT	322


extern YYSTYPE yylval;
