
	%{ 

	#include <stdio.h> 

	%} 

	%token DIGIT 
	
	%% 

	start : expr '\n'		{printf("\nComplete");exit(1);} 
		; 

	expr:  expr '+' expr		{$$ = $1 + $3} 
		| expr '*' expr		{$$ = $1 * $3} 
		| '(' expr ')'
		| DIGIT			{$$ = $1;} 
		; 

	%% 

	yyerror() 
	{ 
		printf("Error"); 
	} 

	main() 
	{ 
		yyparse(); 
		return 1; 
	} 


