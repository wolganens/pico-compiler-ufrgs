/* Programa principal do pico. */
#include <stdio.h>
#include "node.h"
#include "symbol_table.h"

char* progname;
int lineno;
extern FILE* yyin;
FILE *tacoutput;
extern symbol_t variable_table;
extern symbol_t temp_table;
extern int variable_desloc;
extern int temp_desloc;

void print_inst_tac_low_level (FILE * out, struct node_tac *code)
{
	char res[15];
	char arg1[15];
	char arg2[15];
	
	int i;
	
	entry_t *variable;

	if (sscanf(code->inst->res, "TEMP%03d", &i) == 1)
	{
		variable = lookup(temp_table, code->inst->res);
		sprintf(res, "%03d(Rx)", variable->desloc);
	}
	else
	{
		if((variable = lookup(variable_table, code->inst->res)) != NULL)
		{
			sprintf(res, "%03d(SP)", variable->desloc);
		}

	}

	if (sscanf(code->inst->arg1, "TEMP%03d", &i) == 1)
	{
		variable = lookup(temp_table, code->inst->arg1);
		sprintf(arg1, "%03d(Rx)", variable->desloc);
	}
	else
	{
		if((variable = lookup(variable_table, code->inst->arg1)) != NULL)
		{
			sprintf(arg1, "%03d(SP)", variable->desloc);
		}
		else
		{
			strcpy(arg1, code->inst->arg1);
		}
	}
	
	if (sscanf(code->inst->arg2, "TEMP%03d", &i) == 1)
	{
		printf("ARG2 = TEMP\n");
		variable = lookup(temp_table, code->inst->arg2);
		sprintf(arg2, "%03d(Rx)", variable->desloc);
	}
	else
	{
		if((variable = lookup(variable_table, code->inst->arg2)) != NULL)
		{
			sprintf(arg2, "%03d(SP)", variable->desloc);
		}
		else
		{
			strcpy(arg2, code->inst->arg2);
		}
	}
	
	if(!strcmp(code->inst->res, "PRINT"))
	{		
		fprintf(out, "%03d:   %s %s\n", code->number, code->inst->res, arg1);
	}
	else
	{
		fprintf(out, "%03d:   %s := %s %s %s\n", code->number, res, arg1, code->inst->op, arg2);
	}
}


void print_tac_low_level (FILE * out, struct node_tac * code)
{
	fprintf(out, "%d\n%d\n", variable_desloc, temp_desloc);
	while(code != NULL)
	{ 
		print_inst_tac_low_level (out, code);
		code = code->next;
	}
}

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
	
	init_table(&variable_table);
	init_table(&temp_table);

	progname = argv[0];
	
	if (!yyparse()) 
		printf("Successfull compilation!.\n");
	else 
		printf("Error on compilation!.\n");
	
	
	tacoutput = fopen(argv[2], "w+");
	print_tac_low_level (tacoutput, syntax_tree->code);
	fclose(tacoutput);
		
	return 0;
}

yyerror(char* s)
{
	fprintf(stderr, "%s: %s", progname, s);
	fprintf(stderr, "line %d\n", lineno);
}
