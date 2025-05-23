#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"

void cadastrar_investidor() {
    investidor_individual novo;

    printf("Digite o nome do investidor: ");
    scanf(" %[^\n]", novo.nome);

    printf("Digite o CPF do investidor (11 dígitos): ");
    scanf("%s", novo.cpf);

    novo.saldo = 0.0;

    FILE *fp = fopen("investidores.bin", "ab");
    if (!fp) {
        printf("Erro ao abrir o arquivo de investidores.\n");
        return;
    }

    fwrite(&novo, sizeof(investidor_individual), 1, fp);
    fclose(fp);

    printf("✅ Investidor cadastrado com sucesso!\n");
}
