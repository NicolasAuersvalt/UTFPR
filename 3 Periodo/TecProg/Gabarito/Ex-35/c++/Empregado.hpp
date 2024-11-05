#ifndef H_EMPREGADO
#define H_EMPREGADO

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Empregado
{
protected:
    string nome;
    int CPF;
    string cargo;

public:
    Empregado(string nome = "Sem Nome", int CPF = 0, string cargo = "Sem cargo");
    ~Empregado();

    virtual void mostraDados();
    virtual float calculaSalario(int horasTrabalhadas);
};

#endif
