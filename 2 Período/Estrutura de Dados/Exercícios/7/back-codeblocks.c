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

List* insert_back (List *l, int elem) {
  /*Terminar*/	
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
int main () {
  List *l = create ();
  l = insert_back (l, 1);
  l = insert_back (l, 2);
  l = insert_back (l, 4);
  print (l);
  destroy (l);
  return 0;
} 
