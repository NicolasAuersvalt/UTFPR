#include <stdio.h>
#include <stdlib.h>

/*====================================================================*/
// IMPORTANTE
int *criaHistograma(int largura, int *val, int n_faixa, int n, int *total) {
  // Encontrar o valor mínimo e máximo
  int min_val = val[0];
  int i, faixa;
  *total = 0;
  int histograma[n_faixa];

  for (i = 1; i < n; i++) {
    if (val[i] < min_val)
      min_val = val[i];
  }
 
  for (i = 0; i < n_faixa; i++)
    histograma[i] = 0;
  
  // Contar as ocorrências de cada valor na faixa correspondente
  for (i = 0; i < n; i++) {

    faixa = (val[i] - min_val) / largura;
    histograma[faixa]++;
  }

  // Calcular o total de ocorrências
  for (i = 0; i < n_faixa; i++) {
    *total += histograma[i];
    // Teste
    printf("[%d - %d]: %d\n", min_val + i * largura, min_val + (i + 1) *largura - 1, histograma[i]);
  }

  return total;
}
/*====================================================================*/
// IRRELEVANTE
int main() {
  int valores[] = {1, 5, 2, 3, 4, 6, 7, 8, 9, 9, 10, 11, 12, 12, 16, 20};
  int n = sizeof(valores) / sizeof(valores[0]);
  int total;

  int *histograma = criaHistograma(5, valores, 4, n, &total);

  printf("\nTotal de Ocorrências: %d\n", total);

  // Liberar a memória alocada para o histograma
  free(histograma);

  return 0;
}