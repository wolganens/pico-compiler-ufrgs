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
	 * Verifica se parametro n1 está correto			TEM QUE ACRESCENTAR TODOS
	 */
	//if ((t != code_node)  && (t != declaracoes_node)  && (t != declaracao_node)  && (t != tipo_node)  && (t != int_node))
	if ((t < code_node) || (t > expbool_node && t < int_node) || (t > rightbracket_node))
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
	return new_node;
}


/** accessor to the i'th child of a Node.
 * @param n : the node to be consulted. Must abort the program if 'n' is NULL.
 * @param i : the number of the child that one wants. Must be lower 
 *       than the degree of the node and larger than 0. 
 *       Must abort the program if i is not correct.
 * @return a pointer on a Node.
 */
Node* child(Node* n, int i) 
{
	Nodelist *backward = n->children;
	int number, k;

	if(n == NULL)
		exit(-1);

	number = nb_of_children(n);

	if(i == 0 || i > number)
		exit(-1);

	
	for (k = 0; k != i; k++)
	{
		backward = backward->next;
	}
	
	return n->backward;
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

/** Prints into a file the lexemes contained in the node rooted by 'n'.
 *  The impression must follow a depth-first order.
 *  @param outfile : the file to which the lexemes are printed.
 *  @param n : the root node of the tree. Must abort the program if 'n' is NULL.
 *
 */
void uncompile(FILE* outfile, Node *n) 
{

	fopen(outfile, "a+");
	if (n != NULL)
		{

		if (n->children != NULL)
		{

			uncompile(outfile, n->chilren);
			uncompile(outfile, n->next);
		
		}
		if (n->children == NULL)		//é uma folha (deve ser colocada no arquivo)
		{

			fwrite(n->lexeme, 1, strlen(n->lexeme), outfile);
			uncompile(outfile, n->next);

		}
	
	}


}



