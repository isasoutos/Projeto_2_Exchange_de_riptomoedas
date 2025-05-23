// main_investidor.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcao.h"

int main() {
    cotacao *lista = malloc(sizeof(cotacao));
    printf("\nÁrea do Investidor\n");
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
            consultar_saldo(&user, lista);
        } else if (opcao == 2) {
            deposito(lista, &user);
        } else if (opcao == 3) {
            sacar(lista, &user);
        } else if (opcao == 4) {
            extrato(lista);
        } else if (opcao == 5) {
            listar_criptomoedas_compra();
            comprar_criptomoeda(lista, &user);
        } else if (opcao == 6) {
            listar_criptomoedas_venda();
            venda_criptomoeda(lista, &user);

        } else if (opcao == 7) {
            atualizar_cotacao_bit(lista);
            atualizar_cotacao_eth(lista);
            atualizar_cotacao_rip(lista);
        }

    } while (opcao != 8);

    free(lista);
    return 0;
}
