#pragma once

class PolReg {
    // Classe base tem atributos protegidos
protected:
    int num_lados;
    double tam_lados;

public:
    // Valores de atributos com número 0 por default
    PolReg(const int numlados = 0, const double tamlados = 0);
    ~PolReg();

    // Gets necessários para informar os atributos
    int getNumLados() const { return num_lados; }
    double getTamLados() const { return tam_lados; }

    // Retornam cálculos
    double calculaPerimetro() const;
    int calculaAnguloInterno() const;

    // Polimorfisa a classe, retornando 0 por não existir forma de calcular a área de um polígono regular genérico
    virtual double calculaArea() = 0;
};