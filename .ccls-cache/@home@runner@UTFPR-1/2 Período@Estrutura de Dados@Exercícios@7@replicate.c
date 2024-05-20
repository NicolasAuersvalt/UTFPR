#include "list.h"

List* replicate (List *l, int k) {
  /*Terminar!*/	
  List *t = l;
  int i;
  while(t!=NULL){
    for(i=1;i<k;i++){
      List *node = (List*)malloc(sizeof(List));
      printf("Teste\n");
      node->data = t->data;
      node->prev = t;
      node->next = t->next;
      t->next = node;
      t=t->next;
    }
    t=t->next;
  }
  return l;
}

int main (){ 
  int i;	
  int k = 3;	
  int n = 4;	
  List *l = create ();
  for (i = n; i >= 1; i--) {
    l = insert_front (l, i);
  }
  print (l);
  l = replicate (l, k);
  print (l);
  destroy (l);
  return 0;
} 
