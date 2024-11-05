#pragma once

#include <string>
#include <vector>
using namespace std;

class Pessoa;

class Familia {
private:
    Pessoa* pPrincipal;
    Pessoa* pConjuge;
    vector<Pessoa*> listaFilhos;
    string sobrenome;

public:
    Familia(const char* sobrenomeF = "");
    Familia(char* sobrenomeF);
    ~Familia();

    string getSobrenome();
    void listarArvoreFamiliar();
    void adicionarFilho(Pessoa* pFilho);
    void setPrincipal(Pessoa* p);
    void setConjuge(Pessoa* p);
};
