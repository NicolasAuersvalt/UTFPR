#include "list.h"

int meio (List *l) {
  List *fast = l, *slow = l, *t=l;

  while (t!=NULL){
    // Slow anda de 1 em 1
    // Fast anda de 2 em 2

    // CONDIÇÃO DE PARADA (professor passou)
    if((fast->next) == NULL || (fast->next->next)==NULL){
      return slow->data;
    }

  	slow = slow->next;
	fast=fast->next->next;
  }
  return slow->data;
}

int main () {
  int i;	
 
  List *l0 = create();
  for (i = 0; i < 3; i++)
    l0 = insert (l0, i);	
  print (l0); 
  printf("Elemento no meio da lista: %d\n", meio(l0));
  destroy (l0);

  List *l1 = create();
  for (i = 0; i < 10; i++)
    l1 = insert (l1, i);	
  print (l1); 
  printf("Elemento no meio da lista: %d\n", meio(l1));
  destroy (l1);

  List *l2 = create();
  for (i = 0; i < 19; i++)
    l2 = insert (l2, i);	 
  print (l2); 
  printf("Elemento no meio da lista: %d\n", meio(l2));
  destroy (l2);

  return 0;
}
