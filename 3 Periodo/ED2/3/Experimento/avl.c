#include<stdio>

#include "avl.h"

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
	balancear(a);
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
	balancear(a);
	return a;
}

int nivelar(Arvore *a){

	if(a==NULL){
		return -1;
	}

	a->altura = nivelar(a->dir) - nivelar(a->esq);
	return a->altura;

}

void balancear(Arvore *a){
	// Percorre até as folhas
	
	// Chegou nas folhas
	if(a!=NULL){
		balancear(a->esq);
		balancear(a->dir);

		if(a->altura > 1){ // desbalanceado p direita
				   //
			// rotacao
			if(a->dir > 0){ // mesmo sinal -> Rotacao simples
				// cria um ponteiro de apoio
				Arvore *a = a->dir;

			}
			else if (a->dir < 0){ // Sinais diferentes -> dupla
				
			}
		}

		if(a->altura < -1){ // desbalanceado p esquerda
				    //
			// rotacao
			if(a->dir > 0){ // mesmo sinal -> Rotacao simples
				
			}
			else if (a->dir < 0){ // Sinais diferentes -> dupla
				
			}
		}

		else if(a->altura < 1){ // desbalanceado p esq

		}
	}

	else{
		
	}
}


int main(){

	

	return 0;
}
