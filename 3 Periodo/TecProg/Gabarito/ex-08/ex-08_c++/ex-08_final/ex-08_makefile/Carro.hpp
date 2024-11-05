#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Carro
{
private:
    int combustivelMax, combustivelAt, consumo;
public:
    //Construtoras
    Carro(int max, int cons);
    Carro();

    //Destrutora
    ~Carro();

    //Set's
    bool setCombMax(int max);
    bool setConsumo(int comb);

    //Get's
    int getCombustivel();

    //O carro anda uma distância dada
    void andar(int dist);

    //O carro abastece o tanque com um quantidade dada
    void abastecer(int quantComb);
};
