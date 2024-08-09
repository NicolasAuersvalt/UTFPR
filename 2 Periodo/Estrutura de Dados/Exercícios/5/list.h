#ifndef _list_h_
#define _list_h_

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

#endif
