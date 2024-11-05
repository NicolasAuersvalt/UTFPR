#include "Poligono.h"

#include <iostream>
#include <math.h>

Poligono::Poligono() { }

Poligono::~Poligono() {
    Ponto* tmp;
    for (int i = 0; i < getQuantidadePontos(); i++) {
        tmp = pontos[i];
        if (tmp != NULL)
            delete (tmp);

        pontos[i] = NULL;
    }
    pontos.clear();
}

void Poligono::setVertice(Ponto* pPonto) {
    if (pPonto == NULL) {
        std::cout << "Ponteiro NULL ao incluir novo vertice em Poligono" << std::endl;
        exit(1);
    }

    pontos.push_back(pPonto);
}

/* Calcula e imprime o perimetro do Poligono */
void Poligono::imprimirPerimetro() {
    float perimetro = 0;

    /* Soma todas as distancias entre os pontos */
    for (int i = 0; i < getQuantidadePontos() - 1; i++) {
        perimetro += calcDist(pontos[i], pontos[i + 1]);
    }
    /* Falta somar a distancia do ultimo ponto para o primeiro */
    if (getQuantidadePontos() - 1 > 1)
        perimetro += calcDist(pontos[getQuantidadePontos() - 1], pontos[0]);

    std::cout << "O perimetro do Poligono é " << perimetro << std::endl;
}

/* Acessa o vetor retornando o Ponto correspondente ao indice i do vetor */
Ponto* Poligono::operator[](int i) {
    if (i < 0 || i >= getQuantidadePontos()) {
        std::cout << "Vector out of range." << std::endl;
        exit(8);
    }

    return pontos[i];
}

/* Pega a quantiade de pontos */
int Poligono::getQuantidadePontos() const {
    return pontos.size();
}

/* Calcula a distancia entre dois pontos */
float Poligono::calcDist(Ponto* p1, Ponto* p2) {
    return sqrt((p1->getX() - p2->getX()) * (p1->getX() - p2->getX()) + (p1->getY() - p2->getY()) * (p1->getY() - p2->getY()));
}

/* Remover ponto do poligono */
void Poligono::removerPonto(Ponto* pPonto) {
    vector<Ponto*>::iterator itr;

    Ponto* tmp = NULL;
    for (itr = pontos.begin(); itr != pontos.end(); itr++) {
        tmp = *itr;
        if (tmp == pPonto) {
            if (pPonto != NULL) {
                delete (pPonto);
                pontos.erase(itr);
            }
            return;
        }
    }
}

/* Imprime todos os pontos e seu indice */
void Poligono::imprimirTodosPontos() {
    Ponto* tmp = NULL;
    cout << "Imprimindo pontos poligono: \nindice - (x,y)" << endl;
    
    if (getQuantidadePontos() < 1) {
        cout << "Nao ha pontos nesse poligono!" << endl;
        return;
    }

    for (int i = 0; i < getQuantidadePontos(); i++) {
        tmp = pontos[i];
        if (tmp)
            cout << i << " - (" << tmp->getX() << "," << tmp->getY() << ")" << endl;
        else
            cout << i << " - sem coordenadas" << endl;
    }
}