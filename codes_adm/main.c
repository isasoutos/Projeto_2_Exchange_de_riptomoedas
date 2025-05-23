#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"
#include <string.h>

int main() {
    usuario *cadastro = malloc(sizeof(usuario));
    printf("Área do Administrador\n");
    int escolha;

    #define USUARIO_ADM "administrador"
    #define SENHA_ADM "4321"

    char usuario_login[50];
    char senha[50];

    printf("Digite o seu usuário: ");
    scanf("%s", usuario_login);
    printf("Digite a sua senha: ");
    scanf("%s", senha);

    if (strcmp(usuario_login, USUARIO_ADM) == 0 && strcmp(senha, SENHA_ADM) == 0) {
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

        } while (escolha != 8);  // <-- agora 0 encerra o programa
    } else {
        printf("Usuário ou senha incorretos.\n");
    }

    free(cadastro);
    return 0;
}
