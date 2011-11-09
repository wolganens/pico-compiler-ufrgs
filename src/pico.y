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

  int desloc = 0;

  int t_counter = 0;
  int l_counter = 0;
  
  symbol_t symbol_table;
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

%type<no> inicio
%type<no> inicializa

%start inicio

 /* A completar com seus tokens - compilar com 'yacc -d' */

%%
inicio: inicializa code 	{  $$ = $2; 
				/*FILE * out;
				out = fopen ("teste.txt","a+");
				print_tac(out, $$->code);
				//print_tac(out, NULL);
				fclose(out);*/
				}
	;

inicializa:          	{
			//FUNÇÕES DE TESTE DA LISTA.C

			/*struct node_tac * teste = (struct node_tac *)malloc(sizeof(struct node_tac));
			teste->inst = create_inst_tac("res", "arg1", "op", "arg2");
			struct node_tac * teste2 = (struct node_tac *)malloc(sizeof(struct node_tac));
			teste2->inst = create_inst_tac("res'", "arg1'", "op'", "arg2'");

			//append_inst_tac(&teste, teste2->inst); //NAO SEI EXATAMENTE PARA QUE SERVE, ATÉ AGORA ELA INSERE INST NO FINAL DA LISTA DO 1º ARGUMENTO.
			cat_tac(&teste, &teste2);		

			FILE * out;
			out = fopen ("teste.txt","a+");
			//print_tac(out, syntax_tree->code);
			print_tac(out, teste);
			fclose(out);*/
			

			init_table(&symbol_table); 
			}   
	;

code: declaracoes acoes		 { $$ = create_node( @$.first_line, code_node, NULL, $1, $2, NULL);  syntax_tree = $$; }
    | acoes			 { $$ = $1; syntax_tree = $$; }
    ;

declaracoes: declaracao ';' {   Node *filho2 = create_node( @2.first_line, semicolon_node, $2, NULL, NULL);
    			    	$$ = create_node( @$.first_line, declaracoes_node, NULL, $1, filho2, NULL);  }
    			    	
           | declaracoes declaracao ';' {   Node* filho3 = create_node( @3.first_line, semicolon_node, $3, NULL, NULL);
    			    		    $$ = create_node( @1.first_line, declaracoes_node, NULL, $1, $2, filho3, NULL);  }
       	   ;

declaracao: tipo ':' listadeclaracao {   Node* filho2 = create_node( @2.first_line, colon_node, $2, NULL, NULL);
					 $$ = create_node( @$.first_line, declaracao_node, NULL, $1, filho2, $3, NULL);  
				     }
	   ;

listadeclaracao: IDF	{  $$ = create_node(@1.first_line, idf_node, $1, NULL, NULL);
			   
			   $$->type = $<no>-1->type;
			   $$->size = $<no>-1->size;
			   $$->desloc = $<no>-1->desloc;
			   
			   entry_t *variable = (entry_t *) malloc (sizeof(entry_t));
			   variable->name = $$->lexeme;
			   variable->type = $$->type;
			   variable->size = $$->size;
			   variable->desloc = desloc;
			   desloc = desloc + $$->size;

			   printf("%03d: lexema:%s. tamanho:%d. desloc:%d.\n", $$->num_line, $$->lexeme, $$->size, desloc);

			   if(insert(&symbol_table, variable))
			   {
				printf("Error (%d). The variable %s was redeclared.\n", $$->num_line, $$->lexeme);
				exit(1);
			   }	
			
				/*FILE * out;
				out = fopen ("teste.txt","a+");
				print_tac(out, $$->code);
				//print_tac(out, NULL);
				fclose(out); */

				   
			}			 

               | IDF ',' listadeclaracao   {   Node* filho1 = create_node( @1.first_line, idf_node, $1, NULL, NULL);
					       Node* filho2 = create_node( @2.first_line, comma_node, $2, NULL, NULL);
					       $$ = create_node( @$.first_line, listadeclaracao_node, NULL, filho1, filho2, $3, NULL);
					       
					       $$->type = $<no>-1->type;
					       $$->size = $<no>-1->size;
					       $$->desloc = $<no>-1->desloc;
					   
					       entry_t *variable = (entry_t *) malloc (sizeof(entry_t));
					       variable->name = $$->lexeme;
					       variable->type = $$->type;
					       variable->size = $$->size;
					       variable->desloc = desloc;
					       desloc = desloc + $$->size;

						printf("%03d: lexema:%s. tamanho:%d. desloc:%d.\n", $$->num_line, $$->lexeme, $$->size, desloc);
					   
					       if(insert(&symbol_table, variable))
					       {
					   	   printf("Error (%d). The variable %s was redeclared.\n", $$->num_line, $$->lexeme);
						   exit(1);
					       }	
			   		   }
               ;

