#include "queue.h"

Queue* create () {
  return NULL;
}

void destroy (Queue *q) {
  while (q != NULL) {
    Queue *t = q->next;
    free(q);
    q = t;
  }
}

int empty (Queue *q) {
  return(q==NULL);
  
}

Queue* enqueue (Queue *q, int elem) {
  
  /*Terminar*/
  Queue *novo = (Queue *)malloc (sizeof(Queue));
  novo -> data = elem;
  novo ->next = NULL;
  if(q==NULL)
    return novo;
  else{
    Queue *t = q;
    while(t->next != NULL)
      t=t->next;
    t->next = novo;
    return q;
  }
}

Queue* dequeue (Queue *q) {
  /*Terminar*/

  if(q==NULL){
    return 0;
  }
  Queue *t = q->next;
  free(q);
  return t;

}

int get_front (Queue *q) {
  /*Terminar*/

  if(!empty(q)) // q!=NULL
    return q->data;
  
}

void print (Queue *q) {
  /*Terminar*/

  Queue *t;
  
  
  for(t=q; t!= NULL; t= t->next){
    printf("%d", t->data);
  }
}


