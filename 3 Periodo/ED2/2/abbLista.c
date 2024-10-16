#include "abbLista.h"
const int INF = 10000000;

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
	/* Completar */

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
				Arvore *tmp = a->esq;
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
// Arvore vazia
int min(Arvore *a){

	printf("Nó %d\n", a->info);
	int esq = a->info, dir = a->info;

	if(a->esq != NULL) esq = min(a->esq);
	if(a->dir != NULL) dir = min(a->dir);

	return esq > dir ? dir : esq;
}
//========= Q2 - max =====
int max(Arvore *a){

	printf("Nó %d\n", a->info);
	int esq = a->info, dir = a->info;

	if(a->esq != NULL) esq = max(a->esq);
	if(a->dir != NULL) dir = max(a->dir);

	return esq < dir ? dir : esq;
}

//========= Q3 - imprime_decrescente =====

void imprime_decrescente(Arvore *a){
	if(a != NULL){
		imprime_decrescente(a->dir);
		imprime_decrescente(a->esq);
		printf("%d", a->info);
	}
}


//========= Q4 - maior ramo =====

int maior_ramo(Arvore *a){
	if(a == NULL){
		return 0;
	}
	int
	maior_ramo(a->esq)+a->info > maior_ramo(a->dir) 
	return max(maior_ramo(a->esq)+a->info, maior_ramo(a->dir);
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

	a = inserir (a, 50);
	a = inserir (a, 30);
	a = inserir (a, 90);
	a = inserir (a, 20);
	a = inserir (a, 40);
	a = inserir (a, 95);
	a = inserir (a, 10);
	a = inserir (a, 35);
	a = inserir (a, 45);

	//....

	printf("\n");
	pre_order (a);	
	printf("\n");

	// printf("Minimo é %d",min(a));

	// printf("Max é %d",max(a));
	
	imprime_decrescente(a);

	// ====== Q5 ====

	return 0;
}


