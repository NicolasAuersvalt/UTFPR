#include<stdio.h>

int insertion(int *A, int n){

	int i;

	// Percorre todo o vetor
	for(i=1; i<n; i++){
		// Cada posição será a chave
		int key = A[i];

		// Declara uma posição anterior
		int j = i-1;

		// Pega esse j e vai voltando até o começo do vetor
		while((j>=0)&&(key<A[j])){
			// Enquanto a chave for menor que cada posição desse
			// j, desloca uma posição para frente do vetor
			
			// Dica, não precisa se preocupar com o A[i] pois
			// a chave está salva em key
			A[j+1] = A[j];
		}
		// Após deslocar tudo, coloca a chave em sua posição ordenada
		A[j+1] = key;
	}

}

int main(){
	
	// Percorre todo o vetor
	
	// Seleciona uma chave e compara para ver se todos os anteriores são menores
	
		// Caso não seja
		// Desloca todos os elementos 1 casa à direita e posiciona a chave


	return 0;
}

