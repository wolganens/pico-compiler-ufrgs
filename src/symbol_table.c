/** @file symbol_table.c
 * \version 1
 * \author Daniel Beck
 * \author Francieli Zanon
 * \author Joseane Barrios
 * \brief Implementacao de uma tabela hash
 */

#include "symbol_table.h"
#define EOS '\0'

entry_t * new_variable (char * name, int type, int size, int desloc, void *extra)
{
	entry_t *new_variable = (entry_t *) malloc (sizeof(entry_t));
	new_variable->name = name;
	new_variable->type = type;
	new_variable->size = size;
	new_variable->desloc = desloc;
	new_variable->extra = extra;
}

int hashpjw(s)
char *s;
{
    char *p;
    unsigned h = 0, g;
    for ( p = s; *p != EOS; p = p+1 ) {
        h = (h << 4) + (*p);
        if  (g = h&0xf0000000) {
            h = h ^ (g >> 24);
            h = h ^ g;
         }
       }
    return h % PRIME;
} 
    

/** \brief Inicializar a tabela de Hash.
 *
 * @param table, uma referencia sobre uma tabela de simbolos.
 * @return o valor 0 se deu certo.
 */
int init_table(symbol_t* table) {
   // zera o conteúdo da tabela
   int x = 0;
    for(x = 0; x < PRIME; x++) {
        table->entries[x] = NULL;
    }
    return 0;
}

/** \brief Destruir a tabela de Hash.
 *
 * 'free_table' eh o destrutor da estrutura de dados. Deve ser chamado pelo 
 * usuario no fim de seu uso de uma tabela de simbolos.
 * @param table, uma referencia sobre uma tabela de simbolos.
 */
void free_table(symbol_t* table) {
    // libera a memória das entradas
   int x = 0;
    for(x = 0; x < PRIME; x++) {
        if(table->entries[x] != NULL) {
            struct table_node_entry * atual = table->entries[x];
            struct table_node_entry * proximo = atual->next;

            free(atual);
            while(proximo != NULL) {
                atual = proximo;
                proximo = atual->next;
                free(atual);
            }

            table->entries[x] = NULL;
        }
    }
    return;
}

/** \brief Retornar um ponteiro sobre a entrada associada a 'name'.
 *
 * Essa funcao deve consultar a tabela de simbolos para verificar se se encontra
 * nela uma entrada associada a um char* (string) fornecido em entrada. Para
 * a implementacao, sera necessario usar uma funcao que mapeia um char* a
 * um numero inteiro. Aconselha-se, por exemplo, consultar o livro do dragao
 * (Aho/Sethi/Ulman), Fig. 7.35 e a funcao HPJW.
 *
 * @param table, uma tabela de simbolos.
 * @param name, um char* (string).
 * @return um ponteiro sobre a entrada associada a 'name', ou NULL se 'name'
 *         nao se encontrou na tabela.
 */
 
entry_t* lookup(symbol_t table, char* name) {
    // A partir de um nome, calcula um hash
    // para associá-lo a um número inteiro
    int hash = hashpjw(name);
    // que será um índice para acessar a tabela de símbolos.
    // verifica se existe ponteiro 
    if(table.entries[hash] != NULL) {

        struct table_node_entry * atual = table.entries[hash]; // inicia com o primeiro nodo da lista encadeada

        // se não for a "entry" que estamos procurando (o "name" é diferente) e ainda existe um nodo seguinte...
        while(( strcmp(name, atual->entry_data->name)) && (atual->next != NULL)) {
            atual = atual->next; // vai para o nodo seguinte
        }

    // se existe, retorna o ponteiro
//        return table.entries[hash];
        if( ! strcmp(name, atual->entry_data->name)) { // se o "name" é igual
            return atual->entry_data;
        } else { // se o "name" não é igual, foi até o fim da lista encadeada e não encontrou, então retorna NULL
            return NULL;
        }
    } else {
    // senão, retorna null    
        return NULL;
    }
}

/** \brief Inserir uma entrada em uma tabela.
 *
 * @param table, uma tabela de simbolos.
 * @param entry, uma entrada.
 * @return um numero negativo se nao se conseguiu efetuar a insercao, zero se
 *   deu certo.
 */
int insert(symbol_t* table, entry_t* entry) {
    if(lookup(*table, entry->name) != NULL) { // se a chave já existe, retorna um numero negativo.
        return -1;
    }

    // cria o nodo de lista encadeada para esta entrada
    struct table_node_entry * nodo = malloc(sizeof(struct table_node_entry));
    nodo->entry_data = entry;
    nodo->next = NULL;
    
    // calcula o hash para associá-lo a um inteiro
    int hash = hashpjw(entry->name);
    // e se não houver lista encadeada ainda
    // entao nenhum elemento foi adicionado ainda para esta chave
    // insere na tabela de símbolos 
    if(table->entries[hash] == NULL) {
    // inicia a lista encadeada com este elemento
        table->entries[hash] = nodo;
    } else {
        // se a lista encadeada já existe, adiciona o elemento no inicio:
        nodo->next = table->entries[hash]; // o próximo do novo elemento é o primeiro elemento da lista
        table->entries[hash] = nodo; // agora, o primeiro elemento da lista passa a ser o elemento recem criado
    }

     return 0;
}

