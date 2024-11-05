#include "Aluno.hpp"

Aluno::Aluno(const string &nome, const int &nota1, const int &nota2) : nome(nome), nota1(nota1), nota2(nota2)
{
}

Aluno::~Aluno()
{
}

void Aluno::setNome(const string &nome)
{
  this->nome = nome;
}

const string &Aluno::getNome() const
{
  return this->nome;
}

void Aluno::setNota1(const int &nota1)
{
  this->nota1 = nota1;
}

const int &Aluno::getNota1() const
{
  return this->nota1;
}

void Aluno::setNota2(const int &nota2)
{
  this->nota2 = nota2;
}

const int &Aluno::getNota2() const
{
  return this->nota2;
}

double Aluno::getMedia() const
{
  return (this->getNota1() + this->getNota2()) / 2;
}

bool Aluno::operator==(const Aluno &aluno) const
{
  return this->getNome() == aluno.getNome();
}