#include "Conta.hpp"
#include "Cliente.hpp"

// Construtora & Destrutora
Conta::Conta(const int &nroConta) : nroConta(nroConta), saldo(0.f), titular(nullptr)
{
}

Conta::~Conta()
{
}

// Getters & Setters
const double &Conta::getSaldo() const
{
  return this->saldo;
}

const int &Conta::getNumero() const
{
  return this->nroConta;
}

const Cliente *Conta::getTitular() const
{
  return this->titular;
}

void Conta::setTitular(Cliente *cliente)
{
  this->titular = cliente;
}

// Métodos requeridos
bool Conta::sacar(const double &valor)
{
  // Verifica que o valor seja positivo
  if (valor > 0)
  {
    this->saldo -= valor;
    return true;
  }
  return false;
}

bool Conta::depositar(const double &valor)
{
  // Verifica que o valor seja positivo
  if (valor > 0)
  {
    this->saldo += valor;
    return true;
  }
  return false;
}