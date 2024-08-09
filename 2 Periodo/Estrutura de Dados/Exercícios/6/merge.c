#include "list.h"

/* */
List* merge (List *A, List *B) {
  if(A == NULL){
    return B;
  }
  if(B == NULL){
    return A;
  }
  if(A->data > B->data){ // A > B -> A fica
    
    B->next = merge(A, B->next);

    return B;
   
  }
  else if(A->data < B->data){ // A < B -> B fica

    A->next = merge(A->next, B);

    return A;


  }
}

/* */
int main () {
  int k;
  List *A = NULL;
  for (k = 0; k <= 14; k += 2) {
    A = insert_back (A, k);
  }
  printf("Lista = ");
  print (A);
  printf("\n");

  List *B = NULL;
  for (k = 1; k <= 9; k += 2) {
    B = insert_back (B, k);
  }
  printf("Lista = ");
  print (B);
  printf("\n");

  List *C = merge (A, B);
  printf("Lista = ");
  print (C);
  printf("\n");

  destroy (C);
  return 0;
}


