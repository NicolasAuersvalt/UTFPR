#ifndef C_PESSOA
#define C_PESSOA

#include <string>
#include <ctime>

// Permite utilizar diretamente string sem adicionar std::
using std::string;

class Pessoa
{
private:
  string nome;
  int idade, diaN, mesN, anoN;

public:
  Pessoa();
  Pessoa(const string &nome, const int &diaN, const int &mesN, const int &anoN);
  ~Pessoa();
  void caculaIdade();
  const int &getIdade() const;
  void setNome(const string &nome);
  const string &getNome() const;
  void setDataDeNascimento(const int &diaN, const int &mesN, const int &anoN);
};

#endif
