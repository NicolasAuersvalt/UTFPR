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

int in (List *l, int k) {
  /*Terminar!*/	
}

/***************/
/* Programa.c  */
/***************/
int main () {
  int k;
  List *l = NULL;
  for (k = 0; k <= 4; k++) 
    l = insert (l, k);
  for (k = 9; k >= 5; k--) 
    l = insert (l, k);
  print (l);
  printf("Pertence %d = %d?\n", 9, in(l, 9));
  printf("Pertence %d = %d?\n", -1, in(l, -1));
  destroy (l);
  return 0;
}
