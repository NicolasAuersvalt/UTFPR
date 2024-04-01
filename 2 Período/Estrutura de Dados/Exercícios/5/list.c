#include "list.h"

List* create () {
  return NULL;
}

void destroy (List *l) {
  /*Terminar*/	
}

int empty (List *l) {
  /*Terminar*/	
}

List* insert (List *l, int elem) {
  List *n = (List *)malloc(sizeof(List));
  n->data = elem;
  n->next = l;
  return n;  
}

void print (List *l) {
  List *t;
  printf("List: ");
  for (t = l; t != NULL; t = t->next) {
    printf("%d ", t->data);
  }
  printf("\n");
}
