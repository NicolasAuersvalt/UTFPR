#include<iostream>
#include"Pessoa.h"
using namespace std;



int main(){

	Universidade UTFPR;
	UTFPR.setNome("UTFPR");

	Pessoa Nicolas;
	Nicolas.setNome("Nicolas Auersvalt Marques");
	Nicolas.setIdade(20);
	Nicolas.setUniversidade(&UTFPR);

	cout << "Aluno: " << Nicolas.getNome() << " da " << Nicolas.getUniversidade();
	cout << " tem " << Nicolas.getIdade() << endl;
	


	return 0;
}
