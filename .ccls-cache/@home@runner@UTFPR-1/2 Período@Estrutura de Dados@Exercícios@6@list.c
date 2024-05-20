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

List* remove_all(List *l, int k){
  if(l==NULL)
	  return l;
  else{
    if(l->data == k){
    	List *n = l->next;
	free(l);
	l=n;
	remove_all(l->next, k);
    }

	remove_all(l->next, k);
  }
  return l;
}

List* copy(List *L){
  if(L==NULL){
    return NULL;
  }
  else{
  List *copia = (List*)malloc(sizeof(int));
  copia->data=L->data;
  copia->next = copy(L->next);
  return copia;
  }
}

int similar (List *A, List *B){
  if((A==NULL) && (B==NULL)){
    if(A->data == B->data){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if(A!=NULL && B!= NULL){
    return similar(A->next, B->next);
  }
  else if(A==NULL){
    return similar(A, B->next);
  }
  else{
    return similar(B, B);
  }
}

List* intersection (List *A, List *B){
  if(A==NULL && B==NULL){
    List *t = A;
    intersection(A->next, B->next);
  }
  else if(A!=NULL && B!=NULL){
    if(A->data > B->data){
      List *t;
      t = A;
      t->next = intersection(A, B->next);
      return t;
    }
    if(A->data < B->data){
      List *t;
      t = B;
      t->next = intersection(A->next, B);
      return t;
    }
    else if(A==NULL){
      List *t = B;
      return t;
    }
    else{
      List *t = A;
      return t;
    }
  }
}