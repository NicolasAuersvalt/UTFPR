#ifndef CONTAS_H
#define CONTAS_H

class Contas {
    private:
        int numero;
        float saldo;

    public:
        Contas(int numero = 0, float saldo = 0.0f) 
            : numero(numero), saldo(saldo) {}

        ~Contas() {}
        
        void sacar(float valor) {
            if (valor <= saldo && valor > 0) {
                saldo -= valor;
            }
        }

        void depositar(float dep) {
            if (dep > 0) {
                saldo += dep;
            }
        }

        float getSaldo() const { return saldo; }
        int getNumero() const { return numero; }
};

#endif
