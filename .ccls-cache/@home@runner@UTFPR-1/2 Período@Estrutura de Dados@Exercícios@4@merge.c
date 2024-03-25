#include "list.h"

List *merge(List *A, List *B) {
  /*Terminar*/
  List *c, *a, *b;

  c = (List *)malloc(sizeof(List));

  for (/*  */; (a != NULL) || (b != NULL); /*  */) {
    // Primeiro verifica se algum deles é nulo

    if (a->data == b->data) {
      // coloca os dois elementos em seguida

      c->data = a->data;

      // Desloca
      c = c->next;

      c->data = b->data;

    } else if (a->data < b->data) { // a < b
                                    // Coloca o a, depois o b
      c->data = a->data;

      // Desloca
      c = c->next;

      c->data = b->data;

    }

    else if (a->data < b->data) { // a < b

      c->data = b->data;

      // Desloca
      c = c->next;

      c->data = a->data;
    }

    a = a->next;
    b = b->next;
  }

  // Pega o resto ou só retorna

  if (a != NULL) {

    // Adiciona o restante de a em c
    c->next = a->next;

  } else if (b != NULL) {

    // Adiciona o restante de b em c
    c->next = b->next;
  }
  return c;
}

/**/
int main() {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2)
    A = insert(A, k);
  for (k = 19; k >= 0; k -= 2)
    B = insert(B, k);
  print(A);
  print(B);
  List *C = merge(A, B);
  print(C);
  destroy(C);
  return 0;
}
