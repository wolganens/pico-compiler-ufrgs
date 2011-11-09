/* Programa principal do pico. */
#include <stdio.h>
#include "node.h"

char* progname;
int lineno;
extern FILE* yyin;
FILE *file;

int main(int argc, char* argv[]) 
{
	if (argc != 4)
	{
		printf("Try: %s -0  <input_file>.'tac' <input_file>'pico'. Try again!\n", argv[0]);
		exit(-1);
	}
	if (argv[1] == "-o")
	{
		printf("Try: %s -0  <input_file>.'tac' <input_file>'pico'. Try again!\n", argv[0]);
		exit(-1);
	} 
	
	yyin = fopen(argv[3], "r");
	
	
	if (!yyin)
	{
		printf("Error: Could not find %s. Try again!\n", argv[3]);
		exit(-1);
	}



	progname = argv[0];
	
	if (!yyparse()) 
		printf("OKAY.\n");
	else 
		printf("ERROR.\n");
	
	//FILE * out = fopen(argv[3], "w");
	
	//print_tac(out, syntax_tree->code);
	
	file = fopen("uncompiled.txt", "w+");

	uncompile(file, syntax_tree);
	
	return 0;
}

yyerror(char* s)
{
	fprintf(stderr, "%s: %s", progname, s);
	fprintf(stderr, "line %d\n", lineno);
}
