#include <math.h>
#include <stdio.h>

float area = 0, delta_x, xi, altura, erro_area = 1, precisao = 0.1,
      area_atual = 0, x_inicial = 0, x_final = 0;

int i, n_retangulos = 10000;

float somaRiemann(float x_inicial, float x_final, int n_retangulos);

float funcao(float x);

int main() {

  printf("Digite o limite inicial: \n");
  scanf("%f", &x_inicial);

  printf("\nDigite o limite final: \n");
  scanf("%f", &x_final);

  float area = somaRiemann(x_inicial, x_final, n_retangulos);

  printf("\nCom %d retangulos\n", n_retangulos);
  printf("\nE precisao de: %f\n", precisao);
  printf("\nA area sob a curva eh: %f\n", area);

  return 0;
}

float somaRiemann(float x_inicial, float x_final, int n_retangulos) {

  // Percorre todos os retângulos
  while (erro_area > precisao) {
    area_atual = 0;

    // Calcula o delta x
    delta_x = (x_final - x_inicial) / n_retangulos;

    for (i = 0; i < n_retangulos; i++) {

      // Calcula x estrela
      xi = x_inicial + delta_x * i; // Inicial i=0 => xi = x_inicial

      // Determina a altura no ponto xi
      altura = funcao(xi);

      // Atualiza o valor comparativo para o erro da área
      area = area_atual;

      area_atual += altura * delta_x;

      // Determina o erro entre a area anterior e posterior
      erro_area = area - area_atual;

      // Se esse erro for < 0, torna-o positivo
      if (erro_area < 0)
        erro_area *= -1;
    }
  }

  return area_atual;
}

float funcao(float x) {
  // Determina o valor da altura

  float y;

  // Y = X²
  y = pow(x, 2);

  return y;
}
