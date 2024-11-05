#pragma once

#include <string>
#include <vector>
using namespace std;

class Familia;

class Pessoa {
private:
    string nome;
    Pessoa* pai;
    Pessoa* mae;
    Familia* pFamilia;
    vector<Pessoa*> listaFilhos;

public:
    Pessoa(const char* n = "", Pessoa* pMae = NULL, Pessoa* pPai = NULL);
    Pessoa(char* n, Pessoa* pMae = NULL, Pessoa* pPai = NULL);
    ~Pessoa();

    string getNome();
    string getNomeCompleto();
    void setNome(string* nome);
    void imprimeNomeCompleto() const;
    void setFamilia(Familia* pFm);
    void setMae(Pessoa* pMae);
    void setPai(Pessoa* pPai);
    void adicionarFilho(Pessoa* pFilho);
    void listarFilhos();
};