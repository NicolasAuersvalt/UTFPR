#ifndef C_PESSOA
#define C_PESSOA

#include <ctime>

#include <string>
// Permite utilizar diretamente string sem adicionar std:: - Monitores 
using std::string;

class Pessoa
{
private:
  string nome;
  int idade, diaN, mesN, anoN;

public:
  Pessoa();
  ~Pessoa();
  void caculaIdade();
  const int &getIdade() const;
  void setNome(const string &_nome);
  const string &getNome() const;
  void setDataDeNascimento(const int &_diaN, const int &_mesN, const int &_anoN);
};

#endif
