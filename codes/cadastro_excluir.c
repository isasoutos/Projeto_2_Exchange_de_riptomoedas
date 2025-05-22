#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

#define ARQ_INVESTIDOR "investidores.bin"

int login_existe(const char *login) {
    FILE *fp = fopen(ARQ_INVESTIDOR, "rb");
    if (!fp) return 0;
    usuario temp;
    while (fread(&temp, sizeof(usuario), 1, fp)) {
        if (strcmp(temp.login, login) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int senha_valida(const char *senha) {
    if (strlen(senha) > 4) return 0;
    for (int i = 0; senha[i]; i++) {
        if (senha[i] < '0' || senha[i] > '9') return 0;
    }
    return 1;
}
int cadastrar_investidor(investidor *cadastro) {
    usuario novo;
    printf("Digite o login do investidor (apenas números): ");
    scanf("%s", novo.login);

    if (login_existe(novo.login)) {
        printf("Login já cadastrado!\n");
        return 0;
    }

    printf("Digite a senha do investidor (até 4 dígitos numéricos): ");
    scanf("%s", novo.senha);

    if (!senha_valida(novo.senha)) {
        printf("Senha inválida! Use até 4 dígitos numéricos.\n");
        return 0;
    }

    FILE *fp = fopen(ARQ_INVESTIDOR, "ab");
    if (!fp) {
        printf("Erro ao abrir arquivo de investidores.\n");
        return 0;
    }
    fwrite(&novo, sizeof(usuario), 1, fp);
        fclose(fp);

    printf("Investidor cadastrado com sucesso!\n");
    return 1;
}

int excluir_inv(investidor *cadastro){
    char confirmacao;
    char login[TAM_CPF + 1];
    int i;

    printf("Digite o login do investidor a ser excluido: ");
    scanf("%s", login);

    for(i = 0; i < cadastro->qtde; i++){

        if(strcmp(cadastro->vetor[i]->login, login) == 0){
            printf("Investidor encontrado!\n");
            printf("CPF: %s\n", cadastro->vetor[i]->login);
            printf("Deseja realmente excluir? (s/n): ");
            scanf(" %c", &confirmacao);

            if (confirmacao == 's' || confirmacao == 'S') {
                free(cadastro->vetor[i]);
                for (int j = i; j < cadastro->qtde - 1; j++) {
                    cadastro->vetor[j] = cadastro->vetor[j + 1];
                }
                cadastro->qtde--;
                printf("Investidor excluído com sucesso.\n");
                return 1;

            } else {
                printf("Exclusão cancelada.\n");
                return 0;
            }
        }
    }
    printf("CPF não encontrado.\n");
    return 0;
}

int excluir_investidor_arquivo(const char *login) {
    FILE *fp = fopen(ARQ_INVESTIDOR, "rb");
    if (!fp) {
        printf("Arquivo de investidores não encontrado.\n");
        return 0;
    }
    FILE *fp_temp = fopen("temp.bin", "wb");
    if (!fp_temp) {
        fclose(fp);
        printf("Erro ao criar arquivo temporário.\n");
        return 0;
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

    remove(ARQ_INVESTIDOR);
    rename("temp.bin", ARQ_INVESTIDOR);

    if (encontrado)
        printf("Investidor excluído com sucesso do arquivo!\n");
    else
        printf("Investidor não encontrado no arquivo.\n");

    return encontrado;
}