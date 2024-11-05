#pragma once

#include <time.h>
#include "BubbleSort.hpp"

#define RAZAO 0.7958

class Real {
private:
    BubbleSort<float> v;
    const int tam;
public:
    Real(const int tam);
    ~Real();
    void ordenar();
};