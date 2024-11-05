#include "PolReg.hpp"

// Refazer evitanto o uso desnecessário de this. Prof. Simão. 

PolReg::PolReg(const int &nLados, const double &tamLado) : nLados(nLados), tamLado(tamLado)
{
}

PolReg::~PolReg()
{
}

// Nos dois métodos abaixos, poderia verificar eventuais exceções como números negativos e zeros. Prof. Simão. 

double PolReg::getPerimetro() const
{
  return this->nLados * this->tamLado;
};

double PolReg::getAnguloInterno() const
{
  return 180.0 * (this->nLados - 2.0) / this->nLados;
};

double PolReg::getArea() const
{
  return 0.0;
}