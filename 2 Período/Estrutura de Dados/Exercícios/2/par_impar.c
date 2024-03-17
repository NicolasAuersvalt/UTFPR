#include "queue.h"
#include <time.h>


int main () {
  srand(time(NULL));
  int i=0, n = 10;	
  Queue *par = create(n);
  Queue *impar = create(n);
  while(i<n){
    int sorteio = rand() % 100;
    if((sorteio%2)==0)
      enqueue(par, sorteio);
    else
      enqueue(impar, sorteio);
    i++;
  }
  print(par);  
  print(impar);
  destroy(par);
  destroy(impar);
  
  return 0;
}

