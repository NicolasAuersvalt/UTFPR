#include"stdafx.h"
#include "Planeta.h"

Planeta::Planeta():
    Astro()
{
    tempo_orbita = 0;
    pSol = NULL;
}


Planeta::~Planeta(){}

float Planeta::calcQuantOrbita(){

    float resultado = 0.0;
    if(NULL != pSol){

        int tempo_sol;
        tempo_sol = pSol -> getTempoExistencia();
        resultado = (float) tempo_sol / tempo_orbita;
    }
    else{

        cout << "Ponteiro do Sol está nulo!" << endl;
        resultado = -1.0;
    }
    return resultado;

}