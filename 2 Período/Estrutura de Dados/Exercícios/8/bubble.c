#include "utils.h"

/* */
void bubble_sort(int *A, int n) {
  /*Terminar*/
  int i, j;

  // Percorre uma vez
  for (j = 0; j < n; j++) {
  
    // Garante a correção e todas as possibilidades
    for (i = 0; i < n - 1; i++) {

      // Se encontra um valor vizinho maior
      if (A[i + 1] < A[i]) {

        // Faz a troca
        int apoio = A[i];
        A[i] = A[i + 1];
        A[i + 1] = apoio;
      }
    }
  }
}


void bubble_sort_bidirecional (int *A, int n){

  int i, j;
  // Loop básico
  
  for(i=0; i<n; i++){
  

    // Percorre da direita para a esquerda
    // Menor à direita
    for(j=0; j<n-1; j++){
      if(A[i+1] > A[i]){
        int apoio = A[i];
	       A[i] = A[i+1];
	       A[i+1]=apoio;
      } 
    }
    
    // Percorre da esquerda para a direita

    // Maior à esquerda
     for(j=0; j<n-1; j++){
      if(A[i+1] < A[i]){
        int apoio = A[i];
	       A[i] = A[i+1];
	       A[i+1]=apoio;
      } 
     } 
    n--;
  }
}

/* */
int main(int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  /* if (argc < 2) {
     printf("run: %s [size]\n", argv[0]);
     exit(1);
   }*/

  int i;
  int n = 20;  /*atoi(argv[1]);;*/
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n + 1); /*valores aleatórios*/
  }

  start = clock();
   print (A, n, "Input");
   // bubble_sort(A, n);
  bubble_sort_bidirecional (A,n);
  
   print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free(A);
  return 0;
}
