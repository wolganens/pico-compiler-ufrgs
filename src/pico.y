%{
  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
  #include <stdio.h>
  #include <stdlib.h>
  #include "node.h"

%}

%union {
  char* cadeia;
  struct _node * no;
}


%token IDF
%token INT
%token DOUBLE
%token REAL
%token CHAR
%token QUOTE
%token LE
%token GE
%token EQ
%token NE
%token AND
%token OR
%token NOT
%token IF
%token THEN
%token ELSE
%token WHILE
%token<cadeia> INT_LIT
%token F_LIT
%token END
%token TRUE
%token FALSE
%token STRING
%token CONST
%token STR_LIT
%token FOR
%token NEXT


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
code: declaracoes acoes {   Node* filho1 = create_node( 0, declaracoes_node, "declaracoes", $1, NULL);
    			    Node* filho2 = create_node( 0, acoes_node, "acoes", $2, NULL);
    			    $$ = create_node( 0, code_node, "codigo", filho1, filho2, NULL);  ;syntax_tree = $$; }
    | acoes 		{ $$ = $1; syntax_tree = $$; }
    ;

declaracoes: declaracao ';' { $$ = $1; }
           | declaracoes declaracao ';' {   Node* filho1 = create_node( 0, declaracoes_node, "declaracoes", $1, NULL);
					    Node* filho2 = create_node( 0, declaracao_node, "declaracao", $2, NULL);
    			    		   // Node* filho3 = create_node( 0, semicolon_node, yytext, $3, NULL);
    			    		    $$ = create_node( 0, declaracoes_node, "declaracoes", filho1, filho2, NULL);  }
           ;

declaracao: tipo ':' listadeclaracao {   Node* filho1 = create_node( 0, tipo_node, "tipo", $1, NULL);
    			    		// Node* filho2 = create_node( 0, colon_node, yytext, $2, NULL);
					 Node* filho2 = create_node( 0, listadeclaracao_node, "listadeclaracao", $3, NULL);
    			    		 $$ = create_node( 0, declaracao_node, "declaracao", filho1, filho2, NULL);  }
	   ;

listadeclaracao: IDF  { $$ = $1; }
               | IDF ',' listadeclaracao   {   Node* filho1 = create_node( 0, idf_node, "idf", $1, NULL);
					       Node* filho2 = create_node( 0, listadeclaracao_node, "listadeclaracao", $3, NULL);
    			    		       $$ = create_node( 0, listadeclaracao_node, "listadeclaracao", filho1, filho2, NULL);  }
               ;

tipo: tipounico { $$ = $1; }
    | tipolista { $$ = $1; }
    ;

tipounico: INT      { $$ = $1; }
         | DOUBLE   { $$ = $1; }
         | REAL     { $$ = $1; }
         | CHAR     { $$ = $1; }
         ;

tipolista: INT '(' listadupla ')'     {  Node* filho1 = create_node( 0, int_node, "int", $1, NULL);
					 Node* filho2 = create_node( 0, listadupla_node, "listadupla", $3, NULL);
    			    		 $$ = create_node( 0, tipolista_node, "tipolista", filho1, filho2, NULL);  }
         | DOUBLE '(' listadupla ')'  {  Node* filho1 = create_node( 0, double_node, "double", $1, NULL);
					 Node* filho2 = create_node( 0, listadupla_node, "listadupla", $3, NULL);
    			    		 $$ = create_node( 0, tipolista_node, "tipolista", filho1, filho2, NULL);  }
         | REAL '(' listadupla ')'    {  Node* filho1 = create_node( 0, real_node, "real", $1, NULL);
					 Node* filho2 = create_node( 0, listadupla_node, "listadupla", $3, NULL);
    			    		 $$ = create_node( 0, tipolista_node, "tipolista", filho1, filho2, NULL);  }
         | CHAR '(' listadupla ')'    {  Node* filho1 = create_node( 0, char_node, "char", $1, NULL);
					 Node* filho2 = create_node( 0, listadupla_node, "listadupla", $3, NULL);
    			    		 $$ = create_node( 0, tipolista_node, "tipolista", filho1, filho2, NULL);  }
         ;

listadupla: INT_LIT ':' INT_LIT
          | INT_LIT ':' INT_LIT ',' listadupla
          ;

