#include "Vetor.hpp"

//Construtoras
Vetor::Vetor(int x, int y) :
dx(x), dy(y)
{

}

Vetor::Vetor() :
dx(0), dy(0)
{

}

//Destrutora
Vetor::~Vetor()
{

}

//Set's
void Vetor::setDx(int x)
{
    dx = x;
}

void Vetor::setDy(int y)
{
    dy = y;
}

//Get's
int Vetor::getDx() const
{
    return dx;
}

int Vetor::getDy() const
{
    return dy;
}

//Soma dois vetores
Vetor Vetor::soma(Vetor v)
{
    return Vetor(v.dx + dx, v.dy + dy);
}

//Multiplica um vetor por uma constante
Vetor Vetor::multiplica(int i)
{
    return Vetor(dx*i, dy*i);
}
