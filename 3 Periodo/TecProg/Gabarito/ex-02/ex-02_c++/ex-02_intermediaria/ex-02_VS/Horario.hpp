#ifndef C_HORARIO
#define C_HORARIO

#include <cmath>
#include <cstdint>  // Biblioteca incluida aqui para uint8_t. Prof. Simão. 

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Horario
{
private:
  // Foi utilizado uint8_t porque são mais adequados para este caso (o seu valor máximo é 255)
  uint8_t hora, min;

public:
  Horario();
  Horario(const uint8_t &_hora, const uint8_t &_min);
  ~Horario();
  const uint8_t &getHora() const;
  const uint8_t &getMin() const;
  void setHora(const uint8_t &_hora);
  void setMin(const uint8_t &_min);
  int calcularIntervalo(const Horario &_horario) const;
};

#endif