#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class PolReg
{
private:
    int n_lados, tam_lado;
    int perimetro, angulo, area;
public:
    //Construtoras
    PolReg(int n, int t);
    PolReg();

    //Destrutora
    ~PolReg();

    //Set's
    bool setLados(int n);
    bool setTamanho(int t);

    //Get's
    int getPerimetro();
    int getAngulo();
    int getArea();

    //Calcula o perimetro do poligono regular
    void calcPerimetro();

    //Calcula o valor dos angulos do poligono regular
    void calcAngulo();

    //A área é zero, pois não pe possível calcular a área
    int calcArea();
};
