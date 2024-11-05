#include "CarroEsporte.h"

CarroEsporte::CarroEsporte(const double &consumo, const double &capacidade,
                           const double &tam_sp, const double &num_ad_tun, const double &pot_ex_tur):
    Carro(consumo, capacidade), 
    tam_spoiler(tam_sp), 
    num_adesivos_tuning(num_ad_tun), 
    pot_ext_turbo(pot_ex_tur)
{
}

CarroEsporte::~CarroEsporte(){
}

double CarroEsporte::andar(const double &distancia){
  // Resta o combustível consumido para andar a distância solicitada.
    // Consome 50% de combustível a mais
  double consumo = 1.5*distancia / this->consumo; // km / (km/litro) = litros consumidos
  if (consumo <= this->combustivel)
  {
    // Caso tenha suficiente combustível.
    this->combustivel -= consumo;
    return distancia;
  }
  else
  {
    // Caso NÃO tenha suficiente combustível calcula quantos km conseguiu andar.
    double distanciaPercorrida = this->combustivel * this->consumo; // litros * (km/litros) = km percorridos
    this->combustivel = 0;                                          // Deixa o tanque de combustível vazio.
    return distanciaPercorrida;
  }
}

double CarroEsporte::acelerar(){
    // Gasta 1 litro na acelerada
    this->combustivel -= 1.f;
    // Simulando ronco do motor
    cout << "Vrooom vrooom!" << endl;

    return this->combustivel;
}

const double &CarroEsporte::getTamSpoiler() const{
    return tam_spoiler;
}

const double &CarroEsporte::getNumAdesivosTuning() const{
    return num_adesivos_tuning;
}

const double &CarroEsporte::getPotExtTurbo() const{
    return pot_ext_turbo;
}