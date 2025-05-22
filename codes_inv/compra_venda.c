#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

void comprar_criptomoedas(cotacao *lista, usuario *user){
    char senha_digitada[TAM_SENHA + 1];
    float compra_bit;
    float compra_eth;
    float compra_rip;

    char data_hora[30];
    atual_datahora(data_hora, sizeof(data_hora));

    printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
    printf("Valor do saldo do Bitcoin: R$ %.2f\n", lista->saldo_bit);
    printf("Valor do saldo do Ethereum: R$ %.2f\n", lista->saldo_eth);
    printf("Valor do saldo do Ripple: R$ %.2f\n", lista->saldo_rip);

    int escolher = menu_cripto();

    if (escolher == 1){
        printf("Valor do bitcoin: %.2f\n", lista->bitcoin);
        printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
        printf("Valor do saldo do Bitcoin: R$ %.4f\n", lista->saldo_bit);

        printf("Digite o valor que deseja comprar: ");
        scanf("%f", &compra_bit);

        if (lista->saldo_reais >= compra_bit){
            lista->saldo_bit = ((compra_bit / lista->bitcoin) - ((compra_bit/lista->bitcoin)*2/100)) + lista->saldo_bit;
            lista->saldo_reais = lista->saldo_reais - compra_bit;

            printf("Digite sua senha para confirmar sua compra: ");
            scanf(" %4s", senha_digitada);

            if (strcmp(user->senha, senha_digitada) != 0) {
                printf("Senha incorreta! Compra cancelado, tente novamente.\n");
                return;
            }

            printf("Saldo atual: %.2f as %s\n", lista->saldo_reais, data_hora);
            printf("Saldo bitcoin: %.4f as %s\n", lista->saldo_bit, data_hora);
            printf("Taxa de compra 2%%\n");
            sprintf(lista->historico[lista->total_operacao], "Saldo bitcoin de R$ %.5f\n", lista->saldo_bit);
            lista->total_operacao++;

        }else if(lista->saldo_reais < compra_bit){
            printf("Saldo insulficiente\n");
        }

    }else if(escolher == 2){
        printf("Valor do ethereum: %.2f\n", lista->ethereum);
        printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
        printf("Valor do saldo do Ethereum: R$ %.2f\n", lista->saldo_eth);

        printf("Digite o valor que deseja comprar: ");
        scanf("%f", &compra_eth);

        if (lista->saldo_reais >= compra_eth){
            lista->saldo_eth = ((compra_eth / lista->ethereum) - ((compra_eth/lista->ethereum)*1/100)) + lista->saldo_eth;
            lista->saldo_reais = lista->saldo_reais - compra_eth;

            printf("Digite sua senha para confirmar sua compra: ");
            scanf(" %4s", senha_digitada);

            if (strcmp(user->senha, senha_digitada) != 0) {
                printf("Senha incorreta! Compra cancelado, tente novamente.\n");
                return;
            }

            printf("Saldo atual: %.2f as %s\n", lista->saldo_reais, data_hora);
            printf("Saldo ethereum: %.2f as %s\n", lista->saldo_eth, data_hora);
            printf("Taxa de compra 1%%\n");
            sprintf(lista->historico[lista->total_operacao], "Saldo ethereum de R$ %.2f\n", lista->saldo_eth);
            lista->total_operacao++;

        }else if(lista->saldo_reais < compra_eth){
            printf("Saldo insulficiente\n");
        }

    }else if(escolher == 3){
        printf("Valor do ripple: %.2f\n", lista->ripple);
        printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
        printf("Valor do saldo do Ripple: R$ %.2f\n", lista->saldo_rip);

        printf("Digite o valor que deseja comprar: ");
        scanf("%f", &compra_rip);

        if (lista->saldo_reais >= compra_rip){
            lista->saldo_rip = ((compra_rip / lista->ripple) - ((compra_rip/lista->ripple)*1/100)) + lista->saldo_rip;
            lista->saldo_reais = lista->saldo_reais - compra_rip;

            printf("Digite sua senha para confirmar sua compra: ");
            scanf(" %4s", senha_digitada);

            if (strcmp(user->senha, senha_digitada) != 0) {
                printf("Senha incorreta! Compra cancelado, tente novamente.\n");
                return;
            }

            printf("Saldo atual: %.2f as %s\n", lista->saldo_reais, data_hora);
            printf("Saldo ripple: %.2f as %s\n", lista->saldo_rip, data_hora);
            printf("Taxa de compra 1%%\n");
            sprintf(lista->historico[lista->total_operacao], "Saldo Ripple de R$ %.2f\n", lista->saldo_rip);
            lista->total_operacao++;

        }else if(lista->saldo_reais < compra_rip){
            printf("Saldo insulficiente\n");
        }
    }else {
        printf("Criptomoeda não identificada!\n");
    }
}



