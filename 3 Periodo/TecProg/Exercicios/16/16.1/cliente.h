#include <vector>
#include <string>

class Contas; // Declaração antecipada para resolver dependência

class Cliente {
    private:
        std::string nome;
        int cpf;
        int qtdContas;
        std::vector<Contas> contas;

    public:
        Cliente(std::string nome = "", int cpf = 0, int qtdContas = 3)
            : nome(nome), cpf(cpf), qtdContas(qtdContas), contas(qtdContas) {}

        ~Cliente() {}
        std::string gerarRelatorio() {
            // Implementação do relatório
        }
        void aplicarRecursos(int na) {
            // Implementação de aplicação de recursos
        }
};
