// colaborador.h
#ifndef COLABORADOR_H
#define COLABORADOR_H

#include <string>

class Colaborador {

    protected:
        std::string nome;
        int tempoServico; // Em anos

    public:
        Colaborador();
        Colaborador(const std::string& nome, int tempoServico);
        virtual ~Colaborador();

        void setNome(const std::string& nome);
        std::string getNome() const;

        void setTempoServico(int tempo);
        int getTempoServico() const;
};

#endif

