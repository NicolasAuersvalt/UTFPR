#include "PolReg.hpp"

//Construtoras
PolReg::PolReg(int n, int t)
{
    if(!setLados(n) || !setTamanho(t))
        exit(0);

    calcPerimetro();
    calcAngulo();
    calcArea();
}

PolReg::PolReg() :
n_lados(0), tam_lado(0), perimetro(0), angulo(0), area(0)
{

}

//Destrutora
PolReg::~PolReg()
{

}

//Set's
bool PolReg::setLados(int n)
{
    if(n < 3)
    {
        std::cout << "Número de lados incorreto!" << std::endl;
        return false;
    }
    n_lados = n;
    return true;
}

bool PolReg::setTamanho(int t)
{
    if(t < 1)
    {
        std::cout << "Tamanho dos lados incorreto!" << std::endl;
        return false;
    }
    tam_lado = t;
    return true;
}

//Get's
int PolReg::getPerimetro()
{
    return perimetro;
}

int PolReg::getAngulo()
{
    return angulo;
}

int PolReg::getArea()
{
    return area;
}

//Calcula o perimetro do poligono regular
void PolReg::calcPerimetro()
{
    perimetro = n_lados*tam_lado;
}

//Calcula o valor dos angulos do poligono regular
void PolReg::calcAngulo()
{
    angulo = 180*(n_lados - 2)/n_lados;
}

//A área é zero, pois não pe possível calcular a área
int PolReg::calcArea()
{
    area = 0;
    return 0;
}
