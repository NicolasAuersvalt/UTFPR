#include "utils.h"

/* */
void insertion_sort(int *A, int n) {
  int i;
  int inversoes = 0;

  // Percorre todo o vetor
  for (i = 1; i < n; i++) {
    // Cada posição será a chave
    int key = A[i];
    int flag = 1;

    // Declara uma posição anterior
    int j = i - 1;

    // Pega esse j e vai voltando até o começo do vetor
    
    while ((j >= 0) && (key < A[j])) {
      if(key<A[j] && flag==1){
        inversoes++;
        flag = 0;
      }
      
      // Enquanto a chave for menor que cada posição desse
      // j, desloca uma posição para frente do vetor

      // Dica, não precisa se preocupar com o A[i] pois
      // a chave está salva em key
      A[j + 1] = A[j];
      j--;
    }
    // Após deslocar tudo, coloca a chave em sua posição ordenada
    // Ou troca i com i mesmo
    A[j + 1] = key;
  }
  printf("Total de Inversões: %d\n", inversoes);
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
  int n = 10; /*toi(argv[1]);*/
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n + 1); /*valores aleatórios*/
  }

  start = clock();
  print (A, n, "Input");
  insertion_sort(A, n);
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
