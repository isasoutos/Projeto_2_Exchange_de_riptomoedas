#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

int menu() {
    int opcao;

    printf("------------------------------\n");
    printf("1- Consultar saldo\n");
    printf("8- Sair\n");
    printf("Digite o que deseja: ");
    scanf("%d", &opcao);

    return opcao;
}


void consultar_saldo(cotacao *lista){
    float reais = 0.00; 
    float saldo_bit = 0.00;
    float saldo_eth = 0.00;
    float saldo_rip = 0.00;

    printf("Valor do saldo do Real: R$ %.2f\n", reais);
    printf("Valor do saldo do Bitcoin: R$ %.2f\n", saldo_bit);
    printf("Valor do saldo do Ethereum: R$ %.2f\n", saldo_eth);
    printf("Valor do saldo do Ripple: R$ %.2f\n", saldo_rip);
}