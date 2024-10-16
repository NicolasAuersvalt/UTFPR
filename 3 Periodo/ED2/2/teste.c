#include "abbLista.h"
const int Maximo = 10^7;

Arvore* cria_arvore_vazia (void) {
	return NULL;
}

void arvore_libera (Arvore* a) {
	if (a != NULL) {
		arvore_libera (a->esq);
		arvore_libera (a->dir);
		free(a);
	}
}

//========= Q1 - inserir
Arvore* inserir (Arvore *a, int v) {

	if(a == NULL){
		a = (Arvore*)malloc(sizeof(Arvore));
		a->info = v;
		a->esq = NULL;
		a->dir = NULL;
	}
	else if(v < a->info){
		a->esq = inserir(a->esq, v);
	}
	else{
		a->esq = inserir(a->dir, v);

	}
	return a;
}

//========= Q1 - remover
Arvore* remover (Arvore *a, int v) {
	/* Completar */
	if(a==NULL){return NULL;}
	else{
		if(a->info > v){
			a->esq = remover(a->esq,v);
		}
		else if(a->info < v){
			a->dir = remover(a->dir,v);

		}
		else{
			if((a->esq == NULL) && (a->dir == NULL)){
				free(a);
				a = NULL;
			}
			else if(a->dir == NULL){
				Arvore *tmp = a;
				a = a->esq;
				free(tmp);
			}
			else if(a->esq == NULL){
				Arvore *tmp = a;
				a = a->dir;
				free(tmp);
			}
			else{
				Arovre *tmp = a->esq;
				while(tmp -> dir != NULL)
					tmp = tmp -> dir;
				a->info = tmp -> info;
				tmp->info = v;
				a->esq = remover(a->esq, v);
			}
		}
	}
	return a;
}


//========= Q1 - busca
int buscar (Arvore *a, int v) {
	/* Completar */
	if(a == NULL){return 0;}
	else if(v< a->info){
		return buscar(a->esq, v);
	}
	else if(v>a->info){
		return buscar(a->dir, v);
	}
	else{
		return 1;
	}

	return 1; 

}

//========= Q2 - min =====


int min(Arvore *a){

	// Arvore vazia
	if(a->info == NULL){
		return 0;
	}
	else if(a->esq->info == NULL){
		return a->esq->info;
	}
	else{
		min(a->esq->info);
	}
}

//========= Q2 - max =====

int max(Arvore *a){

	// Arvore vazia
	if(a->info == NULL){
		return 0;
	}
	else if(a->esq->info == NULL){
		return a->dir->info;
	}
	else{
		max(a->dir->info);
	}
}

//========= Q3 - imprime_decrescente =====

void imprime_descrescente(Arvore *a){
	if(a->info == NULL){
		return 0;
	}
	imprime_decrescente(a->dir);
		imprime_decrescente(a->esq);
	printf("%d", a->info);
}


//========= Q4 - maior ramo =====

int maior_ramo(Arvore *a){
	if(a->info == NULL){
		return 0;
	}
	return max(maior_ramo(a->esq)+a->info, maior_ramo(a->dir);
}

int gerador(Arvore* a, int total, int desejado){
	for(int  i=0; i<total; i++){
		inserir(a, i);	
	}

	printf("%d", busca(a, desejado);

}

int ancestral(Arvore *a, int e1, int e2){
	if(a->NULL){
		return 0;
	}

	if(a->info > e1){
		if(ancestral(a->esq, e1, e2)) // Encontrou e1 à esquerda
			if(ancestral(a->dir, e1, e2)
					printf("%d", a->info);
					return 0;
	}
	if(a->info < e1){
		if(ancestral(a->dir, e1, e2))
			if(ancestral(a->esq, e1, e2)
					printf("%d", a->info);
					return 0;
	}
	if(a->info == e1 || a->info == e2){
		// Agora volta até encontrar o ancestral comum
		return 1;
	}

}

Arvore* constroi_balanceado(int vet[], int esq, int dir){

	// Escolhe o meio
	int meio = (esq + dir)/2;

	// Variaveis limites
	int left, right;

	// Cria a árvore
	Arvore a;
	cria_arvore_vazia();
	
	// Divide os elementos esq / dir
	
	left = 0;
	right = meio;

	// Bota o elemento central na raiz da arvore
	inserir(a, meio);

	divididor(a, vet, left, right);

	left = meio;
	right = dir;

	divididor(a,vet, left, right);
	return a;

}

int divididor(Arvore *a, vet[], int left, int right){
	// Esquerda primeiro

		// Se houver apenas 2 elementos em tal intervalo
	if((left+right) == 2){
		inserir(a, vet[left]);
		inserir(a, vet[right]);
		return 0;
	}

	// Pega a meiuca desse intervalo
	int subMeio = (left + right)/2;

	// Coloca como nova raiz interna
	inserir(a,subMeio);

	// obs, ele já vai colocar na esquerda da raiz
	divididor(a, vet, left, subMeio);
	divididor(a, vet, subMeio, right);
	return 0;
}


void pre_order (Arvore* a) {
	if (a != NULL) {
		printf("%d ", a->info);
		pre_order (a->esq);
		pre_order (a->dir);
	} 
}

int main () {

	int i;

	Arvore *a = cria_arvore_vazia ();

	//inserir
	//....

	printf("\n");
	pre_order (a);	
	printf("\n");


	// ====== Q5 ====
	gerador(a,10000,100000);

	return 0;
}


