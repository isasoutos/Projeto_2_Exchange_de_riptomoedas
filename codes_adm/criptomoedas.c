#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

#define CRIPTOMOEDA "criptomoedas.bin"

int cripto_existe(const char *nome) {
    FILE *fp = fopen(CRIPTOMOEDA, "rb");
    if (!fp) return 0;
    cripto temp;
    while (fread(&temp, sizeof(cripto), 1, fp)) {
        if (strcmp(temp.nome, nome) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void cadastrar_cripto() {
    cripto moeda;
    printf("Digite o nome da criptomoeda que deseja cadastrar: ");
    scanf("%s", moeda.nome);

    if (cripto_existe(moeda.nome)) {
        printf("Criptomoeda já cadastrada!\n");
        return;
    }

    printf("Digite a sua cotação: R$");
    scanf("%f", &moeda.cotacao_inicial);

    printf("Digite a sua taxa de compra (em %%): ");
    scanf("%f", &moeda.taxa_compra);

    printf("Digite a sua taxa de venda (em %%): ");
    scanf("%f", &moeda.taxa_venda);

    FILE *fp = fopen(CRIPTOMOEDA, "ab");
    if (!fp) {
        printf("Erro ao abrir arquivo de criptomoedas.\n");
        return;
    }
    fwrite(&moeda, sizeof(cripto), 1, fp);
    fclose(fp);

    printf("Criptomoeda cadastrada com sucesso!\n");
}

void excluir_cripto() {
    char nome[TAM_CRIPTO];
    printf("Digite o nome da criptomoeda que deseja excluir: ");
    scanf("%s", nome);

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
            encontrado = 1; 
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