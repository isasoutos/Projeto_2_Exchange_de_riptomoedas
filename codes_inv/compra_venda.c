#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

void listar_criptomoedas() {
    FILE *arq = fopen("../codes_adm/criptomoedas.bin", "rb");
    if (!arq) {
        printf("Nenhuma criptomoeda cadastrada.\n");
        return;
    }

    cripto moeda;
    printf("Criptomoedas Cadastradas");
    while (fread(&moeda, sizeof(cripto), 1, arq) == 1) {
        printf("Nome: %s\n", moeda.nome);
        printf("Cotação Atual: R$ %.2f\n", moeda.cotacao);
        printf("Taxa de compra: %.2f%%\n", moeda.taxa_compra);
        printf("Taxa de venda: %.2f%%\n\n", moeda.taxa_venda);
    }

    fclose(arq);
}

void comprar_criptomoeda(cotacao *lista, usuario *user) {
    char nome[TAM_CRIPTO];
    char senha_digitada[TAM_SENHA + 1];
    float valor_compra;
    int encontrado = 0;

    printf("Digite o nome da criptomoeda que deseja comprar: ");
    scanf(" %[^\n]", nome);

    FILE *arq = fopen("../codes_adm/criptomoedas.bin", "rb");
    if (!arq) {
        printf("Arquivo de criptomoedas não encontrado.\n");
        return;
    }

    cripto moeda;
    while (fread(&moeda, sizeof(cripto), 1, arq) == 1) {
        if (strcmp(moeda.nome, nome) == 0) {
            encontrado = 1;

            printf("Cotação atual: R$ %.2f\n", moeda.cotacao);
            printf("Taxa de compra: %.2f%%\n", moeda.taxa_compra);
            printf("Quanto deseja investir em %s? R$ ", nome);
            scanf("%f", &valor_compra);

            if (valor_compra > lista->saldo_reais) {
                printf("Saldo insuficiente.\n");
                fclose(arq);
                return;
            }

            printf("Digite sua senha para confirmar trasação: ");
            scanf(" %4s", senha_digitada);

            if  (strcmp(user->senha, senha_digitada) != 0) {
                printf("Senha incorreta! Deposito cancelado, tente novamente.\n");
                return;
            } else{
                  float taxa = valor_compra * (moeda.taxa_compra / 100.0);
                  float valor_liquido = valor_compra - taxa;
                  float quantidade = valor_liquido / moeda.cotacao;

                    if (strcmp(moeda.nome, "Bitcoin") == 0)
                       lista->saldo_bit += quantidade;
                    else if (strcmp(moeda.nome, "Ethereum") == 0)
                        lista->saldo_eth += quantidade;
                    else if (strcmp(moeda.nome, "Ripple") == 0)
                        lista->saldo_rip += quantidade;
                    else
                        printf("Nome da moeda não mapeado se encontra no saldo\n");

                    lista->saldo_reais -= valor_compra;

                    printf("Compra realizada com sucesso!\n");
                    printf("Taxa cobrada: R$ %.2f\n", taxa);
                    break;
                }
        }
    }

    fclose(arq);

    if (!encontrado) {
        printf("Criptomoeda não encontrada.\n");
    }
}