#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"

void consultar_saldo() {
    char login[TAM_CPF + 1] = {0}; 
    printf("Digite o login do investidor que deseja consultar: ");
    scanf("%s", login);

    FILE *fp = fopen("investidores.bin", "rb");
    if (!fp) {
        printf("Erro ao abrir o arquivo de investidores.\n");
        return;
    }

    usuario temp;
    int encontrado = 0;

    while (fread(&temp, sizeof(usuario), 1, fp)) {
        printf("DEBUG >> Lido: [%s] | Digitado: [%s]\n", temp.login, login);

        if (strncmp(temp.login, login, TAM_CPF) == 0) {
            printf("\nInvestidor encontrado:\n");
            printf("Nome: %s\n", temp.nome);
            printf("CPF: %s\n", temp.login);
            printf("Saldo atual: R$ %.2f\n", temp.saldo);

            if (temp.saldo == 0.0) {
                printf("Nenhum depósito foi realizado ainda.\n");
            }

            encontrado = 1;
            break;
        }
    }

    fclose(fp);

    if (!encontrado) {
        printf("Investidor com CPF %s não encontrado.\n", login);
    }
}
