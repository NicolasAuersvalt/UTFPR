#ifndef C_CALC_DADOS
#define C_CALC_DADOS

#include "stdinc.hpp"

class CalcDados
{
private:
  double n1, n2;
  char operacao;

public:
  CalcDados();
  ~CalcDados();
  void setOperando(const int &i, const double &valor);
  const double &getOperando(const int &i) const;
  void setOperacao(const char &operacao);
  const char &getOperacao() const;
};

#endif