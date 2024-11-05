#include "Principal.h"

#include <iostream>
#include <stdio.h>

Principal::Principal() :
polig() {
    exec();
}

Principal::~Principal() {
}

void Principal::exec() {
    int opcao = 1;
    while (opcao != 0) {
        std::cout << "\n=========================================" << std::endl;
        std::cout << "1 - Incluir ponto no poligono\n2 - Remover ponto do Poligono\n3 - Imprimir perimetro do poligono\n4 - Imprimir todos os prontos\n0 - Sair\n";
        std::cout << "=========================================\nSelecione uma opçao: ";
        scanf("%d%*c", &opcao);
        std::cout << "=========================================" << std::endl;
        switch (opcao) {
        case 1:
            lerPonto();
            break;
        case 2:
            removerPonto();
            break;
        case 3:
            imprimirPerimetro();
            break;
        case 4:
            polig.imprimirTodosPontos();
            break;
        default:
            break;
        }
    }
}

void Principal::lerPonto() {
    float x = 0, y = 0;
    std::cout << "\nDigite a coordenada do vertice no formato(x.x, y.y) :";
    scanf("(%f,%f)%*c", &x, &y);

    Ponto* tmp = new Ponto;
    tmp->setPonto(x, y);

    polig.setVertice(tmp);
}

void Principal::imprimirPerimetro() {
    polig.imprimirPerimetro();
}

void Principal::removerPonto() {
    int x = 0;

    polig.imprimirTodosPontos();
    cout << "\nQual ponto deseja remover? ";

    scanf("%d%*c", &x);

    polig.removerPonto(polig[x]);
}