// Função 5

void geraOndaQuadrada(double *dados, int n_amostras, int taxa, double freq)
{
    double ciclo, meio_periodo;
    int valores, valor_atual = 1, contador = 0;

    ciclo = taxa / freq;
    meio_periodo = ciclo / 2;

    // Loop para gerar a onda quadrada
    for (valores = 0; valores < n_amostras; valores++)
    {
        dados[valores] = valor_atual;

        // Verifica se chegamos ao final de um ciclo
        if (valores <= (contador + 1) * ciclo + meio_periodo)
        {
            // Volta ao valor maximo
            valor_atual = 1;
            contador++;
        }

        // Verifica se chegamos à metade de um ciclo para inverter o valor
        else if (valores >= (contador * ciclo + meio_periodo))
        {
            // Muda para o valor minimo
            valor_atual = -1;
        }
    }
}