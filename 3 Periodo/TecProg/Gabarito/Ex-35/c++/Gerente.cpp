#include "Gerente.hpp"

Gerente::Gerente(string nome, int CPF, float bonus) :
    Empregado(nome, CPF, "Gerente")
{
    this->bonus = bonus;
}

Gerente::~Gerente() {

}
    
void Gerente::mostraDados() {
    cout << "Nome do gerente: " << this->nome << ", CPF: " << this->CPF << ", bonus: " << this->bonus << endl;
}

float Gerente::calculaSalario(int horasTrabalhadas)
{
    float salario = 0;

    if(horasTrabalhadas > 0) {
        if(horasTrabalhadas < 176)
            salario = horasTrabalhadas * 30. + bonus;
        else
            salario = (176 * 30.) + bonus;
    }

    return salario;
}