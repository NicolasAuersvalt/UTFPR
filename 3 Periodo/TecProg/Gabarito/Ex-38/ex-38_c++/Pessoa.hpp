#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Pessoa {
    protected:
    string nome;
    int idade;
    public:
    Pessoa(const string nome_="",const int idade_=-1);
    ~Pessoa();

    virtual void Mostradados();
};