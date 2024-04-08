/******************
 *     List.h 
 * ***************/
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
} Node, List;

/*Interface:*/
List* create ();
void print (List *l);
void destroy (List *l);
List* insert_back (List *l, int k);
List* removek (List *l, int k);

/******************
 *     List.c 
 * ***************/
List* insert_back (List *l, int k) {
  if (l == NULL) {
    l = (Node*)malloc(sizeof(Node));
    l->data = k;
    l->next = NULL;
  }
  else {
    l->next = insert_back (l->next, k);
  }
  return l;
}

/* */
void print (List* l) {
  if (l != NULL) {
    printf("%d ", l->data);
    print (l->next);      
  }
}

/******************
 *   Program.c 
 * ***************/
int size (List *l) {
  /*Terminar*/	
}

/* */
int main () {
  List *l = NULL;
  int k;
  for (k = 5; k <= 9; k++) {
    l = insert_back (l, k);
  }
  for (k = 4; k >= 0; k--) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("Size = %d\n", size(l));
  return 0;
}


