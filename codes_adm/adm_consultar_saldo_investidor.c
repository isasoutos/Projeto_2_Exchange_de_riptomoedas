#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"


void listar_investidores() {
    FILE *fp = fopen("investidores.bin", "rb");
    if (!fp) {
        printf("Erro ao abrir o arquivo de investidores.\n");
        return;
    }

    investidor_individual temp;
    int count = 0;

    printf("\n=== Lista de Investidores ===\n");
    while (fread(&temp, sizeof(investidor_individual), 1, fp)) {
        printf("%d. Nome: %s | CPF: %s\n", ++count, temp.nome, temp.cpf);
    }

    if (count == 0)
        printf("Nenhum investidor cadastrado.\n");

    fclose(fp);
}

void consultar_saldo() {
    char cpf[TAM_CPF + 1] = {0};  // Zera a string CPF
    printf("Digite o CPF do investidor que deseja consultar: ");
    scanf("%s", cpf);

    FILE *fp = fopen("investidores.bin", "rb");
    if (!fp) {
        printf("Erro ao abrir o arquivo de investidores.\n");
        return;
    }

    investidor_individual temp;
    int encontrado = 0;

    while (fread(&temp, sizeof(investidor_individual), 1, fp)) {
        // Debug temporário para verificar o que está sendo comparado
        printf("DEBUG >> Lido: [%s] | Digitado: [%s]\n", temp.cpf, cpf);

        if (strncmp(temp.cpf, cpf, TAM_CPF) == 0) {
            printf("\n✅ Investidor encontrado:\n");
            printf("Nome: %s\n", temp.nome);
            printf("CPF: %s\n", temp.cpf);
            printf("Saldo atual: R$ %.2f\n", temp.saldo);

            if (temp.saldo == 0.0) {
                printf("⚠️  Nenhum depósito foi realizado ainda.\n");
            }

            encontrado = 1;
            break;
        }
    }

    fclose(fp);

    if (!encontrado) {
        printf("❌ Investidor com CPF %s não encontrado.\n", cpf);
    }
}