/** \brief Traduz entry para string
 *
 * Uma entrada individual da tabela de símbolos é transformada em uma string. Declarada aqui para ser chamada pelo print_file_table
 *
 * @param entry_t, uma entrada na tabela de simbolos.
 * @return a string correspondente a entrada.
 */
char * str_entry(char * retbuffer, entry_t* entry);

/** \brief Imprimir o conteudo de uma tabela.
 *
 * A formatacao exata e deixada a carga do programador. Deve-se listar todas
 * as entradas contidas na tabela atraves de seu nome (char*). Deve retornar
 * o numero de entradas na tabela.
 *
 * @param table, uma tabela de simbolos.
 * @return o numero de entradas na tabela.
 */
int print_table(symbol_t table) {
    return print_file_table(stdout, table);
}

/** \brief Imprimir o conteudo de uma tabela em um arquivo.
 *
 * A formatacao exata e deixada a carga do programador. Deve-se listar todas
 * as entradas contidas na tabela atraves de seu nome (char*). Deve retornar
 * o numero de entradas na tabela. A saida deve ser dirigida para um arquivo,
 * cujo descritor e passado em parametro.
 *
 * @param out, um descrito de arquivo (FILE*).
 * @param table, uma tabela de simbolos.
 * @return o numero de entradas na tabela.
 */
int print_file_table(FILE* out, symbol_t table) {
    printf("PRINTING SYMBOL TABLE\n\n");
    int entry_count = 0;
    // varre a tabela de símbolos
    int x = 0;
    for(x = 0; x < PRIME; x++) {
    // onde houver ponteiro, imprime o conteúdo da entrada
        if(table.entries[x] != NULL) {
            char tmp_string[1000];

            struct table_node_entry * atual = table.entries[x]; // inicia com o primeiro nodo da lista encadeada

            do {
                str_entry(tmp_string, atual->entry_data);
                fprintf(out, "%s", tmp_string); // imprime o nodo
                entry_count++;
                atual = atual->next; // vai para o nodo seguinte
            } while(atual != NULL);

        }
    }
    
    printf("END OF PRINTING SYMBOL TABLE\n\n");
    return entry_count;
}

char * str_entry(char * retbuffer, entry_t* entry) {
    sprintf(retbuffer, "ENTRY: %s;\n\tType: %d;\n\tSize: %d;\n\tDesloc: %d.",entry->name, entry->type, entry->size, entry->desloc);
    
    char extra[500];
    char limits[500];
              
    if (entry->extra != NULL)
    {
    	sprintf(extra, "\n\tNdim: %d\n\t", entry->extra->ndim);
	int i = 0;
  	while(entry->extra->limits != NULL)
    	{
    		sprintf(limits, "Limit %d: [%d : %d]\n\t", i++, entry->extra->limits->inf_lim, entry->extra->limits->sup_lim);
    		strcat(extra, limits);
    		entry->extra->limits = entry->extra->limits->next;
    	}
    	strcat(retbuffer, extra);
    }    	
    strcat(retbuffer, "\n\n");
    return retbuffer;
}

int array_limit(char *name, int dimension, symbol_t table)
{
	entry_t *array;
	
	if ((array = lookup(table, name)) == NULL)
	{
		printf("array_limit: Varible %s doesnt exist\n", name);
		exit(1);
	}
		
	if (dimension > array->extra->ndim)
	{
		printf("array_limit: Ilegal array dimension. Dimension %d is larger than array dimension %d\n", dimension, array->extra->ndim);
		exit(1);
	}

	int i = 1;
	
	limNode *limitNode = array->extra->limits;
		
	while(i < dimension)
	{
		limitNode = limitNode->next;
		i++;
	}
	
	return limitNode->sup_lim - limitNode->inf_lim + 1;
}

int array_constant(char *name, symbol_t table)
{
	int i = 1;
	int soma = 0;
	
	entry_t *array;
		
	if ((array = lookup(table, name)) == NULL)
	{
		printf("array_constant: Varible %s doesnt exist\n", name);
		exit(1);
	}
	
	limNode *currentDimension = array->extra->limits;
	
	if (array->extra->ndim == 1)
	{
		soma = currentDimension->inf_lim;
	}	
	else
	{	
		while(i < array->extra->ndim)
		{
			if (i == 1)
			{
				soma = (currentDimension->inf_lim * array_limit(name, i + 1, table)) + currentDimension->next->inf_lim;
			}
			else
			{
				soma *= array_limit(name, i + 1, table);
				soma += currentDimension->next->inf_lim;
			}
			currentDimension = currentDimension->next;
			i++;
		}
	}	
	switch(array->type)
	{
		case int_node:
			soma *= INT_SIZE;
			break;
			
		case double_node:
			soma *= DOUBLE_SIZE;
			break;
			
		case real_node:
			soma *= REAL_SIZE;
			break;
			
		case char_node:
			soma *= CHAR_SIZE;
			break;
	}
	
	soma = array->desloc - soma;
	
	return soma;
}
