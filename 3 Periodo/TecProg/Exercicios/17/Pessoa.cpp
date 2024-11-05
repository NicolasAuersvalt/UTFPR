#include "Pessoa.h"
#include <iostream>
using namespace std;

Pessoa::Pessoa() : idade(0), Univ(nullptr) {}

Pessoa::~Pessoa() {}

void Pessoa::setNome(string nomeP) {
    nome = nomeP;
}

string Pessoa::getNome() {
    return nome;
}

void Pessoa::setIdade(int idadeP) {
    idade = idadeP;
}

int Pessoa::getIdade() {
    if (idade > 0) {
        return idade;
    } else {
        cout << "Idade Incorreta" << endl;
        return -1;  // Valor de erro
    }
}

void Pessoa::setUniversidade(Universidade* uni) {
    Univ = uni;
}

string Pessoa::getUniversidade() {
    return (Univ != nullptr) ? Univ->getNome() : "Nenhuma universidade atribuída";
}
