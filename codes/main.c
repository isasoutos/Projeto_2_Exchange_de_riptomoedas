#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>
#include <time.h>

Transacao transacoes[150];
int total_transacoes = 0;


int main(){
    cotacao *lista = malloc(sizeof(cotacao));
    usuario user = {"42246165806", "1234"};  // CPF e senha fixos
    int opcao;

    setenv("TZ", "America/Sao_Paulo", 1);
    tzset();

    lista->bitcoin = 83233.10; //Valor do dia 04/04/2025 as 13:15
    lista->ethereum = 1791.54; //Valor do dia 04/04/2025 as 13:17
    lista->ripple = 2.11; //valor do dia 04/04/205 as 13:20
    lista->saldo_reais = 0.0;
    lista->saldo_bit = 0.0;
    lista->saldo_eth = 0.0;
    lista->saldo_rip = 0.0;

    while (!login(&user)) {
        printf("Tente novamente...\n");
    }

    do{
        opcao = menu();

        if(opcao == 1){
            consultar_saldo(lista);
        }else if(opcao == 2){
            deposito(lista, &user);
        }else if(opcao == 5){
            comprar_criptomoedas(lista, &user);
        }else if(opcao == 7){
            atualizar_cotacao(lista);
        }else if(opcao == 3){
            sacar(lista, &user);      
        }else if(opcao == 6){
            vender_criptomoedas(lista);
        }else if(opcao == 4){
            extrato(transacoes, total_transacoes);        
        }
        
        
    } while (opcao != 8);

    free(lista);
    return 0;
}
