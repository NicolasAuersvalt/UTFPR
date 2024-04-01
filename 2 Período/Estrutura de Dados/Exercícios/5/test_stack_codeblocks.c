/*************/
/*  Stack.h  */
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
} Stack;

/*Interface:*/
Stack* create ();
void destroy (Stack *s);
Stack* push (Stack *s, int elem);
Stack* pop (Stack *s);
int get_peek (Stack *s);
int empty (Stack *s);
void print (Stack *s);

/*************/
/*  Stack.c  */
/*************/

Stack* create () {
  return NULL;
}

void destroy (Stack *s) {
  while (s != NULL) {
    /*Terminar*/
  }
}

Stack* push (Stack *s, int elem) {
  /*Terminar*/
  /*Cria um elemento (malloc) e insere no início da lista.*/	
}

Stack* pop (Stack *s) {
  /*Terminar*/
  /*Remove o elemento (free) do início da lista.*/	
}

int get_peek (Stack *s) {
  /*Terminar*/
  /*Retorna a informação (data) armazenada no início da lista.*/	
}

int empty (Stack *s) {
  /*Terminar*/
}

void print (Stack *s) {
  /*Terminar*/
}

/**************/
/* Programa.c */
/**************/
int parser (char *c) {
  Stack *s = create();
  int i = 0;
  while (c[i] != '\0') {
    if ( (c[i] == '(') || (c[i] == '[') )
      s = push (s, c[i]);
    else if (c[i] != ' ') {
      if (c[i] == ')') {
        if (empty(s)) { return FALSE; }
	int v = get_peek (s);
        if (v != '(') { return FALSE; }
      }
      else if (c[i] == ']') {
        if (empty(s)) { return FALSE; }
	int v = get_peek (s);
        if (v != '[') { return FALSE; }
      } 	
      s = pop (s);
    }
    i++;
  }
  if (!empty(s)) { return FALSE; }
  else { return TRUE; }
}

int main () {

  char *s1 = "( ( ) [ ( ) ] )";
  if (parser(s1))
    printf("String %s: bem formada\n", s1);
  else
    printf("String %s: mal formada\n", s1);

  char *s2 = "( [ ) ]";
  if (parser(s2))
    printf("String %s: bem formada\n", s2);
  else
    printf("String %s: mal formada\n", s2);

  char *s3 = "( ) [ ]";
  if (parser(s3))
    printf("String %s: bem formada\n", s3);
  else
    printf("String %s: mal formada\n", s3);

  char *s4 = "( [ ]";
  if (parser(s4))
    printf("String %s: bem formada\n", s4);
  else
    printf("String %s: mal formada\n", s4);

  char *s5 = ") (";
  if (parser(s5))
    printf("String %s: bem formada\n", s5);
  else
    printf("String %s: mal formada\n", s5);
  return 0;
}