acoes: comando ';'  { $$ = $1; }
     | comando ';' acoes   {  Node* filho1 = create_node( 0, comando_node, "comando", $1, NULL);
    			      Node* filho2 = create_node( 0, acoes_node, "acoes", $3, NULL);
    			      $$ = create_node( 0, acoes_node, "acoes", filho1, filho2, NULL); }
    ;

comando: lvalue '=' expr         {   Node* filho1 = create_node( 0, lvalue_node, "lvalue", $1, NULL);
				     Node* filho2 = create_node( 0, expr_node, "expr", $3, NULL);
    			    	     $$ = create_node( 0, comando_node, "comando", filho1, filho2, NULL);  }
       | enunciado { $$ = $1; }
       ;

lvalue: IDF   { $$ = $1; }
      | IDF '[' listaexpr ']'     {  Node* filho1 = create_node( 0, idf_node, "idf", $1, NULL);
				     Node* filho2 = create_node( 0, listaexpr_node, "listaexpr", $3, NULL);
    			    	     $$ = create_node( 0, lvalue_node, "lvalue", filho1, filho2, NULL);  }
      ;

listaexpr: expr   { $$ = $1; }
	   | expr ',' listaexpr   {  Node* filho1 = create_node( 0, expr_node, "expr", $1, NULL);
				     Node* filho2 = create_node( 0, listaexpr_node, "listaexpr", $3, NULL);
    			    	     $$ = create_node( 0, listaexpr_node, "listaexpr", filho1, filho2, NULL);  }
	   ;

expr: expr '+' expr  {  Node* filho1 = create_node( 0, expr_node, "expr", $1, NULL);
			Node* filho2 = create_node( 0, plus_node, "plus", $3, NULL);
    			Node* filho3 = create_node( 0, expr_node, "expr", $3, NULL);
    			$$ = create_node( 0, expr_node, "expr", filho1, filho2, filho3, NULL); }
    | expr '-' expr  {  Node* filho1 = create_node( 0, expr_node, "expr", $1, NULL);
			Node* filho2 = create_node( 0, minus_node, "minus", $3, NULL);
    			Node* filho3 = create_node( 0, expr_node, "expr", $3, NULL);
    			$$ = create_node( 0, expr_node, "expr", filho1, filho2, filho3, NULL); }
    | expr '*' expr  {  Node* filho1 = create_node( 0, expr_node, "expr", $1, NULL);
			Node* filho2 = create_node( 0, mul_node, "mul", $3, NULL);
    			Node* filho3 = create_node( 0, expr_node, "expr", $3, NULL);
    			$$ = create_node( 0, expr_node, "expr", filho1, filho2, filho3, NULL); }
    | expr '/' expr  {  Node* filho1 = create_node( 0, expr_node, "expr", $1, NULL);
			Node* filho2 = create_node( 0, div_node, "div", $3, NULL);
    			Node* filho3 = create_node( 0, expr_node, "expr", $3, NULL);
    			$$ = create_node( 0, expr_node, "expr", filho1, filho2, filho3, NULL); }
    | '(' expr ')'   { $$ = $1; }
    | INT_LIT        { $$ = $1; }								//{ $$ = create_node(@1.first_line, int_node, $1, NULL); } 
    | F_LIT          { $$ = $1; }
    | lvalue         { $$ = $1; }
    | chamaproc      { $$ = $1; }
    ;

chamaproc: IDF '(' listaexpr ')'   {  Node* filho1 = create_node( 0, idf_node, "idf", $1, NULL);
				      Node* filho2 = create_node( 0, listaexpr_node, "listaexpr", $3, NULL);
    			    	      $$ = create_node( 0, chamaproc_node, "chamaproc", filho1, filho2, NULL);  }
         ;

enunciado: expr { $$ = $1 ;}
         | IF '(' expbool ')' THEN acoes fiminstcontrole    {   Node* filho1 = create_node( 0, if_node, "if", $1, NULL);
								Node* filho2 = create_node( 0, expbool_node, "expbool", $2, NULL);
								Node* filho3 = create_node( 0, then_node, "then", $3, NULL);
				      				Node* filho4 = create_node( 0, acoes_node, "acoes", $4, NULL);
								Node* filho5 = create_node( 0, fiminstcontrole_node, "fiminstcontrole", $5, NULL);
    			    	      			$$ = create_node( 0, enunciado_node, "enunciado", filho1, filho2, filho3, filho4, filho5, NULL);  }
         | WHILE '(' expbool ')' '{' acoes '}'  {   Node* filho1 = create_node( 0, while_node, "while", $1, NULL);
						    Node* filho2 = create_node( 0, expbool_node, "expbool", $2, NULL);
						    Node* filho3 = create_node( 0, acoes_node, "acoes", $3, NULL);
    			    	      		    $$ = create_node( 0, enunciado_node, "enunciado", filho1, filho2, filho3, NULL);  }
         ;

