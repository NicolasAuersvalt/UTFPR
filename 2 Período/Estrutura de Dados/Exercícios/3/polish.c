#include "stack.h"

void reversed_polish_notation (char *c) {
  Stack *s = create(strlen(c));
  int i = 0;

  printf("\n \n%s\n \n", c);
  
  while (c[i] != '\0') {
    
    /*Terminar*/
    /*Utilizar somente as operações push, pop, empty, ... (interface)*/

    int counter=0;

    // Dica
    
    if(c[i]=='+' || c[i] == '*'){ // Produto
      
    	push(s, c[i]);
      
    }

    else if(c[i] == ')'){ // Termina operação
    
      printf("%c",get_peek(s));
      pop(s);
      
    }
    else if(c[i]== '(' || c[i] == ' ');
  
    else{ // Número
    
	  // Exibe na tela
	
	  printf("%c", c[i]);

    }
    
    // IMPRIME O NÚMERO DIRETO NA TELA
      // EMPILHA A OPERAÇÃO

    // Lógica 9 0 1 + 2 3 * * +

    // Empilha os números

    // 9 0 1

    // Achou +

    // Soma 0 + 1

    // 9 1 2 3 

    // Achou *
    
    // Se o contador == 1 -> Armazena os operadores passados

    // Se não, vai armazenando os números
    
    i++;    
  }
  printf("\n");
  destroy(s);
}

int compute_polish_expression(char *c){
	

}


int main () {
  char *c = "( 9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )";
  reversed_polish_notation (c);
  return 0;
}
