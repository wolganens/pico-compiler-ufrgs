%{
  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
  #include <stdio.h>
  #include <stdlib.h>
  #include "node.h"
  #include "symbol_table.h"
  #include "labels.h"
  #include "lista.h"
  #include "inherited.h"

  int variable_desloc = 0;
  int temp_desloc = 0;

  int t_counter = 0;
  int l_counter = 0;
  
  extern symbol_t variable_table;
  extern symbol_t temp_table;
%}

%error-verbose

%union {
  char* cadeia;
  struct _node * no;
}

%token<cadeia> IDF
%token<cadeia> INT
%token<cadeia> DOUBLE
%token<cadeia> REAL
%token<cadeia> CHAR
%token<cadeia> QUOTE
%token<cadeia> LE
%token<cadeia> GE
%token<cadeia> EQ
%token<cadeia> NE

%token<cadeia> PRINTF

%token<cadeia> '+'
%token<cadeia> '-'
%token<cadeia> '*'
%token<cadeia> '/'
%token<cadeia> '='

%token<cadeia> '>'
%token<cadeia> '<'

%token<cadeia> ','
%token<cadeia> ';'
%token<cadeia> ':'

%token<cadeia> '('
%token<cadeia> ')'
%token<cadeia> '{'
%token<cadeia> '}'
%token<cadeia> '['
%token<cadeia> ']'

%token<cadeia> AND
%token<cadeia> OR
%token<cadeia> NOT
%token<cadeia> IF
%token<cadeia> THEN
%token<cadeia> ELSE
%token<cadeia> WHILE
%token<cadeia> INT_LIT
%token<cadeia> F_LIT
%token<cadeia> END
%token<cadeia> TRUE
%token<cadeia> FALSE
%token<cadeia> STRING
%token<cadeia> CONST
%token<cadeia> STR_LIT
%token<cadeia> FOR
%token<cadeia> NEXT

%left OR
%left AND
%left NOT
%left '+' '-'
%left '*' '/'

%type<no> code 
%type<no> declaracoes
%type<no> declaracao
%type<no> listadeclaracao
%type<no> tipo
%type<no> tipounico
%type<no> tipolista
%type<no> listadupla
%type<no> acoes
%type<no> comando
%type<no> lvalue
%type<no> listaexpr
%type<no> expr
%type<no> chamaproc
%type<no> enunciado
%type<no> fiminstcontrole
%type<no> expbool

%start code

 /* A completar com seus tokens - compilar com 'yacc -d' */

%%
code: declaracoes acoes	{	$$ = create_node( @$.first_line, code_node, NULL, $1, $2, NULL);
	           		syntax_tree = $$; 
	   			cat_tac(&($$->code), &($2->code));
	 		}
    | acoes		{ 
    				$$ = $1;
    				syntax_tree = $$;
    			}
    ;

declaracoes: declaracao ';' {   Node *filho2 = create_node( @2.first_line, semicolon_node, $2, NULL, NULL);
    			    	$$ = create_node( @$.first_line, declaracoes_node, NULL, $1, filho2, NULL);  
			    }
    			    	
           | declaracoes declaracao ';' {   	Node* filho3 = create_node( @3.first_line, semicolon_node, $3, NULL, NULL);
    		    				$$ = create_node( @1.first_line, declaracoes_node, NULL, $1, $2, filho3, NULL);  
					}
       	   ;

declaracao: tipo ':' listadeclaracao {	Node* filho2 = create_node( @2.first_line, colon_node, $2, NULL, NULL);
					$$ = create_node( @$.first_line, declaracao_node, NULL, $1, filho2, $3, NULL);

					if ($1->variable->extra == NULL)	//simple variable
						do_variable_insertion ($$, &variable_table, $1->variable);
					else					//array
						do_vector_insertion ($$, &variable_table, $1->variable);
					}
	   ;

listadeclaracao: IDF	{  $$ = create_node(@1.first_line, idf_node, $1, NULL, NULL);	}
						 

               | IDF ',' listadeclaracao {	Node* filho1 = create_node( @1.first_line, idf_node, $1, NULL, NULL);        					
						Node* filho2 = create_node( @2.first_line, comma_node, $2, NULL, NULL);               					
						$$ = create_node( @$.first_line, listadeclaracao_node, NULL, filho1, filho2, $3, NULL);
					 }
		;

