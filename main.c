#include <stdio.h>
#include "projeto3.h"

int main(void)
{
    float valor_devido;
    unsigned char b;

    float peso[14] = {80, 100, 200, 300, 400, 500, 1000, 80, 100, 200, 300, 400, 500, 1000};
    float custo_fixo[14] = {6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7};
    float preco_kg[14] = {18, 18, 18, 18, 18, 18, 18, 16, 16, 16, 16, 16, 16, 16};
    float largura_faixa[14] = {100, 100, 100, 100, 100, 100, 100, 80, 80, 80, 80, 80, 80, 80};
    float desconto_faixa[14] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05};
    float desconto_max[14] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6};
    float resultados_previstos[14] = {7.44, 7.80, 9.42, 10.86, 12.12, 13.20, 17.70, 8.28, 8.58, 10.07, 11.46, 12.76, 13.94, 18.39};

    float resultado;
    int i, j;

    printf("Calcula valor devido:\n");
    printf("Computado|Esperado\n\n");

    for (i = 0; i < 14; i++)
    {
        resultado = calculaValorDevido(peso[i], custo_fixo[i], preco_kg[i], largura_faixa[i], desconto_faixa[i], desconto_max[i]);

        printf("%.2f\t%.2f\n", resultado, resultados_previstos[i]);
    }

    printf("\n\nCalcula Paridade:\n");
    for (i = 0; i < 256; i++)
    {
        b = i;
        for (j = 0; j < 8; j++)
            printf("%d", (b >> (7 - j)) % 2);
        printf(": %u\n", calculaParidade(i));
    }

    printf("\n\nFourcc: \n");
    printf("%d", fourcc('D', 'I', 'V', 'X'));
    return 0;
}
