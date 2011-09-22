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
%token<no> INT
%token<no> DOUBLE
%token<no> REAL
%token<no> CHAR
%token<no> QUOTE
%token<no> LE
%token<no> GE
%token<no> EQ
%token<no> NE

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

%token<no> AND
%token<no> OR
%token<no> NOT
%token<no> IF
%token<no> THEN
%token<no> ELSE
%token<no> WHILE
%token<cadeia> INT_LIT
%token<cadeia> F_LIT
%token<no> END
%token<no> TRUE
%token<no> FALSE
%token<cadeia> STRING
%token<cadeia> CONST
%token<cadeia> STR_LIT
%token<no> FOR
%token<no> NEXT


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
code: declaracoes acoes {   Node* filho1 = create_node( @1.first_line, declaracoes_node, "declaracoes", $1, NULL);
    			    Node* filho2 = create_node( @1.first_line, acoes_node, "acoes", $2, NULL);
    			    $$ = create_node( @1.first_line, code_node, "codigo", filho1, filho2, NULL);  ;syntax_tree = $$; }
    | acoes 		{ $$ = $1; syntax_tree = $$; }
    ;

declaracoes: declaracao ';' {   Node* filho1 = create_node( @1.first_line, declaracao_node, "declaracao", $1, NULL);
				Node* filho2 = create_node( @1.first_line, semicolon_node, $2, NULL, NULL);
    			    	$$ = create_node( @1.first_line, declaracoes_node, "declaracoes", filho1, filho2, NULL);  }
           | declaracoes declaracao ';' {   Node* filho1 = create_node( @1.first_line, declaracoes_node, "declaracoes", $1, NULL);
					    Node* filho2 = create_node( @1.first_line, declaracao_node, "declaracao", $2, NULL);
    			    		    Node* filho3 = create_node( @1.first_line, semicolon_node, $3, NULL, NULL);
    			    		    $$ = create_node( @1.first_line, declaracoes_node, "declaracoes", filho1, filho2, filho3, NULL);  }
           ;

declaracao: tipo ':' listadeclaracao {   Node* filho1 = create_node( @1.first_line, tipo_node, "tipo", $1, NULL);
    			    		 Node* filho2 = create_node( @1.first_line, colon_node, $2, NULL, NULL);
					 Node* filho3 = create_node( @1.first_line, listadeclaracao_node, "listadeclaracao", $3, NULL);
    			    		 $$ = create_node( @1.first_line, declaracao_node, "declaracao", filho1, filho2, filho3, NULL);  }
	   ;

listadeclaracao: IDF /* { $$ = $1; } */   { $$ = create_node(@1.first_line, idf_node, $1, NULL, NULL); } 
               | IDF ',' listadeclaracao   {   Node* filho1 = create_node( @1.first_line, idf_node, $1, NULL, NULL);
						Node* filho2 = create_node( @1.first_line, comma_node, $2, NULL, NULL);
					       Node* filho3 = create_node( @1.first_line, listadeclaracao_node, "listadeclaracao", $3, NULL);
    			    		       $$ = create_node( @1.first_line, listadeclaracao_node, "listadeclaracao", filho1, filho2, filho3, NULL);  }
               ;

tipo: tipounico { $$ = $1; }
    | tipolista { $$ = $1; }
    ;

tipounico: INT      { $$ = $1; }
         | DOUBLE   { $$ = $1; }
         | REAL     { $$ = $1; }
         | CHAR     { $$ = $1; }
         ;

tipolista: INT '(' listadupla ')'     {  Node* filho1 = create_node( @1.first_line, int_node, "int", $1, NULL);
					Node* filho2 = create_node( @1.first_line, rightbracket_node, $2, NULL, NULL);
					 Node* filho3 = create_node( @1.first_line, listadupla_node, "listadupla", $3, NULL);
					Node* filho4 = create_node( @1.first_line, leftbracket_node, $4, NULL, NULL);
    			    		 $$ = create_node( @1.first_line, tipolista_node, "tipolista", filho1, filho2, filho3, filho4, NULL);  }
         | DOUBLE '(' listadupla ')'  {  Node* filho1 = create_node( @1.first_line, double_node, "double", $1, NULL);
					Node* filho2 = create_node( @1.first_line, rightbracket_node, $2, NULL, NULL);
					 Node* filho3 = create_node( @1.first_line, listadupla_node, "listadupla", $3, NULL);
					Node* filho4 = create_node( @1.first_line, leftbracket_node, $4, NULL, NULL);
    			    		 $$ = create_node( @1.first_line, tipolista_node, "tipolista", filho1, filho2, filho3, filho4, NULL);  }
         | REAL '(' listadupla ')'    {  Node* filho1 = create_node( @1.first_line, real_node, "real", $1, NULL);
					Node* filho2 = create_node( @1.first_line, rightbracket_node, $2, NULL, NULL);
					 Node* filho3 = create_node( @1.first_line, listadupla_node, "listadupla", $3, NULL);
					Node* filho4 = create_node( @1.first_line, leftbracket_node, $4, NULL, NULL);
    			    		 $$ = create_node( @1.first_line, tipolista_node, "tipolista", filho1, filho2, filho3, filho4, NULL);  }
         | CHAR '(' listadupla ')'    {  Node* filho1 = create_node( @1.first_line, char_node, "char", $1, NULL);
					Node* filho2 = create_node( @1.first_line, rightbracket_node, $2, NULL, NULL);
					 Node* filho3 = create_node( @1.first_line, listadupla_node, "listadupla", $3, NULL);
					Node* filho4 = create_node( @1.first_line, leftbracket_node, $4, NULL, NULL);
    			    		 $$ = create_node( @1.first_line, tipolista_node, "tipolista", filho1, filho2, filho3, filho4, NULL);  }
         ;

