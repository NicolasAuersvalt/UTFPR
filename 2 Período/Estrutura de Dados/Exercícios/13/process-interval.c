#include "utils.h"

/* */
int* process_interval (int *A, int n, int range) {
  int i, j;
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/
  /*Terminar*/

  // 1
  for(i=0; i<=range; i++){

    // Inicializa o vetor
    C[i]=0;
  }

  // 2
  for(j=0; j<=(n-1); j++){

    // Contagem de ocorrências
    C[A[j]] = C[A[j]]+1;

  }

  // 3 Acumula ocorrências
  for(i=1; i<=range; i++){

    // Acumula as ocorrências
    C[i] = C[i] + C[i-1];

  }
  
  return C;
}

int query (int *C, int n, int i, int j) {
  /*Terminar*/
  /*Não pode ter laço de repetição!*/

  if(i==j)
    return C[j];
    
  else
    return C[j]-C[i];
}

/* */
int main () {
  int a, b, n = 15;
  int range = 10;
  int A[] = {9,2,0,8,7,9,3,2,0,7,5,0,2,6,0};
  print (A, n, "Input");
  int *C = process_interval (A, n, range);
  a = 0, b = 3;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 4, b = 8;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 0, b = 0;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 6, b = 6;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 2, b = 4;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 9, b = 9;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  return 0;
}

