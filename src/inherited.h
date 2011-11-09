#include "node.h"
#include "symbol_table.h"
#include "lista.h"
#include "tokens.h"

extern int desloc;

void do_symbol_insertion(Node *root, symbol_t *table, int type, int size);
