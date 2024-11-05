#ifndef C_POLREG
#define C_POLREG

class PolReg
{
private:
  int nLados;
  double tamLado;

public:
  PolReg(const int &nLados, const double &tamLado);
  ~PolReg();
  /* OBS.: Utilizamos funções constantes por causa que não modificam nenhum atributo */
  double getPerimetro() const;
  double getAnguloInterno() const;
  double getArea() const;
};

#endif