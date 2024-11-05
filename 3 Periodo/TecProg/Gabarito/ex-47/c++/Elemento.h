#pragma once

#include <iostream>

template<class TE>
class Elemento{
    private:
        Elemento<TE>* prox;
        Elemento<TE>* ant;
        TE type;
    public:
        Elemento();
        Elemento(TE type);
        ~Elemento();

        void setProx(Elemento<TE>* prox);
        Elemento<TE>* getProx();

        void setAnt(Elemento<TE>* ant);
        Elemento<TE>* getAnt();


        void setType(TE* type);
        TE getType();
};

template<class TE>
Elemento<TE>::Elemento():
    prox(nullptr), ant(nullptr), type()
{

}

template<class TE>
Elemento<TE>::Elemento(TE type):
    prox(nullptr), ant(nullptr), type(type)
{

}

template<class TE>
Elemento<TE>::~Elemento(){
    
}

template<class TE>
void Elemento<TE>::setProx(Elemento<TE>* prox){
    this->prox = prox;
}

template<class TE>
Elemento<TE>* Elemento<TE>::getProx(){
    return prox;
}

template<class TE>
void Elemento<TE>::setAnt(Elemento<TE>* ant){
    this->ant = ant;
}

template<class TE>
Elemento<TE>* Elemento<TE>::getAnt(){
    return ant;
}

template<class TE>
void Elemento<TE>::setType(TE* type){
    this->type = type;
}

template<class TE>
TE Elemento<TE>::getType(){
    return type;
}