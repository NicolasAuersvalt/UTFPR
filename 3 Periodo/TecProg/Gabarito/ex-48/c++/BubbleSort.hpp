#pragma once

#include <iostream>

template<class BS>
class BubbleSort {
    private:
        BS* tipo;
        const int tam;
    public:
        BubbleSort(const int tam, const BS* tipo);
        BubbleSort(const int tam);
        ~BubbleSort();

        void setTipo(BS* tipo);

        void classifica();
        bool MaiorQue(BS a, BS b);

        void imprimir();
};

template<class BS>
BubbleSort<BS>::BubbleSort(const int tam, const BS* tipo):
    tipo(tipo), tam(tam)
{

}

template<class BS>
BubbleSort<BS>::BubbleSort(const int tam):
    tam(tam), tipo(nullptr)
{

}

template<class BS>
BubbleSort<BS>::~BubbleSort(){

}

template<class BS>
void BubbleSort<BS>::setTipo(BS* tipo){
    this->tipo = tipo;
}

template<class BS>
void BubbleSort<BS>::classifica(){
    int pos = tam - 1;
    while(pos > 0){
        for(int i = 0; i < pos; i++){
            if(MaiorQue(tipo[i], tipo[i + 1])){
                BS aux = tipo[i];
                tipo[i] = tipo[i + 1];
                tipo[i + 1] = aux;
            }
        }
        pos--;
    }
}

template<class BS>
bool BubbleSort<BS>::MaiorQue(BS a, BS b){
    /*
    if(a > b){
        return true;
    }
    return false;
    */
   //operator ternário:
    return (a > b) ? true : false;
}

template<class BS>
void BubbleSort<BS>::imprimir(){
    for(int i = 0; i < tam; i++){
        std::cout << tipo[i] << " ";
    }
    std::cout << "\n";
}