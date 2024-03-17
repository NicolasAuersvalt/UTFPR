/*============================================================================*/
/* GERADOR DE CASOS DE TESTE PARA O PROBLEMA DO WII SENSOR BAR                */
/*----------------------------------------------------------------------------*/
/* Autor: Bogdan T. Nassu                                                     */
/*============================================================================*/
/** Um gerador de casos de teste para o problema do Wii Sensor Bar. Geramos uma
 * imagem preta com dois círculos brancos, adicionamos ruído binário, aplicamos
 * uma suavização, e adicionamos ruído Gaussiano. */
/*============================================================================*/

#include <stdlib.h>
#include <math.h>

#include "gerador_de_testes.h"

/*============================================================================*/

#define PI 3.1415926535897932384626433832795

#define N_TAMANHOS 6
int LARGURAS [] = {128,320,640,800,1024,1280};
int ALTURAS [] = {96,240,480,600,768,1024};

/* Tamanho min/max para os círculos. */
#define MIN(a,b) ((a<b)? a : b)
#define MAX(a,b) ((a>b)? a : b)
#define RAIO_MIN 3
#define RAIO_MAX(img) (MIN(img->altura,img->largura)/20)

/* Ruído e suavização. */
#define MAX_PROB_RUIDO_BINARIO 1000 /* Probabilidade máxima de ruído binário, multiplicada por 100 (i.e. 100 = 1%) */
#define PARAMETRO_SUAVIZACAO 4 /* Quanto menor, mais borradas as imagens tendem a ficar. */
#define SIGMA_RUIDO 25 /* Quanto maior, mais ruído. */

/*============================================================================*/
/* Funções internas do módulo. */

void copiaImagem1C (Imagem1C* img, Imagem1C* copia);
int desenhaLuzes (Imagem1C* img, Coordenada* l, Coordenada* r);
void desenhaCirculo (Imagem1C* img, Coordenada centro, int raio);
void ruidoBinario (Imagem1C* img);
void suavizaImagem (Imagem1C* img);
void adicionaRuido (Imagem1C* img);
double rand_normal (double mean, double stddev);
double anguloEntrePontos (Coordenada pt1, Coordenada pt2);

/*============================================================================*/
/** Função central do gerador, cria um caso de testes.
 *
 * Parâmetros: int seed: a semente para o gerador de números aleatórios.
 *             Coordenada* l: centro do círculo esquerdo.
 *             Coordenada* r: centro do círculo direito.
 *             double* angulo: angulo entre os dois centros, em radianos no
 *               intervalo (-PI/2, +PI/2).
 *
 * Valor de retorno: uma imagem contendo o caso de teste. Lembre-se de destruí-la! */

Imagem1C* geraCasoDeTeste (int seed, Coordenada* l, Coordenada* r, double* angulo)
{
    Imagem1C* img;
    int i, j, tam;

    /* Escolhe um tamanho e cria a imagem. */
    srand (seed);
    tam = rand () % N_TAMANHOS;
    img = criaImagem1C (LARGURAS [tam], ALTURAS [tam]);

    /* Pinta a imagem de preto. */
    for (i = 0; i < img->altura; i++)
        for (j = 0; j < img->largura; j++)
            img->dados [i][j] = 0;

    /* Agora vai... */
    int ciclos_blur = desenhaLuzes (img, l, r);
    ciclos_blur = MAX (1, ciclos_blur); /* Borra mais quando tem círculos maiores. */
    ruidoBinario (img);
    for (i = 0; i < ciclos_blur; i++)
        suavizaImagem (img);
    adicionaRuido (img);
    for (i = 0; i < ciclos_blur/2; i++)
        suavizaImagem (img);
    adicionaRuido (img);

    *angulo = anguloEntrePontos (*l, *r);

    return (img);
}

/*----------------------------------------------------------------------------*/
/** Copia o conteúdo de uma imagem para outra.
 *
 * Parâmetros: Imagem1C* img: imagem a copiar.
 *             Imagem1C* copia: imagem de destino. Pressupomos que tem o mesmo
 *               tamanho da imagem de entrada.
 *
 * Valor de retorno: nenhum. */

void copiaImagem1C (Imagem1C* img, Imagem1C* copia)
{
    unsigned long i, j;

    for (i = 0; i < copia->altura; i++)
        for (j = 0; j < copia->largura; j++)
            copia->dados [i][j] = img->dados [i][j];
}

/*----------------------------------------------------------------------------*/
/** Desenha dois círculos brancos na imagem dada. Armazena as coordenadas dos
 * centros.
 *
 * Parâmetros: Imagem1C* img: desenha aqui.
 *             Coordenada* l: centro do círculo esquerdo (saída).
 *             Coordenada* r: centro do círculo direito (saída).
 *
 * Valor de retorno: O raio das luzes desenhadas, além dos 3 parâmetros de saída. */

int desenhaLuzes (Imagem1C* img, Coordenada* l, Coordenada* r)
{
    int raio, aux, foi = 0;

    while (!foi) /* Repete até conseguir algo que preste... */
    {
        /* Define o raio dos círculos. */
        raio = rand () % (RAIO_MAX(img)-RAIO_MIN+1) + RAIO_MIN;

        /* Define a posição dos círculos. */
        l->x = rand () % (img->largura-raio*2) + raio;
        l->y = rand () % (img->altura-raio*2) + raio;
        r->x = rand () % (img->largura-raio*2) + raio;
        r->y = rand () % (img->altura-raio*2) + raio;

        /* Troca l por r, se for preciso. */
        if (l->x > r->x)
        {
            aux = l->x;
            l->x = r->x;
            r->x = aux;
        }

        /* O espaço entre os círculos precisa ser de pelo menos raio pixels. Usamos 3*raio porque medimos a distância dos centros. */
        /* A distância horizontal entre os círculos também precisa ser razoável. Consideramos que RAIO_MIN*2 é uma boa medida para não dar confusão. */
        if (sqrt ((l->x-r->x)*(l->x-r->x) + (l->y-r->y)*(l->y-r->y)) > 3*raio && r->x - l->x > RAIO_MIN*2)
        {
            /* Desenha os círculos. */
            desenhaCirculo (img, *l, raio);
            desenhaCirculo (img, *r, raio);
            foi = 1;
        }
    }

    return (raio);
}

