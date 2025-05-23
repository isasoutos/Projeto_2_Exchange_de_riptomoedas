#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

#define CRIPTOMOEDA "criptomoedas.bin"

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
