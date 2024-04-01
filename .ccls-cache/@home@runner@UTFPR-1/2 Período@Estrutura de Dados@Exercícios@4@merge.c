#include "list.h"

List *merge(List *A, List *B) {
    List *C = NULL;
    List *T = NULL; 

    if (A == NULL)
        return B;
    if (B == NULL)
        return A;

    if (A->data <= B->data) {
        C = A;
        A = A->next;
    } else {
        C = B;
        B = B->next;
    }

    T = C; 

    while (A != NULL && B != NULL) {
        if (A->data <= B->data) {
            T->next = A;
            A = A->next;
        } else {
            T->next = B;
            B = B->next;
        }
        T = T->next; 
    }

    if (A != NULL)
        T->next = A;
    else if (B != NULL)
        T->next = B;

    return C;
}


/**/
int main() {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2)
    A = insert(A, k);
  for (k = 19; k >= 0; k -= 2)
    B = insert(B, k);
  print(A);
  print(B);
  List *C = merge(A, B);
  print(C);
  destroy(C);
  return 0;
}
