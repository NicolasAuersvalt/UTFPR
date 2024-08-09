#include "utils.h"
#include <math.h>
#include <string.h>

/* */
int linear_search(char **words, int n, char *key) {
  /*Terminar*/
  int i;
  for (i = 0; i < n; i++) {
    if (strcmp(words[i], key) == 0)
      return i;
  }
  return i;
}

/* */
int binary_search_iterative(char **words, int n, char *key) {
  /*Terminar*/
  // Pega o meio, tendo a esquerda e direita
  int l = 0, r = n - 1;

  // Enquanto a direita for maior que a esquerda
  while (r >= l) {

    // Meio
    int m = (r + l) / 2;
    if (strcmp(words[m], key) == 0)
      return m;

    // Se for maior
    else if (strcmp(words[m], key) > 0) {

      // Esquerda será o ponto médio para limitar o intervalor
      r = m - 1;
    }

    // Se for menor
    else if (strcmp(words[m], key) < 0)

      // Direita será o ponto médio
      l = m + 1;
  }

  // Não encontrou
  return 0;
}

/* */
int binary_search_recursive(char **words, int l, int r, char *key) {

  if(r<=l){
    return 0;
  }

    // Meio
    int m = (r + l) / 2;
    if (strcmp(words[m], key) == 0)
      return m;

    // Se for maior
    else if (strcmp(words[m], key) > 0) {

      // Esquerda será o ponto médio para limitar o intervalor
      return binary_search_recursive(words, l, m-1, key);
    }

    // Se for menor
    else if (strcmp(words[m], key) < 0)

      // Direita será o ponto médio
      return binary_search_recursive(words, m+1, r, key);
  
}

/* */
int get_number_of_lines(FILE *f) {
  int n = 0;
  if (f == NULL)
    return n;
  while (!feof(f)) {
    char c;
    fscanf(f, "%c", &c);
    if (c == '\n')
      n++;
  }
  rewind(f);
  return (n - 1);
}

/* */
int main(int argc, char *argv[]) {
  /*if (argc < 2) {
    printf("run: %s [word_to_search]\n", argv[0]);
    exit(1);
    }*/
  clock_t start, end;
  double elapsed_time;
  // char *key = argv[1];
  char *key = "ACADEMICO";
  FILE *f = fopen("palavras.txt", "r");
  int n = get_number_of_lines(f);
  char **words = (char **)malloc(n * sizeof(char *));
  int i, index;
  for (i = 0; i < n; i++)
    words[i] = (char *)malloc(256 * sizeof(char));
  i = 0;
  while (!feof(f)) {
    fscanf(f, "%s", words[i]);
    i++;
  }

  /*Busca linear*/
  start = clock();
  index = linear_search(words, n, key);
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time (linear): %.2f\n", elapsed_time);
  if (index >= 0) {
    printf("Key %s, found at %d\n", key, index);
  } else {
    printf("Element not found.\n");
  }

  /*Busca binária iterativa*/
  start = clock();
  index = binary_search_iterative(words, n, key);
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time (binary): %.2f\n", elapsed_time);
  if (index >= 0) {
    printf("Key %s, found at %d\n", key, index);
  } else {
    printf("Element not found.\n");
  }

  /*Busca binária recursiva*/
  start = clock();
  index = binary_search_recursive(words, 0, n - 1, key);
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time (binary): %.2f\n", elapsed_time);
  if (index >= 0) {
    printf("Key %s, found at %d\n", key, index);
  } else {
    printf("Element not found.\n");
  }

  /*Desalocando estruturas*/
  for (i = 0; i < n; i++)
    free(words[i]);
  free(words);
  fclose(f);
  return 0;
}
