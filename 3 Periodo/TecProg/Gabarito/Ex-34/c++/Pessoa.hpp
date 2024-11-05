#ifndef H_PESSOA
#define H_PESSOA

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Pessoa
{
protected:
    string nome;
    char genero;
    int diaNasc;
    int mesNasc;
    int anoNasc;

public:
    Pessoa(string nome = "Sem Nome", char genero = 'm', int diaNasc = 1, int mesNasc = 1, int anoNasc = 1970);
    ~Pessoa();

    virtual string obter_descricao();
    void setDataNascimento(int d, int m, int a);
    void setGenero(char g);
};

#endif