#pragma once

#include "Elemento.h"

template<class PL>
class Pilha{
private:
    Elemento<PL>* ult;
    unsigned int tam;
    const unsigned int tamMax;
public:
    Pilha(const int tamMax);
    ~Pilha();
    void push(PL type);
    void pop();
    PL operator[](int pos);
    const int getTam();
};

template<class PL>
Pilha<PL>::Pilha(const int tamMax):
    ult(nullptr), tam(0), tamMax(tamMax)
{

}    

template<class PL>
Pilha<PL>::~Pilha(){
    /*
    if(ult != nullptr){
        Elemento<PL>* aux = ult;
        Elemento<PL>* aux2 = nullptr;
        while(aux != nullptr){
            aux2 = aux->getAnt();
            delete(aux);
            aux = aux2;
        }
        aux = nullptr;
        aux2 = nullptr;
        ult = nullptr;
        tam = 0;
    }
    */
}

template<class PL>
void Pilha<PL>::push(PL type){
    if(tam == tamMax){
        std::cout << "tam is max" << std::endl;
    } else {
        Elemento<PL>* aux = new Elemento<PL>(type);
        if(aux == nullptr){
            std::cout << "Error -1: cannot allocate memory" << std::endl;
            exit(1);
        } 
        if(ult == nullptr){
            ult = aux;
        } else {
            aux->setAnt(ult);
            ult->setProx(aux);
            ult = aux;
        }
        tam++;
    }
}

template<class PL>
void Pilha<PL>::pop(){
    if(ult == nullptr){
        std::cout << "Pilha is empty" << std::endl;
    } else {
        Elemento<PL>* aux = ult;
        Elemento<PL>* ant = aux->getAnt();
        if(ant != nullptr){
            ant->setProx(nullptr);
        }
        //delete(aux);
        aux = nullptr;
        ult = ant;
        tam--;
    }
}

template<class PL>
PL Pilha<PL>::operator[](int pos){
    if(pos < 0 || pos >= tam){
        std::cout << "Error -1: pos is invalid" << std::endl;
        exit(1);
    } 
    Elemento<PL>* aux = ult;
    for(int i = 0; i < pos; i++){
        aux = aux->getAnt();
    }
    return aux->getType();
}

template<class PL>
const int Pilha<PL>::getTam(){
    return tam;
}
