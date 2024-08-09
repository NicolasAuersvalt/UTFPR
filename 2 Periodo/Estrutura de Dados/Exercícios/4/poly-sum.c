#include "plist.h"

List* poly_sum (List *pA, List *pB) {
  /*Terminar!*/	
  List *head=NULL, *temp;

  while((pA != NULL) && (pB != NULL)){
    if(pA==NULL){
      temp->next = pB;
    }
    else if(pB==NULL){
      temp->next = pA;
    }

    else if(pA->p.d == pB->p.d){ // Sum -> Link to a
      if(head == NULL){
        head=pA;
        temp=pA;
      }
      pA->p.c += pB->p.c;
      temp->next=pA;
      temp=temp->next;
      pA = pA->next;
      pB = pB->next;
      
    }
    else if(pA->p.d < pB->p.d){ // Fixes A and moves a=a->next
      if(head==NULL){ 
        head = pB;
        temp = pB;
      }
      else{
      temp->next = pB;
      temp = temp->next;
      }
      pA=pA->next;
    }
    else if(pA->p.d > pB->p.d){ // Fixes A and moves a=a->next
      if(head==NULL){ 
        head = pA;
        temp = pA;
      }
      else{
      temp->next = pA;
      temp = temp->next;
      }
      pB=pB->next;
    }
  }
  return head;
}

int main () {

  List *pA = create ();
  pA = insert (pA, (poly){2, 0});
  pA = insert (pA, (poly){4, 1});
  pA = insert (pA, (poly){5, 2});
  pA = insert (pA, (poly){7, 5});
  print (pA);

  List *pB = create ();
  pB = insert (pB, (poly){-5, 0});
  pB = insert (pB, (poly){-4, 1});
  pB = insert (pB, (poly){5, 2});
  pB = insert (pB, (poly){3, 6});
  print (pB);

  List *pC = poly_sum (pA, pB);
  print (pC);

  destroy (pA);
  destroy (pB);
  destroy (pC);
}
