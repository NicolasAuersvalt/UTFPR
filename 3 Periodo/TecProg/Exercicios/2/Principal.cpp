#include "Principal.h"

Principal::Principal(){

	Nicolas.Inicializa(23,11,2003, "Nícolas Auersvalt");
	Albert.Inicializa(14,3,1879, "Albert Einstein");
	Newton.Inicializa(4,1,1643, "Isaac Newton");

	int dia, mes, ano;
	cout << "Informe o dia/mes/ano atual: " << endl;
	cin >> dia >> mes >> ano;

	Uni.setNome("UTFPR");
	Nicolas.setUni(&Uni);

	Executar();
}


void Principal::Executar(){
	
	Nicolas.Calc_Idade(dia, mes, ano);
	Albert.Calc_Idade(dia, mes, ano);
	Newton.Calc_Idade(dia, mes, ano);

	Nicolas.getUni();
}
