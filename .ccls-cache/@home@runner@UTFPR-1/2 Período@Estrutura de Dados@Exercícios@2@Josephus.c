#include "queue.h"

int Josephus(Queue *q, int elem, int pos, Queue *u){
  // Faz cópia da queue até o elemento e depois dele
  if(getsize(q)==1){
    return q->array[0];
  }
  int i=pos, posicao, achou = 0, j=pos;
  Queue *copia;
  for(i=0; achou != 1 ; i++){
    j++;
    // Garante ser circular
    if(i==q->back){
      i= q->front;
    }
    if((j%elem)==0){
      achou=0;
      if(i<q->back){
        for(i=i; i<q->back; i++){
          enqueue(copia, i);
        }
      }
    }
    return Josephus(q, elem, j, copia);
  }
  

}

int main(){
	Queue *fila;
	fila = create(10);
	int elem = 5, i;
	for(i=0; i<10;i++){
	  enqueue(fila, i);
	}
	printf("Fila: ");
	print(fila);
	printf("\nO último é: %d", Josephus(fila, elem, 0, fila));
}
