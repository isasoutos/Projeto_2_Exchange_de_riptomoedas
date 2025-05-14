#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

void atualizar_cotacao_bit(cotacao *lista){
    int negativo = -5;
    int positivo = 5;

    int pos_neg = rand() %2;

    if (pos_neg == 0) {
        pos_neg = -1;
    } else {
        pos_neg = 1;
    }

    int atual_bit = (rand() % (positivo - negativo + 1)) + negativo;
    float percentual = atual_bit / 100.0; 
    printf("Valor do bitcoin: %.2f\n", lista->bitcoin);
    lista->bitcoin *= (1 + (percentual*pos_neg));

    printf("Novo valor do bitcoin: %.2f\n", lista->bitcoin);
    printf("Porcentagem aplicada: %.2f%%\n", percentual * 100);
    printf("\n");

}

void atualizar_cotacao_eth(cotacao *lista){
    int negativo = -5;
    int positivo = 5;

    int pos_neg = rand() %2;

    if (pos_neg == 0) {
        pos_neg = -1;
    } else {
        pos_neg = 1;
    }

    int atual_eth = (rand() % (positivo - negativo + 1)) + negativo;
    float percentual = atual_eth / 100.0; 
    printf("Valor do ethereum: %.2f\n", lista->ethereum);
    lista->ethereum *= (1 + (percentual*pos_neg));

    printf("Novo valor do ethereum: %.2f\n", lista->ethereum);
    printf("Porcentagem aplicada: %.2f%%\n", percentual * 100);
    printf("\n");
}

void atualizar_cotacao_rip(cotacao *lista){
    int negativo = -5;
    int positivo = 5;
    int pos_neg = rand() %2;

    if (pos_neg == 0) {
        pos_neg = -1;
    } else {
        pos_neg = 1;
    }

    int atual_rip = (rand() % (positivo - negativo + 1)) + negativo;
    float percentual = atual_rip / 100.0; 
    printf("Valor do ripple: %.2f\n", lista->ripple);
    lista->ripple *= (1 + (percentual*pos_neg));

    printf("Novo valor do ripple: %.2f\n", lista->ripple);
    printf("Porcentagem aplicada: %.2f%%\n", percentual * 100);
}