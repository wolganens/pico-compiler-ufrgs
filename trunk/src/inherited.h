#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "symbol_table.h"
#include "lista.h"
#include "tokens.h"

extern int variable_desloc;

void do_symbol_insertion(Node *root, symbol_t *table, int type, int size);
