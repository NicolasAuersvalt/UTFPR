// Função 5

void geraOndaQuadrada(double *dados, int n_amostras, int taxa, double freq)
{
    double ciclo, meio_periodo;
    int valores, valor_atual = 1, ciclo_atual = 0;

    ciclo = (taxa / freq);
    meio_periodo = ciclo / 2;

    // Loop para gerar a onda quadrada
    for (valores = 0; valores < n_amostras; valores++)
    {
        dados[valores] = valor_atual;

        // Verifica se chegamos ao final de um ciclo
        if (valores >= (ciclo_atual + 1) * ciclo)
        {
            // Volta ao valor maximo
            valor_atual = 1;
            ciclo_atual++;
        }

        // Verifica se chegamos à metade de um ciclo para inverter o valor
        else if (valores >= (ciclo_atual * ciclo + meio_periodo))
        {
            // Muda para o valor minimo
            valor_atual = -1;
        }
    }
}
