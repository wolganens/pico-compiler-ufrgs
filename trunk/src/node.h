/** @file node.h
 *  @version 1.1
 */

#ifndef _NODE_H_
#define _NODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <lista.h>

#ifdef __GNUC__
    /* If using gcc, warn about missing NULLs */
    #define NULL_TERMINATED __attribute__((sentinel))
#else
    #define NULL_TERMINATED
#endif

typedef int Node_type;

/* Serie de constantes que servirao para definir tipos de nos (na arvore). 
 * Essa serie pode ser completada ou alterada a vontade.
 */
#define code_node             298
#define declaracoes_node      299
#define declaracao_node       300
#define tipo_node             301
#define acoes_node            302
#define listadeclaracao_node  303
#define tipounico_node        304
#define tipolista_node        305
#define listadupla_node       306
#define comando_node          307
#define lvalue_node           308
#define listaexpr_node        309
#define expr_node             310
#define chamaproc_node        311
#define enunciado_node        312
#define fiminstcontrole_node  313
#define expbool_node          314
#define print_node	      315

#define int_node              501
#define double_node           502
#define real_node             503
#define char_node             504
#define le_node               505 
#define ge_node               506
#define eq_node               507
#define ne_node               508
#define and_node              509
#define or_node               510
#define not_node              511
#define if_node               512
#define then_node             513
#define else_node             514
#define for_node              515
#define next_node             516
#define while_node            517
#define end_node              518
#define true_node             519
#define false_node            520
#define quote_node            521
#define idf_node              522
#define const_node            523
#define str_lit_node          524
#define int_lit_node          525
#define f_lit_node            526

#define semicolon_node        527    // ;
#define colon_node            528    // :
#define comma_node            529    // ,
#define div_node              530    // /
#define minus_node            531    // -
#define plus_node             532    // +
#define mul_node              533    // *
#define attr_node             534    // =
#define lower_node            535    // <
#define greater_node          536    // >
#define leftbracket_node      537    // (
#define rightbracket_node     538    // )
#define leftbracket2_node     539    // {
#define rightbracket2_node    540    // }
#define leftbracket3_node     541    // {
#define rightbracket3_node    542    // }

typedef struct _nodelist {
	struct _nodelist *next;
	struct _node *node;
} Nodelist;

typedef struct _node {
   int num_line;   	/**< numero de linha. */
   char *lexeme;   	/**< o lexema retornado pelo analizador lexical. */
   Node_type type; 	/**< Um dos valores definidos acima pelos # defines. */
   void *attribute;	/**< Qualquer coisa por enquanto. */
   Nodelist *children;  /**< Lista de filhos da arvore. */
   int height;		/**< Altura do nó. */
} Node;

extern Node * syntax_tree;

struct attr_E {
   char* local;
   char* code;
   //struct node_tac* code;
};

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
NULL_TERMINATED
Node* create_node(int nl, Node_type t, char* lexeme, Node* child0, ...);

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
 */
void uncompile(FILE* outfile, Node *n);

#endif
