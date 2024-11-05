#include "PolReg.hpp"

PolReg::PolReg(const int &nLados, const double &tamLado) : nLados(nLados), tamLado(tamLado)
{
}

PolReg::~PolReg()
{
}

double PolReg::getPerimetro() const
{
  return this->nLados * this->tamLado;
};

double PolReg::getAnguloInterno() const
{
  return 180 * (this->nLados - 2) / this->nLados;
};

double PolReg::getArea() const
{
  return 0;
}