tipo: tipounico { $$ = $1; }
    | tipolista { $$ = $1; }
    ;

tipounico: INT    {  	$$ = create_node(@1.first_line, int_node, $1, NULL, NULL);
	      		$$->type = int_node;
	      		
	      		$$->variable = (entry_t *) malloc(sizeof(entry_t));
	      		$$->variable->type = int_node;
	  		$$->variable->size = INT_SIZE; }

         | DOUBLE {	$$ = create_node(@1.first_line, double_node, $1, NULL, NULL);
        		$$->type = double_node;
        		
		   	$$->variable = (entry_t *) malloc(sizeof(entry_t));
	      		$$->variable->type = double_node;
	  		$$->variable->size = DOUBLE_SIZE; }

         | REAL   {	$$ = create_node(@1.first_line, real_node, $1, NULL, NULL);
         		$$->type = real_node;
         		
	      		$$->variable = (entry_t *) malloc(sizeof(entry_t));
	      		$$->variable->type = real_node;
	  		$$->variable->size = REAL_SIZE; } 

         | CHAR   { 	$$ = create_node(@1.first_line, char_node, $1, NULL, NULL);
         		$$->type = char_node;
         		
	      		$$->variable = (entry_t *) malloc(sizeof(entry_t));
	      		$$->variable->type = char_node;
	  		$$->variable->size = CHAR_SIZE; } 
         ;

tipolista: INT '(' listadupla ')'     { Node* filho1 = create_node( @1.first_line, int_node, $1, NULL, NULL);
 					Node* filho2 = create_node( @2.first_line, leftbracket_node, $2, NULL, NULL);
					Node* filho4 = create_node( @4.first_line, rightbracket_node, $4, NULL, NULL);
    		 			$$ = create_node( @$.first_line, tipolista_node, NULL, filho1, filho2, $3, filho4, NULL);  
    			    		 				
    		 			$$->variable = $3->variable;
    		 			$$->variable->type = int_node;
    		 			$$->variable->size *= INT_SIZE;  		 				
    		 		 	}

         | DOUBLE '(' listadupla ')'  { Node* filho1 = create_node( @1.first_line, double_node, $1, NULL, NULL);
 					Node* filho2 = create_node( @2.first_line, leftbracket_node, $2, NULL, NULL);
 					Node* filho4 = create_node( @4.first_line, rightbracket_node, $4, NULL, NULL);
    		 			$$ = create_node( @$.first_line, tipolista_node, NULL, filho1, filho2, $3, filho4, NULL); 

    		 			$$->variable = $3->variable;
	 				$$->variable->type = double_node;
	 				$$->variable->size *= DOUBLE_SIZE; 
    		 			}

         | REAL '(' listadupla ')'    { Node* filho1 = create_node( @1.first_line, real_node, $1, NULL, NULL);
 					Node* filho2 = create_node( @2.first_line, leftbracket_node, $2, NULL, NULL);
 					Node* filho4 = create_node( @4.first_line, rightbracket_node, $4, NULL, NULL);
    		 			$$ = create_node( @$.first_line, tipolista_node, NULL, filho1, filho2, $3, filho4, NULL);
    			    		 			
    		 			$$->variable = $3->variable;
	 				$$->variable->type = real_node;
	 				$$->variable->size *= REAL_SIZE; 
    		 			}

         | CHAR '(' listadupla ')'    { Node* filho1 = create_node( @1.first_line, char_node, $1, NULL, NULL);
 					Node* filho2 = create_node( @2.first_line, leftbracket_node, $2, NULL, NULL);
					Node* filho4 = create_node( @4.first_line, rightbracket_node, $4, NULL, NULL);
    		 			$$ = create_node( @$.first_line, tipolista_node, NULL, filho1, filho2, $3, filho4, NULL);
    		 			
    		 			$$->variable = $3->variable;
	 				$$->variable->type = char_node;
	 				$$->variable->size *= CHAR_SIZE; 
	 				}
         ;

