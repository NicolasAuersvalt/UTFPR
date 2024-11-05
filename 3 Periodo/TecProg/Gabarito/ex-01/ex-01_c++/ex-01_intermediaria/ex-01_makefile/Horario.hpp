#ifndef C_HORARIO
#define C_HORARIO
#include <cmath>
#include <cstdint>

class Horario
{
private:
  // Foi utilizado uint8_t porque são mais adequados para este caso (o seu valor máximo é 255)
    std::uint8_t hora, min;

public:
  Horario();
  ~Horario();
  const u_int8_t &getHora() const;
  const u_int8_t &getMin() const;
  void setHora(const u_int8_t &hora);
  void setMin(const u_int8_t &min);
  int calcularIntervalo(const Horario &horario) const;
};

#endif
