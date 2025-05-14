#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

int login(usuario *user) {
    char cpf_input[TAM_CPF + 1];
    char senha_input[TAM_SENHA + 1];

    printf("CPF (somente números): ");
    scanf(" %11s", cpf_input);

    printf("Senha (4 caracteres): ");
    scanf(" %4s", senha_input);

    if (strcmp(user->CPF, cpf_input) == 0 &&
        strcmp(user->senha, senha_input) == 0) {
        printf("\nLogin realizado!\n");
        return 1;
    }

    printf("\nCPF ou senha inválidos.\n");
    return 0;
}