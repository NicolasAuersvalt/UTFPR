#ifndef C_UNIVERSIDADE
#define C_UNIVERSIDADE

#include <string>

class Departamento;

using std::string;

class Universidade
{
private:
  string nome;
  Departamento *departamento;

public:
  // Construtora & Destrutora
  Universidade();
  Universidade(const string &nome, const Departamento &departamento);
  ~Universidade();
  // Métodos
  const string &getNome() const;
  void setNome(const string &nome);
  Departamento *getDepartamento() const;
  void setDepartamento(Departamento *departamento);
};

#endif