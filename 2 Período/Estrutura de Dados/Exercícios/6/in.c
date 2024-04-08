#include "list.h"
#include <limits.h>

/* */
int in (List *l, int k) {
  
  if(l==NULL){
    return 0; // NÃO ENCONTROU
  }
  else{
    if(l->data == k){ // Encontrou
      return 1;
    }
    else{
      return in(l->next, k);
    }
  }
}

/* */
int main () {
  List *l = NULL;
  int k;
  for (k = 0; k <= 5; k++) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("In = %d\n", in(l,3));
  printf("In = %d\n", in(l,6));
  destroy (l);
  return 0;
}
