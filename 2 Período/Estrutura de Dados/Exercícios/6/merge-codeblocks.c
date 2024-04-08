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
List* merge (List *A, List *B) {
  /*Terminar.*/	
}

/* */
int main () {
  int k;
  List *A = NULL;
  for (k = 0; k <= 14; k += 2) {
    A = insert_back (A, k);
  }
  printf("Lista = ");
  print (A);
  printf("\n");

  List *B = NULL;
  for (k = 1; k <= 9; k += 2) {
    B = insert_back (B, k);
  }
  printf("Lista = ");
  print (B);
  printf("\n");

  List *C = merge (A, B);
  printf("Lista = ");
  print (C);
  printf("\n");

  return 0;
}


