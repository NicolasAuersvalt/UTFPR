#include "stdafx.h"
#include "Principal.h"
#include "Windows.h"

Principal::Principal()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    //printf("Year:%d\nMonth:%d\nDate:%d\nHour:%d\nMin:%d\nSecond:% d\n" ,st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);

    diaAtual = st.wMonth;
	mesAtual = st.wDay;
	anoAtual = st.wYear;

    Inicializa(); 
}

void Principal::Inicializa ( )
{   
	InicializaAlunos();
    InicializaUnivesidades ( );
    InicializaDepartamentos ( );
    InicializaProfessores ( );
    InicializaDisciplinas ( );
	Executar();
}

void Principal::InicializaAlunos()
{ 
	AAA.setNome	("AAA");
	BBB.setNome	("BBB");
	CCC.setNome	("CCC");
	DDD.setNome	("DDD");
	EEE.setNome	("EEE");
}

void Principal::InicializaUnivesidades ( )
{  
    // Registro do(s) nome(s) da(s) universidade(s)
    UTFPR.setNome     ( "UTFPR"		);
    Princeton.setNome ( "Princeton" );
    Cambridge.setNome ( "Cambridge" );
}

void Principal::InicializaDepartamentos ( )
{ 
    // Registro do(s) nome(s) do(s) departamento(s)
    EletronicaUTFPR.setNome		( "Eletronica UTFPR" );
    MatematicaUTFPR.setNome		( "Matematica UTFPR" );
    FisicaUTFPR.setNome			( "Fisica UTFPR" );
    MatematicaPrinceton.setNome ( "Matematica Princeton" );
    FisicaPrinceton.setNome		( "Fisica Pirnceton" );
    MatematicaCambridge.setNome ( "Matematica Cambridge" );
    FisicaCambridge.setNome		( "Fisica Cambridge" );   
     
    // "Agregação" do(s) Departamento(s) a(s) Universidade(s).
    UTFPR.setDepartamento		( &EletronicaUTFPR );
    UTFPR.setDepartamento		( &MatematicaUTFPR );
    UTFPR.setDepartamento		( &FisicaUTFPR );

    Princeton.setDepartamento	( &MatematicaPrinceton );
    Princeton.setDepartamento	( &FisicaPrinceton );
    Cambridge.setDepartamento	( &MatematicaCambridge );
    Cambridge.setDepartamento	( &FisicaCambridge );
}

void Principal::InicializaProfessores ( )
{   

    // Inicialização do(s) ojeto(s) da classe Professor
    Simao.Inicializa	( 3, 10, 1976, "Jean Simão" );
    Einstein.Inicializa ( 14, 3, 1879, "Albert Einstein" );
    Newton.Inicializa	( 4, 1, 1643, "Isaac Newton" );

     // "Filiação" a universidade.
    Simao.setUnivFiliado	( &UTFPR );
    Einstein.setUnivFiliado ( &Princeton );
    Newton.setUnivFiliado	( &Cambridge );

    // Area de Conhecimento.
    // Simao.setDominio		( "Computação“ );
    // Einstein.setDominio	( "Física" );
    // Newton.setDominio	( "Matemática-Física" );

    // "Filiação" ao departamento.
    Simao.setDepartamento	( &EletronicaUTFPR );
    Einstein.setDepartamento( &FisicaPrinceton );
    Newton.setDepartamento	( &MatematicaCambridge );
 }

void Principal::InicializaDisciplinas ( )
{
    Computacao1_2006.setNome	( "Computacao I 2006" );
    Introd_Alg_2007.setNome		( "Introducao de Algoritmos de Programacao 2007" );
	Computacao2_2007.setNome	( "Computao II" );
	Metodos2_2007.setNome		( "Métodos II" );

    Computacao1_2006.setDepartamento  ( &EletronicaUTFPR );
    Introd_Alg_2007.setDepartamento	  ( &EletronicaUTFPR );
    Computacao2_2007.setDepartamento  ( &EletronicaUTFPR );
    Metodos2_2007.setDepartamento     ( &EletronicaUTFPR );

    Metodos2_2007.setAluno ( &AAA );
    Metodos2_2007.setAluno ( &BBB );
    Metodos2_2007.setAluno ( &CCC );
    Metodos2_2007.setAluno ( &DDD );
    Metodos2_2007.setAluno ( &EEE );

	Computacao2_2007.setAluno ( &AAA );
    Computacao2_2007.setAluno ( &EEE );
    Computacao2_2007.setAluno ( &DDD );
}

void Principal::CalcIdadeProfs ( )
{
    // Cálculo da idade.
    Simao.Calc_Idade    ( diaAtual, mesAtual, anoAtual );
    Einstein.Calc_Idade ( diaAtual, mesAtual, anoAtual );
    Newton.Calc_Idade	( diaAtual, mesAtual, anoAtual );
    printf ("\n");
}

void Principal::UnivOndeProfsTrabalham ( )
{
    // Universidade que a Pessoa trabalha.
    Simao.OndeTrabalho ( );
    Einstein.OndeTrabalho ( );
    Newton.OndeTrabalho ( );
    //printf ("\n");
	cout << endl;
}

void Principal::DepOndeProfsTrabalham ( )
{
    // Departamento que a Pessoa trabalha.
    Simao.QualDepartamentoTrabalho ( );
    Einstein.QualDepartamentoTrabalho ( );
    Newton.QualDepartamentoTrabalho ( );
    //printf ( "\n" );
	cout << endl;
}

void Principal::ListeDiscDeptos()
{
	EletronicaUTFPR.listeDisciplinas();
	cout << endl;
}

void Principal::ListeAlunosDisc()
{
    Metodos2_2007.listeAlunos();
    cout << endl;

    Computacao2_2007.listeAlunos();  
    cout << endl;

	//Metodos2_2007.listeAlunos2();
    //cout << endl;
}

void Principal::Executar()
{
    CalcIdadeProfs();
    UnivOndeProfsTrabalham();
    DepOndeProfsTrabalham();
	ListeDiscDeptos();
    ListeAlunosDisc();
}