/*----------------------------------------------------------------------------*/
/** Desenha um círculo branco na imagem dada. O raio não inclui o pixel
 * central, então o círculo ocupará uma região que vai de (x-raio,y-raio) a
 * (x+raio,y+raio), inclusive.
 *
 * Parâmetros: Imagem1C* img: desenha aqui.
 *             Coordenada centro: centro do círculo.
 *             int raio: raio do círculo.
 *
 * Valor de retorno: NENHUM */

void desenhaCirculo (Imagem1C* img, Coordenada centro, int raio)
{
    int i, j, lim;

    for (i = -raio; i <= raio; i++)
    {
        lim = sqrt (raio*raio - i*i);

        for (j = -lim; j <= lim; j++)
            img->dados [centro.y + i][centro.x + j] = 255;
    }
}

/*----------------------------------------------------------------------------*/
/** Adiciona ruído binário a uma imagem. Inverte cada byte que for sorteado.
 *
 * Parâmetros: Imagem1C* img: imagem a alterar.
 *
 * Valor de retorno: NENHUM */

void ruidoBinario (Imagem1C* img)
{
    int i, j, prob;

    /* Define a probabilidade de ruído binário. */
    prob = rand () % (MAX_PROB_RUIDO_BINARIO+1);

    for (i = 0; i < img->altura; i++)
        for (j = 0; j < img->largura; j++)
            if (rand () % 10000 < prob)
                img->dados [i][j] = ~img->dados [i][j];
}

/*----------------------------------------------------------------------------*/
/** Suaviza a imagem com um filtro 3x3. O peso do pixel central é escolhido
 * aleatoriamente, ou seja, a imagem pode ficar mais ou menos borrada.
 *
 * Parâmetros: Imagem1C* img: imagem a suavizar.
 *
 * Valor de retorno: nenhum */

void suavizaImagem (Imagem1C* img)
{
    unsigned long row, col;
    int peso_centro;
    Imagem1C* copia; /* Precisamos guardar os dados originais. Seria bem mais eficiente guardar apenas uma janela, mas copiar tudo é bem mais simples... */
    copia = criaImagem1C (img->largura, img->altura);
    copiaImagem1C (img, copia);

    peso_centro = rand () % PARAMETRO_SUAVIZACAO + 4;
    for (row = 1; row < img->altura-1; row++)
        for (col = 1; col < img->largura-1; col++)
            img->dados [row][col] = (copia->dados [row-1][col-1] +
                                     copia->dados [row-1][col]*2 +
                                     copia->dados [row-1][col+1] +
                                     copia->dados [row][col-1]*2 +
                                     copia->dados [row][col]*peso_centro +
                                     copia->dados [row][col+1]*2 +
                                     copia->dados [row+1][col-1] +
                                     copia->dados [row+1][col]*2 +
                                     copia->dados [row+1][col+1])/(peso_centro + 12);
    destroiImagem1C (copia);
}

/*----------------------------------------------------------------------------*/
/** Adiciona ruído a uma imagem.
 *
 * Parâmetros: Imagem1C* img: imagem à qual adicionaremos ruído.
 *
 * Valor de retorno: nenhum. */

void adicionaRuido (Imagem1C* img)
{
    unsigned long row, col;

    for (row = 0; row < img->altura; row++)
        for (col = 0; col < img->largura; col++)
        {
            double ruido = rand_normal (0, SIGMA_RUIDO);
            img->dados [row][col] = (unsigned char) (MIN (255, MAX (0, img->dados [row][col] + ruido)));
        }
}

/*----------------------------------------------------------------------------*/
/** Código copiado de outro lugar para gerar números aleatórios seguindo uma
 * distribuição normal. Original em:
 * en.literateprograms.org/Box-Muller_transform_%28C%29#chunk%20use:complete%20Box-Muller%20function */

double rand_normal (double mean, double stddev)
{
    static double n2 = 0.0;
    static int n2_cached = 0;
    if (!n2_cached)
    {
        double x, y, r;
        do
        {
            x = 2.0*rand()/RAND_MAX - 1;
            y = 2.0*rand()/RAND_MAX - 1;
            r = x*x + y*y;
        }
        while (r == 0.0 || r > 1.0);
        {
            double result;
            double d = sqrt(-2.0*log(r)/r);
            double n1 = x*d;
            n2 = y*d;
            result = n1*stddev + mean;
            n2_cached = 1;
            return result;
        }
    }
    else
    {
        n2_cached = 0;
        return n2*stddev + mean;
    }
}

/*----------------------------------------------------------------------------*/
/** Calcula o ângulo da reta que passa entre dois pontos.
 *
 * Parâmetros: Coordenada pt1: um ponto.
 *             Coordenada pt2: outro ponto.
 *
 * Valor de retorno: o ângulo da reta que passa por pt1 e pt2. */

double anguloEntrePontos (Coordenada pt1, Coordenada pt2)
{
    return (0); // TODO: depois da entrega!
}

/*============================================================================*/
