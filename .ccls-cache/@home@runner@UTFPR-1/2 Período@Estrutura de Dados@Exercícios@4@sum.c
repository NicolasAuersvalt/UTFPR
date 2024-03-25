#include "list.h"

/* */
int sum (List *l) {
  /*Terminar!*/	

   int sum=0;
   
   List *t;

   for(t=l; t != NULL; t= t->next){ // o(n+1)
	   
     sum += t->data;

  }

   return sum;

}

/* */
int main () {
  int k;
  List *l = NULL;
  for (k = 0; k <= 4; k++) 
    l = insert (l, k);
  for (k = 9; k >= 5; k--) 
    l = insert (l, k);
  print (l);
  printf("Sum = %d\n", sum(l));
  destroy (l);
  return 0;
}
