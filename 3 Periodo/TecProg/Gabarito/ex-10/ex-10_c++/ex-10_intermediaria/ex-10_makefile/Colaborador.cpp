#include <Colaborador.hpp>

const int V_ESTAGIARIO(0);
const int V_EMPREGADO(1);
const int V_SOCIO(2);
const int Colaborador::HORAS_TRABALHADAS_PADRAO(80);

// Construtora & Destrutora
Colaborador::Colaborador(const string &nome, const int &tipoVinculo) : nome(nome), tipoVinculo(tipoVinculo), tempoServico(0), salarioPorHora(0), horasTrabalhadas(0)
{
}

Colaborador::~Colaborador() {}

double Colaborador::calculaRendimentos() const
{
  double rendimento = 0.f;
  double bonusTempoServico = pow(1.1, this->tempoServico);
  switch (this->tipoVinculo)
  {
  case 0:
    rendimento = this->salarioPorHora * Colaborador::HORAS_TRABALHADAS_PADRAO;
  case 1:
    // Calcula o bonus
    rendimento = this->salarioPorHora * this->horasTrabalhadas * bonusTempoServico;
    // Verifica se tem horas extras
    if (this->horasTrabalhadas > 144)
    {
      // Caso tenha horas extras, calcula os 50% adicionais por hora extra trabalhada
      rendimento += this->salarioPorHora * (this->horasTrabalhadas - 144) * 0.5;
    }
    break;
  case 2:
    rendimento = this->salarioPorHora * this->horasTrabalhadas;
  default:
    break; // Vinculo inválido
  }
  return rendimento;
}
double Colaborador::calculaCusto() const
{
  double custo = 0.f;
  switch (this->tipoVinculo)
  {
  // Para os empregados se adiciona um 80% em conceito de (impostos, INSS, etc)
  case 1:
    custo = this->calculaRendimentos() * 1.8;
    break;
  // Estagiários e Sócios não possuem custos adicionais além de seus salarios
  default:
    custo = this->calculaRendimentos();
    break;
  }
  return custo;
}
// Getters & Setters
const string &Colaborador::getNome() const
{
  return this->nome;
}

void Colaborador::setTempoServico(const int &tempoServico)
{
  this->tempoServico = tempoServico;
}

const int &Colaborador::getTempoServico() const
{
  return this->tempoServico;
}

void Colaborador::setSalarioPorHora(const double &salarioPorHora)
{
  this->salarioPorHora = salarioPorHora;
}

const double &Colaborador::getSalarioPorHora() const
{
  return this->salarioPorHora;
}

void Colaborador::setHorasTrabalhadas(const int &horasTrabalhadas)
{
  this->horasTrabalhadas = horasTrabalhadas;
}

const int &Colaborador::getHorasTrabalhadas() const
{
  return this->horasTrabalhadas;
}