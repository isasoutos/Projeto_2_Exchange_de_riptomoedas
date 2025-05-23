#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"
#include <string.h>

int main() {
    usuario *cadastro = malloc(sizeof(usuario));
    int escolha;
    int login_valido = 0;

    #define USUARIO_ADM "administrador"
    #define SENHA_ADM "4321"

    char usuario_login[50];
    char senha[50];

    printf("Área do Administrador\n");

    while (!login_valido) {
        printf("Digite o seu usuário: ");
        scanf("%49s", usuario_login);
        printf("Digite a sua senha: ");
        scanf("%49s", senha);

        if (strcmp(usuario_login, USUARIO_ADM) == 0 && strcmp(senha, SENHA_ADM) == 0) {
            login_valido = 1; // sai do loop
        } else {
            printf("Usuário ou senha incorretos. Tente novamente.\n");
        }
    }

    // Aqui só chega se o login for válido
    do {
        escolha = menu_adm();

        if (escolha == 1) {
            cadastrar_investidor(cadastro);
        } else if (escolha == 2) {
            excluir_inv(cadastro);
        } else if (escolha == 3) {
            cadastrar_cripto();
        } else if (escolha == 4) {
            excluir_cripto();
        } else if (escolha == 5) {
            consultar_saldo();
        } 

    } while (escolha != 8);  // 8 encerra o programa

    free(cadastro);
    return 0;
}
