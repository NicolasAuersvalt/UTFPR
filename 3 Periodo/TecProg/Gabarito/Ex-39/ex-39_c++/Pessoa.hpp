#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Pessoa {
    private:
    //Contador de pessoas
    static int pessoas;

    protected:
    string nome;
    int idade;
    public:
    Pessoa(const string nome_="",const int idade_=-1);
    virtual ~Pessoa();

    virtual void Mostradados();

    static int QuantidadePessoas(); 
};