#pragma once

#include <time.h>
#include "BubbleSort.hpp"

#define LIMITE 100

class Inteiro {
private:
    BubbleSort<int> v;
    const int tam;
public:
    Inteiro(const int tam);
    ~Inteiro();
    void orndenar();
};