#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

#define CRIPTOMOEDA "criptomoedas.bin"

void excluir_cripto() {
    char nome[TAM_CRIPTO];
    char confirmacao;

    printf("Digite o nome da criptomoeda que deseja excluir: ");
    scanf("%s", nome);
    
    printf("Tem certeza que deseja excluir a criptomoeda '%s'? (s/n): ", nome);
    scanf(" %c", &confirmacao);

    if (confirmacao != 's' && confirmacao != 'S') {
        printf("Operação de exclusão cancelada.\n");
        return;
    }

    FILE *fp = fopen(CRIPTOMOEDA, "rb");
    if (!fp) {
        printf("Arquivo de criptomoedas não encontrado.\n");
        return;
    }

    FILE *fp_temp = fopen("temp_cripto.bin", "wb");
    if (!fp_temp) {
        fclose(fp);
        printf("Erro ao criar arquivo temporário.\n");
        return;
    }

    cripto temp;
    int encontrado = 0;
    while (fread(&temp, sizeof(cripto), 1, fp)) {
        if (strcmp(temp.nome, nome) == 0) {
            encontrado = 1; // não escreve no novo arquivo
        } else {
            fwrite(&temp, sizeof(cripto), 1, fp_temp);
        }
    }

    fclose(fp);
    fclose(fp_temp);

    remove(CRIPTOMOEDA);
    rename("temp_cripto.bin", CRIPTOMOEDA);

    if (encontrado)
        printf("Criptomoeda excluída com sucesso!\n");
    else
        printf("Criptomoeda não encontrada.\n");
}