listadupla: INT_LIT ':' INT_LIT		{  	Node* filho1 = create_node( @1.first_line, int_lit_node, $1, NULL, NULL);
						Node* filho2 = create_node( @2.first_line, colon_node, $2, NULL, NULL);
	   					Node* filho3 = create_node( @3.first_line, int_lit_node, $3, NULL, NULL);
	    		  			$$ = create_node( @$.first_line, listadupla_node, NULL, filho1, filho2, filho3, NULL);
	    		  			   		  			
	    		  			$$->variable = (entry_t *) malloc(sizeof(entry_t));
	    		  			$$->variable->extra = (vector_info *) malloc(sizeof(vector_info));
	    		  			
	    		  			$$->variable->extra->ndim = 1;
	    		  			
	    		  			$$->variable->extra->limits = (limNode *) malloc(sizeof(limNode));    			    		  			
	    		  			
	    		  			int inf_lim = $$->variable->extra->limits->inf_lim = atoi($1);
				  		int sup_lim = $$->variable->extra->limits->sup_lim = atoi($3);
	    		  			    		  			
	    		  			$$->variable->extra->limits->next = NULL;
	    		  			
	    		  			$$->variable->size += sup_lim - inf_lim + 1;
				  			
			  			if (sup_lim < inf_lim)
			  			{
							printf("ERROR(%d). Ilegal array limits.\n", $$->num_line);
							exit(1);
				      		}
				      		
    			    		 }

          | INT_LIT ':' INT_LIT ',' listadupla	{  	Node* filho1 = create_node( @1.first_line, int_lit_node, $1, NULL, NULL);
   							Node* filho2 = create_node( @2.first_line, colon_node, $2, NULL, NULL);
   							Node* filho3 = create_node( @3.first_line, int_lit_node, $3, NULL, NULL);
   							Node* filho4 = create_node( @4.first_line, comma_node, $4, NULL, NULL);
			    		           	
			    		           	$$ = create_node( @$.first_line, listadupla_node, NULL, filho1, filho2, filho3, filho4, $5, NULL);
			    		           			    		           	
			    		           	$$->variable = $5->variable;
				  			$$->variable->extra->ndim += 1;
				  			
							limNode *new_limit = (limNode *) malloc(sizeof(limNode));
							
							int inf_lim = new_limit->inf_lim= atoi($1);
				  			int sup_lim = new_limit->sup_lim = atoi($3);
							new_limit->next = NULL;							
							
							new_limit->next = $$->variable->extra->limits;
							$$->variable->extra->limits = new_limit;
				  			
				  			$$->variable->size *= sup_lim - inf_lim + 1;
				  			
				  			if (sup_lim < inf_lim)
				  			{
								printf("ERROR(%d). Ilegal array limits.\n", $$->num_line);
								exit(1);
					      		}
					      	}
          ;

acoes: comando ';'  {	Node* filho2 = create_node( @2.first_line, semicolon_node, $2, NULL, NULL);
			$$ = create_node( @$.first_line, acoes_node, NULL, $1, filho2, NULL);
			cat_tac(&($$->code), &($1->code));
		    }

     | comando ';' acoes   { 	Node* filho2 = create_node( @2.first_line, semicolon_node, $2, NULL, NULL);
	      		  	$$ = create_node( @$.first_line, acoes_node, NULL, $1, filho2, $3, NULL); 
	     			cat_tac(&($1->code), &($3->code));
				cat_tac(&($$->code), &($1->code));				
		    	   }
    ;

