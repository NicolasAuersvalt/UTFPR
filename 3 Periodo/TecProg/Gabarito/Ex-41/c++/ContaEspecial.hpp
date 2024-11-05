#pragma once

#include "ContaCorrente.hpp"

class ContaEspecial :
    public ContaCorrente
{
public:
    ContaEspecial();
    ~ContaEspecial();
    virtual void sacar(const double valor) override;
};