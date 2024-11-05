#include "Ponto.h"

Ponto::Ponto(float x, float y) :
x(x),
y(y) { }

Ponto::~Ponto() {
}

void Ponto::setPonto(float x, float y) {
    this->x = x;
    this->y = y;
}

float Ponto::getX() const {
    return x;
}

float Ponto::getY() const {
    return y;
}
