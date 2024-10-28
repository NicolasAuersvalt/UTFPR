// socio.cpp
#include <iostream>
#include "socio.h"

using namespace std;

Socio::Socio() {
    cout << "Socio" << endl;
}

Socio::~Socio() {}

void Socio::setNome(const std::string& nome) {
    this->nome = nome;
}

std::string Socio::getNome() const {
    return nome;
}

void Socio::setValores(float val, int horas) {
    valHora = val;
    horasTrabalhadas = horas;
}

void Socio::setHorasTrabalhadas(int horas) {
    horasTrabalhadas = horas;
}

int Socio::getHorasTrabalhadas() const {
    return horasTrabalhadas;
}

float Socio::calculaPagamento() const {
    return valHora * horasTrabalhadas;
}

