#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcao.h"

int menu_principal() {
    int escolha;

    printf("----------------------------------------------------------\n");
    printf("Bem-vindo ao sistema de gerenciamento de criptomoedas!\n");
    printf("=== MENU PRINCIPAL ===\n");
    printf("1. Entrar como Administrador\n");
    printf("2. Entrar como Investidor\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    printf("----------------------------------------------------------\n");
    
    return escolha;
}

int menu_inv() {
    int opcao;

    printf("----------------------------------------------------------\n");
    printf("=== MENU DO INVESTIDOR ===\n");
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

int menu_adm() {
    int escolha;

    printf("----------------------------------------------------------\n");
    printf("=== MENU DO ADMINISTRADOR ===\n");
    printf("1- Cadastrar Novo Investidor\n");
    printf("2- Excluir Investidor\n");
    printf("3- Cadastro de Criptomoeda\n");
    printf("4- Excluir Criptomoeda\n");
    printf("5- Saldo do Investidor\n");
    printf("6- Extrato do Investidor\n");
    printf("7- Atualizar cotação\n");
    printf("8- Sair\n");


    printf("Digite o que deseja: ");
    scanf("%d", &escolha);
    printf("----------------------------------------------------------\n");
    return escolha;
}