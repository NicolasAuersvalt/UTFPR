#ifndef C_COLABORADOR
#define C_COLABORADOR
#include <string>
#include <cmath>

using std::pow;
using std::string;

class Colaborador
{
private:
  static const int HORAS_TRABALHADAS_PADRAO;
  string nome;
  int tempoServico;
  int tipoVinculo;
  double salarioPorHora;
  int horasTrabalhadas;

public:
  // Construtora & Destrutora
  Colaborador(const string &nome, const int &tipoVinculo);
  ~Colaborador();
  // Métodos
  double calculaRendimentos() const;
  double calculaCusto() const;
  // Getters & Setters
  const string &getNome() const;
  void setTempoServico(const int &tempoServico);
  const int &getTempoServico() const;
  void setSalarioPorHora(const double &salacioPorHora);
  const double &getSalarioPorHora() const;
  void setHorasTrabalhadas(const int &horasTrabalhadas);
  const int &getHorasTrabalhadas() const;
};
#endif