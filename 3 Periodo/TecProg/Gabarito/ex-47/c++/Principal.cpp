#include "Principal.h"

Principal::Principal():
    pilha_de_inteiros(TAM_MAX_PILHA_INTEIROS), pilha_de_caracter(TAM_MAX_PILHA_CARACTERES), num(-1)
{
    executarInteiro();
    executarCaracter();
}

Principal::~Principal(){

}

void Principal::executarInteiro(){
    while(num != 3){
        system("cls");
        std::cout << "Pilha de Inteiros" << "\n\n";
        pilha_de_inteiros.imprimir();
        std::cout << "1 - Empilhar" << std::endl;
        std::cout << "2 - Desempilhar" << std::endl;
        std::cout << "3 - Sair" << "\n\n";
        std::cout << "Digito: " << std::endl;
        std::cin >> num;

        switch (num)
        {
        case 1:
            pilha_de_inteiros.add_na_pilha();
            break;
        case 2:
            pilha_de_inteiros.remove_da_pilha();
            break;
        case 3:
            break;
        default:
            std::cout << "Entrada invalida!" << std::endl;
            break;
        }

        system("pause");
    }
}

void Principal::executarCaracter(){
    num = -1;
    while(num != 3){
        system("cls");
        std::cout << "Pilha de Caracteres" << "\n\n";
        pilha_de_caracter.imprimir();
        std::cout << "1 - Empilhar" << std::endl;
        std::cout << "2 - Desempilhar" << std::endl;
        std::cout << "3 - Sair" << "\n\n";
        std::cout << "Digito: " << std::endl;
        std::cin >> num;

        switch (num)
        {
        case 1:
            pilha_de_caracter.add_na_pilha();
            break;
        case 2:
            pilha_de_caracter.remove_da_pilha();
            break;
        case 3:
            break;
        default:
            std::cout << "Entrada invalida!" << std::endl;
            break;
        }

        system("pause");
    }
}