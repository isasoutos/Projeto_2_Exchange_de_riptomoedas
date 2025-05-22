#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"

int main() {
    investidor *cadastro = malloc(sizeof(investidor));
    printf("Área do Administrador\n");
    int escolha;

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
        }

    } while (escolha != 8);

    free(cadastro);
    return 0;
}
