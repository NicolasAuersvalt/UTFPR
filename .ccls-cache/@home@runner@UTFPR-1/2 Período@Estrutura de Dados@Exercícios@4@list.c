#include "list.h"

/* */
List* create () {
  return NULL;	
}

/* */
List* insert (List *l, int elem) {
  List *node = (List *)malloc(sizeof(List));
  node->data = elem;
  node->next = l;
  return node;
}

/* */
List* insert_back (List *l, int elem) {
  /* Terminar! */
  
  List *t=l, *node;

  // Sem nenhum elemento

  if(t->next==NULL){

    // Aloca Espaço
    node = (List*) malloc (sizeof(List));
    
    node->next = NULL;
    node->data = elem;
    
    return node;
  }

  // Percorre até chegar na cauda
  for(; t->next != NULL; t=t->next);

  // Aloca espaço
  node = (List*) malloc (sizeof(List));

  // T que apontava para null apontará para node
  t->next = node;

  // Node armazena elemento e aponta para null
  node->next = NULL;
  node->data = elem;

  return l;
  
}

/* */
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

/* */
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

/* */
void print (List *l) {
  List *t;
  printf ("List: ");
  for (t = l; t != NULL; t = t->next)
    printf ("%d ", t->data);
  printf("\n");
}

/* */
void destroy (List *l) {
  if (l != NULL) {	
    List *t = l->next; 
    free (l); 
    l = t;    
  }  

  int size(){

    
  }
}
