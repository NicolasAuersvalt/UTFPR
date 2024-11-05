#include "Real.hpp"

Real::Real(const int tam):
    tam(tam), v(tam)
{
    srand(time(NULL));
    float* aux = (float*)malloc(sizeof(float)*tam);
    for(int i = 0; i < tam; i++){
        aux[i] = (rand()%150)*RAZAO;
    }
    v.setTipo(aux);
}

Real::~Real(){

}

void Real::ordenar(){
    std::cout << "Antes: ";
    v.imprimir();
    v.classifica();
    std::cout << "Depois: ";
    v.imprimir();
    std::cout << "\n";
}