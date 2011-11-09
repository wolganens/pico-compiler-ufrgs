#include "inherited.h"

void do_symbol_insertion(Node *root, symbol_t *table, int type, int size)
{
	int i;
	Node *node;
	char * aux = (char *) malloc(7*sizeof(char));
	
	for (i = 1; i <= nb_of_children(root); i++)
	{		
		node = child(root, i);
		printf("%d\n", node->type);
						
		if (node->type == idf_node)
		{		
			entry_t *variable = (entry_t *) malloc(sizeof(entry_t));
			variable->name = node->lexeme;
			sprintf(aux, "%03d(SP)", desloc);
			variable->name2 = aux;
			//printf("%03d(SP)", desloc);		
			variable->type = type;
			variable->size = size;
			variable->desloc = desloc;
			desloc = desloc + size;
			
			if(insert(table, variable))
			{
				printf("Redeclared symbol: %s\n", variable->name);
				exit(1);
			}

		}
		do_symbol_insertion(node, table, type, size);
	}
}
