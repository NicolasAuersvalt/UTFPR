#include "Familia.h"
#include "Pessoa.h"
#include <stdio.h>

int main() {
    Pessoa filho1("Pedro Almeida");
    Pessoa filho2("Lucas Augusto");
    Pessoa pai("Carlão Souza");
    Pessoa mae("Maria Giovanni");

    Familia jhonson("Jhonson");
    jhonson.setConjuge(&pai);
    jhonson.setPrincipal(&mae);
    jhonson.adicionarFilho(&filho1);
    jhonson.adicionarFilho(&filho2);

    jhonson.listarArvoreFamiliar();

    pai.listarFilhos();

    return 0;
}