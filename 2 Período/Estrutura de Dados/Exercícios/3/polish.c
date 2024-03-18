#include "stack.h"

void reversed_polish_notation (char *c) {
  Stack *s = create(strlen(c));
  int i = 0;
  while (c[i] != '\0') {
    /*Terminar*/
    /*Utilizar somente as operações push, pop, empty, ... (interface)*/

    int counter=0;


    // Dica

    // IMPRIME O NÚMERO DIRETO NA TELA
      // EMPILHA A OPERAÇÃOss

    
    
    // Se o contador == 1 -> Armazena os operadores passados

    // Se não, vai armazenando os números
    
    i++;    
  }
  printf("\n");
  destroy(s);
}

int main () {
  char *c = "( 9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )";
  reversed_polish_notation (c);
  return 0;
}
