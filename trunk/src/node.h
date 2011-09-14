/** @file node.h
 *  @version 1.1
 */

#ifndef _NODE_H_
#define _NODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef int Node_type;

/* Serie de constantes que servirao para definir tipos de nos (na arvore). 
 * Essa serie pode ser completada ou alterada a vontade.
 */
#define code_node             298
#define declaracoes_node      299
#define declaracao_node       300
#define tipo_node             301
#define int_node              501
/* A completar */

/** Estrutura de dados parcial para o no da arvore.
 *
 */

typedef struct _node {
   int num_line;   /**< numero de linha. */
   char* lexeme;   /**< o lexema retornado pelo analizador lexical. */
   Node_type type; /**< Um dos valores definidos acima pelos # defines. */
   void* attribute;/**< Qualquer coisa por enquanto. */
   /* Fim das informacoes armazenadas em cada no.
    * A seguir, completar essa estrutura de dados com o necessário para
    * a implementacao dos metodos especificados.
    */

} Node;

extern Node * syntax_tree;

/**
 *  * Node constructor.
 *
 * @param nl: line number where this token was found in the source code.
 * @param t: node type (one of the values #define'd above). Must abort
 *             the program if the type is not correct.
 * @param lexeme: whatever string you want associated to this node.
 * @param attr: a semantical attribute.
 * @param child0: first of a list of pointers to children Node*'s. See the
 * extra file 'exemplo_func_var_arg.c' for an example.
 * To create a leaf, use NULL as last argument to create_node().
 * @return a pointer to a new Node.
 */
Node* create_node(int nl, Node_type t,
        char* lexeme, Node* child0, ...);

/** accessor to the number of children of a Node.
 *  Must abort the program if 'n' is NULL.
 */
int nb_of_children(Node* n);

/** Tests if a Node is a leaf.
 *  Must abort the program if 'n' is NULL.
 *  @return 1 if n is a leaf, 0 else.
 */
int is_leaf(Node* n);

/** accessor to the i'th child of a Node.
 * @param n : the node to be consulted. Must abort the program if 'n' is NULL.
 * @param i : the number of the child that one wants. Must be lower 
 *       than the degree of the node and larger than 0. 
 *       Must abort the program if i is not correct.
 * @return a pointer on a Node.
 */
Node* child(Node* n, int i) ;

/** Destructor of a Node. Desallocates (recursively) all the tree rooted at
 * 'n'.
 */
int deep_free_node(Node* n) ;

/** returns the height of the tree rooted by 'n'.
 *  The height of a leaf is 1. 
 */
int height(Node *n) ;

/** Prints into a file the lexemes contained in the node rooted by 'n'.
 *  The impression must follow a depth-first order.
 *  @param outfile : the file to which the lexemes are printed.
 *  @param n : the root node of the tree. Must abort the program if 'n' is NULL.
 *
 */
void uncompile(FILE* outfile, Node *n) ;


#endif
