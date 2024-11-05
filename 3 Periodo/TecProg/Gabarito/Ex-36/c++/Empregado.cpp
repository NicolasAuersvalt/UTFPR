#include "Empregado.hpp"

Empregado::Empregado(string nome, int CPF, string cargo) {
    this->nome = nome;
    this->CPF = CPF;
    this->cargo = cargo;
}

Empregado::~Empregado() {
}

void Empregado::mostraDados() {
    cout << "Nome: " << this->nome << ", CPF: " << this->CPF << ", Cargo: " << this->cargo << endl;
}

float Empregado::calculaSalario(int horasTrabalhadas) {
    return 415.;
}