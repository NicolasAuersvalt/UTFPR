#include<stdio.h>

const int ano = 2024, dia = 1, mes = 10;


typedef struct{

	int dia, mes, ano, idade;

} Pessoa;

int idade(Pessoa pes, int anoAtual, int diaAtual, int mesAtual){

	int idd = anoAtual - pes.ano;
	if (pes.mes > mesAtual){
		idd--;	
	}

	else{
		if(pes.mes == mesAtual){
			if(pes.dia > diaAtual){
				idd--;
			}

		}
		
	}
		
	return idd;
}

int main(){

	Pessoa Einstein, Newton;

	Einstein.dia = 14;
	Einstein.mes = 03;
	Einstein.ano = 1879;
	Einstein.idade = idade(Einstein, ano, dia, mes);

	Newton.dia = 1;
	Newton.mes = 1;
	Newton.ano = 1643;

	Newton.idade = idade(Newton, ano, dia, mes);

	printf("%d", Einstein.idade);

	return 0;
}
