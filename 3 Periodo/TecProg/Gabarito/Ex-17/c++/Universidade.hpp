#ifndef C_UNIVERSIDADE
#define C_UNIVERSIDADE
#include <string>

using std::string;

class Universidade
{
private:
  string nome;

public:
  // Construtora & Destrutora
  Universidade();
  ~Universidade();
  // Métodos
  const string &getNome() const;
  void setNome(const string &nome);
};

#endif