void vender_criptomoedas (cotacao *lista) {
    // Taxas sugeridas na orientação: Bitcoin 3%, Ethereum 2%, Ripple 1%
    float valor_venda;
    int escolher = menu_cripto();
    char senha_digitada[TAM_SENHA + 1];

    char data_hora[30];
    atual_datahora(data_hora, sizeof(data_hora));

    if (escolher == 1) {
        printf("Valor do Bitcoin: %.2f\n", lista->bitcoin);
        printf("Saldo em Bitcoin: %.4f\n", lista->saldo_bit);

        printf("Digite quanto deseja vender: ");
        scanf("%f", &valor_venda);

        if (valor_venda <= 0 || valor_venda > lista->saldo_bit) {
            printf("Valor inválido ou saldo insuficiente.\n Tente novamente.\n");
            return;
        }

        float valor_em_reais = valor_venda * lista->bitcoin;
        float taxa = valor_em_reais * 0.03;
        float liquido = valor_em_reais - taxa;

        lista->saldo_bit -= valor_venda;
        lista->saldo_reais += liquido;

        printf("Digite sua senha para confirmar sua compra: ");
        scanf(" %4s", senha_digitada);

        printf("Venda realizada!\n");
        printf("Taxa de 3%%: R$ %.2f\n", taxa);
        printf("Recebido %s em reais: R$ %.2f\n",data_hora, liquido);
        sprintf(lista->historico[lista->total_operacao], "Saldo recebido R$ %.2f\n", liquido);
        lista->total_operacao++;
    }

    else if (escolher == 2) { // Ethereum
        printf("Valor do Ethereum: %.2f\n", lista->ethereum);
        printf("Saldo em Ethereum: %.2f\n", lista->saldo_eth);

        printf("Digite quanto de Ethereum deseja vender: ");
        scanf("%f", &valor_venda);

        if (valor_venda <= 0 || valor_venda > lista->saldo_eth) {
            printf("Valor inválido ou saldo insuficiente.\nTente novamente.\n");
            return;
        }

        float valor_em_reais = valor_venda * lista->ethereum;
        float taxa = valor_em_reais * 0.02;
        float liquido = valor_em_reais - taxa;

        lista->saldo_eth -= valor_venda;
        lista->saldo_reais += liquido;

        printf("Digite sua senha para confirmar sua compra: ");
        scanf(" %4s", senha_digitada);

        printf("Venda realizada!\n");
        printf("Taxa de 2%%: R$ %.2f\n", taxa);
        printf("Recebido %s em reais: R$ %.2f\n", data_hora, liquido);
        sprintf(lista->historico[lista->total_operacao], "Saldo recebido R$ %.2f\n", liquido);
        lista->total_operacao++;
    }

    else if (escolher == 3) { // Ripple
        printf("Valor do Ripple: %.2f\n", lista->ripple);
        printf("Saldo em Ripple: %.2f\n", lista->saldo_rip);

        printf("Digite quanto deseja vender: ");
        scanf("%f", &valor_venda);

        if (valor_venda <= 0 || valor_venda > lista->saldo_rip) {
            printf("Valor inválido ou saldo insuficiente.\n Tente novamente.\n");
            return;
        }

        float valor_em_reais = valor_venda * lista->ripple;
        float taxa = valor_em_reais * 0.01;
        float liquido = valor_em_reais - taxa;

        lista->saldo_rip -= valor_venda;
        lista->saldo_reais += liquido;

        printf("Digite sua senha para confirmar sua compra: ");
        scanf(" %4s", senha_digitada);

        printf("Venda realizada!\n");
        printf("Taxa de 1%%: R$ %.2f\n", taxa);
        printf("Recebido %s em reais: R$ %.2f\n", data_hora, liquido);
        sprintf(lista->historico[lista->total_operacao], "Saldo recebido R$ %.2f\n", liquido);
        lista->total_operacao++;
    }

    else {
        printf("Moeda inválida.\n");
    }}