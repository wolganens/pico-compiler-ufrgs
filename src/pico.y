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

%type<no> code 
%type<no> acoes
%type<no> comando
%type<no> enunciado
%type<no> expr

%start code

 /* A completar com seus tokens - compilar com 'yacc -d' */

%%
code: declaracoes acoes {   Node* filho1 = create_node( , declaracoes_node, "declaracoes", $1, NULL);
    			    Node* filho2 = create_node( , acoes_node, "acoes", $2, NULL);
    			    $$ = create_node( , code_node, "codigo", filho1, filho2, NULL);  ;syntax_tree = $$;  }
    | acoes 		{ $$ = $1; syntax_tree = $$; }
    ;

declaracoes: declaracao ';' {   Node* filho1 = create_node( , declaracao_node, "declaracao", $1, NULL);
    			    	Node* filho2 = create_node( , terminal_node, yytext, $2, NULL);
    			    	$$ = create_node( , declaracoes_node, "declaracoes", filho1, filho2, NULL);  }
           | declaracoes declaracao ';' {   Node* filho1 = create_node( , declaracoes_node, "declaracoes", $1, NULL);
					    Node* filho2 = create_node( , declaracao_node, "declaracao", $2, NULL);
    			    		    Node* filho3 = create_node( , semicolon_node, yytext, $3, NULL);
    			    		    $$ = create_node( , declaracoes_node, "declaracoes", filho1, filho2, filho3, NULL);  }
           ;

declaracao: tipo ':' listadeclaracao {   Node* filho1 = create_node( , tipo_node, "tipo", $1, NULL);
    			    		 Node* filho2 = create_node( , colon_node, yytext, $2, NULL);
					 Node* filho3 = create_node( , listadeclaracao_node, "listadeclaracao", $3, NULL);
    			    		 $$ = create_node( , declaracao_node, "declaracao", filho1, filho2, filho3, NULL);  }
	   ;

listadeclaracao: IDF
               | IDF ',' listadeclaracao
               ;

tipo: tipounico 
    | tipolista
    ;

tipounico: INT
         | DOUBLE
         | REAL
         | CHAR
         ;

tipolista: INT '(' listadupla ')'
         | DOUBLE '(' listadupla ')'
         | REAL '(' listadupla ')'
         | CHAR '(' listadupla ')'
         ;

listadupla: INT_LIT ':' INT_LIT
          | INT_LIT ':' INT_LIT ',' listadupla
          ;

acoes: comando ';'  { $$ = $1; }
    | comando ';' acoes
    ;

comando: lvalue '=' expr
       | enunciado { $$ = $1;}
       ;

lvalue: IDF
      | IDF '[' listaexpr ']'
      ;

listaexpr: expr
	   | expr ',' listaexpr
	   ;

expr: expr '+' expr  
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | INT_LIT  { $$ = create_node(@1.first_line, int_node, $1, NULL); } 
    | F_LIT    
    | lvalue
    | chamaproc
    ;

chamaproc: IDF '(' listaexpr ')'
         ;

enunciado: expr { $$ = $1 ;}
         | IF '(' expbool ')' THEN acoes fiminstcontrole
         | WHILE '(' expbool ')' '{' acoes '}'
         ;

fiminstcontrole: END
               | ELSE acoes END
               ;

expbool: TRUE 
       | FALSE
       | '(' expbool ')'
       | expbool AND expbool
       | expbool OR expbool
       | NOT expbool
       | expr '>' expr
       | expr '<' expr
       | expr LE expr
       | expr GE expr
       | expr EQ expr
       | expr NE expr
       ;
%%
 /* A partir daqui, insere-se qlqer codigo C necessario.
  */