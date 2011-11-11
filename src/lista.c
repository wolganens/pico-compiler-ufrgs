#include "lista.h"

void append_inst_tac (struct node_tac ** code, struct tac * inst)
{
	if (*code == NULL) //lista vazia
	{
		*code = (struct node_tac *) malloc (sizeof(struct node_tac));
		(*code)->number = 1;
		(*code)->inst = inst;
		(*code)->next = NULL;
		(*code)->prev = NULL;
	}
	else 
	{
		int i = 2;
		struct node_tac *forward = (*code);

		while(forward->next != NULL) //percorre-se a lista
		{
			forward = forward->next;
			i++;
		}
		forward->next = (struct node_tac *) malloc (sizeof(struct node_tac));
		forward->next->number = ++i;
		forward->next->inst = inst;
		forward->next->next = NULL;
		forward->next->prev = forward;
	}
}

void cat_tac(struct node_tac ** code_a, struct node_tac ** code_b)
{
	if(*code_a == NULL) //lista a vazia
	{
		*code_a = *code_b;
	}
	else
	{	
		if(*code_b == NULL)
		{
			*code_b = *code_a;
		}
		else
		{
			int i=1;
			
			struct node_tac *backward = *code_a;
		
			while(backward->next != NULL) //percorre-se a lista
			{
				backward = backward->next;
				i++;
			}
		
			backward->next = (*code_b);
			(*code_b)->prev = backward;
		
			while((backward = backward->next) != NULL) //atualiza-se os indices da lista_b
			{
				backward->number = ++i;
			}
		}
	}
}

struct tac* create_inst_tac(const char* res, const char* arg1, const char* op, const char* arg2)
{
	struct tac * new_tac;
	
	new_tac = (struct tac *) malloc(sizeof(struct tac));

	new_tac->res  = (char*) res;
	new_tac->arg1 = (char*) arg1;
	new_tac->op   = (char*) op;
	new_tac->arg2 = (char*) arg2;

	return new_tac;
}

void print_inst_tac (FILE * out, struct node_tac *code)
{
	if(!strcmp(code->inst->res, "PRINT"))
	{
		fprintf(out, "%03d:   %s %s\n", code->number, code->inst->res, code->inst->arg1);
	}
	else
	{		
		fprintf(out, "%03d:   %s := %s %s %s\n", code->number, code->inst->res, code->inst->arg1, code->inst->op, code->inst->arg2);
	}
}


void print_tac (FILE * out, struct node_tac * code)
{
	printf("\n\nPrograma Compilado:\n");
	printf("===============================================\n");
	while(code != NULL){
		print_inst_tac (out, code);
		code = code->next;
	}
	printf("===============================================\n\n");
}
