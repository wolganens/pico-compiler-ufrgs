#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include "node.h"

Node * syntax_tree;

void add_list (Node *node, Nodelist **root)
{
	if (*root == NULL)
	{
		if ((*root = malloc(sizeof(Nodelist))) == NULL)
		{
			perror("malloc() error:");
			exit(-1);
		}
		
		(*root)->node = node;
		(*root)->next = NULL;
	}
	else
	{
		Nodelist **backward = root;
		Nodelist **forward = &((*root)->next);
		
		while (*forward != NULL)
		{
			backward = forward;
			forward = &((*forward)->next);
		}
		
		if ((*forward = malloc(sizeof(Nodelist))) == NULL)
		{
			perror("malloc() error:");
			exit(-1);
		}
		
		(*forward)->next = NULL;
		(*forward)->node = node;
	}
}

Node* create_node(int nl, Node_type t, char* lexeme, Node* child0, ...)
{
	va_list ap;
	va_start(ap, child0);
	
	/**
	 * Verifica se parametro n1 está correto
	 */
	if ((t < code_node) || (t > expbool_node && t < int_node) || (t > rightbracket3_node))
	{
		printf("\nPrograma não foi escrito corretamente.\n");
		exit(-1);		
	}

	Node *new_node;	

	if ((new_node = (Node *) malloc(sizeof(Node))) == NULL)
	{
		perror("");
		exit(-1);
	}	
	
	new_node->num_line = nl;
	new_node->lexeme = lexeme;
	new_node->type = t;
	new_node->children = NULL;
	
	Node* child;
	
	for (child = child0; child != NULL; child = va_arg(ap, Node*))
	{
		add_list(child, &(new_node->children));
	}
	
	va_end(ap);
	
	return new_node;
}

Node* child(Node* n, int i) 
{
	if (n == NULL)
		exit(-1);

	if (i < 0 || i > nb_of_children(n))
		exit(-1);

	Nodelist *backward = n->children;
	
	int k;
	
	for (k = 0; k != i-1; k++)
	{
		backward = backward->next;
	}
	
	return backward->node;
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

int deep_free_node(Node* n)
{
	if (nb_of_children(n) == 0)
	{
		free(n);
		return 1;
	}
	
	Nodelist *backward = n->children;
	Nodelist *forward = backward->next;
	
	while(backward != NULL)
	{
		deep_free_node(backward->node);
		backward = forward;
		
		if (forward != NULL)
			forward = forward->next;		
	}
	
	free(n);
	
	return 1;
}

int height(Node *n) 
{
	if (nb_of_children(n) == 0)
	{
		return 1;
	}
	
	Nodelist *backward = n->children;
	Nodelist *forward = backward->next;
	
	while(backward != NULL)
	{
		backward->node->height = height(backward->node);
		backward = forward;
		
		if (forward != NULL)
			forward = forward->next;
	}
	
	backward = n->children;
	forward = backward->next;
	
	int i = backward->node->height;
	
	while (backward != NULL)
	{
		if (i < backward->node->height)
			i = backward->node->height;
			
		backward = forward;
		
		if (forward != NULL)
			forward = forward->next;
	}
	
	return i + 1;
}

void uncompile(FILE* outfile, Node *n) 
{
	char *space = " ";

	if (outfile == NULL)
	{
		perror("Error on FILE: ");
		exit(-1);
	}
	
	if (is_leaf(n))
	{
		fwrite(n->lexeme, 1, strlen(n->lexeme), outfile);
		fwrite(space, 1, strlen(space), outfile);
		return;
	}
	
	Nodelist *backward = n->children;
	Nodelist *forward = backward->next;
	
	while(backward != NULL)
	{
		uncompile(outfile, backward->node);
		backward = forward;
		
		if (forward != NULL)
			forward = forward->next;
	}
	return;
}

/*int main()
{
	Node *node[17];	
		
	node[0] = create_node(0, expbool_node , "abc", NULL);
	node[1] = create_node(0, expbool_node , NULL, node[0], NULL);
	node[2] = create_node(0, expbool_node , "bdsa", NULL);
	node[3] = create_node(0, expbool_node , "casd", NULL);
	node[4] = create_node(0, expbool_node , NULL, node[1], node[2], node[3], NULL);
	
	node[5] = create_node(0, expbool_node , "dfas", NULL);
	node[6] = create_node(0, expbool_node , "easf", NULL);
	node[7] = create_node(0, expbool_node , NULL, node[5], NULL);
	node[8] = create_node(0, expbool_node , NULL, node[6], node[7], NULL);
	
	node[9] = create_node(0, expbool_node , "fafs", NULL);
	node[10] = create_node(0, expbool_node , "gasf", NULL);
	node[11] = create_node(0, expbool_node , "hasf", NULL);
	node[12] = create_node(0, expbool_node , NULL, node[9], node[10], node[11], NULL);
	
	node[13] = create_node(0, expbool_node , "iafs", NULL);
	node[14] = create_node(0, expbool_node , NULL, node[13], node[12], NULL);
	
	node[15] = create_node(0, expbool_node , NULL, node[8], node[14], NULL);
	
	node[16] = create_node(0, expbool_node , NULL, node[4], node[15], NULL);
	
	printf("A altura da arvore eh: %d\n", height(node[16]));	

	
	uncompile(file, node[16]);
	
	return 0;
}*/