tipo: tipounico { $$ = $1; }
    | tipolista { $$ = $1; }
    ;

tipounico: INT      { $$ = create_node(@1.first_line, int_node, $1, NULL, NULL);
		      $$->type = int_node;
	              $$->size = INT_SIZE; }

         | DOUBLE   { $$ = create_node(@1.first_line, double_node, $1, NULL, NULL);
		      $$->type = double_node;
		      $$->size = DOUBLE_SIZE; } 

         | REAL     { $$ = create_node(@1.first_line, real_node, $1, NULL, NULL);
		      $$->type = real_node;
		      $$->size = REAL_SIZE; } 

         | CHAR     { $$ = create_node(@1.first_line, char_node, $1, NULL, NULL);
		      $$->type = char_node;
		      $$->size = CHAR_SIZE; } 
         ;

tipolista: INT '(' listadupla ')'     {  Node* filho1 = create_node( @1.first_line, int_node, $1, NULL, NULL);
					 Node* filho2 = create_node( @2.first_line, rightbracket_node, $2, NULL, NULL);
					 Node* filho4 = create_node( @4.first_line, leftbracket_node, $4, NULL, NULL);
    			    		 $$ = create_node( @$.first_line, tipolista_node, NULL, filho1, filho2, $3, filho4, NULL);  }

         | DOUBLE '(' listadupla ')'  {  Node* filho1 = create_node( @1.first_line, double_node, $1, NULL, NULL);
					 Node* filho2 = create_node( @2.first_line, rightbracket_node, $2, NULL, NULL);
					 Node* filho4 = create_node( @4.first_line, leftbracket_node, $4, NULL, NULL);
    			    		 $$ = create_node( @$.first_line, tipolista_node, NULL, filho1, filho2, $3, filho4, NULL);  }

         | REAL '(' listadupla ')'    {  Node* filho1 = create_node( @1.first_line, real_node, $1, NULL, NULL);
					 Node* filho2 = create_node( @2.first_line, rightbracket_node, $2, NULL, NULL);
					 Node* filho4 = create_node( @4.first_line, leftbracket_node, $4, NULL, NULL);
    			    		 $$ = create_node( @$.first_line, tipolista_node, NULL, filho1, filho2, $3, filho4, NULL);  }

         | CHAR '(' listadupla ')'    {  Node* filho1 = create_node( @1.first_line, char_node, $1, NULL, NULL);
					 Node* filho2 = create_node( @2.first_line, rightbracket_node, $2, NULL, NULL);
					 Node* filho4 = create_node( @4.first_line, leftbracket_node, $4, NULL, NULL);
    			    		 $$ = create_node( @$.first_line, tipolista_node, NULL, filho1, filho2, $3, filho4, NULL);  }
         ;

listadupla: INT_LIT ':' INT_LIT		{  Node* filho1 = create_node( @1.first_line, int_lit_node, $1, NULL, NULL);
					   Node* filho2 = create_node( @2.first_line, colon_node, $2, NULL, NULL);
					   Node* filho3 = create_node( @3.first_line, int_lit_node, $3, NULL, NULL);
    			    		   $$ = create_node( @$.first_line, listadupla_node, NULL, filho1, filho2, filho3, NULL);  }

          | INT_LIT ':' INT_LIT ',' listadupla	{  Node* filho1 = create_node( @1.first_line, int_lit_node, $1, NULL, NULL);
						   Node* filho2 = create_node( @2.first_line, colon_node, $2, NULL, NULL);
					           Node* filho3 = create_node( @3.first_line, int_lit_node, $3, NULL, NULL);
						   Node* filho4 = create_node( @4.first_line, comma_node, $4, NULL, NULL);
    			    		           $$ = create_node( @$.first_line, listadupla_node, NULL, filho1, filho2, filho3, filho4, $5, NULL);  }
          ;

acoes: comando ';'  {	Node* filho2 = create_node( @2.first_line, semicolon_node, $2, NULL, NULL);
    			$$ = create_node( @$.first_line, acoes_node, NULL, $1, filho2, NULL);
 
			//cat_tac(&($$->code), &($1->code));

			/*FILE * out;
			out = fopen ("teste.txt","a+");
			print_tac(out, $$->code);
			//print_tac(out, NULL);
			fclose(out);*/

		    }

     | comando ';' acoes   {  Node* filho2 = create_node( @2.first_line, semicolon_node, $2, NULL, NULL);
    			      $$ = create_node( @$.first_line, acoes_node, NULL, $1, filho2, $3, NULL); 

				//cat_tac(&($1->code), &($3->code));
				//cat_tac(&($$->code), &($1->code));

				/*FILE * out;
				out = fopen ("teste.txt","a+");
				print_tac(out, $$->code);
				//print_tac(out, NULL);
				fclose(out);*/


		    	   }
    ;

