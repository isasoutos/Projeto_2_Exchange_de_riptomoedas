#include <stdio.h>
#include <string.h>
#include "adm.h"
#include <stdlib.h>

int menu() {
    int escolha;

    printf("----------------------------------------------------------\n");
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