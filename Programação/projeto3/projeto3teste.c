/*
    remover static, e salvador de imagem.
*/

#include "trabalho3.h"
#include <math.h> // Por causa de sqrt () e acos ()
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x_inicial;
  int y_inicial;
  int x_final;
  int y_final;
  double centro_x;
  double centro_y;
} Coordenada_bola;

void ha_brancos(int rotulo, int branco, Imagem1C *img);
void maioresRotulos(Imagem1C *img, int rotulo, int *rotulo_maior1,
                    int *rotulo_maior2);
void encontraCentros(Imagem1C *img, int *rotulo_maior, Coordenada_bola *bola);
double calculaAngulo(Coordenada_bola *bola1, Coordenada_bola *bola2);

/*============================================================================*/
double detectaSensorBar(Imagem1C *img, Coordenada *l, Coordenada *r) {

  Coordenada_bola bola1;
  Coordenada_bola bola2;

  static int aux = 0; // !!! REMOVER APÓS TESTES !!!

  double angulo;

  // Intervalo de mudança de tonalidade
  int tonalidade = 120, branco = 255, preto = 0;

  int i, j;

  // Variável para rotular cada reunião de brancos
  int rotulo = 0;

  // Identificador dos rotulos maiores
  int rotulo_maior1 = 1, rotulo_maior2 = 1;

  // Torna a imagem Preto (0) e Branco (255)
  for (i = 0; i < img->altura; i++) {

    for (j = 0; j < img->largura; j++) {

      if (img->dados[i][j] > tonalidade) {

        // Preenche com Brancos
        img->dados[i][j] = branco;

      } else

        // Preenche com Pretos
        img->dados[i][j] = preto;
    }
  }

  // Preenche com Rótulo
  for (i = 0; i < img->altura; i++) {

    for (j = 0; j < img->largura; j++) {

      // Encontrou Branco
      if (img->dados[i][j] == branco) {

        // Atualiza o valor do rótulo
        rotulo++;

        // Rotula a posição do primeiro branco encontrado
        img->dados[i][j] = rotulo;

        // Pinta os laterais
        ha_brancos(rotulo, branco, img);
      }
    }
  }

  // Chamada da função para encontrar os maiores rotulos

  maioresRotulos(img, rotulo, &rotulo_maior1, &rotulo_maior2);

  printf("\nBola 1\n");
  // Encontra o centro 1
  encontraCentros(img, &rotulo_maior1, &bola1);

  printf("\nBola 2\n");
  // Encontra o centro 2
  encontraCentros(img, &rotulo_maior2, &bola2);

  return calculaAngulo(&bola1, &bola2);

  // !!! LEMBRAR DE REMOVER !!!
  char foostring[64];
  sprintf(foostring, "binaria%d.bmp", aux);
  salvaImagem1C(img, foostring);
  aux++;
}

/*============================================================================*/
/** Objetivo da funcao eh rotular os agrupamentos brancos**/
void ha_brancos(int rotulo, int branco, Imagem1C *img) {

  int i, j, lateral = 1, ha_branco = 1;

  while (ha_branco) {

    ha_branco = 0;

    // Percorre a Matriz tentando encontrar o rotulo
    for (i = 0; i < img->altura; i++) {

      for (j = 0; j < img->largura; j++) {

        // PROCURA OS ROTULOS

        // Se achar rotulo E tiver vizinho branco
        if (img->dados[i][j] == rotulo) {

          // Linha + - altura estiver dentro da imagem
          if (((i + lateral) < img->altura) && ((i - lateral) >= 0)) {

            // Coluna + - largura estiver dentro da imagem
            if (((j + lateral) < img->largura) && ((j - lateral) >= 0)) {

              // Baixo
              if (img->dados[i + lateral][j] == branco) {
                img->dados[i + lateral][j] = rotulo;
                ha_branco = 1;
              }

              // Direita
              if (img->dados[i][j + lateral] == branco) {
                img->dados[i][j + lateral] = rotulo;
                ha_branco = 1;
              }

              // Cima
              if (img->dados[i - lateral][j] == branco) {
                img->dados[i - lateral][j] = rotulo;
                ha_branco = 1;
              }

              // Esquerda
              if (img->dados[i][j - lateral] == branco) {
                img->dados[i][j - lateral] = rotulo;
                ha_branco = 1;
              }

              // Pega os vizinhos nas diagonais

              // Diagonal direita inferior
              if (img->dados[i + lateral][j + lateral] == branco) {
                img->dados[i + lateral][j + lateral] = rotulo;
                ha_branco = 1;
              }

              // Diagonal esquerda Inferior
              if (img->dados[i + lateral][j - lateral] == branco) {
                img->dados[i + lateral][j - lateral] = rotulo;
                ha_branco = 1;
              }

              // Diagonal Direita Superior
              if (img->dados[i - lateral][j + lateral] == branco) {
                img->dados[i - lateral][j + lateral] = rotulo;
                ha_branco = 1;
              }

              // Diagonal Esquerda Superior
              if (img->dados[i - lateral][j - lateral] == branco) {
                img->dados[i - lateral][j - lateral] = rotulo;
                ha_branco = 1;
              }
            }
          }
        }
      }
    }
  }
}

