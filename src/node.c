#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

Node * syntax_tree;

Nodelist * create_list (void)
{
	return NULL;
}

void add_list (Node *node, Nodelist *root)
{
	Nodelist *backward = root;
	Nodelist *forward = backward->next;
	
	if (root == NULL)
	{
		if ((root = malloc(sizeof(Nodelist))) == NULL)
			exit(-1);
	}
	else
	{
		while(forward != NULL)
		{
			backward = forward;
			forward = forward->next;
		}
		
		if ((forward = malloc(sizeof(Nodelist))) == NULL)
			exit(-1);
		
		forward->next = NULL;
		forward->node = node;
	}
}

Node* create_node(int nl, Node_type t, char* lexeme, Node* child0, ...)
{
	Node *new_node;
	
	Nodelist *children = create_list();
	
	va_list ap;
	va_start(ap, child0);
	
	/**
	 * Verifica se parametro n1 está correto
	 */
	if ((nl != code_node)  && (nl != declaracoes_node)  && (nl != declaracao_node)  && (nl != tipo_node)  && (nl != int_node))
	{
		exit(-1);
		printf("\nPrograma não foi escrito corretamente.\n");
	}
	
	if ((new_node = (new_node *) malloc(sizeof(new_node))) == NULL)
	{
		exit(-1);
	}		
	
	new_node->num_line = nl;
	new_node->lexeme = lexeme;
	new_node->type = t;
	
	for (child = child0; child != NULL; child = va_arg(ap, Node *))
	{
		add_list(child, children);
	}
}

int nb_of_children(Node* n)
{
	Nodelist *backward = n->children;
	
	int i;
	
	if (n == NULL)
		exit(-1);
	
	for (i = 0; backward != NULL; i++)
	{
		backward = backward->next;
	}
	
	return i;
}

int is_leaf(Node* n)
{
	if (n->children == NULL)
		return 1;
	else
		return 0;
}

/** Destructor of a Node. Desallocates (recursively) all the tree rooted at
 * 'n'.
 */
int deep_free_node(Node* n)
{
	if (n == NULL)
		return 0;
		
	Nodelist *backward = n->children;
	Nodelist *forward = backward->next;
	
	while(backward != NULL)
	{
		deep_free_node(backward->node);
		free(backward);
		backward = forward;
		forward = forward->next;
	}
	
	return 1;
}

/** returns the height of the tree rooted by 'n'.
 *  The height of a leaf is 1. 
 */
int height(Node *n) 
{
	if (n == NULL)
		return 0;

	Nodelist *backward = n->children;
	Nodelist *forward = backward->next;
	int node_height = 1;
	
	/*acho que melhor maneira de calcular a altura do nodo é primeiro transformar a árvore em binária*/

	return node_height;
}

