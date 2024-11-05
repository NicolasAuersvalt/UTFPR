#include "Departamento.hpp"

Departamento::Departamento() : nome(""),
                               universidade(nullptr){

                               };

Departamento::Departamento(const string &nome, Universidade *universidade) : nome(nome), universidade(universidade){

                                                                                         };
Departamento::~Departamento(){

};

void Departamento::setNome(const string &nome)
{
  this->nome = nome;
};

const string &Departamento::getNome() const
{
  return this->nome;
};

void Departamento::setUniversidade(Universidade *universidade)
{
  this->universidade = universidade;
};

const Universidade *Departamento::getUniversidade() const
{
  return this->universidade;
};