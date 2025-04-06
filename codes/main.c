#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

int main(){
    cotacao *lista = malloc(sizeof(cotacao));
    int opcao;

    lista->bitcoin = 83233.10; //Valor do dia 04/04/2025 as 13:15
    lista->ethereum = 1791.54; //Valor do dia 04/04/2025 as 13:17
    lista->ripple = 2.11; //valor do dia 04/04/205 as 13:20
    lista->saldo_reais = 0.0;
    lista->saldo_bit = 0.0;
    lista->saldo_eth = 0.0;
    lista->saldo_rip = 0.0;

    do{
        opcao = menu();

        if(opcao == 1){
            consultar_saldo(lista);
        }else if(opcao == 2){
            deposito(lista);
        }else if(opcao == 4){
            comprar_criptomoedas(lista);
        }
    } while (opcao != 8);

    free(lista);
    return 0;
}
int menu() {
    int opcao;

    printf("----------------------------------------------------------\n");
    printf("1- Consultar saldo\n");
    printf("2- Depósito\n");
    printf("4- Comprar Criptomoedas\n");
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
    printf("Digite a moeda: ");
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
        printf("Valor do saldo do Bitcoin: R$ %.2f\n", lista->saldo_eth);

        printf("Digite o valor que deseja comprar: ");
        scanf("%f", &compra_eth);

        if (lista->saldo_reais >= compra_eth){
            lista->saldo_eth = ((compra_eth / lista->ethereum) - ((compra_eth/lista->ethereum)*2/100)) + lista->saldo_eth;
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

        printf("Digite o valor que deseja comprar: ");
        scanf("%f", &compra_rip);

        if (lista->saldo_reais >= compra_rip){
            lista->saldo_rip = ((compra_rip / lista->ripple) - ((compra_rip/lista->ripple)*2/100)) + lista->saldo_rip;
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