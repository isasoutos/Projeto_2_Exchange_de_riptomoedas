#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

int menu() {
    int opcao;

    printf("----------------------------------------------------------\n");
    printf("1- Consultar saldo\n");
    printf("2- Depósito\n");
    printf("8- Sair\n");
    printf("Digite o que deseja: ");
    scanf("%d", &opcao);
    printf("----------------------------------------------------------\n");
    return opcao;
}


void consultar_saldo(cotacao *lista){

    printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
    printf("Valor do saldo do Bitcoin: R$ %.2f\n", lista->saldo_bit);
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