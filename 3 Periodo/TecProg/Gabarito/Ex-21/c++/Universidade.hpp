#ifndef C_UNIVERSIDADE
#define C_UNIVERSIDADE

#include "stdinc.hpp"
#include "Departamento.hpp"

class Universidade
{
private:
  string nome;
  list<Departamento *> lDepartamentos;
  int nDepartamentos;
  const static int MAX_DEPARTAMENTOS = 50;

public:
  // Construtora & Destrutora
  Universidade();
  ~Universidade();
  // Métodos
  const string &getNome() const;
  void setNome(const string &nome);
  void addDepartamento(Departamento *departamento);
  void imprimeDepartamentos() const;
};

#endif