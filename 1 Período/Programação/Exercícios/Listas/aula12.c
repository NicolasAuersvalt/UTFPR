
/* #include <stdio.h>

void segundosParaHMS(int *total_segundos, int *h, int *m, int *s) {
  int total = *total_segundos;

  if (total >= 60) {
    *m = (total / 60);
    if (*m >= 60) {
      *s = (total % 60);
      *h = (*m / 60);
    }

    *m %= 60;

    printf("%d:%d:%d", *s, *m, *h);
  }
}

int main() {

  int total_segundos = 0, h = 0, m = 0, s = 0;

  scanf("%d", &total_segundos);

  segundosParaHMS(&total_segundos, &h, &m, &s);

  return 0;
}
*/
#include <stdio.h>

void removeExtremos(int *n, int *pri, int *ult, int *pot) {
  int tn;
  tn = *n;
  while (tn >= 10) {
    tn = tn / 10;
    *pot *= 10;
  }
  *pri = *n / *pot;
  *ult = *n % 10;
  *n = *n % *pot;
  *n = *n / 10;
}

int main() {
  int n = 0, pri = 0, ult = 0, pot = 1;

  printf("Digite um valor \n");
  scanf("%d", &n); // Não conterá digito 0

  removeExtremos(&n, &pri, &ult, &pot);

  if ((pri == ult) && (n / 10 == n % 10)) {
    printf("\nÉ um palíndromo!");
  }

  return 0;
}