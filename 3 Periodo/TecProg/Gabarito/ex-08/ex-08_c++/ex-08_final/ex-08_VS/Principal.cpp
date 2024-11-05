#include "Principal.hpp"

//Construtora
Principal::Principal() :
gol(45, 12), uno(40, 14)
{

}

//Destrutora
Principal::~Principal()
{

}

void Principal::executar()
{
    gol.abastecer(20);
    cout << "O gol tem atualmente " << gol.getCombustivel() << " litros de combustível." << endl;

    uno.abastecer(25);
    cout << "O uno tem atualmente " << uno.getCombustivel() << " litros de combustível." << endl;

    uno.andar(150);
    cout << "Depois de viajar o uno tem " << uno.getCombustivel() << " litros de combustível." << endl;

    gol.andar(80);
    cout << "Depois de viajar o gol tem " << gol.getCombustivel() << " litros de combustível." << endl;

}
