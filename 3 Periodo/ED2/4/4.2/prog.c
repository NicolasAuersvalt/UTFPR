#include "avl.h"

int main () {

   Arvore *AVL = NULL;

   for(int i=0; i<=40; i++){
	AVL = inserir(AVL, i);
   }

   /*TERMINAR (INSERIR DEMAIS CHAVES)!!!*/

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