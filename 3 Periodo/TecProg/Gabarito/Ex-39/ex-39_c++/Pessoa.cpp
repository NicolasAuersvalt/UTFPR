#include "Pessoa.hpp"

int Pessoa::pessoas(0);

Pessoa::Pessoa(const string nome_,const int idade_){
    pessoas++;
    nome = nome_;
    idade = idade_;
}
Pessoa::~Pessoa(){
    pessoas--;
}


void Pessoa::Mostradados(){
        cout<<"Nome da pessoa: "<<nome<<endl;
        cout<<"Idade da pessoa: "<<idade<<endl<<endl;
}

int Pessoa::QuantidadePessoas(){
    return pessoas;
}