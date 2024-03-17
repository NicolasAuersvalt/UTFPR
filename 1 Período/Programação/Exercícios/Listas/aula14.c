#include<stdio.h>

#define N 80

int main(){
  
int n, i, acertos = 0
  
  char gabarito[N], input[N];
  
  scanf("%d",&n);
  scanf("%s",gabarito);
  scanf("%s",input);
  
 for(i=0;i<n;i++){
   if(gabarito[i]==input[i])
      acertos++;
 }


printf("Acertos \n", acertos);


  return 0;
}