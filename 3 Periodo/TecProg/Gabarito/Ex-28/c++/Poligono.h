#pragma once

#include "Ponto.h"
#include <vector>
using namespace std;

class Poligono {
private:
    vector<Ponto*> pontos;

public:
    Poligono();
    ~Poligono();

    void setVertice(Ponto* pPonto);
    void imprimirPerimetro();
    Ponto* operator[](int i);
    int getQuantidadePontos() const;
    void removerPonto(Ponto* pPonto);
    void imprimirTodosPontos();

private:
    float calcDist(Ponto* p1, Ponto* p2);
};
