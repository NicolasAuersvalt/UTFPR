#include "list.h"

List* create_circular (List *head) {
  if(head!=NULL){
    List *tail = head;
    while(tail->next != NULL)
      tail = tail->next;
    tail->next = head;
    head -> prev = tail;
}

int main () {
  int i;	
  int n = 4;	
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  print (l);
  l = create_circular(l);
  print (l);
  destroy (l);
  return 0;
} 
