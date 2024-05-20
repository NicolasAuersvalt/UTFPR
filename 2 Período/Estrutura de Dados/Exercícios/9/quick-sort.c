#include "utils.h"

/* */
int partition(int A[], int left, int right) {
  /*Terminar*/

  // 1 seleciona o pivot
  int p = A[right];

  // 2 Define o I e o J (limites dos vetores que serao divididos)

  int i = left - 1;
  int j;

  // percorre com j até a direita
  for (j = left; j <= (right - 1);
       j++) { // right -1 por causa do pivot em right

    // Se encontrar um valor maior q o pivot
    if (A[j] <= p) {

      // I anda uma casa
      i++;

      // Troca a posição de i com j
      swap(A, i, j);
    }
  }

  // printf("Passei");

  // Faz a troca de A[i+1] com A[d], para colocar o pivot em seu lugar ordenado
  swap(A, (i + 1), right);

  // Retorna o pivot
  return i + 1;
}

/* */
void quick_sort(int *A, int left, int right) {
  /*Terminar*/

  // Se esquerda for maior que direita (sem sentido) quebra
  if (left < right) {

    // Divide e salva a posicao do pivot
    int p = partition(A, left, right);

    // Agora divide o vetor à esquerda, em rela~cao ao pivot

    quick_sort(A, left, (p - 1)); // -1 pois p já está ordenado

    quick_sort(A, (p + 1), right); // p+1 pois p já está ordenado
  }
}

/* */
int main(int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  int i;
  int n = 10000000; /*Altere para 100, 1000, 10 mil, 1 milhao elementos!*/
  int range = 10;   /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n + 1); /*valores aleatórios*/
    // A[i] = i; /*ordem crescente*/
    // A[i] = n-i; /*ordem descrente*/
    // A[i] = 0; /*iguais*/
  }

  start = clock();
  // print(A, n, "Input");
  quick_sort(A, 0, n - 1);
  // print(A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free(A);
  return 0;
}
