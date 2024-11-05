#ifndef C_HORARIO
#define C_HORARIO
#include <cmath>

class Horario
{
private:
  // Foi utilizado uint8_t porque são mais adequados para este caso (o seu valor máximo é 255)
  uint8_t hora, min;

public:
  Horario();
  Horario(const uint8_t &hora, const uint8_t &min);
  ~Horario();
  const uint8_t &getHora() const;
  const uint8_t &getMin() const;
  void setHora(const uint8_t &hora);
  void setMin(const uint8_t &min);
  int calcularIntervalo(const Horario &horario) const;
};

#endif