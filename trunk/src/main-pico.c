/* Programa principal do pico. */
#include <stdio.h>
#include "node.h"

char* progname;
int lineno;
extern FILE* yyin;
FILE *file;

int main(int argc, char* argv[]) 
{
	if (argc != 2)
	{
		printf("Try: %s <input_file>. Try again!\n", argv[0]);
		exit(-1);
	}
	
	yyin = fopen(argv[1], "r");
	
	if (!yyin)
	{
		printf("Error: Could not find %s. Try again!\n", argv[1]);
		exit(-1);
	}

	progname = argv[0];
	
	if (!yyparse()) 
		printf("OKAY.\n");
	else 
		printf("ERROR.\n");
	
	file = fopen("uncompiled.txt", "w+");

	uncompile(file, syntax_tree);
	
	return 0;
}

yyerror(char* s)
{
	fprintf(stderr, "%s: %s", progname, s);
	fprintf(stderr, "line %d\n", lineno);
}
