%{
  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
  #include <stdio.h>
  #include <stdlib.h>
  #include "node.h"
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
code: declaracoes acoes { $$ = create_node( @$.first_line, code_node, NULL, $1, $2, NULL);  syntax_tree = $$; }
    | acoes 		{ $$ = $1; syntax_tree = $$; }
    ;

declaracoes: declaracao ';' {   Node *filho2 = create_node( @2.first_line, semicolon_node, $2, NULL, NULL);
    			    	$$ = create_node( @$.first_line, declaracoes_node, NULL, $1, filho2, NULL);  }
    			    	
           | declaracoes declaracao ';' {   Node* filho3 = create_node( @3.first_line, semicolon_node, $3, NULL, NULL);
    			    		    $$ = create_node( @1.first_line, declaracoes_node, NULL, $1, $2, filho3, NULL);  }
       	   ;

declaracao: tipo ':' listadeclaracao {   Node* filho2 = create_node( @2.first_line, colon_node, $2, NULL, NULL);
					 $$ = create_node( @$.first_line, declaracao_node, NULL, $1, filho2, $3, NULL);  }
	   ;

listadeclaracao: IDF    		   {   $$ = create_node(@1.first_line, idf_node, $1, NULL, NULL); }
               | IDF ',' listadeclaracao   {   Node* filho1 = create_node( @1.first_line, idf_node, $1, NULL, NULL);
					       Node* filho2 = create_node( @2.first_line, comma_node, $2, NULL, NULL);
					       $$ = create_node( @$.first_line, listadeclaracao_node, NULL, filho1, filho2, $3, NULL);  }
               ;

tipo: tipounico { $$ = $1; }
    | tipolista { $$ = $1; }
    ;

tipounico: INT      { $$ = create_node(@1.first_line, int_node, $1, NULL, NULL); } 
         | DOUBLE   { $$ = create_node(@1.first_line, double_node, $1, NULL, NULL); } 
         | REAL     { $$ = create_node(@1.first_line, real_node, $1, NULL, NULL); } 
         | CHAR     { $$ = create_node(@1.first_line, char_node, $1, NULL, NULL); } 
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
    			$$ = create_node( @$.first_line, acoes_node, NULL, $1, filho2, NULL);  }

     | comando ';' acoes   {  Node* filho2 = create_node( @2.first_line, semicolon_node, $2, NULL, NULL);
    			      $$ = create_node( @$.first_line, acoes_node, NULL, $1, filho2, $3, NULL); }
    ;

comando: lvalue '=' expr         {   Node* filho2 = create_node( @2.first_line, attr_node, $2, NULL, NULL);
				     $$ = create_node( @$.first_line, comando_node, NULL, $1, filho2, $3, NULL);  }
       | enunciado { $$ = $1; }
       ;

lvalue: IDF    			  { $$ = create_node(@1.first_line, idf_node, $1, NULL, NULL); } 

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
    			$$ = create_node( @$.first_line, expr_node, NULL, $1, filho2, $3, NULL); } 

    | expr '-' expr  {  Node* filho2 = create_node( @2.first_line, minus_node, $2, NULL, NULL);
    			$$ = create_node( @$.first_line, expr_node, NULL, $1, filho2, $3, NULL); }

    | expr '*' expr  {  Node* filho2 = create_node( @2.first_line, mul_node, $2, NULL, NULL);
    			$$ = create_node( @$.first_line, expr_node, NULL, $1, filho2, $3, NULL); } 

    | expr '/' expr  {  Node* filho2 = create_node( @2.first_line, div_node, $2, NULL, NULL);
    			$$ = create_node( @$.first_line, expr_node, NULL, $1, filho2, $3, NULL); } 

    | '(' expr ')'   {  Node* filho1 = create_node( @1.first_line, rightbracket_node, $1, NULL, NULL);
			Node* filho3 = create_node( @3.first_line, leftbracket_node, $3, NULL, NULL);
    			$$ = create_node( @$.first_line, expr_node, NULL, filho1, $2, filho3, NULL); }

    | INT_LIT        { $$ = create_node(@$.first_line, int_lit_node, $1, NULL, NULL); } 

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
