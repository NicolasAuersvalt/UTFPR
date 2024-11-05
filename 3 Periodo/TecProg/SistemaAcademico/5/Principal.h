#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include "Professor.h"
#include "Universidade.h"
#include "Aluno.h"
#include "Disciplina.h"

class Principal
{
 private:
    // Universidades
    Universidade UTFPR;
    Universidade Princeton;
    Universidade Cambridge;

    // Departamentos
    Departamento EletronicaUTFPR;
    Departamento MatematicaUTFPR;
    Departamento FisicaUTFPR;

    Departamento MatematicaPrinceton;
    Departamento FisicaPrinceton;

    Departamento MatematicaCambridge;
    Departamento FisicaCambridge;

    // Professores
    Professor Simao;
    Professor Einstein;
    Professor Newton;

    // Disciplinas
    Disciplina Computacao1_2006;
    Disciplina Introd_Alg_2007;
    Disciplina Computacao2_2007;
    Disciplina Metodos2_2007;    

	// Alunos
    Aluno     AAA;
    Aluno     BBB;
    Aluno     CCC;
    Aluno     DDD;
    Aluno     EEE;

    int       diaAtual;
    int       mesAtual;
    int       anoAtual;

  public:

    Principal ();

    // Inicializações...
    void Inicializa();
    void InicializaUnivesidades();
    void InicializaDepartamentos();
    void InicializaProfessores();
    void InicializaAlunos();
    void InicializaDisciplinas();

    void Executar();
    
    void CalcIdadeProfs();
    void UnivOndeProfsTrabalham();
    void DepOndeProfsTrabalham();
	void ListeDiscDeptos ( );
	void ListeAlunosDisc();

	void executar();

};

#endif
