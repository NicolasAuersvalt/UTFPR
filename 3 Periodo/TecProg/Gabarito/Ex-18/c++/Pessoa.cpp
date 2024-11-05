#include "Pessoa.hpp"

/**
 * Construtora: inicializamos os atributos.
 * **/
Pessoa::Pessoa() : nome(""),
                   idade(0),
                   diaN(0),
                   mesN(0),
                   anoN(0),
                   departamento(nullptr){

                   };

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
  // Calculamos a idade sempre que a data de nascimento é atualizada
  this->caculaIdade();
};

void Pessoa::setDepartamento(Departamento *departamento)
{
  this->departamento = departamento;
}
const Departamento *Pessoa::getDepartamento() const
{
  return this->departamento;
}
void Pessoa::imprimeInformacao() const
{
  string nDep = "", nUni = "";
  // Verificamos se a pessoa está associada a uma departamento
  if (this->departamento)
  {
    nDep = this->departamento->getNome();
    nUni = this->departamento->getUniversidade()->getNome();
  }

  cout << this->nome << " | Idade: " << this->getIdade() << " | Universidade: " << nUni << " <" << nDep << ">" << endl;
}