/*============================================================================*/
/** Objetivo da funcao eh identificar quais serao os dois maiores
agrupamentos com o mesmo rotulo **/

void maioresRotulos(Imagem1C *img, int rotulo, int *rotulo_maior1,
                    int *rotulo_maior2) {

  int i, j, cont;

  // Declara vetor inteiro aux
  int *aux;

  // Aloca memoria dinamicamente com tamanho igual ao numero de rotulos
  aux = (int *)malloc(rotulo * sizeof(int));

  // Inicializa o vetor auxiliar com zeros
  for (i = 0; i < rotulo; i++) {
    aux[i] = 0;
  }

  // Percorre a imagem e conta a ocorrencia de cada rotulo
  for (i = 0; i < img->altura; i++) {
    for (j = 0; j < img->largura; j++) {
      if (img->dados[i][j] < rotulo)
        aux[img->dados[i][j]]++;
    }
  }
  // Encontra os dois maiores rotulos
  for (cont = 1; cont < rotulo; cont++) {

    // Identifica o maior rotulo baseado na posicao
    if (aux[cont] > aux[*rotulo_maior1]) {

      // Atualiza o 2nd maior rotulo
      *rotulo_maior2 = *rotulo_maior1;

      // Atualiza o 1st maior rotulo
      *rotulo_maior1 = cont;
    }

    // Identifica o segundo maior rotulo
    else if (aux[cont] > aux[*rotulo_maior2] &&
             aux[cont] != aux[*rotulo_maior1])
      *rotulo_maior2 = cont;
  }
  // Libera a memoria alocada dinamicamente
  free(aux);
}

/*============================================================================*/
/** Objetivo da funcao eh identificar quais sáo os centros dos dois maiores
agrupamentos de LEDs **/
void encontraCentros(Imagem1C *img, int *rotulo_maior, Coordenada_bola *bola) {

  // Percorre toda a matriz
  // coordenada[x_inicial, x_final, y_inicial, y_final]

  int i, j;

  int achou = 1;

  // Esquerda
  printf("Esquerda: \n");

  for (j = 1; j < img->largura - 1; j++) {
    for (i = 1; i < img->altura - 1; i++) {
      if ((img->dados[i][j] == *rotulo_maior) && (achou == 1)) {
        bola->x_inicial = j + 1;
        printf("x inicial:%d\n", bola->x_inicial);
        achou = 0;
      }
    }
  }

  achou = 1;

  // Direita
  printf("Direita: \n");
  for (j = img->largura - 1; j > 1; j--) {
    for (i = 1; i < img->altura - 1; i++) {
      if ((img->dados[i][j] == *rotulo_maior) && (achou)) {
        bola->x_final = j + 1;
        printf("x final:%d\n", bola->x_final);
        achou = 0;
      }
    }
  }

  achou = 1;

  // Cima
  printf("Cima: \n");

  for (i = 1; i < img->altura - 1; i++) {
    for (j = 1; j < img->largura - 1; j++) {
      if ((img->dados[i][j] == *rotulo_maior) && (achou)) {
        bola->y_inicial = i + 1;
        printf("y inicial:%d\n", bola->y_inicial);
        achou = 0;
      }
    }
  }

  achou = 1;

  // Baixo
  printf("Baixo: \n");

  for (i = img->altura - 1; i > 1; i--) { //*** E O MENOS 1****
    for (j = 1; j < img->largura - 1; j++) {
      if ((img->dados[i][j] == *rotulo_maior) && (achou)) {
        bola->y_final = i + 1;
        printf("y final:%d\n", bola->y_final);
        achou = 0;
      }
    }
  }
  achou = 0;

  // Calcula o centro

  bola->centro_x = bola->x_inicial + ((bola->x_final - bola->x_inicial) / 2.0);
  bola->centro_y = bola->y_inicial + ((bola->y_final - bola->y_inicial) / 2.0);

  printf("x Coordenada: %.2f\n", bola->centro_x);
  printf("y Coordenada: %.2f\n", bola->centro_y);
}

/*============================================================================*/
/** Objetivo da funcao eh retornar o angulo entre os leds atraves
de um cosseno obtido de uma operacao com produto escalar
e modulos de vetores. **/
/// Aqui considera-se vetores raio-posição de cada led
/// com origem na posição img[0][0].
double calculaAngulo(Coordenada_bola *bola1, Coordenada_bola *bola2) {

  double cosseno;

  // Para os módulos dos vetores posiçao dos leds
  double modulo_um, modulo_dois;

  // Bola 1
  modulo_um = sqrt((double)(bola1->centro_x * bola1->centro_x +
                            bola1->centro_y * bola1->centro_y));

  // Bola 2
  modulo_dois = sqrt((double)(bola2->centro_x * bola2->centro_x +
                              bola2->centro_y * bola2->centro_y));

  /*Cálculo do cosseno entre os vetores igual ao feito em G.A (produto
  escalar/ produto dos módulos)*/
  cosseno = (double)(bola1->centro_x * bola2->centro_x +
                     bola1->centro_y * bola2->centro_y) /
            (modulo_um * modulo_dois);

  double angulo = acos(cosseno);

  printf("\n Nosso Angulo calculado de %f \n", angulo);

  // Angulo calculado já em radianos
  return acos(cosseno);
}
