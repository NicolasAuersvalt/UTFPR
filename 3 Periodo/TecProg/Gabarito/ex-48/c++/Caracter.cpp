#include "Caracter.hpp"

Caracter::Caracter(const int tam):
    tam(tam), v(tam)
{
    srand(time(NULL));
    char* aux = (char*)malloc(sizeof(char)*tam);
    for(int i = 0; i < tam; i++){
        aux[i] = 97 + rand()%26;
    }
    v.setTipo(aux);
}

Caracter::~Caracter(){

}

void Caracter::ordenar(){
    std::cout << "Antes: ";
    v.imprimir();
    v.classifica();
    std::cout << "Depois: ";
    v.imprimir();
    std::cout << "\n";
}