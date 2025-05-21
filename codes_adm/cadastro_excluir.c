#include <stdio.h>
#include <string.h>
#include "adm.h"
#include <stdlib.h>

cadastro_inv *cadastro_investidor(){

    cadastro_inv *novo = malloc(sizeof(cadastro_inv));
    printf("Digite o login do investidor(apenas números): ");
    scanf("%s", novo->login);

    printf("Digite a senha do investidor(até 4 dígitos): ");
    scanf("%s", novo->senha);

    printf("Investidor Cadastro com sucesso\n");
    return novo;
}

int cadastrar_investidor(investidor *cadastro, cadastro_inv *novo){
    if (cadastro->qtde >= QTDE_INV) {
        printf("Limite de investidores atingido.\n");
        return 0;
    }

    cadastro->vetor[cadastro->qtde] = novo;
    cadastro->qtde++;
    return 1;
}

int excluir_inv(investidor *cadastro){
    char confirmacao;
    char login[TAM_CPF + 1];
    int i;

    printf("Digite o login do investidor a ser excluido: ");
    scanf("%s", login);

    for(i = 0; i < cadastro->qtde; i++){

        if(strcmp(cadastro->vetor[i]->login, login) == 0){
            printf("Investidor encontrado!\n");
            printf("CPF: %s\n", cadastro->vetor[i]->login);
            printf("Deseja realmente excluir? (s/n): ");
            scanf(" %c", &confirmacao);

            if (confirmacao == 's' || confirmacao == 'S') {
                free(cadastro->vetor[i]);
                for (int j = i; j < cadastro->qtde - 1; j++) {
                    cadastro->vetor[j] = cadastro->vetor[j + 1];
                }
                cadastro->qtde--;
                printf("Investidor excluído com sucesso.\n");
                return 1;

            } else {
                printf("Exclusão cancelada.\n");
                return 0;
            }
        }
    }
    printf("CPF não encontrado.\n");
    return 0;
}