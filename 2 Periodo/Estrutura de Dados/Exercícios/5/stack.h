#ifndef _stack_h_
#define _stack_h_

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
} Stack;

/*Interface:*/
Stack* create ();
void destroy (Stack *s);
Stack* push (Stack *s, int elem);
Stack* pop (Stack *s);
int get_peek (Stack *s);
int empty (Stack *s);
void print (Stack *s);

#endif
