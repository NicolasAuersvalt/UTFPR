/*************/
/*  List.h   */
/*************/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR -INT_MAX
#define TRUE 1
#define FALSE 0

/*Structure*/
typedef struct node { 
  int data;
  struct node *next;
} List;

/*Interface:*/
List* create ();
void destroy (List *l);
List* insert (List *l, int elem);
int empty (List *l);
void print (List *l);

/*************/
/*  List.c  */
/*************/

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

/**************/
/* Programa.c */
/**************/
int meio (List *l) {
  /*Terminar*/
}

int main () {
  int i;	
 
  List *l0 = create();
  for (i = 0; i < 3; i++)
    l0 = insert (l0, i);	
  print (l0); 
  printf("Elemento no meio da lista: %d\n", meio(l0));
  destroy (l0);

  List *l1 = create();
  for (i = 0; i < 10; i++)
    l1 = insert (l1, i);	
  print (l1); 
  printf("Elemento no meio da lista: %d\n", meio(l1));
  destroy (l1);

  List *l2 = create();
  for (i = 0; i < 19; i++)
    l2 = insert (l2, i);	 
  print (l2); 
  printf("Elemento no meio da lista: %d\n", meio(l2));
  destroy (l2);

  return 0;
}
