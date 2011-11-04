



struct tac* create_inst_tac(const char* res, const char* arg1, const char* op, const char* arg2)
{
	struct tac* new;
	new = (struct tac*) malloc(sizeof (struct tac*));
	strcpy(new->res, res);
	strcpy(new->arg1, arg1); 
	strcpy(new->arg2, arg2); 
	strcpy(new->op, op);  

	return new;
}


void cat_tac(struct node_tac ** code_a, struct node_tac ** code_b)
{
	struct node_tac** new_a;
	struct node_tac** new_b;

	if (code_a == NULL) //lista a vazia
		code_a = code_b;
	if (code_b == NULL) //lista b vazia
		code_b = code_a;
  
	for(*new_a = *code_a; *new_a->next != NULL; *new_a = *new_a->next);
	
	*new_a->next = *code_b;
	*code_a = *new_a;

	for(*new_b = *code_b; *new_b->next != NULL; *new_b = *new_b->next);
	
	*new_b->next = code_a;
	*code_b = *new_b;
	
}
