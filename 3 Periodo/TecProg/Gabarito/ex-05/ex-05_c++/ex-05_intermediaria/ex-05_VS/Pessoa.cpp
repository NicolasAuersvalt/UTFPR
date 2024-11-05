#include "Pessoa.hpp"

#pragma warning(disable : 4996)  // Linha adicionada por Prof. Simão para habilitar função localtime usada abaixo.
// https://docs.microsoft.com/pt-br/cpp/error-messages/compiler-warnings/compiler-warning-level-3-c4996?f1url=%3FappId%3DDev16IDEF1%26l%3DPT-BR%26k%3Dk(C4996)%26rd%3Dtrue&view=msvc-170
// https://stackoverflow.com/questions/19321804/this-function-or-variable-may-be-unsafe-visual-studio

/**
 * Construtora: inicializamos os atributos. - Monitores (2 Sem 2021)
 * **/

Pessoa::Pessoa() : idade(0),
                   diaN(0),
                   mesN(0),
                   anoN(0),
                   nome("")
                   {

                   } // ; // Comentei o ponto e vírgula... - Prof. Simão. 

/**
 * Destrutora - Monitores
 * **/
Pessoa::~Pessoa()
{
} //; // Até onde me consta, compiladores tradicionais não aceitariam este ponto e vírgula. - Prof. Simão. 

/**
 * Calcula a idade utilizando diaN, mesN e anoN; logo guarda o valor
 * no attributo idade.
 * **/
void Pessoa::caculaIdade()
{
  // Obtem a data atual utilizando a biblioteca "ctime" - Monitores. 
  time_t tSac = time(NULL);
  tm tms = *localtime(&tSac);

  // Calcula a idade - Monitores 
  //this->idade = tms.tm_year - this->anoN + 1900;  // Comentei - Prof. Simão
  idade = tms.tm_year - this->anoN + 1900; // Substitui - fazer o mesmo para demais ocorrência 

  // Verifica se a data do aniversário já passou, para ajustar a idade. - Monitores
  // Poderia ter melhor nível de parentização - Prof Simão. 
  if (this->mesN > tms.tm_mon + 1 || (this->mesN == tms.tm_mon + 1 && this->diaN < tms.tm_mday))
  {
    //this->idade--;  // Não usar this assim! Prof. Simao
      idade--; 
  }
};

/**
 * Retorna a idade da pessoa. - Monitores 
 * **/
const int &Pessoa::getIdade() const
{
  //return this->idade; // Alterei o código, cf. linha abaixo, para evitar este vício do operador this. Prof. Simão. 
    return idade;
};

/**
 * Atualiza o nome da pessoa. - Monitores 
 * **/
void Pessoa::setNome(const string &_nome)  // alterei o parametro que estava 'nome' para '_nome'... Prof. Simão. 
{
  //this->nome = nome;
    nome = _nome;
};

/**
 * Retorna o nome da pessoa. - monitores 
 * **/
const string &Pessoa::getNome() const
{
  // return this->nome;
    return nome; 
};

/**
 * Atualiza a data de nacimento da pessoa. - monitores
 * **/

void Pessoa::setDataDeNascimento(const int &_diaN, const int &_mesN, const int &_anoN)
{
  // ATENÇÃO:
  // Utilizando "this->" nos referimos ao atributo privado do objeto,
  // não aos parametros da função - Monitores
  //this->diaN = diaN;
  //this->mesN = mesN;
  //this->anoN = anoN;
  // Paramêtros deveriam ter nome diferentes (e.g., _diaN e não diaN no parâmetro), evitando assim usar this. Prof. Simao
  // Assim, alterei o nome dos parâmestros (e.g., antes estava diaN e agora está _diaN) e comentei linhas acima substituindo 
  // pelas linha que seguem sem o vício do this. Prof. Simão. 
  diaN = _diaN;
  mesN = _mesN;
  anoN = _anoN;
};