listadupla: INT_LIT ':' INT_LIT		{  Node* filho1 = create_node( @1.first_line, int_lit_node, $1, NULL, NULL);
						Node* filho2 = create_node( @1.first_line, colon_node, $2, NULL, NULL);
					   Node* filho3 = create_node( @1.first_line, int_lit_node, $3, NULL, NULL);
    			    		   $$ = create_node( @1.first_line, listadupla_node, "listadupla", filho1, filho2, filho3, NULL);  }
          | INT_LIT ':' INT_LIT ',' listadupla	{  Node* filho1 = create_node( @1.first_line, int_lit_node, $1, NULL, NULL);
						Node* filho2 = create_node( @1.first_line, colon_node, $2, NULL, NULL);
					           Node* filho3 = create_node( @1.first_line, int_lit_node, $3, NULL, NULL);
						Node* filho4 = create_node( @1.first_line, comma_node, $4, NULL, NULL);
						   Node* filho5 = create_node( @1.first_line, listadupla_node, "listadupla", $5, NULL);
    			    		    $$ = create_node( @1.first_line, listadupla_node, "listadupla", filho1, filho2, filho3, filho4, filho5, NULL);  }
          ;

acoes: comando ';'  {   Node* filho1 = create_node( @1.first_line, comando_node, "comando", $1, NULL);
			Node* filho2 = create_node( @1.first_line, semicolon_node, $2, NULL, NULL);
    			$$ = create_node( @1.first_line, acoes_node, "acoes", filho1, filho2, NULL);  }
     | comando ';' acoes   {  Node* filho1 = create_node( @1.first_line, comando_node, "comando", $1, NULL);
				Node* filho2 = create_node( @1.first_line, semicolon_node, $2, NULL, NULL);
    			      Node* filho3 = create_node( @1.first_line, acoes_node, "acoes", $3, NULL);
    			      $$ = create_node( @1.first_line, acoes_node, "acoes", filho1, filho2, filho3, NULL); }
    ;

comando: lvalue '=' expr         {   Node* filho1 = create_node( @1.first_line, lvalue_node, "lvalue", $1, NULL);
				Node* filho2 = create_node( @1.first_line, attr_node, $2, NULL, NULL);
				     Node* filho3 = create_node( @1.first_line, expr_node, "expr", $3, NULL);
    			    	     $$ = create_node( @1.first_line, comando_node, "comando", filho1, filho2, filho3, NULL);  }
       | enunciado { $$ = $1; }
       ;

lvalue: IDF  /* { $$ = $1; } */   { $$ = create_node(@1.first_line, idf_node, $1, NULL, NULL); } 
      | IDF '[' listaexpr ']'     {  Node* filho1 = create_node( @1.first_line, idf_node, $1, NULL, NULL);
					Node* filho2 = create_node( @1.first_line, rightbracket3_node, $2, NULL, NULL);
				     Node* filho3 = create_node( @1.first_line, listaexpr_node, "listaexpr", $3, NULL);
				Node* filho4 = create_node( @1.first_line, leftbracket3_node, $4, NULL, NULL);
    			    	     $$ = create_node( @1.first_line, lvalue_node, "lvalue", filho1, filho2, filho3, filho4, NULL);  }
      ;

listaexpr: expr   { $$ = $1; }    
	   | expr ',' listaexpr   {  Node* filho1 = create_node( @1.first_line, expr_node, "expr", $1, NULL);
					Node* filho2 = create_node( @1.first_line, comma_node, $2, NULL, NULL);
				     Node* filho3 = create_node( @1.first_line, listaexpr_node, "listaexpr", $3, NULL);
    			    	     $$ = create_node( @1.first_line, listaexpr_node, "listaexpr", filho1, filho2, filho3, NULL);  }
	   ;

