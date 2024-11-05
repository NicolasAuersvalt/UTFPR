
// Código com comentário e ajustes. Prof. Simão. 

// Uma primeira critica geral a solução feita por monitores (em semestre anterior - 2 Sem 2021) é   
// que o exercício pede explicitamente uma classe princial, o que (ainda) não existe. Prof. Simão.

// Ainda cabe boa parte das críticas já feita no exercício 01

#include "Horario.hpp"
#include <assert.h>

#define MAX_HORA 24
#define MAX_MIN 60

int main(int argc, char **argv)
{
  // Horario *entrada = NULL, *saida = NULL;    // Isto são ponteiro para alocação de memória dinâmica, desnecessário aqui... Prof. Simão. 
  int h = 0, m = 0;

  // Obtem horario de entrada - Monitores 2 Sem 2021
  cout << "Digite a entrada: HORA MIN" << endl;
  cin >> h >> m;
  // Verifica valores ingresado - Monitores
  assert(h < MAX_HORA);
  assert(m < MAX_MIN);
  
  // entrada = new Horario(h, m);
  Horario entrada(h, m);     // Troquei a linha acima por esta com alocação dita estática (portanto sem ponteiros)  - Prof. Simão 
                             // Obtem horario de saida
  cout << "Digite a saida: HORA MIN" << endl;
  cin >> h >> m;

  // Verifica valores ingresado
  assert(h < MAX_HORA);
  assert(m < MAX_MIN);

  // saida = new Horario(h, m);  
  Horario saida(h, m); // Troquei a linha acima por esta com alocação dita estática (portanto sem ponteiros)  - Prof. Simão

  // Calcula intervalo
  // int intervalo = entrada->calcularIntervalo(*saida);  // Objeto criado dinamicamente usa operador de seta (->). Prof. Simao.
  int intervalo = entrada.calcularIntervalo(saida);  // Objeto criado estaticamente usa operador de ponto (.). 

  // Libera memoria  // As linhas abaixo seriam para a desalócação de memória, mas essa solução por alocação foi aqui retirada. Prof. Simão
  // delete entrada; // Em todo caso, para cada new feito tem de haver um respectivo delete, 
  // delete saida;   // tal qual para cada malloc tem de haver um respectivo free. Prof. Simão. 

  double preco = 0;
  // Calcula o preço
  if (intervalo < 3 * 60)
  {
    preco = 4.5;
  }
  else if (intervalo < 12 * 60)
  {
    // Calcular quantos intervalos de 15 min
    // existem no horario excedente
    int aux = (intervalo - 3 * 60) / 15;
    // Se não deu multiplo de 15 min, deve
    // cobrar um intervalo a mais
    if (((intervalo - 3 * 60) % 15) != 0)
      aux++;
    preco = 4.5 + aux * 0.75;
  }
  else
  {
    preco = 33;
  }
  cout << "Preço = " << preco << endl;
  return 0;
}