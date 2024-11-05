#include "Inteiro.hpp"

Inteiro::Inteiro(const int tam):
    tam(tam), v(tam)
{
    srand(time(NULL));
    int* aux = (int*)malloc(sizeof(int)*tam);
    for(int i = 0; i < tam; i++){
        aux[i] = rand()%LIMITE;
    }
    v.setTipo(aux);
}

Inteiro::~Inteiro(){

}

void Inteiro::orndenar(){
    std::cout << "Antes: ";
    v.imprimir();
    v.classifica();
    std::cout << "Depois: ";
    v.imprimir();
    std::cout << "\n";
}