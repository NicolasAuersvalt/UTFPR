#pragma once

#include <time.h>
#include "BubbleSort.hpp"

class Caracter {
private:
    BubbleSort<char> v;
    const int tam;
public:
    Caracter(const int tam);
    ~Caracter();
    void ordenar();
};
