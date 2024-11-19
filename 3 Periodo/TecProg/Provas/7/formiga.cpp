#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Formiga {
protected:
    static int comidas;

public:
    Formiga() {}
    static int getComidas() { return comidas; }
};
int Formiga::comidas = -1;

class Operaria : public Formiga {
private:
    bool exploradora;
    static int feromonio;

public:
    Operaria() {
        exploradora = rand() % 100 > 50;
    }
    void operator++() {
        if (exploradora) feromonio++;
    }
    bool getExploradora() { return exploradora; }
    static int getFeromonio() { return feromonio; }
};
int Operaria::feromonio = 0;

class Rainha : public Formiga {
private:
    Formigueiro* pLar;

public:
    Rainha() : pLar(nullptr) {}
    ~Rainha() { pLar = nullptr; }
};

class Formigueiro {
private:
    vector<Operaria*> formigal;
    vector<Operaria*>::iterator itFormigal;
    Rainha rainha;

public:
    Formigueiro() { itFormigal = formigal.begin(); }
    void inserir(Operaria* pOp) {
        if (pOp) formigal.push_back(pOp);
    }
    void inicio() { itFormigal = formigal.begin(); }
    void proximo() {
        if (itFormigal != formigal.end()) itFormigal++;
    }
    Operaria* atual() {
        if (itFormigal != formigal.end()) return *itFormigal;
        return nullptr;
    }
    bool fim() { return itFormigal == formigal.end(); }
    bool vivo() { return 10 * static_cast<int>(formigal.size()) >= comidas; }
};

class Jardim {
private:
    Formigueiro formigueiro;
    int quant_folhas;

public:
    Jardim(int quant_f) : quant_folhas(quant_f) {}
    void exploracao() {
        formigueiro.inicio();
        while (!formigueiro.fim()) {
            Operaria* op = formigueiro.atual();
            if (op->getExploradora()) op->operator++();
            formigueiro.proximo();
        }
    }
    void carreira() { /* Implementar lógica */ }
};

int main() {
    for (int i = 0; i < 20; i++) {
        Jardim jardim(i);
        jardim.exploracao();
    }
    return 0;
}
