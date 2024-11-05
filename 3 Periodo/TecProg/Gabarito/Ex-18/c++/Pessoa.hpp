#ifndef C_PESSOA
#define C_PESSOA

#include "Departamento.hpp"
#include <string>
#include <ctime>
#include <iostream>

// Permite utilizar diretamente string sem adicionar std::
using std::cout;
using std::endl;
using std::string;

class Pessoa
{
private:
  string nome;
  int idade, diaN, mesN, anoN;
  Departamento *departamento;

public:
  Pessoa();
  ~Pessoa();
  void caculaIdade();
  const int &getIdade() const;
  void setNome(const string &nome);
  const string &getNome() const;
  void setDataDeNascimento(const int &diaN, const int &mesN, const int &anoN);
  void setDepartamento(Departamento *departamento);
  const Departamento *getDepartamento() const;
  void imprimeInformacao() const;
};

#endif