fiminstcontrole: END  { $$ = $1 ;}
               | ELSE acoes END    {   Node* filho1 = create_node( 0, else_node, "else", $1, NULL);
				       Node* filho2 = create_node( 0, acoes_node, "acoes", $2, NULL);
				       Node* filho3 = create_node( 0, end_node, "end", $3, NULL);
    			    	       $$ = create_node( 0, fiminstcontrole_node, "fiminstcontrole", filho1, filho2, filho3, NULL);  }
               ;

expbool: TRUE   { $$ = $1 ;}
       | FALSE  { $$ = $1 ;}
       | '(' expbool ')'   { $$ = $1 ;}
       | expbool AND expbool       {   Node* filho1 = create_node( 0, expbool_node, "expbool", $1, NULL);
				       Node* filho2 = create_node( 0, and_node, "and", $2, NULL);
				       Node* filho3 = create_node( 0, expbool_node, "expbool", $3, NULL);
    			    	       $$ = create_node( 0, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       | expbool OR expbool        {   Node* filho1 = create_node( 0, expbool_node, "expbool", $1, NULL);
				       Node* filho2 = create_node( 0, or_node, "and", $2, NULL);
				       Node* filho3 = create_node( 0, expbool_node, "expbool", $3, NULL);
    			    	       $$ = create_node( 0, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       | NOT expbool               {   Node* filho1 = create_node( 0, not_node, "not", $1, NULL);
				       Node* filho2 = create_node( 0, expbool_node, "expbool", $2, NULL);
    			    	       $$ = create_node( 0, expbool_node, "expbool", filho1, filho2, NULL);  }
       | expr '>' expr             {   Node* filho1 = create_node( 0, expr_node, "expr", $1, NULL);
				       Node* filho2 = create_node( 0, greater_node, "greater", $2, NULL);
				       Node* filho3 = create_node( 0, expr_node, "expr", $3, NULL);
				       $$ = create_node( 0, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       | expr '<' expr		   {   Node* filho1 = create_node( 0, expr_node, "expr", $1, NULL);
				       Node* filho2 = create_node( 0, lower_node, "lower", $2, NULL);
				       Node* filho3 = create_node( 0, expr_node, "expr", $3, NULL);
				       $$ = create_node( 0, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       | expr LE expr		   {   Node* filho1 = create_node( 0, expr_node, "expr", $1, NULL);
				       Node* filho2 = create_node( 0, le_node, "le", $2, NULL);
				       Node* filho3 = create_node( 0, expr_node, "expr", $3, NULL);
				       $$ = create_node( 0, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       | expr GE expr		   {   Node* filho1 = create_node( 0, expr_node, "expr", $1, NULL);
				       Node* filho2 = create_node( 0, ge_node, "ge", $2, NULL);
				       Node* filho3 = create_node( 0, expr_node, "expr", $3, NULL);
				       $$ = create_node( 0, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       | expr EQ expr		   {   Node* filho1 = create_node( 0, expr_node, "expr", $1, NULL);
				       Node* filho2 = create_node( 0, eq_node, "eq", $2, NULL);
				       Node* filho3 = create_node( 0, expr_node, "expr", $3, NULL);
				       $$ = create_node( 0, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       | expr NE expr    	   {   Node* filho1 = create_node( 0, expr_node, "expr", $1, NULL);
				       Node* filho2 = create_node( 0, ne_node, "ne", $2, NULL);
				       Node* filho3 = create_node( 0, expr_node, "expr", $3, NULL);
				       $$ = create_node( 0, expbool_node, "expbool", filho1, filho2, filho3, NULL);  }
       ;
%%
 /* A partir daqui, insere-se qlqer codigo C necessario.
  */
//uncompile("arq", &syntax_tree);


