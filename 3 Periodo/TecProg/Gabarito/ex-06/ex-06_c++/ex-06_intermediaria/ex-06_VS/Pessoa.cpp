
#pragma warning(disable : 4996)  // Linha adicionada por Prof. Simão para habilitar função localtime usada abaixo.
// https://docs.microsoft.com/pt-br/cpp/error-messages/compiler-warnings/compiler-warning-level-3-c4996?f1url=%3FappId%3DDev16IDEF1%26l%3DPT-BR%26k%3Dk(C4996)%26rd%3Dtrue&view=msvc-170
// https://stackoverflow.com/questions/19321804/this-function-or-variable-may-be-unsafe-visual-studio

#include "Pessoa.hpp"

// Aplicar mesma crítica feitas no exercício anterior quando couber... Prof. Simão. 

/**
 * Construtora: inicializamos os atributos. - Monitores 2 Sem 2021
 * **/
Pessoa::Pessoa() : idade(0),
                   diaN(0),
                   mesN(0),
                   anoN(0),
                   nome(""){

                   };

/**
 * Construtora: recebe o nome e data de nacimento da pessoa, para inicializar os atributos. - monitores 2 Sem 2021
 * **/

// Muito embora no caso dado funcione, seria melho parâmetros e attributes terem denominações 
// ligeiramente distintas, como nome e _nome. Prof. Simão.  
Pessoa::Pessoa(const string &nome, const int &diaN, const int &mesN, const int &anoN) : nome(nome),
                                                                                        diaN(diaN),
                                                                                        mesN(mesN),
                                                                                        anoN(anoN),
                                                                                        idade(0)
{
}

/**
 * Destrutora
 * **/
Pessoa::~Pessoa(){};

/**
 * Calcula a idade utilizando diaN, mesN e anoN; logo guarda o valor
 * no attributo idade.
 * **/
void Pessoa::caculaIdade()
{
  // Obtem a data atual utilizando a biblioteca "ctime"
  time_t tSac = time(NULL);
  tm tms = *localtime(&tSac);

  // Calcula a idade
  this->idade = tms.tm_year - this->anoN + 1900;

  // Verifica se a data do aniversário já passou, para ajustar a idade.
  if (this->mesN > tms.tm_mon + 1 || (this->mesN == tms.tm_mon + 1 && this->diaN < tms.tm_mday))
  {
    this->idade--;
  }
};

/**
 * Retorna a idade da pessoa.
 * **/
const int &Pessoa::getIdade() const
{
  return this->idade;
};

/**
 * Atualiza o nome da pessoa.
 * **/
void Pessoa::setNome(const string &nome)
{
  this->nome = nome;
};

/**
 * Retorna o nome da pessoa.
 * **/
const string &Pessoa::getNome() const
{
  return this->nome;
};

/**
 * Atualiza a data de nacimento da pessoa.
 * **/
void Pessoa::setDataDeNascimento(const int &diaN, const int &mesN, const int &anoN)
{
  // ATENÇÃO:
  // Utilizando "this->" nos referimos ao atributo privado do objeto,
  // não aos parametros da função
  this->diaN = diaN;
  this->mesN = mesN;
  this->anoN = anoN;
};