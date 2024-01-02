#include <math.h>
#include <float.h>

// Função 1

int calculaInterseccao(int n_retangulos)
{

    int x3_se = 0, y3_se = 0, x3_id = 0, y3_id = 0,
        x4_se = 0, y4_se = 0, x4_id = 0, y4_id = 0,
        inter_xi, inter_xf, inter_yi, inter_yf,
        ha_intersecao = 1, x_max, y_max, intervx = 0, intervy = 0, inter_minx = 0, inter_maxx = 0,
        inter_miny = 0, inter_maxy = 0, ret_referencia = 0, ret,
        ha_intery = 1, ha_interx = 1;

    unsigned int area = 0;

    // Seleciono um retângulo referencia para a comparação
    for (ret_referencia; ret_referencia < n_retangulos; ret_referencia++)
    {

        x3_se = pegaXSE(ret_referencia);
        y3_se = pegaYSE(ret_referencia);
        x3_id = pegaXID(ret_referencia);
        y3_id = pegaYID(ret_referencia);

        // Seleciono um retângulo a ser comparado
        for (ret = (ret_referencia + 1); ret < n_retangulos; ret++)
        {
            // Flags de interseção (reinicializadas a cada retângulo comparado)
            ha_intery = 1, ha_interx = 1;

            x4_se = pegaXSE(ret);
            y4_se = pegaYSE(ret);
            x4_id = pegaXID(ret);
            y4_id = pegaYID(ret);

            // Determinação dos valores mínimos e máximos
            // Servirão como parâmetros limites ao percorrer seus intervalos
            if (x4_id > x3_id)
            {
                x_max = x3_id;
            }
            else if (x3_id > x4_id)
            {
                x_max = x4_id;
            }
            if (y4_se > y3_se)
            {
                y_max = y3_se;
            }
            else if (y3_se > y4_se)
            {
                y_max = y4_se;
            }

            // Para cada valor nesse intervalo de Y
            for (intervx = 0; intervx <= x_max; intervx++)
            {
                // Se o intervalo de x estiver na interseção
                if (((intervx >= x3_se) && (intervx <= x3_id)) && ((intervx >= x4_se) && (intervx <= x4_id)))
                {

                    // Determina a interseção inicial e define o limite final a ser somado.
                    if (ha_interx == 1)
                    {
                        // Define o primeiro valor referência da interseção (X)
                        if (inter_maxx < inter_xi)
                        {
                            inter_maxx = inter_xi;
                        }
                        // Atualiza os valores da interseção
                        inter_xi = intervx;
                        inter_xf = intervx;

                        // Soma a quantidade de interseções que houveram
                        ha_interx++;
                    }

                    // Já encontrou interseção
                    else if (ha_interx > 1)
                    {
                        // Interseção final começa a ser determinada através
                        // de um somatório
                        inter_xf += 1;
                        ha_interx++;
                    }
                }
            }
            if (ha_interx == 1)
            {
                // Caso não houver interseção, já será retornado 0
                // Isso evita procedimentos desnecessários
                return 0;
            }

            // Para cada valor nesse intervalo de Y
            for (intervy = 0; intervy <= y_max; intervy++)
            {
                // Se o intervalo de y estiver na interseção
                if (((intervy >= y3_id) && (intervy <= y3_se)) && ((intervy >= y4_id) && (intervy <= y4_se)))
                {
                    // Determina a interseção inicial e define a final para ser somado.
                    if (ha_intery == 1)
                    {
                        // Define o primeiro valor referência da interseção (Y)
                        if (inter_maxy < inter_yi)
                        {
                            inter_maxy = inter_yi;
                        }
                        // Atualiza os valores da interseção
                        inter_yi = intervy;
                        inter_yf = intervy;

                        // Soma a quantidade de interseções que houveram
                        ha_intery++;
                    }
                    // Já encontrou interseção
                    else if (ha_intery > 1)
                    {
                        // Interseção final começa a ser determinada através
                        // de um somatório
                        inter_yf += 1;
                        ha_intery++;
                    }
                }
            }
            if (ha_intery == 1)
            {
                // Caso não houver interseção, já será retornado 0
                return 0;
            }

            // Armazena as interseções
            if (inter_xf < inter_maxx)
            { // Limita ainda mais o x máximo
                inter_maxx = inter_xf;
            }
            if (inter_xi > inter_minx)
            { // Limita ainda mais o x mínimo
                inter_minx = inter_xi;
            }
            if (inter_yf < inter_maxy)
            { // Limita ainda mais o y máximo
                inter_maxy = inter_yf;
            }
            if (inter_yi > inter_miny)
            { // Limita ainda mais o y mínimo
                inter_miny = inter_yi;
            }
        }
    }

    // Cálculo da área da interseção ((PMx2-PMx1) * (PMy2-PMy1))
    area = ((inter_maxx - inter_minx) * (inter_maxy - inter_miny));
    return area;
}

// Função 2

// Função auxiliar para o cálculo da distância
float dist(x1_se, y1_se, x1_id,
           y1_id, x2_se, y2_se,
           x2_id, y2_id)
{
    // Calcula os pontos médios
    float px1_medio = (x1_se + x1_id) / 2.0;
    float py1_medio = (y1_se + y1_id) / 2.0;
    float px2_medio = (x2_se + x2_id) / 2.0;
    float py2_medio = (y2_se + y2_id) / 2.0;

    // Calcula a distância entre as componentes dos pontos médios
    float delta_x = (px1_medio - px2_medio);
    float delta_y = (py1_medio - py2_medio);

    // Calcula a distância (hipotenusa) entre dois pontos (pontos médios)
    // através da fórmula de distância entre dois pontos
    float distancia_pontos = sqrt((delta_x * delta_x) + (delta_y * delta_y)); // Testar dps

    return distancia_pontos;
}

unsigned int encontraParMaisProximo(int n_retangulos)
{
    int ret1_min = 0, ret2_min = 0,
        x1_se = 0, y1_se = 0, x1_id = 0, y1_id = 0,
        x2_se = 0, y2_se = 0, x2_id = 0, y2_id = 0,
        ret_comp = 0;

    float distancia = 0.0, dist_min = FLT_MAX;

    // Seleciona um retângulo de referencia para a comparação
    for (int ret_ref = 0; ret_ref < n_retangulos; ret_ref++)
    {
        x1_se = pegaXSE(ret_ref);
        y1_se = pegaYSE(ret_ref);
        x1_id = pegaXID(ret_ref);
        y1_id = pegaYID(ret_ref);

        // Seleciona um retângulo a se comparado logo após o de referência
        for (ret_comp = ret_ref + 1; ret_comp < n_retangulos; ret_comp++)
        {

            x2_se = pegaXSE(ret_comp);
            y2_se = pegaYSE(ret_comp);
            x2_id = pegaXID(ret_comp);
            y2_id = pegaYID(ret_comp);

            // Chamada da função que calculará a distância
            distancia = dist(x1_se, y1_se, x1_id,
                             y1_id, x2_se, y2_se,
                             x2_id, y2_id);

            // A distância comparada for mínima
            if (distancia < dist_min)
            {
                // Atualiza o valor da distância mínima pelo da comparada
                dist_min = distancia;

                // Armazena as posições dos retângulos cuja distância foi mínima
                ret1_min = ret_ref;
                ret2_min = ret_comp;
            }
        }
    }

    return (ret1_min << 16) | ret2_min;
}
