#include "Principal.hpp"

//Construtora
Principal::Principal() :
gol(45, 12, "Gol")
{

}

//Destrutora
Principal::~Principal()
{

}

void Principal::setViajem()
{
    int dist = 1;
    float comb = 1;

    cout << "Digite a distância da viajem, e o nível de combustível do veículo <distancia, combustivel> :";
    cin >> dist >> comb;
    cout << endl;

    gol.viajem(dist, comb);
}

void Principal::executar()
{
    setViajem();
}
