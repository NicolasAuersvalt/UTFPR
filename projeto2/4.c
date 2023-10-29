// Função 4

void limitaSinal(double *dados, int n_amostras, int n_passos)
{
    int posicoes, laterais;
    double coeficiente = 0.0, apoio = 0.0;

    for (posicoes = 0; posicoes < n_amostras; posicoes++)
    { // Percorre todas as posições

        if ((dados[posicoes] < -1.0) || (dados[posicoes] > 1.0))
        { // Encontrou Saturação

            // Fórmula para determinar o coeficiente que 
            // reduz a 1 ou -1 a saturação
            coeficiente = 1.0 / dados[posicoes];

            // Se coeficiente for negativo, torna-o positivo

            if (coeficiente < 0)
                coeficiente = -coeficiente;

            // Atualiza a posição

            dados[posicoes] *= coeficiente;

          // Atualiza o apoio que será usado para cada lateral
          // em função de sua magnitude
           apoio = (1 - coeficiente) / (n_passos + 1);

            // Percorre n_passos laterais, alterando cada
            for (laterais = 1; laterais <= n_passos; laterais++)
            {

               coeficiente += apoio;
              
                // À esquerda
                dados[(posicoes - laterais)] *= coeficiente;

                // À direita
                dados[(posicoes + laterais)] *= coeficiente;

            }
        }
    }
}
