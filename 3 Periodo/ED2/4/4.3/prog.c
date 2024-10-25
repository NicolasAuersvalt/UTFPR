#include "avl.h"

int main () {

   Arvore *AVL = NULL;
  

   /*TERMINAR (INSERIR DEMAIS CHAVES)!!!*/

   AVL = inserir(AVL, "Nicolas");
   AVL = inserir(AVL, "Ciclano");
   AVL = inserir(AVL, "Bruno");
   AVL = inserir(AVL, "Pedro");
   AVL = inserir(AVL, "Leandro");
   AVL = inserir(AVL, "Renato");

   //AVL = remover (AVL, 'A');
   //AVL = remover (AVL, 'H');
   //AVL = remover (AVL, 'E');
   //AVL = remover (AVL, 'W');
   //AVL = remover (AVL, 'G');
   //AVL = remover (AVL, 'N');
   //AVL = remover (AVL, 'P');
   //AVL = remover (AVL, 'O');

   imprimir_in_order (AVL, 0);

   return 0;
}
