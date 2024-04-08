#include "list.h"

/* */
List* merge (List *A, List *B) {
  if(A == NULL){
    return B;
  }
  else if (B == NULL){
    return A;
  }
  else if(A->data > B->data){ // A > B -> B fica
    
    B->next = merge(A->next, B);

    // b->next = merge(A, B->next)
   
  }
  else if(A->data < B->data){ // A < B -> A fica

    A->next = merge(A, B->next);

    // b->next = merge(A, B->next)

  }
  else if(A->data == B->data){ // A > B -> B fica

    A->next = merge(A->next, B);

    // b->next = merge(A, B->next)

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