comando: lvalue '=' expr {   Node* filho2 = create_node( @2.first_line, attr_node, $2, NULL, NULL);
			     $$ = create_node( @$.first_line, comando_node, NULL, $1, filho2, $3, NULL);
			      
			     struct tac* new_instruction = create_inst_tac($1->local, $3->local, "=", NULL);
			     append_inst_tac(&($3->code), new_instruction);
			
			     cat_tac(&($$->code), &($3->code));
			
				/*cat_tac(&($1->code), &($3->code));
				cat_tac(&($$->code), &($1->code)); */

			FILE * out;
			out = fopen ("teste.txt","a+");
			print_tac(out, $$->code);
			//print_tac(out, NULL);
			fclose(out);


			 }
       | enunciado { $$ = $1; }
       ;

lvalue: IDF { 	$$ = create_node(@1.first_line, idf_node, $1, NULL, NULL);
		
		entry_t * variable;
		
		if ((variable = lookup(symbol_table, $$->lexeme)) == NULL)
		{
			printf("Error (%d). The variable %s was not declared.\n", $$->num_line, $$->lexeme);
			exit(1);
		}
		
		$$->local = variable->name;
		$$->code = NULL;

		$$->type = variable->type;
		$$->size = variable->size;
		$$->desloc = variable->desloc;
	    }

			  		/*print_table(symbol_table);	//TESTANDO TABELA HASH
			  		entry_t *search;
			  		search = lookup(symbol_table, "variavel1");
			  		printf("Nome: %s\n\n", search->name);
					*/
				   	//} 

      | IDF '[' listaexpr ']'     {  Node* filho1 = create_node( @1.first_line, idf_node, $1, NULL, NULL);
			             Node* filho2 = create_node( @2.first_line, rightbracket3_node, $2, NULL, NULL);
				     Node* filho4 = create_node( @4.first_line, leftbracket3_node, $4, NULL, NULL);
    			    	     $$ = create_node( @$.first_line, lvalue_node, NULL, filho1, filho2, $3, filho4, NULL);  }
      ;

listaexpr: expr   { $$ = $1; }    
	 | expr ',' listaexpr   {    Node* filho2 = create_node( @1.first_line, comma_node, $2, NULL, NULL);
				     $$ = create_node( @$.first_line, listaexpr_node, NULL, $1, filho2, $3, NULL);  }
	   ;

expr: expr '+' expr  {  Node* filho2 = create_node( @2.first_line, plus_node, $2, NULL, NULL);
    			$$ = create_node( @$.first_line, expr_node, NULL, $1, filho2, $3, NULL); 

    			$$->local = new_temp(t_counter++);

			struct tac* new_instruction = create_inst_tac($$->local, $1->local, "ADD", $3->local);
			append_inst_tac(&($3->code), new_instruction); 

			cat_tac(&($1->code), &($3->code));
			cat_tac(&($$->code), &($1->code));	
			
			/*FILE * out;
			out = fopen ("teste.txt","a+");
			print_tac(out, $$->code);
			//print_tac(out, NULL);
			fclose(out); */		
		     }

    | expr '-' expr  {  Node* filho2 = create_node( @2.first_line, minus_node, $2, NULL, NULL);
    			$$ = create_node( @$.first_line, expr_node, NULL, $1, filho2, $3, NULL); 
    			
    			$$->local = new_temp(t_counter++);
			
			struct tac* new_instruction = create_inst_tac($$->local, $1->local, "SUB", $3->local);
			append_inst_tac(&($3->code), new_instruction); 

			cat_tac(&($1->code), &($3->code));
			cat_tac(&($$->code), &($1->code));
		     }

    | expr '*' expr  {  Node* filho2 = create_node( @2.first_line, mul_node, $2, NULL, NULL);
    			$$ = create_node( @$.first_line, expr_node, NULL, $1, filho2, $3, NULL); 
    			$$->local = new_temp(t_counter++);
			
			struct tac* new_instruction = create_inst_tac($$->local, $1->local, "MUL", $3->local);
			append_inst_tac(&($3->code), new_instruction); 

			cat_tac(&($1->code), &($3->code));
			cat_tac(&($$->code), &($1->code));
		     }

    | expr '/' expr  {  Node* filho2 = create_node( @2.first_line, div_node, $2, NULL, NULL);
    			$$ = create_node( @$.first_line, expr_node, NULL, $1, filho2, $3, NULL); 
    			$$->local = new_temp(t_counter++);
			
			struct tac* new_instruction = create_inst_tac($$->local, $1->local, "DIV", $3->local);
			append_inst_tac(&($3->code), new_instruction); 

			cat_tac(&($1->code), &($3->code));
			cat_tac(&($$->code), &($1->code));
		     }
		     
    | '(' expr ')'   {  Node* filho1 = create_node( @1.first_line, rightbracket_node, $1, NULL, NULL);
			Node* filho3 = create_node( @3.first_line, leftbracket_node, $3, NULL, NULL);
    			$$ = create_node( @$.first_line, expr_node, NULL, filho1, $2, filho3, NULL); 

			$$->local = $2->local;
		        $$->code = $2->code;
			
		     }

    | INT_LIT        { $$ = create_node(@$.first_line, int_lit_node, $1, NULL, NULL); 
  		       $$->local = $1;
		       $$->code = NULL; }			

    | F_LIT          { $$ = create_node(@$.first_line, f_lit_node, $1, NULL, NULL); }

    | lvalue         { $$ = $1; }

    | chamaproc      { $$ = $1; }
    ;

