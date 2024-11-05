#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

#define HORAS_TRABALHADAS_MES_PADRAO 80

enum vinculo{EMPREGADO, SOCIO, ESTAGIARIO};

class Colaborador
{
private:
    char nome[30];
    int tempoServico, tipoVinculo, horasTrabalha;
    float valorHoraTrabalho;
    float rendimento, custo;
public:
    //Construtoras
    Colaborador(const char* n, int vinculo);
    Colaborador();

    //Destrutora
    ~Colaborador();

    //Set's
    void setNome(const char* n);
    bool setTempoServico(int temp);
    bool setVinculo(int vinculo);
    bool setValorHoraTrabalho(float valor);
    bool setHorasTrabalha(int horas);

    //Get's
    char* getNome();
    float getRendimento();
    float getCusto();

    //Calcula o rendimento com base no vínculo e o número de horas trabalhadas
    void calculaRendimento();

    //Calcula o custo de um colaborador
    void calculaCusto();
};
