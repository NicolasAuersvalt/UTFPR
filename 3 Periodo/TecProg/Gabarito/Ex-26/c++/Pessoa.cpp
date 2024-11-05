#include "Pessoa.h"
#include "Familia.h"

#include <iostream>
#include <string>
using namespace std;

Pessoa::Pessoa(const char* n, Pessoa* pMae, Pessoa* pPai) :
nome(n),
mae(pMae),
pai(pPai) {
    pFamilia = NULL;
}

Pessoa::Pessoa(char* n, Pessoa* pMae, Pessoa* pPai) :
nome(n),
mae(pMae),
pai(pPai) {
    pFamilia = NULL;
}

Pessoa::~Pessoa() {
    pai = NULL;
    mae = NULL;
    pFamilia = NULL;
}

string Pessoa::getNome() {
    return nome;
}

string Pessoa::getNomeCompleto() {
    string nomeCompleto = nome;

    if (pFamilia != NULL) {
        nomeCompleto += " ";
        nomeCompleto += pFamilia->getSobrenome();
    }

    return nomeCompleto;
}

void Pessoa::setNome(string* nome) {
    this->nome = *nome;
}

void Pessoa::imprimeNomeCompleto() const {
    if (pFamilia)
        cout << nome << " " << pFamilia->getSobrenome() << endl;
    else
        cout << nome << endl;
}

void Pessoa::setFamilia(Familia* pFm) {
    this->pFamilia = pFm;
}

void Pessoa::setMae(Pessoa* pMae) {
    if (pMae == NULL) {
        cout << "Ponteiro para mae NULL" << endl;
        return;
    }
    this->mae = pMae;
}

void Pessoa::setPai(Pessoa* pPai) {
    if (pPai == NULL) {
        cout << "Ponteiro para pai NULL" << endl;
        return;
    }
    this->pai = pPai;
}

void Pessoa::adicionarFilho(Pessoa* pFilho) {
    if (pFilho == NULL) {
        cout << "Ponteiro para filho NULL" << endl;
        return;
    }
    listaFilhos.push_back(pFilho);
}

void Pessoa::listarFilhos() {
    if (listaFilhos.size() < 1) {
        cout << getNomeCompleto() << " não possui filhos!" << endl;
        return;
    }

    cout << "Filhos de " << getNomeCompleto() << ":" << endl;

    for (int i = 0; i < listaFilhos.size(); i++) {
        cout << " - " << listaFilhos[i]->getNomeCompleto() << endl;
    }
}