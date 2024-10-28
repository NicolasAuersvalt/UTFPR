// colaborador.cpp
#include "colaborador.h"

Colaborador::Colaborador() : nome(""), tempoServico(0) {}

Colaborador::Colaborador(const std::string& nome, int tempoServico)
    : nome(nome), tempoServico(tempoServico) {}

Colaborador::~Colaborador() {}

void Colaborador::setNome(const std::string& nome) {
    this->nome = nome;
}

std::string Colaborador::getNome() const {
    return nome;
}

void Colaborador::setTempoServico(int tempo) {
    tempoServico = tempo;
}

int Colaborador::getTempoServico() const {
    return tempoServico;
}

