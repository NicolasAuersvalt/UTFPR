#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/***************/
/* List.h      */
/***************/

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
void print (List *l);
void destroy (List *l);
List* insert (List *l, int elem);
List* insert_back (List *l, int elem);
List* removek (List *l, int elem);
List* search (List *l, int k);

/***************/
/* List.c      */
/***************/

List* create () {
  return NULL;	
}

List* insert (List *l, int elem) {
  List *node = (List *)malloc(sizeof(List));
  node->data = elem;
  node->next = l;
  return node;
}

List* search (List *l, int elem) {
  if (l != NULL) {
    List *t = l;	   
    while (t != NULL) {
      if (t->data == elem) 
        return t;
      t = t->next;
    }  
  }
  return NULL;  
}

List* removek (List *l, int elem) {
  List *t = l, *p = NULL;
  while ((t != NULL) && (t->data != elem)) {
    p = t;
    t = t->next;    
  } 
  if (t == NULL) { return l; }
  if (p == NULL) { l = t->next; }
  else { p->next = t->next; }
  free (t);
  return l;
}

void print (List *l) {
  List *t;
  printf ("List: ");
  for (t = l; t != NULL; t = t->next)
    printf ("%d ", t->data);
  printf("\n");
}

void destroy (List *l) {
  if (l != NULL) {	
    List *t = l->next; 
    free (l); 
    l = t;    
  }  
}

List* merge (List *A, List *B){
  /*Terminar*/	
}

/***************/
/* Programa.c  */
/***************/
int main () {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2) 
    A = insert (A, k);
  for (k = 19; k >= 0; k -= 2) 
    B = insert (B, k);
  print (A);
  print (B);
  List *C = merge (A, B);
  print (C);
  destroy (C);
  return 0;
}
