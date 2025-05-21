#include <stdio.h>
#include <string.h>
#include "adm.h"
#include <stdlib.h>

int main(){
    investidor *cadastro = malloc(sizeof(investidor));
    cadastro_inv *novo = malloc(sizeof(cadastro_inv));
    int escolha;
    
    do{
        escolha = menu();

        if(escolha == 1){
            cadastro_inv *novo = cadastro_investidor();
            cadastrar_investidor(cadastro, novo);
        }else if(escolha == 2){
            excluir_inv(cadastro);
        }else if(escolha == 3){

        }else if(escolha == 4){

        }else if(escolha == 5){

        }else if(escolha == 6){

        }else if(escolha == 7){

        }
        
        
    } while (escolha != 8);

    free(cadastro);
    return 0;
}