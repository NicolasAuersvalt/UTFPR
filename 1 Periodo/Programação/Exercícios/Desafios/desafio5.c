#define BUFLEN 1024

codifica(unsigned char* msg, unsigned char* output);
mostraMensagem(unsigned char* input);

int main (){
  
int i;
  
unsigned char buffer [BUFLEN];
  
codifica ((unsigned char*) "Anna.", buffer);
  
// Supondo agora que o '.' delimita o fim da mensagem.
// Mostra os valores numéricos.
  
for (i = 0; buffer [i] != '.'; i++)
  printf ("%d ", buffer [i]);
  printf ("%d\n", buffer [i]);
  
  // Corrompe algum bit.
  buffer [2] = 236;
  mostraMensagem (buffer);
  
  return 0;
}


int contaUns(unsigned char x){
  int cont = 0;

  while(x>0){
    
  }
  
}
// Aponta para o vetor msg (buffer); aponta para o vetor output (mensagem codificada, buffer)
void codifica (unsigned char* msg, unsigned char* output)
{
  int uns = 0, pos = 0;
  char letras, nova_letra;

  // Loop que percorre cada letra da palavra ATÉ .
  for(pos; buffer [pos] != "."; pos++){

    letras = buffer [pos];
    
    // Percorre cada binário da letra
    while(letras > 0){
      if(letras & 1){
        uns++;
      }
      
      // Desloca o vetor 1 casa à direita
      letras =>> 1;
    }

    // Tem quantidade de uns ímpar
    if((uns % 2) != 0){ 
      
      letras = buffer [pos];
      nova_letra = letras | 0X80;
      output[letras] = nova_letra;
      
    }
    else(){
      output = buffer [letras];
    
    buffer[letras] = nova_letra;
    }
  }  

void mostraMensagem (unsigned char* input)
{
  int i;

  for(i=0; buffer[i] != '.'; i++){
    if()
    
  }

  
}
