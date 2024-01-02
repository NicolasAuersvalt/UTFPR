#include <stdio.h>
#include <stdlib.h>

typedef struct{
  float w; //largura
  float h; //altura
}Size;

typedef struct{
  float x; //coordenada x
  float y; //coordenada y
  Size size;
}Rect;

Size calcula(Rect*, int n);

/*====================================================================*/
//IRRELEVANTE
  /*int main()
{
    int n = 3;
    Rect r[n];
    r[0].x = -4;
    r[0].y = 1;
    r[0].size.w = 3;
    r[0].size.h = 2;
    r[1].x = -3;
    r[1].y = 0;
    r[1].size.w = 4;
    r[1].size.h = 2;
    r[2].x = 2;
    r[2].y = -3;
    r[2].size.w = 1;
    r[2].size.h = 4;
    Size oi = calcula(r, n);
    printf("largura %2f altura  %2f\n", oi.w, oi.h);
    return 0;
}*/
/*====================================================================*/

//IMPORTANTE
Size calcula(Rect* retangulos, int n)
{
    Size rect_final, rect_menor, rect_maior;

    for (int i = 0; i < n; i++)
    {
        //Encontra o x do canto superior direito do retângulo mais à direita
        if (retangulos[i].x + retangulos[i].size.w > rect_maior.w)
        {
            rect_maior.w = retangulos[i].x + retangulos[i].size.w;
            //printf("largura maior %2f \n", retangulo_maior.w);
        }
       //Encontra o y do canto inferior do retângulo mais abaixo
        if (retangulos[i].y + retangulos[i].size.h > rect_maior.h)
        {
            rect_maior.h = retangulos[i].y + retangulos[i].size.h;
            //printf("altura maior %2f \n", retangulo_maior.h);
        }
      //Encontra o x do canto inferior esquerdo do retângulo mais à esquerda
        if (retangulos[i].x < rect_menor.w)
        {
            rect_menor.w = retangulos[i].x;
            //printf("largura menor %2f \n", retangulo_menor.w);
        }
      //Encontra o y do canto superior do retângulo mais acima
        if (retangulos[i].y < rect_menor.h)
        {
            rect_menor.h = retangulos[i].y;
            //printf("altura menor %2f \n", retangulo_menor.h);
        }
    }
    //Calcula o tamanho do retângulo pontilhado (largura e altura)
    rect_final.w = rect_maior.w - rect_menor.w;
    rect_final.h = rect_maior.h - rect_menor.h;
  
    //Retorna o tamanho do retângulo pontilhado
    return rect_final;
}


//IMPORTANTE
Size calcula(Rect* retangulos, int n)
{
    Size rect_final, rect_menor, rect_maior;

    for (int i = 0; i < n; i++)
    {
        //Encontra o x do canto superior direito do retângulo mais à direita
        if (retangulos[i].x + retangulos[i].size.w > rect_maior.w)
            rect_maior.w = retangulos[i].x + retangulos[i].size.w;
      
       //Encontra o y do canto inferior do retângulo mais abaixo
        if (retangulos[i].y + retangulos[i].size.h > rect_maior.h)
            rect_maior.h = retangulos[i].y + retangulos[i].size.h;
      
      //Encontra o x do canto inferior esquerdo do retângulo mais à esquerda
        if (retangulos[i].x < rect_menor.w)
            rect_menor.w = retangulos[i].x;
      
      //Encontra o y do canto superior do retângulo mais acima
        if (retangulos[i].y < rect_menor.h)
            rect_menor.h = retangulos[i].y;
    }
    //Calcula o tamanho do retângulo pontilhado (largura e altura)
    rect_final.w = rect_maior.w - rect_menor.w;
    rect_final.h = rect_maior.h - rect_menor.h;

    //Retorna o tamanho do retângulo pontilhado
    return rect_final;
}
