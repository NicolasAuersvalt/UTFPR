#include "CalcInterface.hpp"

// Inicializamos o vetor com as operacoes válidas
const vector<char> CalcInterface::OPERACOES_VALIDAS = vector<char>({'+', '-', '*', '/', 's'});

CalcInterface::CalcInterface(){

};

CalcInterface::~CalcInterface(){

};

double CalcInterface::recebeOperando(const int &i) const
{
  double operando;
  cout << "Insira o operando " << i << endl;
  cin >> operando;
  return operando;
};

char CalcInterface::recebeOperacao() const
{
  char operacao;
  do
  {
    cout << "Insira uma operacao:" << endl;
    cin >> operacao;
  } while (!CalcInterface::isOperacaoValida(operacao));
  return operacao;
};

void CalcInterface::mostraResultado(const double &resultado) const
{
  cout << "Resultado: " << resultado << endl;
};

bool CalcInterface::isOperacaoValida(const char &operacao)
{
  int size = CalcInterface::OPERACOES_VALIDAS.size();
  for (int i = 0; i < size; i++)
    if (CalcInterface::OPERACOES_VALIDAS[i] == operacao)
      return true;
  return false;
}