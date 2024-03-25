// #include "stack.h"
#include "queue.h"

/* */
void reverse (Queue *q) {
 /*Terminar*/	
	Queue *t, *aux;
	int i, size = getsize_queue(q);
  
	t = create_queue(size);

	for(i=1; i<size; i++){

		int apoio = dequeue(q);	
		enqueue(t, apoio);

	}

  int apoiao = front(t);

  int apoio = t->front;
  t->front = (t->back)-1;
  t->back = apoio;

  

  for(i=1; i<size-1; i++){
    
    int apoio = front(t);	
    enqueue(q, apoio);
    (t->front)--;
  
  }
  enqueue(q, apoiao);
}

int main () {
  int i, n = 10;
  Queue *q = create_queue (n+1);
  for (i = 0; i < n; i++) 
    enqueue (q, i);
  print_queue(q);  
  reverse (q);
  print_queue(q);  
  destroy_queue (q);
  return 0;
}
