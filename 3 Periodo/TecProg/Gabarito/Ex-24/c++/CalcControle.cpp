#include "CalcControle.hpp"
CalcControle::CalcControle() : inteface(),
                               dados()
{
}

CalcControle::CalcControle(CalcInterface &calcInterface, CalcDados &calcDados) : inteface(calcInterface),
                                                                                 dados(calcDados)
{
}

CalcControle::~CalcControle()
{
}

void CalcControle::executar()
{
  // Carregamos os dados
  this->dados.setOperando(1, this->inteface.recebeOperando(1));
  //Loop da calculadora
  while(this->dados.getOperacao() != 's')
  {
    this->dados.setOperando(2, this->inteface.recebeOperando(2));
    this->dados.setOperacao(this->inteface.recebeOperacao());
    
    //valida operacao
    if(this->dados.getOperacao() != 's')
    {
      // Executamos a operacao
      double resultado = this->operar(this->dados.getOperando(1), this->dados.getOperando(2), this->dados.getOperacao());
      // Mostramos o resultado
      this->inteface.mostraResultado(resultado);
      // Armazena resultado como primeiro operando e volta para o segundo passo
      this->dados.setOperando(1, resultado);
    }
    else
    {
      //Caso operação == s, finaliza a calculadora
      cout << "Calculadora Finalizada!";
      exit(0);
    }
  }
}

double CalcControle::operar(const double &n1, const double &n2, const char &operacao)
{
  switch (operacao)
  {
  case '*':
    return n1 * n2;
  case '/':
    return n1 / n2;
  case '-':
    return n1 - n2;
  case '+':
    return n1 + n2;
  case 's':
    return 0;
  default:
    cout << "Operação " << operacao << " inválida" << endl;
    exit(1);
  }
}