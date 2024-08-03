#include "utils.h"

/* */
int bad_commit(int *A, int n) {
  // Ponto médio
  int med = (n / 2);
  int achou = 0;
  
  // Loop até encontrar (é fato que existirá ao menos 1)
  while (!achou) {
    printf("A[%d] = %d\n", med, A[med]);
    
    // Verifica se é 0
    if (A[med] == 0) {
      
      // divide à direita
      med = med + (med/2);

    } else { // é 1

      if(med == 0){
        return med;
      }
      
      // verifica se a posição logo à esquerda é 0
      else if (A[med-1] == 0) {
        return med;
        
      } else {
        
        // divide à esquerda
        med = med - (med/2);
      }
    }
  }
}

/* */
int main() {
  int i;
  int n = 7;
  //int A[] = {0, 0, 0, 0, 0, 0, 1};
  int A[] = {1, 1, 1, 1, 1, 1, 1};
  printf("Bad commit: %d\n", bad_commit(A, n));
  return 0;
}
