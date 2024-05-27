#include "utils.h"

/* */
void counting_sort (FILE *f, int range) {
  int i, j, total = 0;
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/
  /*Terminar*/
  /*Imprimir no final desta função as frequências das letras!*/
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

