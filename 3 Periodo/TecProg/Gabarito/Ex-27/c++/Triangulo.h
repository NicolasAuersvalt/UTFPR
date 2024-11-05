#pragma once

#include "Ponto.h"

class Triangulo {
private:
    Ponto* vertice1;
    Ponto* vertice2;
    Ponto* vertice3;

public:
    Triangulo();
    ~Triangulo();

    void setVertice1(float x, float y);
    void setVertice2(float x, float y);
    void setVertice3(float x, float y);

    Ponto* getPVertice1() const;
    Ponto* getPVertice2() const;
    Ponto* getPVertice3() const;

    void imprimirPerimetro();

private:
    bool testeTriangulo();
    float calcDist(Ponto* p1, Ponto* p2);
};
