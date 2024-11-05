#ifndef C_PESSOA
#define C_PESSOA

#include "Universidade.hpp"
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
  Universidade *universidade;

public:
  Pessoa();
  ~Pessoa();
  void caculaIdade();
  const int &getIdade() const;
  void setNome(const string &nome);
  const string &getNome() const;
  void setDataDeNascimento(const int &diaN, const int &mesN, const int &anoN);
  void setUniversidade(Universidade *universidade);
  const Universidade *getUniversidade() const;
  void imprimeInformacao() const;
};

#endif
