/*============================================================================*/
/* GERADOR DE CASOS DE TESTE PARA O PROBLEMA DO WII SENSOR BAR                */
/*----------------------------------------------------------------------------*/
/* Autor: Bogdan T. Nassu                                                     */
/*============================================================================*/
/** Um gerador de casos de teste para o problema do Wii Sensor Bar. Geramos uma
 * imagem preta com dois círculos brancos, adicionamos ruído binário, aplicamos
 * uma suavização Gaussiana, e adicionamos ruído Gaussiano. */
/*============================================================================*/

#ifndef __GERADOR_DE_TESTES_H
#define __GERADOR_DE_TESTES_H

/*============================================================================*/

#include "imagem.h"
#include "trabalho3.h"

/*============================================================================*/

Imagem1C* geraCasoDeTeste (int seed, Coordenada* l, Coordenada* r, double* angulo);

/*============================================================================*/
#endif /* __GERADOR_DE_TESTES_H */
