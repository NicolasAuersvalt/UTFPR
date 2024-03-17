#include "queue.h"
#include <time.h>

void jackpot (int n, int r) {
  /*Terminar*/

  int i, encontrou = 1, pri, sec, ter, elem;
  
  // Gera-se 3 filas

  // 3 Carretéis fixos, não n carretéis
  Queue *carretel1, *carretel2, *carretel3;

  carretel1 = create(r);
  carretel2 = create(r);
  carretel3 = create(r);
  
  for(i=0; i<r-1; i++){
    enqueue(carretel1, i);
    enqueue(carretel2, i);
    enqueue(carretel3, i);
  }

  while(encontrou){

    // Variáveis de apoio
    
    pri = rand() % 10;
    sec = rand() % 10;
    ter = rand() % 10;

    // print

    for(i=0; i<pri; i++){
      elem = dequeue(carretel1);
      
      enqueue(carretel1, elem);
    }
    for(i=0; i<sec; i++){
      elem = dequeue(carretel2);
      
      enqueue(carretel2, elem);
    }
    for(i=0; i<ter; i++){
      elem = dequeue(carretel3);
      
      enqueue(carretel3, elem);
    }

    // Substitui o valor das variáveis de apoio
    
    pri = front(carretel1);
    sec = front(carretel2);
    ter = front(carretel3);
    
    printf("\n%d %d %d", pri, sec, ter);
    
    if((pri == sec) && (sec==ter)){
      printf(" -> Ganhou!");
      encontrou = 0;
    }
  }  
  
  // Três carretéis (3 filas)
  // Gera uma fila para cada carretel
  // toda vez que for chamada a função, eliminará a posição mais antiga
  // e passará a ser a posição mais nova: 
  
    // Mais antiga -> Mais nova
    // Segunda mais antiga -> Mais antiga
    // Mais nova -> segunda mais nova

  // if( carretel[i]==carretel2[i]==carretel3[i])/
    // printf("-> Ganhou\n")
    // return 0;
}

int main () {
  srand(time(NULL));	
  int n = 3;  /*número de carretéis*/ 
  int r = 10; /*sequência de números em cada carretel*/ 
  jackpot (n, r);
}
