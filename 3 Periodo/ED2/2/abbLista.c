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
	int esq=INF, dir=INF;

	if(a->esq != NULL) esq = min(a->esq);
	if(a->dir != NULL) dir = min(a->dir);

	printf("%d\n", esq);
	printf("%d\n", dir);
	return esq > dir ? dir : esq;
}
//========= Q2 - max =====

//========= Q3 - imprime_decrescente =====


//========= Q4 - maior ramo =====


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

	printf("%d",min(a));

	// ====== Q5 ====

	return 0;
}


