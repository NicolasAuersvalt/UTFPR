#include "Colaborador.hpp"
#include <iostream>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

// Função de comparação de custos para organizar o list
bool comparadorCustos(const Colaborador &c1, const Colaborador &c2)
{
  return c1.calculaCusto() > c2.calculaCusto();
}

// Função de comparação de rendimentos para organizar o list
bool comparadorRendimentos(const Colaborador &c1, const Colaborador &c2)
{
  return c1.calculaRendimentos() > c2.calculaRendimentos();
}

int main()
{
  cout.precision(10); // Ajusta decimais do cout
  string nome = "";
  int idTipoVinculo = 0, tempoServico = 0, salario = 0, horasTrabalhadas = 0;
  // Obtem colaborador 0
  nome = "", idTipoVinculo = 0, tempoServico = 0, salario = 0, horasTrabalhadas = 0;
  cout << "Insira as informações do colaborador" << endl;
  cout << "<NOME> <VINCULO> <ANOS SERVICIO> <SALARIO> <HORAS TRABALHADAS>" << endl;
  cin >> nome >> idTipoVinculo >> tempoServico >> salario >> horasTrabalhadas;
  Colaborador colaborador0 = Colaborador(nome, idTipoVinculo);
  colaborador0.setTempoServico(tempoServico);
  colaborador0.setSalarioPorHora(salario);
  colaborador0.setHorasTrabalhadas(horasTrabalhadas);

  nome = "", idTipoVinculo = 0, tempoServico = 0, salario = 0, horasTrabalhadas = 0;
  // Obtem colaborador 1
  cout << "Insira as informações do colaborador" << endl;
  cout << "<NOME> <VINCULO> <ANOS SERVICIO> <SALARIO> <HORAS TRABALHADAS>" << endl;
  cin >> nome >> idTipoVinculo >> tempoServico >> salario >> horasTrabalhadas;
  Colaborador colaborador1 = Colaborador(nome, idTipoVinculo);
  colaborador1.setTempoServico(tempoServico);
  colaborador1.setSalarioPorHora(salario);
  colaborador1.setHorasTrabalhadas(horasTrabalhadas);

  nome = "", idTipoVinculo = 0, tempoServico = 0, salario = 0, horasTrabalhadas = 0;
  // Obtem colaborador 2
  cout << "Insira as informações do colaborador" << endl;
  cout << "<NOME> <VINCULO> <ANOS SERVICIO> <SALARIO> <HORAS TRABALHADAS>" << endl;
  cin >> nome >> idTipoVinculo >> tempoServico >> salario >> horasTrabalhadas;
  Colaborador colaborador2 = Colaborador(nome, idTipoVinculo);
  colaborador2.setTempoServico(tempoServico);
  colaborador2.setSalarioPorHora(salario);
  colaborador2.setHorasTrabalhadas(horasTrabalhadas);

  cout << colaborador0.getNome() << " rendimento " << colaborador0.calculaRendimentos() << "$ custo " << colaborador0.calculaCusto() << "$" << endl;
  cout << colaborador1.getNome() << " rendimento " << colaborador1.calculaRendimentos() << "$ custo " << colaborador1.calculaCusto() << "$" << endl;
  cout << colaborador2.getNome() << " rendimento " << colaborador2.calculaRendimentos() << "$ custo " << colaborador2.calculaCusto() << "$" << endl;

  // Adiciona todos os colaboradores em uma lista para facilitar
  // o proceso de encontrar o maior rendimento e o maior custo.
  list<Colaborador> colaboradores;
  list<Colaborador>::iterator it;
  colaboradores.push_back(colaborador0);
  colaboradores.push_back(colaborador1);
  colaboradores.push_back(colaborador2);

  // Organizamos em relação ao rendimento de forma decrescente e imprimimos o primeiro da lista
  colaboradores.sort(comparadorRendimentos);
  it = colaboradores.begin();
  cout << it->getNome() << " possui o maior rendimento com " << it->calculaRendimentos() << "$" << endl;

  // Organizamos em relação ao custo de forma decrescente e imprimimos o primeiro da lista
  colaboradores.sort(comparadorCustos);
  it = colaboradores.begin();
  cout << it->getNome() << " possui o maior custo com " << it->calculaCusto() << "$" << endl;

  return 0;
}