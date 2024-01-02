/*
#include <stdio.h>
#define N_LINHAS 3
#define N_COLUNAS 4

int campo [N_LINHAS][N_COLUNAS] = { {81, 28, 240, 10},
{40, 10, 100, 240},
{20, 180, 110, 35} };


int main() {

  int max_coluna=0, max_linha=0;
  int soma_coluna, soma_linha, coluna, linha;

  // Percorre cada célula da linha
    for(linha=0; linha < N_LINHAS; linha++){ // 1
      soma_coluna = 0, soma_linha = 0;

      // Percorre cada célula da coluna
      for(coluna=0; coluna < N_COLUNAS; coluna++){

        // Soma todos elementos da coluna
        soma_coluna += campo[linha][coluna];

      }
      if(soma_coluna>max_coluna){
        // Substitui a coluna máxima
        max_coluna = soma_coluna;
      }
    }

  // Achando a Linha
  for(coluna=0; coluna < N_COLUNAS; coluna++){ // 1
    soma_coluna = 0, soma_linha = 0;

    // Percorre cada célula da linha
    for(linha=0; linha < N_LINHAS; linha++){

      // Soma todos elementos da linha
      soma_linha += campo[linha][coluna];

    }
    if(soma_linha>max_linha){
      // Substitui a linha máxima
      max_linha = soma_linha;
    }
  }

  if(max_linha>max_coluna){
    printf("Linha máxima é: %d", max_linha);
  }
 else{
    printf("Coluna máxima é: %d", max_coluna);
  }

    return 0;
}
*/

/*

#include<stdlib.h>
#define N 100


int main() {

  char vetor_strings[N_STRINGS][BUFLEN];

  for(int i=0; i<N_STRINGS; i++){

  fget(vetor_strings[i], BUFLEN, stdin);
    
  }

  for(i=N_STRINGS-1; i>=0; i++){

    printf("%s", vetor_strings[i]);
  }


  
  for()
  
    return 0;
}

*/

//int tabuleiro [N][N] = {{0,1},
  //                     {1,9}};


/*
int main(){

  int coluna, linha;

 // Se nas três posições houver mais preta -> (i,j) será branca

  for(linha = 1; linha<N; linha++){

    for(coluna=1; coluna< N; coluna++){

      int soma = tabuleiro[linha][coluna-1] + tabuleiro[linha-1][coluna-1] +
                 tabuleiro[linha-1][coluna];

      if(soma > 1){ // Mais Branca
        tabuleiro[linha][coluna] = 0; // Coloca preto
      }
      else{ // Mais preto
        tabuleiro[linha][coluna] = 1; // Coloca branco
      }
      printf("%d", tabuleiro[linha][coluna]);
    }
    printf("\n%d", tabuleiro[linha][coluna]);
  }
}
*/

#include <stdio.h>

int main() {
  // Your code here
  return 0;
}