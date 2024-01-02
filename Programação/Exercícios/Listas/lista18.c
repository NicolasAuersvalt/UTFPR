/*
#include <stdio.h>
#define N 3

int main(){

  int matriz[N][N];
  int somador = 1, col_min=1, lin_min=0, tam_min=0,
  tam_max = N;
  int coluna = 0, linha = 0, tamanho = N;

  while(somador <= (N*N)){

    // IDA
    printf("IDA\n");

    for(coluna; coluna<tamanho; coluna++){
      matriz[coluna][linha] = somador;
      somador++;
      printf("[%d]", matriz[coluna][linha]);
  }

    // Desce uma linha para baixo
    linha++;
    printf("\n");

    // DESCIDA
    printf("DESCIDA\n");

    for(linha; linha<tamanho-1; linha++){
      matriz[coluna][linha] = somador;
      somador++;
      printf("[%d]", matriz[coluna][linha]);
    }

    printf("\n");
    // Atualiza o valor do tamanho máximo
    tam_max--;


    // VOLTA
    printf("VOLTA\n");

    for(coluna; coluna>tam_min+1; coluna--){
      matriz[coluna][linha] = somador;
      somador++;
      printf("[%d]", matriz[coluna][linha]);
    }

    printf("\n");

    // SUBIDA
    printf("SUBIDA\n");

    for(linha; linha<tam_min-1; linha--){
      matriz[coluna][linha] = somador;
      somador++;
      printf("[%d]", matriz[coluna][linha]);
    }

    printf("\n");

    // Atualiza o valor mínimo
    tam_min++;

    printf("\n \n");



  }
  for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("[%d]", matriz[coluna][linha]);
        }
        printf("\n");
    }
}
*/

#include <stdio.h>

#define N 5

int main(){

  matriz[N][N] = {{A,B,C,D,E},{A,B,C,D,E},{A,B,C,D,E}};
  
  
}