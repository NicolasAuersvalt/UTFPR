#include "Principal.hpp"

Principal::Principal()
{
    getEntradas();
}

Principal::~Principal()
{

}

void Principal::executar()
{
    Vetor soma = v1.soma(v2);
    Vetor mult1 = v1.multiplica(4);
    Vetor mult2 = v2.multiplica(2);
    std::cout << "Soma dos vetores: <" << soma.getDx() << "," << soma.getDy() << ">"<< std::endl;
    std::cout << "Multiplicação vetor 1: <" << mult1.getDx() << "," << mult1.getDy() << ">" << std::endl;
    std::cout << "Multiplicação vetor 2: <" << mult2.getDx() << "," << mult2.getDy() << ">" << std::endl;
}

void Principal::getEntradas()
{
    int x, y;

    cout << "Digita os valores de x e y do primeiro vetor <x> <y>:";
    cin >> x >> y;
    cout << endl;

    v1 = Vetor(x, y);

    cout << "Digite os valores de x e y do segundo vetor <x> <y>: ";
    cin >> x >> y;
    cout << endl;

    v2 = Vetor(x, y);

       
}