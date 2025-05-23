#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>
#define INV "investidores.bin"


void consultar_saldo(cotacao *lista){

    printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
    printf("Valor do saldo do Bitcoin: R$ %.4f\n", lista->saldo_bit);
    printf("Valor do saldo do Ethereum: R$ %.2f\n", lista->saldo_eth);
    printf("Valor do saldo do Ripple: R$ %.2f\n", lista->saldo_rip);
}

void deposito(cotacao *lista, usuario *user){
    float valor_depo;
    char senha_digitada[TAM_SENHA + 1];
    int encontrado = 0;

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

        FILE *fp = fopen("../codes_adm/investidores.bin", "rb+");
        if (!fp) {
            printf("Erro ao abrir o arquivo de investidores.\n");
            return;
        }

        lista->saldo_reais += valor_depo;

        usuario temp;
        while (fread(&temp, sizeof(usuario), 1, fp)) {
        if (strcmp(temp.login, user->login) == 0) {
        temp.saldo += valor_depo;
        fseek(fp, -sizeof(usuario), SEEK_CUR);
        fwrite(&temp, sizeof(usuario), 1, fp);
        printf("Depósito realizado! Novo saldo: R$ %.2f\n", temp.saldo);
        encontrado = 1;
        break;
    }
    }
    fclose(fp);
    }

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
    sprintf(carteira->historico[carteira->total_operacao], "Saque de R$ %.2f\n", valor);
    carteira->total_operacao++;
}