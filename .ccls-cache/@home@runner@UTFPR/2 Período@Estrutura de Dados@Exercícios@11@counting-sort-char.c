#include "utils.h"

/* */
void counting_sort (FILE *f, int range) {
  int i, j, total = 0;
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/
  /*Terminar*/
  
  // lê o arquivo
  while(!feof(f)){
    char ch;
    fscanf(f, "%c", &ch);
    if(isalpha(ch)){
      char nc = tolower(ch);
      int mapeado = nc - 'a';
      printf("%c mapeado para %d\n", nc, mapeado);
    }
  }

  /*Imprimir no final desta função as frequências das letras!*/

  int *T = (int *)malloc(n * sizeof(int)); /*temporário*/
  int *f = (int *)malloc((range+1) * sizeof(int)); /*contador*/

  /*Terminar*/

  // 1
  for(i=0; i<=range; i++){

    // Inicializa o vetor
    f[i]=0;
  }

  // 2
  for(j=0; j<=(n-1); j++){

    // Incrementa o contador
    f[A[j]] = f[A[j]]+1;

  }

  // 3
  for(i=1; i<=range; i++){

    // Acumula as ocorrências
    f[i] = f[i] + f[i-1];

  }

  // 4
  for(j=(n-1); j >= 0; j--){

    T[f[A[j]]-1] = A[j];
    f[A[j]] = f[A[j]] - 1;

  }

  // 5 Cópia de T para A

  for(i=0; i<n; i++){
    A[i] = T[i];

  }
  
  free (T);
  free (C);

}

/* */
int main (int argc, char *argv[]) {

  /*if (argc < 2) {
    printf("run: %s file.txt\n", argv[0]);
    exit(1);
  }*/

  //FILE *f = fopen(argv[1], "r");
  
  FILE *f = fopen("livro_pt.txt", "r");

  int range = 25; /*número de letras do alfabeto (a-z)*/

  counting_sort (f, range);
  
  fclose (f);

  return 0;
}

