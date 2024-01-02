#include <stdio.h>
#include <stdlib.h>
#define N_FAIXAS 4
#define N_CRIANCAS 16
#define LARGURA 5 

int* criaHistograma(int* val, int* total);

int main()
{
    int consumo[N_CRIANCAS] = { 1, 5, 2, 3, 4, 6, 7, 8, 9, 9, 10, 11, 12, 12, 16, 20 };

    int consumo_total;

  //IMPORTANTE (verificar se largura realmente foi dado como macro)
    int* hist = criaHistograma(consumo, &consumo_total);
  

    printf("\nTotal de Ocorrências: %d\n", hist);

    return 0;
}

