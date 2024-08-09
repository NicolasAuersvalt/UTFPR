
/*
#define BUFLEN 1024

empacotaString (char* string);

int main() {
  
char buffer [BUFLEN];
char *resp;
  
fgets (buffer, BUFLEN, stdin);
// stdin - entrada padrão tipo scanf

buffer[strlen(buffer)-1]='\0';
// Tamanho da string ("N i c o l a s \n \0") - 1
// buffer ficará, então:
// ("N i c o l a s \n")

resp = empacotaString(buffer);
// Passando o endereço de memória da string (buffer)

free(resp);
// Libera a memória alocada

return 0;

}
  
char* empacotaString (char input[]){

 int i, tam;

 char *empac;
// Empacota a string

 tam = strlen(input);
 // strlen - tamanho da string

empac = (char*) malloc ((tam+1) * sizeof(char));
// malloc - alocar memória (tam++ * tamanho da string)

for(i=0; i<tam; i++){

  // Percorrerá a string e empacota cada caractere
  empac[i] = input[i];
}

// Finaliza a string
empac[i] = '\0';

// Retorna a string empacota
return (empac);

}
*/

#define BUFLEN 1024;

concatenaStrings (char* s1, char* s2);

int main() {
  char buffer[BUFLEN];
  
  char s1, s2;

  fgets(buffer, BUFLEN,)


    matriz = [
              (1, 2, 3),
              (4, 5, 6),
              (7, 8, 9)
            ]
  
	return 0;
}

char* concatenaStrings (char* s1, char* s2){

  char

  
}

  