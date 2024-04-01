#include "stack.h"

Stack* create () {
  return NULL;
}

void destroy (Stack *s) {
  while (s != NULL) {
    /*Terminar*/
    Stack *apoio = s->next; // PROVA
    free(s);
    s = apoio;
  }	  
}

Stack* push (Stack *s, int elem) {
  
  Stack *novo = (Stack *)malloc(sizeof(Stack));
  novo->data = elem;
  novo->next = s;
  return novo;
}

Stack* pop (Stack *s) {
  /*Terminar*/
  if(s==NULL){
    return 0;
  }
  
  Stack *apoio = s->next;
  free(s);
  s = apoio;
  return s;
}

int get_peek (Stack *s) {

  if(empty(s))
    return 0;

  return s->data;
}

int empty (Stack *s) {
  return (s == NULL);
}

void print (Stack *s) {
  Stack *apoio=s;
  printf("Stack: ");
  while(apoio->next != NULL)
    printf("%d", apoio->data);

  printf("\n");
}
