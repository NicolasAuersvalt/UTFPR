#ifndef H_FAXINEIRO
#define H_FAXINEIRO

#include "Empregado.hpp"

class Faxineiro :
    public Empregado
{
public:
    Faxineiro(string nome, int CPF);
    ~Faxineiro();

    void mostraDados();
    float calculaSalario(int horasTrabalhadas);
};

#endif