#include "utils.h"

/* */
void quick_find(int *A, int left, int right, int k) { /*Terminar*/

  int pivot = rand()%100;
  while(pivot>right){
    pivot = rand()%100;
    printf("Pivot: %d\n" , pivot);
  }
  int i, j, count = 1;
  for (i = pivot; i < right; i++) {
    if (A[i] < pivot) {
      count++;
    }
  }
  for (i = pivot; i > 0; i--) {
    if (A[i] < pivot) {
      count++;
    }
  }
  if(count!=(k+1)){
    quick_find(A, left, right, k);
  }
  else{
    printf("O valor é: %d\n", A[pivot]);
    printf("Para o %dº menor valor\n", k);
  }
}

/* */
int main() {
  int n = 8;
  int A[] = {7, 1, 3, 10, 17, 2, 21, 9};
  print(A, n, "Input");
  quick_find(A, 0, n - 1, 4);
  print(A, n, "Partial sorted");
  return 0;
}
