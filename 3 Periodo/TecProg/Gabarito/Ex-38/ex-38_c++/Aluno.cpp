#include "Aluno.hpp"

Aluno::Aluno(const string nome,const int idade,const string curso):
Pessoa(nome,idade)
{
    this->curso = curso;
}

Aluno::~Aluno(){

}

void Aluno::Mostradados(){
        cout<<"Nome do aluno: "<<nome<<endl;
        cout<<"Idade do aluno: "<<idade<<endl;
        cout<<"Curso do aluno: "<<curso<<endl<<endl;
}