chamaproc: IDF '(' listaexpr ')'   {  Node* filho1 = create_node( @1.first_line, idf_node, $1, NULL, NULL);
				      Node* filho2 = create_node( @2.first_line, rightbracket_node, $2, NULL, NULL);
				      Node* filho4 = create_node( @4.first_line, leftbracket_node, $4, NULL, NULL);
    			    	      $$ = create_node( @$.first_line, chamaproc_node, NULL, filho1, filho2, $3, filho4, NULL);  }
         ;

enunciado: expr { $$ = $1 ;}
         | IF '(' expbool ')' THEN acoes fiminstcontrole    {   Node* filho1 = create_node( @1.first_line, if_node, $1, NULL, NULL);
								Node* filho2 = create_node( @2.first_line, rightbracket_node, $2, NULL, NULL);
								Node* filho4 = create_node( @4.first_line, leftbracket_node, $4, NULL, NULL);
								Node* filho5 = create_node( @5.first_line, then_node, $5, NULL, NULL);
    			  $$ = create_node( @$.first_line, enunciado_node, NULL, filho1, filho2, $3, filho4, filho5, $6, $7, NULL);  }

         | WHILE '(' expbool ')' '{' acoes '}'  {   Node* filho1 = create_node( @1.first_line, while_node, $1, NULL, NULL);
						    Node* filho2 = create_node( @2.first_line, rightbracket_node, $2, NULL, NULL);
 						    Node* filho4 = create_node( @4.first_line, leftbracket_node, $4, NULL, NULL);
         					    Node* filho5 = create_node( @5.first_line, rightbracket2_node, $5, NULL, NULL);
 						    Node* filho7 = create_node( @7.first_line, leftbracket2_node, $7, NULL, NULL);
    	 $$ = create_node( @$.first_line, enunciado_node, NULL, filho1, filho2, $3, filho4, filho5, $6, filho7, NULL);  }
    	 
    	 | PRINTF '(' expr ')' {   Node* filho1 = create_node( @1.first_line, print_node, $1, NULL, NULL);
				   Node* filho2 = create_node( @2.first_line, rightbracket_node, $2, NULL, NULL);
				   Node* filho4 = create_node( @4.first_line, leftbracket_node, $4, NULL, NULL);
    			$$ = create_node( @$.first_line, enunciado_node, NULL, filho1, filho2, $3, filho4, NULL);  }
 
         ;

fiminstcontrole: END  { $$ = create_node(@1.first_line, end_node, $1, NULL, NULL); } 
               | ELSE acoes END    {   Node* filho1 = create_node( @1.first_line, else_node, $1, NULL, NULL);
				       Node* filho3 = create_node( @3.first_line, end_node, $3, NULL, NULL);
    			    	       $$ = create_node( @$.first_line, fiminstcontrole_node, NULL, filho1, $2, filho3, NULL);  } 
               ;

expbool: TRUE   { $$ = create_node(@1.first_line, true_node, $1, NULL, NULL); } 

       | FALSE  { $$ = create_node(@1.first_line, false_node, $1, NULL, NULL); } 

       | '(' expbool ')'   {  Node* filho1 = create_node( @1.first_line, rightbracket_node, $1, NULL, NULL);
       			      Node* filho3 = create_node( @3.first_line, leftbracket_node, $3, NULL, NULL);  
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
