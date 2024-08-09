/********************
 *     List.h
 ********************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR -INT_MAX

/*Structure*/
typedef struct node { 
  int data;
  struct node *next;
  struct node *prev;
} List;

/*Interface:*/
List* create ();
List* insert_front (List *l, int elem);
List* insert_back (List *l, int elem);
void print (List *l);
void destroy (List *l);
List* search (List *l, int k);

/********************
 *     List.c
 ********************/
List* create () {
  return NULL;	
}

List* insert_front (List *l, int elem) {
  List *node = (List *)malloc(sizeof(List));
  node->data = elem;
  node->next = l;
  node->prev = NULL;
  if (l != NULL) 
    l->prev = node;
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

void print (List *l) {
  List *t, *last;
  printf ("List (front-to-back): {");
  for (t = l; t != NULL; t = t->next) {
    if (t->next != NULL)	  
       printf ("%d, ", t->data);
    else
       printf ("%d", t->data);
    last = t;
  }  
  printf("}\n");
  printf ("List (back-to-front): {");
  for (t = last; t != NULL; t = t->prev) {
    if (t->prev != NULL)	  
       printf ("%d, ", t->data);
    else
       printf ("%d", t->data);
  }  
  printf("}\n");
}

void destroy (List *l) {
  if (l != NULL) {	
    List *t = l->next; 
    free (l); 
    l = t;    
  }  
}

/********************
 *    Programa.c
 ********************/
List* split (List *l, List *x, List *y) {
  /*Terminar!*/	
}

int main () {
  int i;	
  int n = 9;	
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  print (l);
  List *x = search (l, 3);
  List *y = search (l, 7);
  List *ls = split (l, x, y);
  print (l);
  print (ls);
  destroy (l);
  destroy (ls);
  return 0;
} 
