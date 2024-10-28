#include "principal.h"
#include <iostream>
using namespace std;

Principal::Principal(){
	Nicolas.setNome("Nícolas");
	cout << Nicolas.getNome();
	Nicolas.setDataDeNascimento(23, 11, 2003);
	cout << Nicolas.getIdade();
}
Principal::~Principal(){
}