comando: lvalue '=' expr {	Node* filho2 = create_node( @2.first_line, attr_node, $2, NULL, NULL);
			     	$$ = create_node( @$.first_line, comando_node, NULL, $1, filho2, $3, NULL);

				if ($1->array == NULL)
				{		     
					printf("AQUI");				     
				     entry_t * variable;

				     if (((variable) = lookup(variable_table, $1->local)) == NULL)
				     { 
						printf("ERROR(%d). The variable %s was not declared.\n", $$->num_line, $$->lexeme);
						exit(1);
				     }
					  
				     struct tac* new_instruction = create_inst_tac(variable->name, $3->local, "", "");
				     append_inst_tac(&($3->code), new_instruction);

				     cat_tac(&($$->code), &($3->code));				     
				}
				else
				{
					char *indirect_access = (char *) malloc(sizeof(char)*30);
					sprintf(indirect_access, "%s(%s)", $1->local, $1->array);
					
					struct tac *instruction1 = create_inst_tac(indirect_access, $3->local, "", "");
					append_inst_tac(&($3->code), instruction1);

					cat_tac(&($1->code), &($3->code));
					cat_tac(&($$->code), &($1->code));				
			 	}
			 }
       | enunciado { $$ = $1; }
       ;

lvalue: IDF { 	$$ = create_node(@1.first_line, idf_node, $1, NULL, NULL);
		
		entry_t * variable;
		
		if ((variable = lookup(variable_table, $$->lexeme)) == NULL)
		{
			printf("ERROR(%d). The variable %s was not declared.\n", $$->num_line, $$->lexeme);
			exit(1);
		}
		
		$$->local = variable->name;		
		$$->code  = NULL;
	    }

	| listaexpr ']'	{	Node* filho2 = create_node(@2.first_line, rightbracket3_node, $2, NULL, NULL);
				$$ = create_node(@$.first_line, lvalue_node, NULL, $1, filho2, NULL, NULL);
						
				char *temp1 = new_temp(t_counter++);				
				entry_t *temp_variable1 = new_variable(temp1, int_node, INT_SIZE, temp_desloc, NULL);    			
		    		temp_desloc = temp_desloc + INT_SIZE;    			
    				insert(&temp_table, temp_variable1);	
    				
    				entry_t *array;
    				if ((array = lookup(variable_table, $1->array)) == NULL)
				{
					printf("ERROR(%d). The variable %s was not declared.\n", $1->num_line, $1->array);
					exit(1);
				}				
				
				char *weight = (char *) malloc(sizeof(char)*20);
    				switch(array->type)
				{
					case int_node:
						sprintf(weight, "%d", INT_SIZE);
						break;
	
					case double_node:
						sprintf(weight, "%d", DOUBLE_SIZE);
						break;
	
					case real_node:
						sprintf(weight, "%d", REAL_SIZE);
						break;
	
					case char_node:
						sprintf(weight, "%d", CHAR_SIZE);
						break;
				}	
				
				struct tac *instruction1 = create_inst_tac(temp1, $1->local, "MUL", weight);				
				append_inst_tac(&($1->code), instruction1);
				
				char *temp2 = new_temp(t_counter++);				
				entry_t * temp_variable2 = new_variable (temp2, int_node, INT_SIZE, temp_desloc, NULL);			
		    		temp_desloc = temp_desloc + INT_SIZE;    			
    				insert(&temp_table, temp_variable2);
				    				
				int offset = array_constant($1->array, variable_table);
				array->extra->offset = offset;
				char *constant = (char *) malloc(sizeof(char)*35);
				sprintf(constant, "%d", offset, $1->array);
							
				struct tac *instruction2 = create_inst_tac(temp2, temp1, "ADD", constant);
				append_inst_tac(&($1->code), instruction2);		
				
				cat_tac(&($$->code), &($1->code));						
    				
    				$$->local = temp2;
    				$$->array = $1->array;
		}
      	;

