#include <stdio.h>
#include <stdlib.h>

void zigZag(int **m, int altura, int largura);*/
/*====================================================================*/
//IRRELEVANTE
  int main() {
  int altura = 4, largura = 5;
  // Allocate memory for a 2D array
  int **myArray = (int **)malloc(altura * sizeof(int *));
  for (int i = 0; i < altura; i++) {
    myArray[i] = (int *)malloc(largura * sizeof(int));
  }
  zigZag(myArray, altura, largura);

  for (int i = 0; i < altura; i++) {
    for (int j = 0; j < largura; j++) {
      printf("%2d ", myArray[i][j]);
    }
    printf("\n");
  }
  return 0;
}

/*====================================================================*/
//IMPORTANTE
void zigZag(int **m, int altura, int largura) {
  int cont = 1;
  
  // Preenche com os números nas colunas ímpares, descendo
  for (int i = 0; i < largura; i += 2) 
  {
    for (int j = 0; j < altura; j++) 
    {
      m[j][i] = cont;
      cont++;
    }
    cont += altura;
  }

  int cont2 = altura + 1;
  
  // Preenche com os números nas colunas pares, subindo
  for (int i = 1; i < largura; i += 2) 
  {
    for (int j = altura - 1; j >= 0; j--) 
    {
      m[j][i] = cont2;
      cont2++;
    }
    cont2 += altura;
  }
}
