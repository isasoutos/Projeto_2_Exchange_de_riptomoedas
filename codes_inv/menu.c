#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcao.h"

int menu_inv() {
    int opcao;

    printf("----------------------------------------------------------\n");
    printf("1- Consultar saldo\n");
    printf("2- Depósito\n");
    printf("3- Saque\n");
    printf("4- Extrato\n");
    printf("5- Comprar Criptomoedas\n");
    printf("6- Vender Criptomoedas\n");
    printf("7- Atualizar cotação\n");
    printf("8- Sair\n");

    printf("Digite o que deseja: ");
    scanf("%d", &opcao);
    printf("----------------------------------------------------------\n");
    return opcao;
}

int menu_cripto() {
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