expr: expr '+' expr  {  Node* filho1 = create_node( @1.first_line, expr_node, "expr", $1, NULL);
			Node* filho2 = create_node( @1.first_line, plus_node, $2, NULL, NULL);
    			Node* filho3 = create_node( @1.first_line, expr_node, "expr", $3, NULL);  
    			$$ = create_node( @1.first_line, expr_node, "expr", filho1, filho2, filho3, NULL); } 
    | expr '-' expr  {  Node* filho1 = create_node( @1.first_line, expr_node, "expr", $1, NULL);
			Node* filho2 = create_node( @1.first_line, minus_node, $2, NULL, NULL);
    			Node* filho3 = create_node( @1.first_line, expr_node, "expr", $3, NULL);
    			$$ = create_node( @1.first_line, expr_node, "expr", filho1, filho2, filho3, NULL); }
    | expr '*' expr  {  Node* filho1 = create_node( @1.first_line, expr_node, "expr", $1, NULL);
			Node* filho2 = create_node( @1.first_line, mul_node, $2, NULL, NULL);
    			Node* filho3 = create_node( @1.first_line, expr_node, "expr", $3, NULL);
    			$$ = create_node( @1.first_line, expr_node, "expr", filho1, filho2, filho3, NULL); } 
    | expr '/' expr  {  Node* filho1 = create_node( @1.first_line, expr_node, "expr", $1, NULL);
			Node* filho2 = create_node( @1.first_line, div_node, $2, NULL, NULL);
    			Node* filho3 = create_node( @1.first_line, expr_node, "expr", $3, NULL);
    			$$ = create_node( @1.first_line, expr_node, "expr", filho1, filho2, filho3, NULL); } 
    | '(' expr ')'   {  Node* filho1 = create_node( @1.first_line, rightbracket_node, $1, NULL, NULL);
			Node* filho2 = create_node( @1.first_line, expr_node, "expr", $2, NULL);
    			Node* filho3 = create_node( @1.first_line, leftbracket_node, $3, NULL, NULL);  
    			$$ = create_node( @1.first_line, expr_node, "expr", filho1, filho2, filho3, NULL); } 
    | INT_LIT        { $$ = create_node(@1.first_line, int_lit_node, $1, NULL, NULL); } 
    | F_LIT          { $$ = create_node(@1.first_line, f_lit_node, $1, NULL, NULL); } 
    | lvalue         { $$ = $1; }
    | chamaproc      { $$ = $1; }
    ;

chamaproc: IDF '(' listaexpr ')'   {  Node* filho1 = create_node( @1.first_line, idf_node, $1, NULL, NULL);
					Node* filho2 = create_node( @1.first_line, rightbracket_node, $2, NULL, NULL);
				      Node* filho3 = create_node( @1.first_line, listaexpr_node, "listaexpr", $3, NULL);
					Node* filho4 = create_node( @1.first_line, leftbracket_node, $4, NULL, NULL);
    			    	      $$ = create_node( @1.first_line, chamaproc_node, "chamaproc", filho1, filho2, filho3, filho4, NULL);  }
         ;

enunciado: expr { $$ = $1 ;}
         | IF '(' expbool ')' THEN acoes fiminstcontrole    {   Node* filho1 = create_node( @1.first_line, if_node, "if", $1, NULL);
								Node* filho2 = create_node( @1.first_line, rightbracket_node, $2, NULL, NULL);
								Node* filho3 = create_node( @1.first_line, expbool_node, "expbool", $3, NULL);
								Node* filho4 = create_node( @1.first_line, leftbracket_node, $4, NULL, NULL);
								Node* filho5 = create_node( @1.first_line, then_node, "then", $5, NULL);
				      				Node* filho6 = create_node( @1.first_line, acoes_node, "acoes", $6, NULL);
								Node* filho7 = create_node( @1.first_line, fiminstcontrole_node, "fiminstcontrole", $7, NULL);
    			  $$ = create_node( @1.first_line, enunciado_node, "enunciado", filho1, filho2, filho3, filho4, filho5, filho6, filho7, NULL);  }
         | WHILE '(' expbool ')' '{' acoes '}'  {   Node* filho1 = create_node( @1.first_line, while_node, "while", $1, NULL);
							Node* filho2 = create_node( @1.first_line, rightbracket_node, $2, NULL, NULL);
						    Node* filho3 = create_node( @1.first_line, expbool_node, "expbool", $3, NULL);
							Node* filho4 = create_node( @1.first_line, leftbracket_node, $4, NULL, NULL);
							Node* filho5 = create_node( @1.first_line, rightbracket2_node, $5, NULL, NULL);
						    Node* filho6 = create_node( @1.first_line, acoes_node, "acoes", $6, NULL);
							Node* filho7 = create_node( @1.first_line, leftbracket2_node, $7, NULL, NULL);
    	 $$ = create_node( @1.first_line, enunciado_node, "enunciado", filho1, filho2, filho3, filho4, filho5, filho6, filho7, NULL);  } 
         ;

