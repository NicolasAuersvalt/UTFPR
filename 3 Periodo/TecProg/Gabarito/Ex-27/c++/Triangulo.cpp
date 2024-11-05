#include "Triangulo.h"

#include <iostream>
#include <math.h>

Triangulo::Triangulo() {
    vertice1 = new Ponto();
    vertice2 = new Ponto();
    vertice3 = new Ponto();
}

Triangulo::~Triangulo() {
    delete (vertice1);
    delete (vertice2);
    delete (vertice3);
}

void Triangulo::setVertice1(float x, float y) {
    vertice1->setPonto(x, y);
}

void Triangulo::setVertice2(float x, float y) {
    vertice2->setPonto(x, y);
}

void Triangulo::setVertice3(float x, float y) {
    vertice3->setPonto(x, y);
}

Ponto* Triangulo::getPVertice1() const {
    return vertice1;
}

Ponto* Triangulo::getPVertice2() const {
    return vertice2;
}

Ponto* Triangulo::getPVertice3() const {
    return vertice3;
}

/* Calcula e imprime o perimetro do triangulo */
void Triangulo::imprimirPerimetro() {
    float perimetro = 0;

    if (!testeTriangulo()) {
        std::cout << "Os vértices não formam um triangulo, pois são colineares." << std::endl;
        return;
    }

    perimetro += calcDist(vertice1, vertice2);
    perimetro += calcDist(vertice2, vertice3);
    perimetro += calcDist(vertice1, vertice3);

    std::cout << "O perimetro do triangulo é " << perimetro << std::endl;
}

/* Testa se os vertices foram um triangulo */
bool Triangulo::testeTriangulo() {
    if (vertice1->getX() == vertice2->getX() && vertice1->getX() == vertice3->getX())
        return false;
    if (vertice1->getY() == vertice2->getY() && vertice1->getY() == vertice3->getY())
        return false;
    return true;
}

/* Calcula a distancia entre dois pontos */
float Triangulo::calcDist(Ponto* p1, Ponto* p2) {
    return sqrt((p1->getX() - p2->getX()) * (p1->getX() - p2->getX()) + (p1->getY() - p2->getY()) * (p1->getY() - p2->getY()));
}
