#include "Cliente.hpp"
#include "Conta.hpp"

// Construtora & Destrutora
Cliente::Cliente(const string &nome, const string &cpf) : nome(nome), cpf(cpf), nContas(0)
{
  // Cria vetor para as contas
  this->contas = new Conta *[Cliente::N_MAX_CONTAS];
  // Inicializamos todas as posicoes
  for (int i = 0; i < Cliente::N_MAX_CONTAS; i++)
    this->contas[i] = nullptr;
}
Cliente::~Cliente()
{
  // Desaloca vetor de contas
  delete[] this->contas;
}
void Cliente::adicionarConta(Conta *conta)
{
  if (this->nContas < N_MAX_CONTAS)
  {
    // Adiciona nova conta
    this->contas[nContas] = conta;
    // Aumenta nro de contas
    this->nContas++;
  }
}
// Métodos requeridos
string Cliente::gerarRelatorio() const
{
  stringstream ss;
  // Cria o string
  ss << this->nome << " | " << this->cpf << " | N. Contas: " << this->nContas;

  for (int i = 0; i < this->nContas; i++)
  {
    ss << " | Saldo Conta[" << i << "]<" << this->contas[i]->getNumero() << ">: " << this->contas[i]->getSaldo();
  }

  return ss.str();
}
void Cliente::aplicarRecursos(const double &valor, const int &iConta)
{
  // Verifica que a posicao da conta seja valida
  if (this->nContas > iConta)
  {
    this->contas[iConta]->depositar(valor);
  }
}