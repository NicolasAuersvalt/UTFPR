#include "arvore.h"


Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

//========= Exercício 2 - pré-ordem ====


//========= Exercício 2 - in-ordem ====


//========= Exercício 2 - pós-ordem ====


//========= Exercício 3 - pertence ====
int pertence(Arvore *a, char c){
	if(a->info != c){
		if(a->esq != NULL){
			if(pertence(a->esq, c)) return 1;
		}
		if(a->dir != NULL){
			if(pertence(a->dir, c)) return 1;
		}
		return 0;
	}
	else{
		return 1;
	}
}


//========= Exercício 4 - conta nós ====

int conta_nos(Arvore *a){
	// printf("%c", a->info);
	int ramo = 1;
	if(a->info == NULL){
		return 1;
	}
	if(a->esq != NULL){
		ramo += conta_nos(a->esq);
	}
	if(a->dir != NULL){
		ramo += conta_nos(a->dir);
	}
	return ramo;
}


//========= Exercício 5 - calcula altura ====

int altura(Arvore *a){
	printf("%c", a->info);
	int altura_esq = 1, altura_dir=1;
	if(a->info == NULL){
		return 1;
	}
	else if(a->esq !=NULL)
		altura_esq += altura(a->esq);

	else if(a->dir !=NULL)
		altura_dir += altura(a->dir);

	if(altura_dir > altura_esq)
		return altura_dir;
	return altura_esq;
}


//========= Exercício 6 - conta folhas ====

int conta_nos_folha(Arvore *a){
	printf("%c", a->info);
	if(a->info == NULL){
		return 0;
	}
	
	if(a->esq == NULL && a->dir == NULL){
		return 1;
	}
	int node = 0;
	if(a->esq != NULL)
		node += conta_nos_folha(a->esq);
	if(a->dir != NULL) 
		node += conta_nos_folha(a->dir);
	return node;

}

int main (int argc, char *argv[]) {

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );	

   printf("%d", conta_nos_folha(a));


   arv_libera (a);

   return 0;
}

 
