#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

#define ARQ_INVESTIDOR "investidores.bin"

int login(usuario *user) {
    char cpf_input[TAM_CPF + 1];
    char senha_input[TAM_SENHA + 1];
    usuario temp;

    printf("CPF (somente números): ");
    scanf(" %11s", cpf_input);

    printf("Senha (4 caracteres): ");
    scanf(" %4s", senha_input);

    FILE *fp = fopen(ARQ_INVESTIDOR, "rb");
    if (!fp) {
        printf("Erro ao abrir arquivo de investidores.\n");
        return 0;
    }

    while (fread(&temp, sizeof(usuario), 1, fp)) {
        if (strcmp(temp.login, cpf_input) == 0 &&
            strcmp(temp.senha, senha_input) == 0) {
            fclose(fp);
            printf("\nLogin realizado!\n");
            return 1;
        }
    }

    fclose(fp);
    printf("\nCPF ou senha inválidos.\n");
    return 0;
}