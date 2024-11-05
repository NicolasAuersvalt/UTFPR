#ifndef C_CLIENTE
#define C_CLIENTE
#include <string>
#include <sstream>

using std::string;
using std::stringstream;
/*
Necesário para que Conta e Cliente possam incluir-se mutuamente.
OBS.: Unicamente podem ser utilizados ponteiros de Contas.
*/
class Conta;

class Cliente
{
private:
  string nome;
  string cpf;
  int nContas;
  Conta **contas;

  // Constante com o nro máximo de contas
  const int N_MAX_CONTAS = 3;

public:
  // Construtora & Destrutora
  Cliente(const string &nome, const string &cpf);
  ~Cliente();
  void adicionarConta(Conta *conta);
  // Métodos requeridos
  string gerarRelatorio() const;
  void aplicarRecursos(const double &valor, const int &iConta = 0);
};
#endif