listaexpr: listaexpr ',' expr   {	Node* filho2 = create_node(@2.first_line, comma_node, $2, NULL, NULL);
					$$ = create_node(@$.first_line, listaexpr_node, NULL, $1, filho2, $3, NULL, NULL);
						
					char *temp = new_temp(t_counter++);
					entry_t *temp_variable = new_variable (temp, int_node, INT_SIZE, temp_desloc, NULL);    			
		    			temp_desloc = temp_desloc + INT_SIZE;
    					insert(&temp_table, temp_variable);

					int m = $1->ndim + 1;
					
					char *limit = (char *) malloc(sizeof(char)*22);
					sprintf(limit, "%d", array_limit($1->array, m, variable_table));
					
					struct tac *instruction1 = create_inst_tac(temp, $1->local, "MUL", limit);
					append_inst_tac(&($1->code), instruction1);					
					
					char *temp2 = new_temp(t_counter++);
					entry_t *temp_variable2 = new_variable (temp2, int_node, INT_SIZE, temp_desloc, NULL);    			
		    			temp_desloc = temp_desloc + INT_SIZE;
    					insert(&temp_table, temp_variable2);
									
					struct tac *instruction2 = create_inst_tac(temp2, temp, "ADD", $3->local);
					append_inst_tac(&($1->code), instruction2);
					
					cat_tac(&($1->code), &($3->code));
					cat_tac(&($$->code), &($1->code));

					$$->array = $1->array;
					$$->local = temp2;
					$$->ndim = m;					
				}
				
	 | IDF '[' expr 	{    Node* filho1 = create_node( @1.first_line, idf_node, $1, NULL, NULL);
	 			     Node* filho2 = create_node( @2.first_line, leftbracket3_node, $2, NULL, NULL);
				     $$ = create_node(@$.first_line, listaexpr_node, NULL, filho1, filho2, $3, NULL);
				     
				     $$->array = $1;
				     $$->local = $3->local;
				     $$->ndim = 1;
				     cat_tac(&($$->code), &($3->code));			     	     
				}
	 ;

expr: expr '+' expr  {  Node* filho2 = create_node( @2.first_line, plus_node, $2, NULL, NULL);
    			$$ = create_node( @$.first_line, expr_node, NULL, $1, filho2, $3, NULL); 

    			$$->local = new_temp(t_counter++);
    			
    			entry_t * temp_variable = new_variable ($$->local, int_node, INT_SIZE, temp_desloc, NULL);
    			
    			temp_desloc = temp_desloc + INT_SIZE;
    			
    			insert(&temp_table, temp_variable);
    			
			struct tac* new_instruction = create_inst_tac($$->local, $1->local, "ADD", $3->local);
			append_inst_tac(&($3->code), new_instruction); 

			cat_tac(&($1->code), &($3->code));
			cat_tac(&($$->code), &($1->code));
		     }

    | expr '-' expr  {  Node* filho2 = create_node( @2.first_line, minus_node, $2, NULL, NULL);
    			$$ = create_node( @$.first_line, expr_node, NULL, $1, filho2, $3, NULL); 
    			
    			$$->local = new_temp(t_counter++);
    			
    			entry_t * temp_variable = new_variable ($$->local, int_node, INT_SIZE, temp_desloc, NULL);
    			
    			temp_desloc = temp_desloc + INT_SIZE;
    			
    			insert(&temp_table, temp_variable);			
			
			struct tac* new_instruction = create_inst_tac($$->local, $1->local, "SUB", $3->local);
			append_inst_tac(&($3->code), new_instruction); 

			cat_tac(&($1->code), &($3->code));
			cat_tac(&($$->code), &($1->code));
		     }

    | expr '*' expr  {  Node* filho2 = create_node( @2.first_line, mul_node, $2, NULL, NULL);
    			$$ = create_node( @$.first_line, expr_node, NULL, $1, filho2, $3, NULL); 

    			$$->local = new_temp(t_counter++);
    			
    			entry_t * temp_variable = new_variable ($$->local, int_node, INT_SIZE, temp_desloc, NULL);
    			
    			temp_desloc = temp_desloc + INT_SIZE;
    			
    			insert(&temp_table, temp_variable);			
			
			struct tac* new_instruction = create_inst_tac($$->local, $1->local, "MUL", $3->local);
			append_inst_tac(&($3->code), new_instruction); 

			cat_tac(&($1->code), &($3->code));
			cat_tac(&($$->code), &($1->code));
		     }

    | expr '/' expr  {  Node* filho2 = create_node( @2.first_line, div_node, $2, NULL, NULL);
    			$$ = create_node( @$.first_line, expr_node, NULL, $1, filho2, $3, NULL); 

    			$$->local = new_temp(t_counter++);
    			
    			entry_t * temp_variable = new_variable ($$->local, int_node, INT_SIZE, temp_desloc, NULL);
    			
    			temp_desloc = temp_desloc + INT_SIZE;
    			
    			insert(&temp_table, temp_variable);
    			
			struct tac* new_instruction = create_inst_tac($$->local, $1->local, "DIV", $3->local);
			append_inst_tac(&($3->code), new_instruction); 

			cat_tac(&($1->code), &($3->code));
			cat_tac(&($$->code), &($1->code));
		     }
		     
    | '(' expr ')'   {  
    			Node* filho1 = create_node( @1.first_line, leftbracket_node, $1, NULL, NULL);
			Node* filho3 = create_node( @3.first_line, rightbracket_node, $3, NULL, NULL);
			$$ = create_node( @$.first_line, expr_node, NULL, filho1, $2, filho3, NULL); 

			$$->local = $2->local;
			cat_tac(&($$->code), &($2->code));
		     }

    | INT_LIT        { 	
    			$$ = create_node(@$.first_line, int_lit_node, $1, NULL, NULL); 
  		       	$$->local = $1;
			$$->code = NULL; 
			}			

    | F_LIT          { $$ = create_node(@$.first_line, f_lit_node, $1, NULL, NULL); }

    | lvalue         {	
    			$$ = create_node(@$.first_line, expr_node, NULL, $1, NULL, NULL);
    			
    			
    			if ($1->array != NULL)
    			{
	    			char *temp = new_temp(t_counter++);
				entry_t *temp_variable = new_variable (temp, int_node, INT_SIZE, temp_desloc, NULL);    			
				temp_desloc = temp_desloc + INT_SIZE;
				insert(&temp_table, temp_variable);
	    						
				char *indirect_access = (char *) malloc(sizeof(char)*30);
				sprintf(indirect_access, "%s(%s)", $1->local, $1->array);
					
				struct tac *instruction1 = create_inst_tac(temp, indirect_access, "", "");
				append_inst_tac(&($1->code), instruction1);
				   						
				cat_tac(&($$->code), &($1->code));			
				$$->array = $1->array;			
				$$->local = temp;
			}
			
			else
			{
				$$->local = $1->local;
			}
		}

    | chamaproc      { $$ = $1; }
    ;

