#include "Caracter.h"

Caracter::Caracter(int tamMax):
    pilha_de_caracteres(tamMax), tamMax(tamMax)
{

}

Caracter::~Caracter(){
    pilha_de_caracteres.~Pilha();
}

void Caracter::add_na_pilha(){
    char c;
    std::cout << "Insira um caracter: ";
    std::cin >> c;
    pilha_de_caracteres.push(c);
}

void Caracter::remove_da_pilha(){
    pilha_de_caracteres.pop();
}

void Caracter::imprimir(){
    int tam = pilha_de_caracteres.getTam();
    if(tam == 0){
        std::cout << "Pilha vazia!" << "\n\n";
    } else {
        for(int i = tam - 1; i >= 0; i--){
            std::cout << pilha_de_caracteres.operator[](i) << " ";
        }
        std::cout << "\n\n";
    }
}