#include <stdio.h>
#include "Complexo.hpp"
#include "Real.hpp"

using std::cout;
using std::endl;

void imprimeTipoReal(Real const &r);
void imprimeTipoComplexo(Complexo const &c);

int main()
{
    Real v1(10.0);
    Real v2(-5.0);

    Complexo c1(0.0 , 0.0), 
                c2( 1.0 , 0.0),
                c3( 3.0 , 4.0),
                c4( 0.0 , 1.0),
                c5(-1.0 , 1.0),
                c6(-1.0 , 0.0),
                c7(-1.0 ,-1.0),
                c8( 0.0 ,-1.0),
                c9( 1.0 ,-1.0);

    imprimeTipoReal(v1);
    imprimeTipoReal(v2);

    imprimeTipoComplexo(c1);
    imprimeTipoComplexo(c2);
    imprimeTipoComplexo(c3);
    imprimeTipoComplexo(c4);
    imprimeTipoComplexo(c5);
    imprimeTipoComplexo(c6);
    imprimeTipoComplexo(c7);
    imprimeTipoComplexo(c8);
    imprimeTipoComplexo(c9);

    return 0;
}

void imprimeTipoReal(Real const &r)
{
    cout << "Valor = " << r.getReal();
    cout << "\t sinal: ";
    if(r.sinal() == 1)
        cout << "Positivo" << endl;
    else
        cout << "Negativo" << endl;
}

void imprimeTipoComplexo(Complexo const &c) 
{
    cout << "z = " << c.getReal();

    //Imprime parte imaginaria
    if(c.getImag() < 0)
        cout << " " << c.getImag() << "i";
    else
        cout << " +" << c.getImag() << "i";

    //Angulo e modulo
    cout << "\t Angulo: " << c.angulo();
    cout << "\t |z| = " << c.modulo() << endl; 
}