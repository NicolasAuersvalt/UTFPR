#include "stack.h"

int parser (char *c) {
  Stack *s = create(strlen(c));
  int i = 0;

  while (c[i] != '\0') {
    /*Terminar*/

   if((c[i]=='(') || (c[i]=='[')){
   	push(s, c[i]);
   }
   else if(c[i]==')'){
   	if(empty(s) || (pop(s) == '(')){
	       return 0;	
	}
	
   }
   else if(c[i]==']'){
	if(empty(s) || (pop(s) == '[')){
		return 0;
	}
   }
    
    /*Utilizar somente as operações push, pop, empty, ... (interface)*/	  
    
    i++;    
  }

  if(empty(s)){
  	return 1;
  }
  else{
  	return 0;
  }

}

int main () {
  //char *c = "( ( ) [ ( ) ] )";
  char *c = "( [ ) ]";
  //char *c = "( ) [ ]";
  //char *c = "( [ ]";
  //char *c = ") (";
  if (parser(c)) 
    printf("true  (bem formada)\n");
  else  
    printf("false (mal formada)\n");
  return 0;
}
