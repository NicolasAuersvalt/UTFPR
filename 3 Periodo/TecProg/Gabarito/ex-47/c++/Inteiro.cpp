#include "Inteiro.h"

Inteiro::Inteiro(int tamMax):
    pilha_de_inteiros(tamMax), tamMax(tamMax)
{

}

Inteiro::~Inteiro(){
    pilha_de_inteiros.~Pilha();
}

void Inteiro::add_na_pilha(){
    int num;
    std::cout << "Insira um valor: ";
    std::cin >> num;
    pilha_de_inteiros.push(num);
}

void Inteiro::remove_da_pilha(){
    pilha_de_inteiros.pop();
}

void Inteiro::imprimir(){
    int tam = pilha_de_inteiros.getTam();
    if(tam == 0){
        std::cout << "Pilha vazia!" << "\n\n";
    } else {
        for(int i = tam - 1; i >= 0; i--){
            std::cout << pilha_de_inteiros.operator[](i) << " ";
        }
        std::cout << "\n\n";
    }
}