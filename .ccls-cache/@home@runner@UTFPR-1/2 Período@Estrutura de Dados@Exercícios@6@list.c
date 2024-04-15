#include "list.h"

/* */
List* insert_back (List *l, int k) {
  if (l == NULL) {
    l = (Node*)malloc(sizeof(Node));
    l->data = k;
    l->next = NULL;
  }
  else {
    l->next = insert_back (l->next, k);
  }
  return l;
}

/* */
List* removek (List *l, int k) {
  if(l==NULL){
    return l;
  }
  else{
    if(l->data == k){
      List *n = l->next;
      free(l);
      l = n;
      return l;
    }
    else{
      return removek(l->next, k);
    }
  }
}

/* */
void print (List* l) {
  if (l != NULL) {
    printf("%d ", l->data);
    print (l->next);      
  }
}

/* */
void destroy (List *l) {
  if(l==0){
    
  }
  else{
    destroy(l->next);
    free(l);
  }
}

int max(List *l){
  if(l!=NULL){
    int n = max(l->next);
    if (n>l->data){
      return n;
    }
    else
      return l->data;
    
  }
  else{
    return l->data;
  }
  
  
}

