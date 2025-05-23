#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

#define INV "investidores.bin"

void excluir_inv() {
    char login[TAM_CPF];
    printf("Digite o login do investidor que deseja excluir: ");
    scanf("%s", login);

    FILE *fp = fopen(INV, "rb");
    if (!fp) {
        printf("Arquivo de investidores não encontrado.\n");
        return;
    }
    FILE *fp_temp = fopen("temp_inv.bin", "wb");
    if (!fp_temp) {
        fclose(fp);
        printf("Erro ao criar arquivo temporário.\n");
        return;
    }

    usuario temp;
    int encontrado = 0;
    while (fread(&temp, sizeof(usuario), 1, fp)) {
        if (strcmp(temp.login, login) == 0) {
            encontrado = 1; 
        } else {
            fwrite(&temp, sizeof(usuario), 1, fp_temp);
        }
    }
    fclose(fp);
    fclose(fp_temp);

    remove(INV);
    rename("temp_inv.bin", INV);

    if (encontrado)
        printf("Investidor excluído com sucesso!\n");
    else
        printf("Investidor não encontrado.\n");
}