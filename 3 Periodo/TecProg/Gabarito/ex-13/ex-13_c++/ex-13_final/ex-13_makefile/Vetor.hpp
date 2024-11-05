#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Vetor
{
private:
    int dx, dy;
public:
    //Construtoras
    Vetor(int x, int y);
    Vetor();

    //Destrutora
    ~Vetor();

    //Set's
    void setDx(int x);
    void setDy(int y);

    //Get's
    int getDx() const;
    int getDy() const;

    //Soma de dois vetores
    Vetor soma(Vetor v);

    //Multiplicação de um vetor por uma constante
    Vetor multiplica(int i);
};
