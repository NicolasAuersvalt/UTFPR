#include "stdafx.h"
#include "ElAluno.h"

ElAluno::ElAluno()
{
}

ElAluno::~ElAluno()
{

}

void ElAluno::setAluno(Aluno *pa) 
{  
   pAluno = pa; 
}

Aluno* ElAluno::getAluno() 
{   
   return pAluno; 
}

char* ElAluno::getNome() 
{
    return pAluno->getNome(); 
}
