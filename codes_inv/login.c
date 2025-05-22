#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

int login(usuario *user) {
    char login_input[TAM_CPF + 1];
    char senha_input[TAM_SENHA + 1];
    usuario temp;

    printf("Digite o seu login: ");
    scanf("%s", login_input);
    printf("Digite a sua senha de 4 digitos: ");
    scanf("%s", senha_input);

    FILE *fp = fopen("../codes_adm/investidores.bin", "rb");
    if (!fp) {
        printf("Erro ao abrir arquivo de investidores.\n");
        return 0;
    }
    while (fread(&temp, sizeof(usuario), 1, fp)) {
        if (strcmp(temp.login, login_input) == 0 && strcmp(temp.senha, senha_input) == 0) {
            // Preenche a struct user com os dados do arquivo
            strcpy(user->login, temp.login);
            strcpy(user->senha, temp.senha);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    printf("Login ou senha inválidos!\n");
    return 0;
}