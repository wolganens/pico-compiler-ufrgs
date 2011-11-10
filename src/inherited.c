#include "inherited.h"

void do_symbol_insertion(Node *root, symbol_t *table, int type, int size)
{
	int i;
	Node *node;

	for (i = 1; i <= nb_of_children(root); i++)
	{		
		node = child(root, i);
						
		if (node->type == idf_node)
		{
			entry_t *variable = new_variable (node->lexeme, type, size, variable_desloc, NULL);
			
			variable_desloc = variable_desloc + size;
			
			if(insert(table, variable))
			{
				printf("Redeclared symbol: %s\n", variable->name);
				exit(1);
			}

		}
		do_symbol_insertion(node, table, type, size);
	}
}
