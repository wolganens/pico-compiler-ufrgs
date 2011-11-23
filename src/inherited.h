#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "symbol_table.h"
#include "lista.h"
#include "tokens.h"

extern int variable_desloc;

void do_variable_insertion(Node *root, symbol_t *table, entry_t *variable);

void do_vector_insertion(Node *root, symbol_t *table, entry_t *variable);
