#include "stdafx.h"
#include "Departamento.h"

#include "Universidade.h"
#include "Disciplina.h"


Departamento::Departamento()
{
    pDisciplPrim  = NULL;
    pDisciplAtual = NULL; 
}

Departamento::~Departamento()
{
    pDisciplPrim  = NULL;
    pDisciplAtual = NULL; 
}

void Departamento::setNome(char* n)
{
    strcpy(nome, n);
}

char* Departamento::getNome()
{
    return nome;
}

void Departamento::setUniversidade ( Universidade* pu )
{
   pUniv = pu;
}

Universidade* Departamento::getUniversidade ( )
{
   return pUniv;
}

void Departamento::setDisciplina ( Disciplina* pd )
{
     if ( pDisciplPrim == NULL )
     {
        pDisciplPrim  = pd;
        pDisciplAtual = pd;
     }
     else
     {
        pDisciplAtual->pProx = pd;
        pd->pAnte = pDisciplAtual;
        pDisciplAtual = pd;
     }
}

void Departamento::listeDisciplinas ( )
{
     Disciplina* paux;
     paux = pDisciplPrim;
     while ( paux != NULL )
     {
        //printf(" A disciplina %s pertence ao Departamento %s. \n", aux->getNome(), nome );
        cout << " A disciplina " << paux->getNome() << " pertence ao Departamento " << nome << "." << endl;
        paux = paux->pProx;
     }
}

void Departamento::listeDisciplinas2 ( )
{
     Disciplina* paux;
     paux = pDisciplAtual;
     while ( paux != NULL )
     {
        //printf(" A disciplina %s pertence ao Departamento %s \n", aux->getNome(), nome);
		cout << " A disciplina " << paux->getNome() << " pertence ao Departamento " << nome << "." << endl;
        paux = paux->pAnte;
     }
}

