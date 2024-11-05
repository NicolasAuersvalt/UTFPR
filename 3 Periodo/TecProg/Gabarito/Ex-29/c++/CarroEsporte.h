#pragma once

#include <iostream>
using std::cout;
using std::endl;

#include "Carro.h"

class CarroEsporte: public Carro{
private:
    double tam_spoiler, num_adesivos_tuning, pot_ext_turbo;

public:

    CarroEsporte(const double &consumo, const double &capacidade,
                 const double &tam_sp, const double &num_ad_tun, const double &pot_ex_tur);
    ~CarroEsporte();

    double andar(const double &distancia);
    double acelerar();

    const double &getTamSpoiler() const;
    const double &getNumAdesivosTuning() const;
    const double &getPotExtTurbo() const;

};