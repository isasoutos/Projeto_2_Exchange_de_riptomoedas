#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

#define INV "investidores.bin"

int cadastrar_investidor(investidor *cadastro) {
    usuario user;
    printf("Digite o login do novo investidor (apenas números): ");
    scanf("%s", user.login);

    if (login_existe(user.login)) {
        printf("Login já cadastrado!\n");
        return 0;
    }else if (strlen(user.login) != TAM_CPF) {
        printf("Login inválido! Use apenas números e 11 dígitos.\n");
        return 0;
    }else{
        printf("Digite a senha do investidor (até 4 dígitos numéricos): ");
        scanf("%s", user.senha);
    }

    if (!senha_valida(user.senha)) {
        printf("Senha inválida! Use até 4 dígitos numéricos.\n");
        return 0;
    }

    FILE *fp = fopen(INV, "ab");
    if (!fp) {
        printf("Erro ao abrir arquivo de investidores.\n");
        return 0;
    }
    fwrite(&user, sizeof(usuario), 1, fp);
        fclose(fp);

    printf("Investidor cadastrado com sucesso!\n");
    return 1;
}