chamaproc: IDF '(' listaexpr ')'   {  
					Node* filho1 = create_node( @1.first_line, idf_node, $1, NULL, NULL);
					Node* filho2 = create_node( @2.first_line, leftbracket_node, $2, NULL, NULL);
					Node* filho4 = create_node( @4.first_line, rightbracket_node, $4, NULL, NULL);
					$$ = create_node( @$.first_line, chamaproc_node, NULL, filho1, filho2, $3, filho4, NULL);  
					}
         ;

enunciado: expr { $$ = $1 ;}

         | IF '(' expbool ')' THEN acoes fiminstcontrole    {   
         							Node* filho1 = create_node( @1.first_line, if_node, $1, NULL, NULL);
								Node* filho2 = create_node( @2.first_line, leftbracket_node, $2, NULL, NULL);
								Node* filho4 = create_node( @4.first_line, rightbracket_node, $4, NULL, NULL);
								Node* filho5 = create_node( @5.first_line, then_node, $5, NULL, NULL);
								$$ = create_node( @$.first_line, enunciado_node, NULL, filho1, filho2, $3, filho4, filho5, $6, $7, NULL);  
								cat_tac(&($$->code), &($6->code));
								cat_tac(&($$->code), &($7->code));
								}

	 | WHILE '(' expbool ')' '{' acoes '}'  {  	
	 						Node* filho1 = create_node( @1.first_line, while_node, $1, NULL, NULL);
						    	Node* filho2 = create_node( @2.first_line, leftbracket_node, $2, NULL, NULL);
 						    	Node* filho4 = create_node( @4.first_line, rightbracket_node, $4, NULL, NULL);
	 					    	Node* filho5 = create_node( @5.first_line, leftbracket2_node, $5, NULL, NULL);
 						    	Node* filho7 = create_node( @7.first_line, rightbracket2_node, $7, NULL, NULL);
						    	$$ = create_node( @$.first_line, enunciado_node, NULL, filho1, filho2, $3, filho4, filho5, $6, filho7, NULL);
						    	cat_tac(&($$->code), &($6->code));  
						 }
    	 
    	 | PRINTF '(' expr ')' {   	
    	 				Node* filho1 = create_node( @1.first_line, print_node, $1, NULL, NULL);
				  	Node* filho2 = create_node( @2.first_line, leftbracket_node, $2, NULL, NULL);
				  	Node* filho4 = create_node( @4.first_line, rightbracket_node, $4, NULL, NULL);

		    			$$ = create_node( @$.first_line, enunciado_node, NULL, filho1, filho2, $3, filho4, NULL);
					struct tac* new_instruction = create_inst_tac("PRINT", $3->local, "", "");
					append_inst_tac(&($3->code), new_instruction);
					cat_tac(&($$->code), &($3->code));
			  	}
 
         ;

