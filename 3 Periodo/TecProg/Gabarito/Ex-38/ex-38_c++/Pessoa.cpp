#include "Pessoa.hpp"

Pessoa::Pessoa(const string nome_,const int idade_){
    nome = nome_;
    idade = idade_;
}
Pessoa::~Pessoa(){

}


void Pessoa::Mostradados(){
        cout<<"Nome da pessoa: "<<nome<<endl;
        cout<<"Idade da pessoa: "<<idade<<endl<<endl;
}