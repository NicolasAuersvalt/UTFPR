#ifndef C_CALC_INTERFACE
#define C_CALC_INTERFACE

#include "stdinc.hpp"

class CalcInterface
{
private:
  static const vector<char> OPERACOES_VALIDAS;
  static bool isOperacaoValida(const char &operacao);

public:
  CalcInterface();
  ~CalcInterface();
  double recebeOperando(const int &i) const;
  char recebeOperacao() const;
  void mostraResultado(const double &resultado) const;
};

#endif