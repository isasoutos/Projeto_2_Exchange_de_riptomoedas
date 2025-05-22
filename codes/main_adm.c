#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"

int main() {
    printf("\n--- Área do Administrador ---\n");

    investidor *cadastro = malloc(sizeof(investidor));
    int escolha;

    do {
        escolha = menu_adm();

        if (escolha == 1) {
            cadastrar_investidor(cadastro);
        } else if (escolha == 2) {
            excluir_inv(cadastro);
        } else if (escolha == 3) {
            // Outra função de administrador
        } else if (escolha == 4) {
            // Outra função de administrador
        }

    } while (escolha != 8);

    free(cadastro);
    return 0;
}
