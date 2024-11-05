#pragma once
#pragma warning(disable : 4996)

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define ESTRADA 0
#define CIDADE 1
#define NIVEL_COMB_CRITICO 1

class Carro
{
private:
    char nome[30];
    float combustivelMax, combustivelAt;
    int consumo, distPerc;
    int disPercLocal[2]; //Vetor para armazenar a distância percorrida na cidade e na estrada
public:
    //Construtoras
    Carro(float max, int cons, const char* n);
    Carro();

    //Destrutora
    ~Carro();

    //Set's
    bool setCombMax(float max);
    bool setConsumo(int comb);
    void setNome(const char* n);

    //Get's
    float getCombustivel();
    char* getNome();
    
    //O carro anda uma distância dada no respectivo local (estrada ou cidade)
    void andar(int dist, int local);

    //O carro abastece o tanque com uma quantia dada
    void abastecer(float quantComb);

    //O carro realiza um viajem de uma distância e um nivel inicial de combustível no tanque, ambos parâmetros
    void viajem(int dist, float comb);
};
