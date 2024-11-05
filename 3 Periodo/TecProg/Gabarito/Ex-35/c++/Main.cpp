#include <iostream>

#include "Empregado.hpp"
#include "Faxineiro.hpp"
#include "Gerente.hpp"
using std::cin;

int main()
{
    Empregado *ptrEmpregado = nullptr;
    string nome, cargo;
    int op, CPF, horaTrabalhada;
    float bonus;
    
    cout << "Entre com o indice do funcionario: " << endl;
    cout << "1. Faxineiro" << endl;
    cout << "2. Empregado" << endl;
    cout << "3. Gerente" << endl;
    cin >> op;

    if(op < 1 || op > 3)
        cout << "Indice invalido. Finalizando programa!" << endl;
    else {

        cout << "Nome: ";
        cin >> nome;
        cout << "CPF: ";
        cin >> CPF;
        cout << "Horas trabalhadas: ";
        cin >> horaTrabalhada;

        if(op == 1) {
            ptrEmpregado = new Faxineiro(nome, CPF);
        }
        else if(op == 2) {
            cout << "Cargo: ";
            cin >> cargo;
            ptrEmpregado = new Empregado(nome, CPF, cargo);
        }
        else {
            cout << "Bonus: ";
            cin >> bonus;
            ptrEmpregado = new Gerente(nome, CPF, bonus);
        }

        if(ptrEmpregado != nullptr) {
            ptrEmpregado->mostraDados();
            cout << "Salario: R$ " << ptrEmpregado->calculaSalario(horaTrabalhada) << endl;
            delete(ptrEmpregado);
        }
        else{
            cout << "Nao foi possivel criar o funcionario!" << endl;
        }
    }

    return 0;
}