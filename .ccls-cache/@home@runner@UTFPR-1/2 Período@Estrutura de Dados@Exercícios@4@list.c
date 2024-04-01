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
  
  List *node = (List *)malloc(sizeof(List));
  node->data = elem;
  node->next = NULL;
  if(l==NULL){
    return node;
  }
  else{
    List *t = l;
    while(t->next !=NULL)
      t = t->next;
    t->next = node;
    return l;
  }
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
  }

int size(List *l){

	int size;

	List *t;

	for(t=l;t!=NULL;t=t->next){
		size++;
	}


	return size;
}

int max(List *l){

	int max;
	List *t;

	// Verifica se há elementos inciais
	if(t==NULL){
		return 0;
	}

	// Armazena o primeiro para comparação
	max = t->data;

	// Verifica se há maiores
	for(t=l;t!=NULL; t=t->next){
	   if(t->data > max)
		   max  = t->data;
	
	}


}

int similar(List *l, List *m){

   for(; l!=NULL; l=l->next){
      if(l->data!=m->data) return TRUE;
   }
   return FALSE;


}
