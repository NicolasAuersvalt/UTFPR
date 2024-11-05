#ifndef C_CONTA
#define C_CONTA

/*
Necesário para que Conta e Cliente possam incluir-se mutuamente.
OBS.: Unicamente podem ser utilizados ponteiros de Clientes.
*/
class Cliente;

class Conta
{
private:
  int nroConta;
  double saldo;
  Cliente *titular;

public:
  // Construtora & Destrutora
  Conta(const int &nroConta);
  ~Conta();
  // Getters & Setters
  const double &getSaldo() const;
  const int &getNumero() const;
  const Cliente *getTitular() const;
  void setTitular(Cliente *cliente);
  // Métodos requeridos
  bool sacar(const double &valor);
  bool depositar(const double &valor);
};
#endif