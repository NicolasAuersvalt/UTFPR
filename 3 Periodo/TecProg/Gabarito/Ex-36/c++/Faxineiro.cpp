#include "Faxineiro.hpp"

Faxineiro::Faxineiro(string nome, int CPF):
    Empregado(nome, CPF, "Faxineiro") {

}

Faxineiro::~Faxineiro() {

}

void Faxineiro::mostraDados() {
    cout << "Nome do faxineiro: " << this->nome << ", CPF: " << this->CPF << endl;
}

float Faxineiro::calculaSalario(int horasTrabalhadas) {

    float salario = 0;

    if(horasTrabalhadas > 0) {
        if(horasTrabalhadas < 176)
            salario = horasTrabalhadas * 4.5;
        else
            salario = (176 * 4.5) + ((horasTrabalhadas - 176) * 6.0);
    }
    
    return salario;
}