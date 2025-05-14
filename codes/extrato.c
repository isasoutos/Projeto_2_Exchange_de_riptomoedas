#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

void extrato(cotacao *lista){
    char senha_digitada[TAM_SENHA + 1];

    printf("Digite sua senha para acessar seu extrato: ");
    scanf(" %4s", senha_digitada);


    printf("Extrato bancário\n");
    printf("Saldo da conta: R$ %.2f\n", lista->saldo_reais);

    printf("Histório de Operações!\n");

    if(lista->total_operacao == 0){
        printf("Nenhuma operação registrada!\n");
    } else{
        for (int i = 0; i < lista->total_operacao; i++){
            printf("%d. %s\n", i + i, lista->historico[i]);
        }
    }
}