#include "Principal.hpp"

Principal::Principal():
    inteiro(TAM_MAX_VETOR), caracter(TAM_MAX_VETOR), real(TAM_MAX_VETOR)
{
    executar();
}

Principal::~Principal(){

}

void Principal::executar(){
    std::cout << "Inteiro: " << std::endl;
    inteiro.orndenar();

    std::cout << "Caracter: " << std::endl;
    caracter.ordenar();

    std::cout << "Real: " << std::endl;
    real.ordenar();
}