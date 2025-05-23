#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

void consultar_saldo(usuario *user, cotacao *lista) {
    FILE *fp = fopen("../codes_adm/investidores.bin", "rb+");
    if (!fp) {
        printf("Erro ao abrir o arquivo de investidores.\n");
        return;
    }

    usuario temp;
    int encontrado = 0;

    while (fread(&temp, sizeof(usuario), 1, fp)) {
        if (strcmp(temp.login, user->login) == 0) {
            printf("Saldo atual: R$ %.2f\n", temp.saldo);
            for (int i = 0; i < lista->qtd_criptos; i++) {
            printf("Criptomoeda: %s | Saldo: %.6f\n", lista->criptos[i].nome, lista->criptos[i].saldo);
         }

            lista->saldo_reais = temp.saldo;
            fseek(fp, -sizeof(usuario), SEEK_CUR);
            fwrite(&temp, sizeof(usuario), 1, fp);

            encontrado = 1;
            break;
        }
    }

    fclose(fp);

    if (!encontrado) {
        printf("Investidor não encontrado.\n");
    }
}

void deposito(cotacao *lista, usuario *user){
    float valor_depo;
    char senha_digitada[TAM_SENHA + 1];

    char data_hora[30];
    atual_datahora(data_hora, sizeof(data_hora));

    printf("O valor do seu saldo: %.2f\n", lista->saldo_reais);
    printf("Digite o valor que deseja depositar: ");
    scanf("%f", &valor_depo);

    if (valor_depo <= 0){
        printf("Valor insuficiente!\n");
        return;
    }
    printf("Digite sua senha para realizar o deposito: ");
    scanf(" %4s", senha_digitada);

    if (strcmp(user->senha, senha_digitada) != 0) {
        printf("Senha incorreta! Deposito cancelado, tente novamente.\n");
        return;
    } else{
        lista->saldo_reais += valor_depo;
        printf("Depósito de R$ %.2f realizado as %s.\n", valor_depo, data_hora);
        printf("Novo saldo: R$ %.2f as %s\n", lista->saldo_reais, data_hora);
    }

    FILE *fp = fopen("../codes_adm/investidores.bin", "rb+");
    if (!fp) {
        printf("Erro ao abrir o arquivo de investidores.\n");
        return;
    }
    usuario temp;
    while (fread(&temp, sizeof(usuario), 1, fp)) {
        if (strcmp(temp.login, user->login) == 0) {
            temp.saldo = lista->saldo_reais;
            fseek(fp, -sizeof(usuario), SEEK_CUR);
            fwrite(&temp, sizeof(usuario), 1, fp);
            break;
        }
    }
    fclose(fp);

    sprintf(lista->historico[lista->total_operacao], "Depósito de R$ %.2f\n", valor_depo);
    lista->total_operacao++;
}

void sacar(cotacao *carteira, usuario *user) {
    char senha_digitada[TAM_SENHA + 1];
    float valor;

    char data_hora[30];
    atual_datahora(data_hora, sizeof(data_hora));

    printf("Digite sua senha para sacar: ");
    scanf(" %4s", senha_digitada);

    if (strcmp(user->senha, senha_digitada) != 0) {
        printf("Senha incorreta! Saque cancelado, tente novamente.\n");
        return;
    }

    printf("Saldo atual da carteira: R$ %.2f\n", carteira->saldo_reais);
    printf("Digite o valor que deseja sacar: R$ ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("Valor inválido, o valor do saque não pode ser 0!\n");
        return;
    }

    if (valor > carteira->saldo_reais) {
        printf("Saldo insuficiente, realize um aporte e tente novamente!\n");
        return;
    }

    carteira->saldo_reais -= valor;
   
    printf("Saque de R$ %.2f realizado as %s com sucesso!\n", valor, data_hora);
    printf("Novo saldo: R$ %.2f as %s\n", carteira->saldo_reais, data_hora);

    FILE *fp = fopen("../codes_adm/investidores.bin", "rb+");
    if (!fp) {
        printf("Erro ao abrir o arquivo de investidores.\n");
        return;
    }
    usuario temp;
    while (fread(&temp, sizeof(usuario), 1, fp)) {
        if (strcmp(temp.login, user->login) == 0) {
            temp.saldo = carteira->saldo_reais;
            fseek(fp, -sizeof(usuario), SEEK_CUR);
            fwrite(&temp, sizeof(usuario), 1, fp);
            break;
        }
    }
    fclose(fp);

    sprintf(carteira->historico[carteira->total_operacao], "Saque de R$ %.2f\n", valor);
    carteira->total_operacao++;
}

void adicionar_saldo_cripto(cotacao *lista, const char *nome, float quantidade) {
    for (int i = 0; i < lista->qtd_criptos; i++) {
        if (strcmp(lista->criptos[i].nome, nome) == 0) {
            lista->criptos[i].saldo += quantidade;
            return;
        }
    }
    if (lista->qtd_criptos < MAX_CRIPTOS) {
        strcpy(lista->criptos[lista->qtd_criptos].nome, nome);
        lista->criptos[lista->qtd_criptos].saldo = quantidade;
        lista->qtd_criptos++;
    }
}

int remover_saldo_cripto(cotacao *lista, const char *nome, float quantidade) {
    for (int i = 0; i < lista->qtd_criptos; i++) {
        if (strcmp(lista->criptos[i].nome, nome) == 0) {
            if (lista->criptos[i].saldo >= quantidade) {
                lista->criptos[i].saldo -= quantidade;
                return 1; 
            } else {
                return 0;
            }
        }
    }
    return 0; 
}