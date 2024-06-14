#include "utils.h"

/*Função intercala*/
int merge (int A[], int l, int m, int r, int O[], int rlevel) {
  /*Terminar*/	
  int i = l, j = m + 1, k = l;

  // Faz as trocas
  while ((i <= m) && (j <= r)) {
    if (A[i] <= A[j]) {
      O[k++] = A[i++];
    } else {
      O[k++] = A[j++];
    }
  }

  // Preenche com o que sobrou

  // Esquerda
  while (i <= m) {
    O[k++] = A[i++];
  }
  // Direita
  while (j <= r) {
    O[k++] = A[j++];
  }

  // Copia de O para A
  for (i = l; i <= r; i++) {
    A[i] = O[i];
  }
  partition_print(A,l,r,rlevel);
}

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort (int A[], int l, int r, int O[], int rlevel) {
  /*Terminar*/
  // Verifica se é maior  

  int i;
  for(i=0; i<rlevel; i++) {
    printf(" ");
  }
  
  if (l < r) {

    // Tira a média -> menor valor
    int m = ((l + r) / 2);

    // Passa às funções Particiona
    int pos;
    merge_sort(A, l, m, O, rlevel+1); // Vetor da Esquerda
    merge_sort(A, m + 1, r, O, rlevel+1); // Vetor da Direita

    // Intercala

    merge(A, l, m, r, O, rlevel+1);
  } else {
    printf("M-S(%d,%d)\n", l, r);

  }
}

/* */
int main ( ) {
  clock_t start, end;
  double elapsed_time;
  int n = 8; /*quantidade de elementos*/
  int A[] = {5, 2, 7, 4, 8, 1, 9, 8};
  int O[n];  /*vetor auxiliar*/
  start = clock();
  print (A, n, "Input");
  merge_sort (A, 0, n-1, O, 0);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}

