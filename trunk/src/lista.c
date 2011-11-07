#include "lista.h"

void append_inst_tac (struct node_tac ** code, struct tac * inst)
{
	if (*code == NULL) //lista vazia
	{
		*code = (struct node_tac *)malloc (sizeof(struct node_tac));
		(*code)->number = 0;
		(*code)->inst = inst;
		(*code)->next = NULL;
		(*code)->prev = NULL;
	}
	else 
	{
		int i = 0;
		struct node_tac *backward = *code;
		struct node_tac *forward = (*code)->next;
		
		while(forward != NULL) //percorre-se a lista
		{
			backward = backward->next;
			forward = forward->next;
			i++;
		}
		
		forward = (struct node_tac *)malloc (sizeof(struct node_tac));
		forward->number = i;
		forward->inst = inst;
		forward->next = NULL;
		forward->prev = backward;
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
		int i;
		struct node_tac **backward = code_a;
		
		while((*backward)->next != NULL) //percorre-se a lista
		{
			*backward = (*backward)->next;
		}
		
		(*backward)->next = (*code_b);
		(*code_b)->prev = (*backward);
		
		while(((*backward) = (*backward)->next) != NULL) //atualiza-se os indices da lista_b
		{
			(*backward)->number = ++i;
		}
	}
		
}

struct tac* create_inst_tac(const char* res, const char* arg1, const char* op, const char* arg2)
{
	static struct tac new_tac;
		
	new_tac.res 	= (char *) malloc (sizeof(char)*strlen(res));
	new_tac.arg1 	= (char *) malloc (sizeof(char)*strlen(arg1));
	new_tac.op 	= (char *) malloc (sizeof(char)*strlen(op));
	new_tac.arg2 	= (char *) malloc (sizeof(char)*strlen(arg2));
	
	strcpy(new_tac.res, res);
	strcpy(new_tac.arg1, arg1); 
	strcpy(new_tac.op, op);
	strcpy(new_tac.arg2, arg2); 
	
	return &new_tac;
}

/*void print_inst_tac (FILE * out, struct tac i)
{
	fprintf(out, "%d %s %s %s", i.res, i.op, i.arg1, i.arg2);
}
*/

void print_tac (FILE * out, struct node_tac * code)
{
	int i = 1;
	
	if(code != NULL && code->next != NULL)
		while(code->next != NULL)
		{
			if (i <= 9) 
				fprintf(out, "00%d:   %s %s %s %s\n", i, code->inst->res, code->inst->op, code->inst->arg1, code->inst->arg2);
			else
				if (i <= 99)
					fprintf(out, "0%d:   %s %s %s %s\n", i, code->inst->res, code->inst->op, code->inst->arg1, code->inst->arg2);
				else
					fprintf(out, "%d:   %s %s %s %s\n", i, code->inst->res, code->inst->op, code->inst->arg1, code->inst->arg2);
			code = code->next;
			i++;
		}
}



















