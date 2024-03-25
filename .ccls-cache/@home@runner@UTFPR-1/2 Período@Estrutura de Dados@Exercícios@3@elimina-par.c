#include "stack.h"

int main () {
  int tam = 6;
  Stack *s = create (tam);
  srand(time(NULL));
  int i;
  for (i = 0; i < tam; i++) {
    push (s, rand()%10);
  }
  print (s);

  // Cria a auxiliar
  
  Stack *aux  = create(tam);
  // Verifica se peek é par
  
  int auxiliar;

  while(!empty(s)){
	auxiliar = get_peek(s);
  	if((auxiliar%2)!=0){
		push(aux, pop(s));
	}
	else{
		pop(s);
	}
  }
  while(!empty(aux)){
  	push(s, pop(aux));

  }
  print(s);

  /*TERMINAR*/
  destroy (s);
}
