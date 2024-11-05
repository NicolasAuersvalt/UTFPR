#ifndef H_GERENTE
#define H_GERENTE

#include "Empregado.hpp"

class Gerente :
    public Empregado
{
private:
    float bonus;

public:
    Gerente(string nome, int CPF, float bonus = 0);
    ~Gerente();
    
    void mostraDados();
    float calculaSalario(int horasTrabalhadas);
};

#endif