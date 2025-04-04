#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

int main(){
    cotacao *lista = malloc(sizeof(cotacao));
    int opcao;

    float bitcoin = 83233.10; //Valor do dia 04/04/2025 as 13:15
    float ethereum = 1791.54; //Valor do dia 04/04/2025 as 13:17
    float ripple = 2.11; //valor do dia 04/04/205 as 13:20
    float reais = 0.00; 
    float saldo_bit = 0.00;
    float saldo_eth = 0.00;
    float saldo_rip = 0.00;

    do{
        opcao = menu();

        if(opcao == 1){
            consultar_saldo(lista);
        }
    } while (opcao != 8);

    free(lista);
    return 0;
}