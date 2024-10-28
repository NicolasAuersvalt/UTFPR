// socio.h
#ifndef SOCIO_H
#define SOCIO_H

#include "colaborador.h"

class Socio : public Colaborador {

    private:
        float valHora;
        int horasTrabalhadas;

    public:
        Socio();
        ~Socio();

        void setNome(const std::string& nome);
        std::string getNome() const;

        void setValores(float val, int horas);
        void setHorasTrabalhadas(int horas);
        int getHorasTrabalhadas() const;

        float calculaPagamento() const;
};

#endif

