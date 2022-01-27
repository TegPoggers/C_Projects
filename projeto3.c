//David Segalle: 2280507
//Viviane Ruotolo:2324822

#include "projeto3.h"

float calculaValorDevido (float peso, float custo_fixo, float preco_kg, float largura_faixa, float desconto_faixa, float desconto_max){

    float preco_desconto, preco_faixa, desconto;

    preco_desconto = 0;
    preco_faixa = 0;
    desconto = 1;//Desconto de 5% = multiplicar por 100-95 / 100

    while(peso > 0){
        //Se o peso for maior que a faixa ele nao pode ser usado no calculo, entao usa-se a faixa
        if(peso >= largura_faixa)
            preco_faixa = preco_kg * largura_faixa * desconto;
        else
            preco_faixa = preco_kg * peso * desconto;

        //Soma do desconto da faixa e ajuste de unidade
        preco_desconto += preco_faixa / 1000;

        if(desconto > 1 - desconto_max)
            desconto -= desconto_faixa;

        peso -= largura_faixa;
    }

    return custo_fixo + preco_desconto;
}




unsigned char calculaParidade (unsigned char b){

    int contador;

    contador = 0;
    while (b > 0){
        //Se o bit for 1 ele conta para a paridade
        if(b & 1){
            contador++;
        }
        b /= 2;
    }

    //Paridade dos bits setados (valor 1)
    if(contador & 1)
        return 1;

  return 0;

}




unsigned int fourcc (char c1, char c2, char c3, char c4){

    unsigned int valor1, valor2, valor3, valor4, valor;

    //Armazenando os valores decimais de cada char e realiza a operacao de mover os bits
    valor1 = (unsigned int) c1;
    valor2 = (unsigned int) c2 << 8;
    valor3 = (unsigned int) c3 << 16;
    valor4 = (unsigned int) c4 << 24;

    //Soma os bits
    valor = valor1 + valor2 + valor3 + valor4;

    return valor;

}
