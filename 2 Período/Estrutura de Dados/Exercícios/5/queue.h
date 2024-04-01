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
} Queue;

/*Interface:*/
Queue* create ();
void destroy (Queue *q);
Queue* enqueue (Queue *q, int elem);
Queue* dequeue (Queue *q);
int get_front (Queue *q);
int empty (Queue *q);
void print (Queue *q);

#endif
