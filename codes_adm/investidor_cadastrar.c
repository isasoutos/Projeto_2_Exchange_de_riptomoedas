#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"
#define INV "investidores.bin"

void cadastrar_investidor() {
    usuario novo;

    printf("Digite o nome do investidor: ");
    scanf(" %[^\n]", novo.nome);

    printf("Digite o CPF do investidor (11 dígitos): ");
    scanf("%s", novo.login);

    printf("Digite a senha do investidor: ");
    scanf("%s", novo.senha);
    if (senha_valida(novo.senha) == 0) {
        printf("Senha inválida. A senha deve ter pelo menos 4 caracteres.\n");
        return;
    }
    if (login_existe(novo.login) == 1) {
        printf("CPF já cadastrado.\n");
        return;
    }
    novo.saldo = 0.0;

    FILE *fp = fopen(INV, "ab");
    if (!fp) {
        printf("Erro ao abrir o arquivo de investidores.\n");
        return;
    }

    fwrite(&novo, sizeof(usuario), 1, fp);
    fclose(fp);

    printf("Investidor cadastrado com sucesso!\n");
}
