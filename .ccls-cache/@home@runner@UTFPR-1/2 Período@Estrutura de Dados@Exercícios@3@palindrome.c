#include "stack.h"

int palindrome (char *c) {

  Stack *s = create(strlen(c));
  Stack *apoio = create(strlen(c));
  Stack *inverso = create(strlen(c));
  int i;
  
  for(i=0; c[i] != '\0'; i++){
    push(s, c[i]);
    push(apoio, c[i]);
  }

  int j;

  while(!empty(s)){
    push(inverso, pop(s));
  }

  while(!empty(inverso)){
    if(pop(inverso) != pop(apoio)){
      return 0;
    }
  }
  
  return 1;
}

int main () {
  //char *c = "( ( ) [ ( ) ] )";
  char *c = "abccbal";
  if (palindrome(c)) 
    printf("É Palindromo\n");
  else  
    printf("Não é Palindromo\n");
  return 0;
}