fiminstcontrole: END  { $$ = create_node(@1.first_line, end_node, $1, NULL, NULL); } 
               
               | ELSE acoes END    {   
               				Node* filho1 = create_node( @1.first_line, else_node, $1, NULL, NULL);
					Node* filho3 = create_node( @3.first_line, end_node, $3, NULL, NULL);
    			    	      	$$ = create_node( @$.first_line, fiminstcontrole_node, NULL, filho1, $2, filho3, NULL);  
    			    	       	cat_tac(&($$->code), &($2->code));
    			    	   } 
               ;

expbool: TRUE   { $$ = create_node(@1.first_line, true_node, $1, NULL, NULL); } 

       | FALSE  { $$ = create_node(@1.first_line, false_node, $1, NULL, NULL); } 

       | '(' expbool ')'   {  Node* filho1 = create_node( @1.first_line, leftbracket_node, $1, NULL, NULL);
       			      Node* filho3 = create_node( @3.first_line, rightbracket_node, $3, NULL, NULL);  
    			      $$ = create_node( @$.first_line, expbool_node, NULL, filho1, $2, filho3, NULL); } 

       | expbool AND expbool       {   Node* filho2 = create_node( @2.first_line, and_node, $2, NULL, NULL);
				       $$ = create_node( @$.first_line, expbool_node, NULL, $1, filho2, $3, NULL);  }

       | expbool OR expbool        {   Node* filho2 = create_node( @2.first_line, or_node, $2, NULL, NULL);
				       $$ = create_node( @$.first_line, expbool_node, NULL, $1, filho2, $3, NULL);  }

       | NOT expbool               {   Node* filho1 = create_node( @1.first_line, not_node, $1, NULL, NULL);
    			    	       $$ = create_node( @$.first_line, expbool_node, NULL, filho1, $2, NULL);  }

       | expr '>' expr             {   Node* filho2 = create_node( @2.first_line, greater_node, $2, NULL, NULL);
				       $$ = create_node( @$.first_line, expbool_node, NULL, $1, filho2, $3, NULL);  } 

       | expr '<' expr		   {   Node* filho2 = create_node( @2.first_line, lower_node, $2, NULL, NULL);
				       $$ = create_node( @$.first_line, expbool_node, NULL, $1, filho2, $3, NULL);  } 

       | expr LE expr		   {   Node* filho2 = create_node( @2.first_line, le_node, $2, NULL, NULL);
				       $$ = create_node( @$.first_line, expbool_node, NULL, $1, filho2, $3, NULL);  }

       | expr GE expr		   {   Node* filho2 = create_node( @2.first_line, ge_node, $2, NULL, NULL);
				       $$ = create_node( @$.first_line, expbool_node, NULL, $1, filho2, $3, NULL);  }

       | expr EQ expr		   {   Node* filho2 = create_node( @2.first_line, eq_node, $2, NULL, NULL);
				       $$ = create_node( @$.first_line, expbool_node, NULL, $1, filho2, $3, NULL);  }

       | expr NE expr    	   {   Node* filho2 = create_node( @2.first_line, ne_node, $2, NULL, NULL);
				       $$ = create_node( @$.first_line, expbool_node, NULL, $1, filho2, $3, NULL);  }
       ;
%%
