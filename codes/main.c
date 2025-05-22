#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h" 
#include <time.h>

int main() {
    int escolha;

    do {
        escolha = menu_principal();
        if (escolha == 1) {
            menuAdministrador();
        } else if (escolha == 2) {
            menuInvestidor();
        } else if (escolha == 3) {
            printf("Saindo do programa...\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (escolha != 3);

    return 0;
}

// Função do Administrador
void menuAdministrador() {
    printf("\n--- Área do Administrador ---\n");

    investidor *cadastro = malloc(sizeof(investidor));
    int escolha;

    do {
        escolha = menu_adm();

        if (escolha == 1) {
            usuario *cadastro_investidor();
            cadastrar_investidor(cadastro);
        } else if (escolha == 2) {
            excluir_inv(cadastro);
        } else if (escolha == 3) {
            
        } else if (escolha == 4) {
            
        } else if (escolha == 5) {
            
        } else if (escolha == 6) {
            
        } else if (escolha == 7) {
            
        }

    } while (escolha != 8);

    free(cadastro);
}

// Função do Investidor
void menuInvestidor() {
    printf("\n--- Área do Investidor ---\n");

    cotacao *lista = malloc(sizeof(cotacao));
    usuario user;
    int opcao;

    setenv("TZ", "America/Sao_Paulo", 1);
    tzset();

    lista->bitcoin = 83233.10;
    lista->ethereum = 1791.54;
    lista->ripple = 2.11;
    lista->saldo_reais = 0.0;
    lista->saldo_bit = 0.0;
    lista->saldo_eth = 0.0;
    lista->saldo_rip = 0.0;

    while (!login(&user)) {
        printf("Tente novamente...\n");
    }

    do {
        opcao = menu_inv();

        if (opcao == 1) {
            consultar_saldo(lista);
        } else if (opcao == 2) {
            deposito(lista, &user);
        } else if (opcao == 3) {
            sacar(lista, &user);
        } else if (opcao == 4) {
            extrato(lista);
        } else if (opcao == 5) {
            comprar_criptomoedas(lista, &user);
        } else if (opcao == 6) {
            vender_criptomoedas(lista);
        } else if (opcao == 7) {
            atualizar_cotacao_bit(lista);
            atualizar_cotacao_eth(lista);
            atualizar_cotacao_rip(lista);
        }

    } while (opcao != 8);

    free(lista);
}
