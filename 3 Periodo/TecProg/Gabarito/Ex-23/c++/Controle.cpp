#include "Controle.hpp"

Controle::Controle() : turma(), op(0){

                                };

Controle::~Controle(){

};

void Controle::run()
{
  this->iniciarTurma();
  this->op = 0;
  do
  {
    // Perguntamos a operação a realizar
    imprimirMenu();
    cin >> this->op;
    // Verifica e executa a operação solicitada
    switch (this->op)
    {
    case 1:
      this->matricularAluno();
      break;
    case 2:
      this->cancelarAluno();
      break;
    case 3:
      this->imprimirRelatorio();
      break;
    case 0:
      break;
    default:
      cout << "Operação Inválida :( " << endl;
      op = 0;
      break;
    }
  } while (this->op > 0);
};

void Controle::iniciarTurma()
{
  cout << "-> INFORMAR TURMA" << endl;
  string nomeTurma = "", codTurma = "";
  int nVagas = 0;
  cout << "Insira <Nome Turma> <Cod. Turma> <Nro. Vagas> " << endl;
  cin >> nomeTurma >> codTurma >> nVagas;
  // Verifica que o nro de vagas seja um nro válido
  if (nVagas <= 0)
    exit(1);
  // Criamos o objeto da turma com os valores fornecidos
  this->turma = Turma(nomeTurma, codTurma, nVagas);
}

void Controle::matricularAluno()
{
  cout << "-> MATRICULAR ALUNO" << endl;
  string nome = "";
  int nota1 = 0, nota2 = 0;
  // Solicitamos as informações do aluno
  cout << "Insira <Nome Aluno> <Nota 1> <Nota 2>" << endl;
  cin >> nome >> nota1 >> nota2;
  // Criamos o objeto do aluno
  Aluno aluno(nome, nota1, nota2);
  // Matriculamos o aluno
  this->turma.matricularAluno(aluno);
}

void Controle::cancelarAluno()
{
  cout << "-> CANCELAR ALUNO" << endl;
  string nome = "";
  // Solicitamos as informações do aluno
  cout << "Insira <Nome Aluno>" << endl;
  cin >> nome;
  // Criamos o objeto do aluno
  Aluno aluno(nome, 0, 0);
  // Cancelamos o aluno
  this->turma.cancelarAluno(aluno);
}

void Controle::imprimirRelatorio()
{
  cout << "-> INFORMAÇÕES DA TURMA" << endl;
  cout << this->turma.gerarRelatorio() << endl;
}

void Controle::imprimirMenu() const
{
  cout << "0 - SAIR" << endl;
  cout << "1 - Matricular Aluno" << endl;
  cout << "2 - Cancelar Aluno" << endl;
  cout << "3 - Imprimir Relatório Turma" << endl;
}