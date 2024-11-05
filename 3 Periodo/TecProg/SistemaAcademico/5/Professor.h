
#ifndef _PROFESSOR_H_
#define _PROFESSOR_H_

#include "Pessoa.h"
#include "Universidade.h"

class Professor : public Pessoa
{
private:
   Universidade* pUnivFiliado;
   Departamento* pDptoFiliado;
   
public:
    Professor(	int diaNa, int mesNa, int anoNa, char* nome = "");
    Professor();
    ~Professor();

    void setUnivFiliado(Universidade* pu);
    void setDepartamento(Departamento* pdep);
    void OndeTrabalho();
    void QualDepartamentoTrabalho();
};

#endif