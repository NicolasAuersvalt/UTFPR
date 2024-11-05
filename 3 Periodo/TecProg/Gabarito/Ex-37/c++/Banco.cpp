#include "Banco.h"

#include "ContaCorrente.h"
#include "ContaPoupanca.h"

#include <stdio.h>
#include <stdlib.h>

/* Atributo static, sendo inicializado fora da classe */
int Banco::idConta = 0;

#define CLEAR "cls" // Mudar para "cls" no windows

Banco::Banco() {
    exec();
}

Banco::~Banco() {
    /* Deleta todas as contas existentes */
    Conta* pAux = NULL;
    for (int i = 0; i < contas.size(); i++) {
        pAux = static_cast<Conta*>(contas[i]);
        if (pAux)
            delete (pAux);
    }
    contas.clear();
}

void Banco::exec() {
    int opcao = 1;
    while (opcao != 0) {
        opcao = MenuPrincipal();
        switch (opcao) {
        case 1:
            criarNovaConta();
            break;
        case 2:
            lerSaldo();
            break;
        case 3:
            depositarEmConta();
            break;
        case 4:
            sacar();
            break;
        case 5:
            aplicarJuros();
            break;
        default:
            break;
        }
    }
}

/* Imprime menu Principal e retorna a opcao escolhida */
int Banco::MenuPrincipal() const {
    int opcao = -1;

    while (opcao < 0 || opcao > 5) {
        system(CLEAR);
        printf("===================== MENU =====================\n");
        printf("1 - Criar nova conta\n2 - Ler saldo de conta\n3 - Depositar\n4 - Sacar\n5 - Aplicar juros diários\n0 - Sair\n");
        printf("Selecione uma opcao: ");
        scanf("%d%*c", &opcao);
    }

    return opcao;
}

/* Funçao para criar uma nova conta no banco */
void Banco::criarNovaConta() {
    int opcao = 0;

    while (opcao != 1 && opcao != 2) {
        system(CLEAR);
        printf("================== NOVA CONTA ==================\n");
        printf("1 - Criar nova conta corrente\n2 - Criar nova conta poupança\n");
        printf("Selecione uma opcao: ");
        scanf("%d%*c", &opcao);
    }

    Conta* novaConta = NULL;

    if (opcao == 1) {
        /* Static cast para colocar no vector somente ponteiro de conta, ja que CC e CP herdam Conta */
        novaConta = static_cast<Conta*>(new ContaCorrente(idConta++));
        if (novaConta) {
            contas.push_back(novaConta);
            printf("Nova conta criada com id %04d\n", novaConta->getNumeroConta());
        } else
            printf("ERRO ao criar nova conta Corrente");
    }

    else {
        novaConta = static_cast<Conta*>(new ContaPoupanca(idConta++));
        if (novaConta) {
            contas.push_back(novaConta);
            printf("Nova conta criada com id %04d\n", novaConta->getNumeroConta());
        } else
            printf("ERRO ao criar nova conta Poupança");
    }

    getchar();
}

/* Ler saldo em tal conta */
void Banco::lerSaldo() {
    Conta* pAux = NULL;

    pAux = encontraConta();

    if (pAux)
        printf("Saldo da conta: %.2f\n", pAux->getSaldo());

    getchar();
}

/* Deposita uma quantia em cada conta */
void Banco::depositarEmConta() {
    Conta* pAux = NULL;

    pAux = encontraConta();

    if (pAux) {
        double quantia = 0;
        printf("Digite a quantidade a depositar: ");
        scanf("%lf%*c", &quantia);
        if (quantia <= 0.0) {
            printf("Quantia invalida, operaçao nao sucedida!\n");
        }

        else {
            pAux->depositar(quantia);
            printf("Sucesso!\n");
        }
    }
    getchar();
}

/* Saca dinheiro de certa conta */
void Banco::sacar() {
    Conta* pAux = NULL;

    pAux = encontraConta();

    if (pAux) {
        double quantia = 0;
        printf("Digite a quantidade a sacar: ");
        scanf("%lf%*c", &quantia);
        /* Sacar retorna true se foi possivel fazer o saque, ou falso do contrario */
        if (pAux->sacar(quantia))
            printf("Sucesso!\n");
        else
            printf("Saldo insuficiente, operaçao nao realizada!\n");
    }
    getchar();
}

/* Aplica juros em todas as contas */
void Banco::aplicarJuros() {
    /* Nao estava especificado no enunciado se o juros seria aplicado em uma conta somente ou todas,
    portando interpretei que seria em todas as contas, o que faz sentido */

    int dias = -1;
    Conta* pAux = NULL;

    while (dias <= 0) {
        system(CLEAR);
        printf("Informe o numero de dias para aplicar os juros: ");
        scanf("%d%*c", &dias);
    }

    for (int i = 0; i < contas.size(); i++) {
        pAux = static_cast<Conta*>(contas[i]);
        if (pAux)
            pAux->aplicarJurosDiarios(dias);
    }
}

/* Retorna um ponteiro para uma conta com um certo id, ou NULL se nao encontrar */
Conta* Banco::encontraConta() {
    int id = -1;
    Conta* pAux = NULL;

    while (id < 0) {
        system(CLEAR);
        printf("Informe o numero da conta: ");
        scanf("%d%*c", &id);
    }

    for (int i = 0; i < contas.size(); i++) {
        pAux = static_cast<Conta*>(contas[i]);
        if (pAux != NULL)
            if (pAux->getNumeroConta() == id)
                return pAux;
    }

    printf("Conta nao encontrada!\n");

    return NULL;
}