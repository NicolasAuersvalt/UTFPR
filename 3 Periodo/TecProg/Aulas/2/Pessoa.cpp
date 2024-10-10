#include"Pessoa.h"
#include<string.h>
using namespace std;

Principal::Principal()
{
	// Passo para o Construtor
	Nicolas.Inicializa(1, 2, 3, "Nicolas Auersvalt");
	Albert.Inicializa(1, 2, 3, "Nicolas Auersvalt");
	Newton.Inicializa(1, 2, 3, "Nicolas Auersvalt");

	// Executa operações desejadas
	Executar();

}
void Principal::Executar()
{
	Nicolas.Calc_Idade(2,4,2009);
	Albert.Calc_Idade(2,14,2001);
	Newton.Calc_Idade(3,5,2002);

}