fiminstcontrole: END  { $$ = $1 ;}
               | ELSE acoes END    {   Node* filho1 = create_node( @1.first_line, else_node, "else", $1, NULL);
				       Node* filho2 = create_node( @1.first_line, acoes_node, "acoes", $2, NULL);
				       Node* filho3 = create_node( @1.first_line, end_node, "end", $3, NULL);
    			    	       $$ = create_node( @1.first_line, fiminstcontrole_node, "fiminstcontrole", filho1, filho2, filho3, NULL);  } 
               ;

expbool: TRUE   { $$ = $1 ;}
       | FALSE  { $$ = $1 ;}
       | '(' expbool ')'   {  Node* filho1 = create_node( @1.first_line, rightbracket_node, $1, NULL, NULL);
			Node* filho2 = create_node( @1.first_line, expbool_node, "expbool", $2, NULL);
    			Node* filho3 = create_node( @1.first_line, leftbracket_node, $3, NULL, NULL);  
    			$$ = create_node( @1.first_line, expbool_node, "expbool", filho1, filho2, filho3, NULL); } 
       | expbool AND expbool       {   Node* filho1 = create_node( @1.first_line, expbool_node, "expbool", $1, NULL);
				       Node* filho2 = create_node( @1.first_line, and_node, "and", $2, NULL);
				       Node* filho3 = create_node( @1.first_line, expbool_node, "expbool", $3, NULL);
    			    	       $$ = create_node( @1.first_line, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       | expbool OR expbool        {   Node* filho1 = create_node( @1.first_line, expbool_node, "expbool", $1, NULL);
				       Node* filho2 = create_node( @1.first_line, or_node, "and", $2, NULL);
				       Node* filho3 = create_node( @1.first_line, expbool_node, "expbool", $3, NULL);
    			    	       $$ = create_node( @1.first_line, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       | NOT expbool               {   Node* filho1 = create_node( @1.first_line, not_node, "not", $1, NULL);
				       Node* filho2 = create_node( @1.first_line, expbool_node, "expbool", $2, NULL);
    			    	       $$ = create_node( @1.first_line, expbool_node, "expbool", filho1, filho2, NULL);  }
       | expr '>' expr             {   Node* filho1 = create_node( @1.first_line, expr_node, "expr", $1, NULL);
				       Node* filho2 = create_node( @1.first_line, greater_node, $2, NULL, NULL);
				       Node* filho3 = create_node( @1.first_line, expr_node, "expr", $3, NULL);
				       $$ = create_node( @1.first_line, expbool_node, "expbool", filho1, filho2, filho3, NULL);  } 
       | expr '<' expr		   {   Node* filho1 = create_node( @1.first_line, expr_node, "expr", $1, NULL);
				       Node* filho2 = create_node( @1.first_line, lower_node, $2, NULL, NULL);
				       Node* filho3 = create_node( @1.first_line, expr_node, "expr", $3, NULL);
				       $$ = create_node( @1.first_line, expbool_node, "expbool", filho1, filho2, filho3, NULL);  } 
       | expr LE expr		   {   Node* filho1 = create_node( @1.first_line, expr_node, "expr", $1, NULL);
				       Node* filho2 = create_node( @1.first_line, le_node, "le", $2, NULL);
				       Node* filho3 = create_node( @1.first_line, expr_node, "expr", $3, NULL);
				       $$ = create_node( @1.first_line, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       | expr GE expr		   {   Node* filho1 = create_node( @1.first_line, expr_node, "expr", $1, NULL);
				       Node* filho2 = create_node( @1.first_line, ge_node, "ge", $2, NULL);
				       Node* filho3 = create_node( @1.first_line, expr_node, "expr", $3, NULL);
				       $$ = create_node( @1.first_line, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       | expr EQ expr		   {   Node* filho1 = create_node( @1.first_line, expr_node, "expr", $1, NULL);
				       Node* filho2 = create_node( @1.first_line, eq_node, "eq", $2, NULL);
				       Node* filho3 = create_node( @1.first_line, expr_node, "expr", $3, NULL);
				       $$ = create_node( @1.first_line, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       | expr NE expr    	   {   Node* filho1 = create_node( @1.first_line, expr_node, "expr", $1, NULL);
				       Node* filho2 = create_node( @1.first_line, ne_node, "ne", $2, NULL);
				       Node* filho3 = create_node( @1.first_line, expr_node, "expr", $3, NULL);
				       $$ = create_node( @1.first_line, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       ;
%%
 /* A partir daqui, insere-se qlqer codigo C necessario.
  */
//uncompile("arq", &syntax_tree);


