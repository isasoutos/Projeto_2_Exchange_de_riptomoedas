#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

int menu() {
    int opcao;

    printf("----------------------------------------------------------\n");
    printf("1- Consultar saldo\n");
    printf("2- Depósito\n");
    printf("4- Comprar Criptomoedas\n");
    printf("6- Atualizar cotação\n");
    printf("8- Sair\n");
    printf("Digite o que deseja: ");
    scanf("%d", &opcao);
    printf("----------------------------------------------------------\n");
    return opcao;
}

int cripto() {
    int moedas;

    printf("---------------------\n");
    printf("1- Bitcoin\n");
    printf("2- Ethereum\n");
    printf("3- Ripple\n");
    printf("---------------------\n");
    printf("Digite a moeda que deseja: ");
    scanf("%d", &moedas);

    return moedas;

}

void consultar_saldo(cotacao *lista){

    printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
    printf("Valor do saldo do Bitcoin: R$ %.4f\n", lista->saldo_bit);
    printf("Valor do saldo do Ethereum: R$ %.2f\n", lista->saldo_eth);
    printf("Valor do saldo do Ripple: R$ %.2f\n", lista->saldo_rip);
}

void deposito(cotacao *lista){
    float valor_depo;

    printf("O valor do seu saldo: %.2f\n", lista->saldo_reais);
    printf("Digite o valor que deseja depositar: ");
    scanf("%f", &valor_depo);
    if (valor_depo <= 0){
        printf("Valor insuficiente!\n");
        return;
    }

    lista->saldo_reais += valor_depo;

    printf("Depósito de R$ %.2f realizado.\n", valor_depo);
    printf("Novo saldo: R$ %.2f\n", lista->saldo_reais);
}
void comprar_criptomoedas(cotacao *lista){
    float compra_bit;
    float compra_eth;
    float compra_rip;

    printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
    printf("Valor do saldo do Bitcoin: R$ %.2f\n", lista->saldo_bit);
    printf("Valor do saldo do Ethereum: R$ %.2f\n", lista->saldo_eth);
    printf("Valor do saldo do Ripple: R$ %.2f\n", lista->saldo_rip);

    int escolher = cripto();

    if (escolher == 1){
        printf("Valor do bitcoin: %.2f\n", lista->bitcoin);
        printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
        printf("Valor do saldo do Bitcoin: R$ %.4f\n", lista->saldo_bit);
        printf("Taxa de compra 2 porcento\n");

        printf("Digite o valor que deseja comprar: ");
        scanf("%f", &compra_bit);

        if (lista->saldo_reais >= compra_bit){
            lista->saldo_bit = ((compra_bit / lista->bitcoin) - ((compra_bit/lista->bitcoin)*2/100)) + lista->saldo_bit;
            lista->saldo_reais = lista->saldo_reais - compra_bit;
            printf("Saldo atual: %.2f\n", lista->saldo_reais);
            printf("Saldo bitcoin: %.4f\n", lista->saldo_bit);
        }else if(lista->saldo_reais < compra_bit){
            printf("Saldo insulficiente\n");
        }
    }else if(escolher == 2){
        printf("Valor do ethereum: %.2f\n", lista->ethereum);
        printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
        printf("Valor do saldo do Ethereum: R$ %.2f\n", lista->saldo_eth);
        printf("Taxa de compra 1 porcento\n");

        printf("Digite o valor que deseja comprar: ");
        scanf("%f", &compra_eth);

        if (lista->saldo_reais >= compra_eth){
            lista->saldo_eth = ((compra_eth / lista->ethereum) - ((compra_eth/lista->ethereum)*1/100)) + lista->saldo_eth;
            lista->saldo_reais = lista->saldo_reais - compra_eth;
            printf("Saldo atual: %.2f\n", lista->saldo_reais);
            printf("Saldo ethereum: %.2f\n", lista->saldo_eth);
        }else if(lista->saldo_reais < compra_eth){
            printf("Saldo insulficiente\n");
        }
    }else if(escolher == 3){
        printf("Valor do ripple: %.2f\n", lista->ripple);
        printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
        printf("Valor do saldo do Ripple: R$ %.2f\n", lista->saldo_rip);
        printf("Taxa de compra 1 porcento\n");

        printf("Digite o valor que deseja comprar: ");
        scanf("%f", &compra_rip);

        if (lista->saldo_reais >= compra_rip){
            lista->saldo_rip = ((compra_rip / lista->ripple) - ((compra_rip/lista->ripple)*1/100)) + lista->saldo_rip;
            lista->saldo_reais = lista->saldo_reais - compra_rip;
            printf("Saldo atual: %.2f\n", lista->saldo_reais);
            printf("Saldo ripple: %.2f\n", lista->saldo_rip);
        }else if(lista->saldo_reais < compra_rip){
            printf("Saldo insulficiente\n");
        }
    }else {
        printf("Criptomoeda não identificada!\n");
    }
}

void atualizar_cotacao(cotacao *lista){
    int negativo = -5;
    int positivo = 5;
    int escolher = cripto();

    float atual_rip;
    int pos_neg = rand() %2;

    if (pos_neg == 0) {
        pos_neg = -1;
    } else {
        pos_neg = 1;
    }

    if (escolher == 1){
        int atual_bit = (rand() % (positivo - negativo + 1)) + negativo;
        float percentual = atual_bit / 100.0; 
        printf("Valor do bitcoin: %.2f\n", lista->bitcoin);
        lista->bitcoin *= (1 + (percentual*pos_neg));
        printf("Novo valor do bitcoin: %.2f\n", lista->bitcoin);
        printf("Porcentagem aplicada: %.2f%%\n", percentual * 100);
    }else if(escolher == 2){
        int atual_eth = (rand() % (positivo - negativo + 1)) + negativo;
        float percentual = atual_eth / 100.0; 
        printf("Valor do ethereum: %.2f\n", lista->ethereum);
        lista->ethereum *= (1 + (percentual*pos_neg));
        printf("Novo valor do ethereum: %.2f\n", lista->ethereum);
        printf("Porcentagem aplicada: %.2f%%\n", percentual * 100);
    }else if (escolher == 3){
        int atual_rip = (rand() % (positivo - negativo + 1)) + negativo;
        float percentual = atual_rip / 100.0; 
        printf("Valor do ripple: %.2f\n", lista->ripple);
        lista->ripple *= (1 + (percentual*pos_neg));
        printf("Novo valor do ripple: %.2f\n", lista->ripple);
        printf("Porcentagem aplicada: %.2f%%\n", percentual * 100);
    }else {
        printf("Criptomoeda não identificada!\n");
    }
}