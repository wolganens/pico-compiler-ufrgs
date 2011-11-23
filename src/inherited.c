#include "inherited.h"

void do_variable_insertion(Node *root, symbol_t *table, entry_t *variable)
{
	int i;
	Node *node;

	for (i = 1; i <= nb_of_children(root); i++)
	{		
		node = child(root, i);
						
		if (node->type == idf_node)
		{
			entry_t *new_symbol = new_variable(node->lexeme, variable->type, variable->size, variable_desloc, NULL);
			
			variable_desloc += new_symbol->size;
			
			if(insert(table, new_symbol))
			{
				printf("ERROR(%d). The variable %s was already declared.\n", node->num_line, new_symbol->name);
				exit(1);
			}

		}
		do_variable_insertion(node, table, variable);
	}
}

void do_vector_insertion(Node *root, symbol_t *table, entry_t *variable)
{
	int i;
	Node *node;

	for (i = 1; i <= nb_of_children(root); i++)
	{		
		node = child(root, i);
						
		if (node->type == idf_node)
		{
			entry_t *new_variable = (entry_t *) malloc(sizeof(entry_t));
			
			new_variable->name = node->lexeme;
			new_variable->type = variable->type;
			new_variable->size = variable->size;
			new_variable->desloc = variable_desloc;
			
			new_variable->extra = (vector_info *) malloc(sizeof(vector_info));
			new_variable->extra->ndim = variable->extra->ndim;
			
			limNode *new_var_limits = new_variable->extra->limits = (limNode *) malloc(sizeof(limNode));
			limNode *var_limits = variable->extra->limits;
			
			while(var_limits != NULL)
			{
				new_var_limits->inf_lim = var_limits->inf_lim;
				new_var_limits->sup_lim = var_limits->sup_lim;
				new_var_limits->next = var_limits->next;
				
				new_var_limits = new_var_limits->next;
				var_limits = var_limits->next;
			}
			
			variable_desloc += new_variable->size;
			
			if(insert(table, new_variable))
			{
				printf("ERROR(%d). The variable %s was already declared.\n", node->num_line, new_variable->name);
				exit(1);
			}

		}
		do_vector_insertion(node, table, variable);
	}
}
