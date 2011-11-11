 /* Secao das declaracoes */

%option noyywrap
 /* Sera copiado no .c final */
%{
    #include <stdlib.h>
    #include <string.h>
  
    #include "tokens.h"
    
    int VAL_INT;
    double VAL_DOUBLE;
%}

%option yylineno
%{
#define YY_USER_ACTION yylloc.first_line = yylineno;
%}


 /* Definicoes regulares (A COMPLETAR conforme a especificacao) */

digito     [0-9]
letra      [a-z]
LETRA      [A-Z]

%%



 /* Secao das Regras de traducao */
 /* O que consta aqui eh puramente ilustrativo... A COMPLETAR ! 
  * Ver tambem "tokens.h".
  */
  
int    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(INT); }
double { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(DOUBLE); }
real   { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(REAL);   }
char   { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(CHAR);   }
string { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(STRING); }
"*"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return('*');    }
"+"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return('+');    }
"-"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return('-');    }
"/"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return('/');    }
","    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(',');    }
";"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(';');    }
":"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(':');    }
"'"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(QUOTE);  }
"("    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return('(');    }
")"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(')');    }
"["    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return('[');    }
"]"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(']');    }
"{"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return('{');    }
"}"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return('}');    }
"<"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return('<');    }
">"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return('>');    }
"="    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return('=');    }
"<="   { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(LE);     }
">="   { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(GE);     }
"=="   { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(EQ);     }
"<>"   { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(NE);     }
"&"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(AND);    }
"|"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(OR);     }
"!"    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(NOT);    }
if     { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(IF);     }
then   { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(THEN);   }
else   { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(ELSE);   }
for    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(FOR);    }
next   { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(NEXT);   }
while  { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(WHILE);  }
end    { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(END);    }
true   { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(TRUE);   }
false  { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(FALSE);  }
print  { yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return(PRINTF); }

[ \t\n]+					
({letra}|[_])+({letra}|{LETRA}|[_]|{digito})*  	{ yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return( IDF ); }
{LETRA}+([_]|{LETRA}|{digito})*	        	{ yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext);  return( CONST ); }
["]({letra}|{LETRA}|{digito}|[ ])*["]		{ yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext);  return( STR_LIT ); }
{digito}+					{ VAL_INT = atoi(yytext); yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return( INT_LIT ); }
{digito}*\.{digito}+(([eE])([+-])?{digito}+)?   { VAL_DOUBLE = atof(yytext); yylval.cadeia = (char*) malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.cadeia, yytext); return( F_LIT ); }

  /* Tratamento dos erros lexicais: a regra seguinte pega tudo o que nao
   * fechou com uma Regexp anterior.
   */
. { printf("Erro lexical - caractere nao reconhecido: %c.\n", yytext[0]);
    exit(-1); }
%%
 /* Secao dos  Procedimentos auxiliares  */

 /* Para redefinir a entrada padrao do LEX. 
  * Redefinir a variavel 'yyin' para ler de um arquivo. Por exemplo:
     yyin = fopen("Meu_programa.c", "r");
  * ira mandar ler o programa a ser compilado pelo analisador lexical
  * em 'Meu_programa.c'.
  * O default eh ler da entrada standard (o teclado).
  */
extern FILE *yyin;
int old_main(int argc, char* argv[]) {
   int token;
   if (argc != 2) {
     printf("uso: %s <input_file>. Try again!\n", argv[0]);
     exit(-1);
   }
   yyin = fopen(argv[1], "r");
    if (!yyin) {
     printf("Uso: %s <input_file>. Could not find %s. Try again!\n", 
         argv[0], argv[1]);
     exit(-1);
   }
  /* agora a entrada padrao eh o arquivo especificado como 1o argumento ao
   * executavel (argv[1]).
   * Soh chama o analisador lexical default fornecido pelo output do Flex:
   */
  while (token=yylex()) { 
     /* neste laco, obtem-se "palavra por palavra" os tokens reconhecidos
      * pelo scanner fornecido pelo Lex. Poderia ser feita a analise
      * sintatica... Sera feito depois!
      */
     printf("Meu analisador lexical reconheceu o token %d\n", token);
  }
  return(0);
}
