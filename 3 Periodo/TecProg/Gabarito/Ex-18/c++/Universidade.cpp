#include "Universidade.hpp"

Universidade::Universidade() : nome(""), departamento(nullptr)
{
}

Universidade::Universidade(const string &nome, const Departamento &departamento) : nome(nome), departamento(nullptr)
{
}

Universidade::~Universidade()
{
}

const string &Universidade::getNome() const
{
  return this->nome;
}

void Universidade::setNome(const string &nome)
{
  this->nome = nome;
}

Departamento *Universidade::getDepartamento() const
{
  return this->departamento;
}

void Universidade::setDepartamento(Departamento *departamento)
{
  this->departamento = departamento;
}