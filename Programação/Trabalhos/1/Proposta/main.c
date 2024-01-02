/*============================================================================*/
/* ICSF13 - 2023-2 - TRABALHO 1                                               */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu                                                            */
/* Leyza E. B. Dorini                                                         */
/* Daniel F. Pigatto                                                          */
/*============================================================================*/

#include <stdio.h>
#include <stdlib.h>

#include "trabalho1.h"

/*============================================================================*/
/* Selecione aqui quais funções devem ser testadas. */

#define TESTA_INTERSECCAO 1
#define TESTA_PAR_MAIS_PROXIMO 1

/*----------------------------------------------------------------------------*/
/* Configuração dos testes. Coloque o nome de um dos arquivos txt. */

#define ARQUIVO_RETANGULOS "teste_retangulos1.txt" /* Arquivo contendo dados para teste. */

/*============================================================================*/

void testaRetangulos ()
{
    int n_testes, n_retangulos;
    int i_teste, i_retangulo;
    int interseccao, interseccao_esperada;
    unsigned int par_mais_proximo, par_mais_proximo_esperado;
    FILE* in_file;

    /* Abre o arquivo contendo os dados. */
    in_file = fopen (ARQUIVO_RETANGULOS, "r");
    if (!in_file)
    {
        printf ("Nao foi possivel abrir o arquivo %s!\n", ARQUIVO_RETANGULOS);
        return;
    }

    /* Para cada teste... */
    fscanf (in_file, "%d\n", &n_testes);
    for (i_teste = 0; i_teste < n_testes; i_teste++)
    {
        /* Para cada retangulo... */
        fscanf (in_file, "%d\n", &n_retangulos);
        criaVetorRetangulos (n_retangulos);
        for (i_retangulo = 0; i_retangulo < n_retangulos; i_retangulo++)
        {
            /* Lê e adiciona. */
            int tlx, tly, brx, bry;
            fscanf (in_file, "%d %d %d %d\n", &tlx, &tly, &brx, &bry);
            adicionaRetangulo (i_retangulo, tlx, tly, brx, bry);
        }

        /* Pronto, agora podemos testar. */
        fscanf (in_file, "%d", &interseccao_esperada);
        fscanf (in_file, "%d", &par_mais_proximo_esperado);

        if (TESTA_INTERSECCAO)
        {
            interseccao = calculaInterseccao (n_retangulos);

            if (interseccao != interseccao_esperada)
            {
                printf ("Interseccao: Erro no teste %d.\nEsperava %d, calculou %d.\n", i_teste, interseccao_esperada, interseccao);
                //mostraRetangulos (n_retangulos);
            }
        }

        if (TESTA_PAR_MAIS_PROXIMO)
        {
            par_mais_proximo = encontraParMaisProximo (n_retangulos);

            if (par_mais_proximo != par_mais_proximo_esperado)
            {
                printf ("Par mais proximo: Erro no teste %d.\nEsperava 0x%X, calculou 0x%X.\n", i_teste, par_mais_proximo_esperado, par_mais_proximo);
                //mostraRetangulos (n_retangulos);
            }
        }

        destroiVetorRetangulos ();
    }

    printf ("%d testes executados.\n", n_testes);
    fclose (in_file);
}

/*----------------------------------------------------------------------------*/

int main()
{
    if (TESTA_INTERSECCAO || TESTA_PAR_MAIS_PROXIMO)
        testaRetangulos ();

    return 0;
}

/*============================================================================*/
