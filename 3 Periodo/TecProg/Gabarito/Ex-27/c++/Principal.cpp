#include "Principal.h"

#include <iostream>
#include <stdio.h>

Principal::Principal():
triang(){
    exec();
}

Principal::~Principal()
{
}

void Principal::exec(){
    float x = 0, y = 0;

    std::cout << "Criando um triangulo... \nDigite a coordenada do primeiro vertice no formato (x.x,y.y): ";
    scanf("(%f,%f)%*c", &x, &y);
    triang.setVertice1(x,y);

    std::cout << "Digite a coordenada do segundo vertice no formato (x.x,y.y): ";
    scanf("(%f,%f)%*c", &x, &y);
    triang.setVertice2(x,y);

    std::cout << "Digite a coordenada do terceiro vertice no formato (x.x,y.y): ";
    scanf("(%f,%f)%*c", &x, &y);
    triang.setVertice3(x,y);

    triang.imprimirPerimetro();
}