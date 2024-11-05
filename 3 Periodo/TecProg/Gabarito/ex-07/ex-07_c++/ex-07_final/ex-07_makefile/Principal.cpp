#include "Principal.hpp"

Principal::Principal()
{

}

Principal::~Principal()
{

}

void Principal::getEntradas()
{
    int n, t;
    cout << "Digite o número de lados do poligno regular e o tamanho de cada lado <lados, tamanho>: ";
    cin >> n >> t;

    poligono = PolReg(n, t);
}

void Principal::executar()
{
    getEntradas();

    cout << "O perimetro do poligono regular é " << poligono.getPerimetro() << endl;
    cout << "O angulo do poligono regular é " << poligono.getAngulo() << endl;
    cout << "A área do poligono regular é " << poligono.getArea() << endl;
}
