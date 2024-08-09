#include "list.h"

/* */
List* merge (List *A, List *B){
  List *H = NULL; /*head*/
  List *C = NULL; /*temporary*/
  while ((A != NULL) && (B != NULL)) {
    if (A->data < B->data) {
      if (H == NULL) {
        H = A;
        C = A;
      } 	    
      else { 
        C->next = A;
        C = C->next; 
      }
      A = A->next;	    
    }
    else {
      if (H == NULL) { H = B; C = B; } 	    
      else { C->next = B; C = C->next; }
      B = B->next;	    
    }
  }
  if (A == NULL) { C->next = B; }
  if (B == NULL) { C->next = A; }
  return H; 
}

/* */
int main () {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2) 
    A = insert (A, k);
  for (k = 19; k >= 0; k -= 2) 
    B = insert (B, k);
  print (A);
  print (B);
  List *C = merge (A, B);
  print (C);
  destroy (C);
  return 0;
}
