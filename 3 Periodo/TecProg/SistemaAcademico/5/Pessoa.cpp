#include "stdafx.h"
#include "Pessoa.h"


Pessoa::Pessoa(int diaNa, int mesNa, int anoNa, char* nome)
{
  Inicializa(diaNa, mesNa, anoNa, nome);
}

Pessoa::Pessoa()
{
}

void Pessoa::Inicializa(int diaNa, int mesNa, int anoNa, char* nome)
{
   diaP = diaNa;
   mesP = mesNa;
   anoP = anoNa;
   strcpy(nomeP, nome);
   id = -1;
}

void Pessoa::Calc_Idade(int diaAT, int mesAT, int anoAT)
{
     idadeP = anoAT - anoP;
     if (mesP > mesAT)
     {
       idadeP = idadeP - 1;
     }
     else
     {
       if (mesP == mesAT)
       {
           if (diaP > diaAT)
           {
              idadeP = idadeP - 1;
           }
       }
     }
     //printf("\n A idade da Pessoa %s é %d \n", nomeP, idadeP);
	 cout << endl << " A idade da Pessoa " << nomeP << " é " << idadeP << "." << endl;
}

int Pessoa::informaIdade()
{
   return idadeP;
}



