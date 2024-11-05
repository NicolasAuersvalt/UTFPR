#include "Universidade.hpp"

Universidade::Universidade() : nome(""), lDepartamentos(), nDepartamentos(0)
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

void Universidade::addDepartamento(Departamento *departamento)
{
  if (this->nDepartamentos < this->MAX_DEPARTAMENTOS)
  {
    this->lDepartamentos.emplace_front(departamento);
    this->nDepartamentos++;
  }
  else
  {
    cerr << "Máximo 50 departamentos" << endl;
    exit(1);
  }
}

void Universidade::imprimeDepartamentos() const
{
  cout << "Departamentos: " << endl;
  list<Departamento *>::const_iterator iterator = this->lDepartamentos.begin();
  while (iterator != this->lDepartamentos.end())
  {
    cout << "\t -> " << (*iterator)->getNome() << endl;
    iterator++;
  }
}