#ifndef C_CALC_CONTROLE
#define C_CALC_CONTROLE

#include "stdinc.hpp"
#include "CalcDados.hpp"
#include "CalcInterface.hpp"

class CalcControle
{
private:
  CalcDados dados;
  CalcInterface inteface;
  double operar(const double &n1, const double &n2, const char &operacao);

public:
  CalcControle();
  CalcControle(CalcInterface &calcInterface, CalcDados &calcDados);
  ~CalcControle();
  void executar();
};
#endif