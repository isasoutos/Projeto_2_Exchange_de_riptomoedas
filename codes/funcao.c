#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>
#include <time.h>

extern Transacao transacoes[150];
extern int total_transacoes;

int login(usuario *user) {
    char cpf_input[TAM_CPF + 1];
    char senha_input[TAM_SENHA + 1];

    printf("CPF (somente números): ");
    scanf(" %11s", cpf_input);

    printf("Senha (4 caracteres): ");
    scanf(" %4s", senha_input);

    if (strcmp(user->CPF, cpf_input) == 0 &&
        strcmp(user->senha, senha_input) == 0) {
        printf("\nLogin realizado!\n");
        return 1;
    }

    printf("\nCPF ou senha inválidos.\n");
    return 0;
}

int menu() {
    int opcao;

    printf("----------------------------------------------------------\n");
    printf("1- Consultar saldo\n");
    printf("2- Depósito\n");
    printf("3- Saque\n");
    printf("4- Extrato\n");
    printf("5- Comprar Criptomoedas\n");
    printf("6- Vender Criptomoedas\n");
    printf("7- Atualizar cotação\n");
    printf("8- Sair\n");
    printf("10- Exibir Extrato\n");


    printf("Digite o que deseja: ");
    scanf("%d", &opcao);
    printf("----------------------------------------------------------\n");
    return opcao;
}

int cripto() {
    int moedas;

    printf("---------------------\n");
    printf("1- Bitcoin\n");
    printf("2- Ethereum\n");
    printf("3- Ripple\n");
    printf("---------------------\n");
    printf("Digite a moeda que deseja: ");
    scanf("%d", &moedas);

    return moedas;

}

void consultar_saldo(cotacao *lista){

    printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
    printf("Valor do saldo do Bitcoin: R$ %.4f\n", lista->saldo_bit);
    printf("Valor do saldo do Ethereum: R$ %.2f\n", lista->saldo_eth);
    printf("Valor do saldo do Ripple: R$ %.2f\n", lista->saldo_rip);
}

void atual_datahora(char *destino, int tamanho) { 
    time_t agora;
    struct tm *info_tempo;
    time(&agora);
    info_tempo = localtime(&agora);
    strftime(destino, tamanho, "%d/%m/%Y %H:%M:%S", info_tempo);
}


void deposito(cotacao *lista, usuario *user){
    float valor_depo;
    char senha_digitada[TAM_SENHA + 1];

    char data_hora[30];
    atual_datahora(data_hora, sizeof(data_hora));

    printf("O valor do seu saldo: %.2f\n", lista->saldo_reais);
    printf("Digite o valor que deseja depositar: ");
    scanf("%f", &valor_depo);
    lista->saldo_reais += valor_depo;


    if (valor_depo <= 0){
        printf("Valor insuficiente!\n");
        return;
    }
    printf("Digite sua senha para realizar o deposito: ");
    scanf(" %4s", senha_digitada);

    if (strcmp(user->senha, senha_digitada) != 0) {
        printf("Senha incorreta! Deposito cancelado, tente novamente.\n");
        return;
    }

    lista->saldo_reais += valor_depo;
    registrar_transacao(transacoes, total_transacoes, "Depósito", valor_depo, 0.0);


    printf("Depósito de R$ %.2f realizado as %s.\n", valor_depo, data_hora);
    printf("Novo saldo: R$ %.2f as %s\n", lista->saldo_reais, data_hora);
}

void comprar_criptomoedas(cotacao *lista, usuario *user){
    char senha_digitada[TAM_SENHA + 1];
    float compra_bit;
    float compra_eth;
    float compra_rip;

    char data_hora[30];
    atual_datahora(data_hora, sizeof(data_hora));

    printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
    printf("Valor do saldo do Bitcoin: R$ %.2f\n", lista->saldo_bit);
    printf("Valor do saldo do Ethereum: R$ %.2f\n", lista->saldo_eth);
    printf("Valor do saldo do Ripple: R$ %.2f\n", lista->saldo_rip);

    int escolher = cripto();

    if (escolher == 1){
        printf("Valor do bitcoin: %.2f\n", lista->bitcoin);
        printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
        printf("Valor do saldo do Bitcoin: R$ %.4f\n", lista->saldo_bit);

        printf("Digite o valor que deseja comprar: ");
        scanf("%f", &compra_bit);

        if (lista->saldo_reais >= compra_bit){
            lista->saldo_bit = ((compra_bit / lista->bitcoin) - ((compra_bit/lista->bitcoin)*2/100)) + lista->saldo_bit;
            lista->saldo_reais = lista->saldo_reais - compra_bit;

            printf("Digite sua senha para confirmar sua compra: ");
            scanf(" %4s", senha_digitada);

            if (strcmp(user->senha, senha_digitada) != 0) {
                printf("Senha incorreta! Compra cancelado, tente novamente.\n");
                return;
            }

            printf("Saldo atual: %.2f as %s\n", lista->saldo_reais, data_hora);
            printf("Saldo bitcoin: %.4f as %s\n", lista->saldo_bit, data_hora);
            printf("Taxa de compra 2%%\n");

        }else if(lista->saldo_reais < compra_bit){
            printf("Saldo insulficiente\n");
        }

    }else if(escolher == 2){
        printf("Valor do ethereum: %.2f\n", lista->ethereum);
        printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
        printf("Valor do saldo do Ethereum: R$ %.2f\n", lista->saldo_eth);

        printf("Digite o valor que deseja comprar: ");
        scanf("%f", &compra_eth);

        if (lista->saldo_reais >= compra_eth){
            lista->saldo_eth = ((compra_eth / lista->ethereum) - ((compra_eth/lista->ethereum)*1/100)) + lista->saldo_eth;
            lista->saldo_reais = lista->saldo_reais - compra_eth;

            printf("Digite sua senha para confirmar sua compra: ");
            scanf(" %4s", senha_digitada);

            if (strcmp(user->senha, senha_digitada) != 0) {
                printf("Senha incorreta! Compra cancelado, tente novamente.\n");
                return;
            }

            printf("Saldo atual: %.2f as %s\n", lista->saldo_reais, data_hora);
            printf("Saldo ethereum: %.2f as %s\n", lista->saldo_eth, data_hora);
            printf("Taxa de compra 1%%\n");

        }else if(lista->saldo_reais < compra_eth){
            printf("Saldo insulficiente\n");
        }

    }else if(escolher == 3){
        printf("Valor do ripple: %.2f\n", lista->ripple);
        printf("Valor do saldo do Real: R$ %.2f\n", lista->saldo_reais);
        printf("Valor do saldo do Ripple: R$ %.2f\n", lista->saldo_rip);

        printf("Digite o valor que deseja comprar: ");
        scanf("%f", &compra_rip);

        if (lista->saldo_reais >= compra_rip){
            lista->saldo_rip = ((compra_rip / lista->ripple) - ((compra_rip/lista->ripple)*1/100)) + lista->saldo_rip;
            lista->saldo_reais = lista->saldo_reais - compra_rip;

            printf("Digite sua senha para confirmar sua compra: ");
            scanf(" %4s", senha_digitada);

            if (strcmp(user->senha, senha_digitada) != 0) {
                printf("Senha incorreta! Compra cancelado, tente novamente.\n");
                return;
            }

            printf("Saldo atual: %.2f as %s\n", lista->saldo_reais, data_hora);
            printf("Saldo ripple: %.2f as %s\n", lista->saldo_rip, data_hora);
            printf("Taxa de compra 1%%\n");

        }else if(lista->saldo_reais < compra_rip){
            printf("Saldo insulficiente\n");
        }
    }else {
        printf("Criptomoeda não identificada!\n");
    }
}



void atualizar_cotacao(cotacao *lista){
    int negativo = -5;
    int positivo = 5;
    int escolher = cripto();

    float atual_rip;
    int pos_neg = rand() %2;

    if (pos_neg == 0) {
        pos_neg = -1;
    } else {
        pos_neg = 1;
    }

    if (escolher == 1){
        int atual_bit = (rand() % (positivo - negativo + 1)) + negativo;
        float percentual = atual_bit / 100.0; 
        printf("Valor do bitcoin: %.2f\n", lista->bitcoin);
        lista->bitcoin *= (1 + (percentual*pos_neg));
        printf("Novo valor do bitcoin: %.2f\n", lista->bitcoin);
        printf("Porcentagem aplicada: %.2f%%\n", percentual * 100);
    }else if(escolher == 2){
        int atual_eth = (rand() % (positivo - negativo + 1)) + negativo;
        float percentual = atual_eth / 100.0; 
        printf("Valor do ethereum: %.2f\n", lista->ethereum);
        lista->ethereum *= (1 + (percentual*pos_neg));
        printf("Novo valor do ethereum: %.2f\n", lista->ethereum);
        printf("Porcentagem aplicada: %.2f%%\n", percentual * 100);
    }else if (escolher == 3){
        int atual_rip = (rand() % (positivo - negativo + 1)) + negativo;
        float percentual = atual_rip / 100.0; 
        printf("Valor do ripple: %.2f\n", lista->ripple);
        lista->ripple *= (1 + (percentual*pos_neg));
        printf("Novo valor do ripple: %.2f\n", lista->ripple);
        printf("Porcentagem aplicada: %.2f%%\n", percentual * 100);
    }else {
        printf("Criptomoeda não identificada!\n");
    }
}

void sacar(cotacao *carteira, usuario *user) {
    char senha_digitada[TAM_SENHA + 1];
    float valor;

    char data_hora[30];
    atual_datahora(data_hora, sizeof(data_hora));

    printf("Digite sua senha para sacar: ");
    scanf(" %4s", senha_digitada);

    if (strcmp(user->senha, senha_digitada) != 0) {
        printf("Senha incorreta! Saque cancelado, tente novamente.\n");
        return;
    }

    printf("Saldo atual da carteira: R$ %.2f\n", carteira->saldo_reais);
    printf("Digite o valor que deseja sacar: R$ ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("Valor inválido, o valor do saque não pode ser 0!\n");
        return;
    }

    if (valor > carteira->saldo_reais) {
        printf("Saldo insuficiente, realize um aporte e tente novamente!\n");
        return;
    }

    carteira->saldo_reais -= valor;
    registrar_transacao(transacoes, total_transacoes, "Saque", valor, 0.0);

   
    printf("✅ Saque de R$ %.2f realizado as %s com sucesso!\n", valor, data_hora);
    printf("Novo saldo: R$ %.2f as %s\n", carteira->saldo_reais, data_hora);
}
void vender_criptomoedas (cotacao *lista) {
    // Taxas sugeridas na orientação: Bitcoin 3%, Ethereum 2%, Ripple 1%
    float valor_venda;
    int escolher = cripto();

    char data_hora[30];
    atual_datahora(data_hora, sizeof(data_hora));

    if (escolher == 1) {
        printf("Valor do Bitcoin: %.2f\n", lista->bitcoin);
        printf("Saldo em Bitcoin: %.4f\n", lista->saldo_bit);

        printf("Digite quanto deseja vender: ");
        scanf("%f", &valor_venda);

        if (valor_venda <= 0 || valor_venda > lista->saldo_bit) {
            printf("Valor inválido ou saldo insuficiente.\n Tente novamente.\n");
            return;
        }

        float valor_em_reais = valor_venda * lista->bitcoin;
        float taxa = valor_em_reais * 0.03;
        float liquido = valor_em_reais - taxa;

        lista->saldo_bit -= valor_venda;
        lista->saldo_reais += liquido;

        printf("Venda realizada!\n");
        printf("Taxa de 3%%: R$ %.2f\n", taxa);
        printf("Recebido %s em reais: R$ %.2f\n",data_hora, liquido);
    }

    else if (escolher == 2) { // Ethereum
        printf("Valor do Ethereum: %.2f\n", lista->ethereum);
        printf("Saldo em Ethereum: %.2f\n", lista->saldo_eth);

        printf("Digite quanto de Ethereum deseja vender: ");
        scanf("%f", &valor_venda);

        if (valor_venda <= 0 || valor_venda > lista->saldo_eth) {
            printf("Valor inválido ou saldo insuficiente.\nTente novamente.\n");
            return;
        }

        float valor_em_reais = valor_venda * lista->ethereum;
        float taxa = valor_em_reais * 0.02;
        float liquido = valor_em_reais - taxa;

        lista->saldo_eth -= valor_venda;
        lista->saldo_reais += liquido;

        printf("Venda realizada!\n");
        printf("Taxa de 2%%: R$ %.2f\n", taxa);
        printf("Recebido %s em reais: R$ %.2f\n", data_hora, liquido);
    }

    else if (escolher == 3) { // Ripple
        printf("Valor do Ripple: %.2f\n", lista->ripple);
        printf("Saldo em Ripple: %.2f\n", lista->saldo_rip);

        printf("Digite quanto deseja vender: ");
        scanf("%f", &valor_venda);

        if (valor_venda <= 0 || valor_venda > lista->saldo_rip) {
            printf("Valor inválido ou saldo insuficiente.\n Tente novamente.\n");
            return;
        }

        float valor_em_reais = valor_venda * lista->ripple;
        float taxa = valor_em_reais * 0.01;
        float liquido = valor_em_reais - taxa;

        lista->saldo_rip -= valor_venda;
        lista->saldo_reais += liquido;

        printf("Venda realizada!\n");
        printf("Taxa de 1%%: R$ %.2f\n", taxa);
        printf("Recebido %s em reais: R$ %.2f\n", data_hora, liquido);
    }

    else {
        printf("Moeda inválida.\n");
    }
    
void registrar_transacao(Transacao transacoes[], int *total, const char *tipo, float valor, float taxa) {
    if (*total >= TAM_EXTRATO) return; // limite de 150
    time_t agora = time(NULL);
    struct tm *tm_info = localtime(&agora);
    
    strftime(transacoes[*total].horario, sizeof(transacoes[*total].horario), "%d/%m %H:%M", tm_info);
    strcpy(transacoes[*total].tipo, tipo);
    transacoes[*total].valor = valor;
    transacoes[*total].taxa = taxa;
    
        (*total)++;
    }

void extrato(Transacao transacoes[], int total) {
    printf("\n========== EXTRATO ==========\n");
    
    if (total == 0) {
        printf("Nenhuma transação registrada.\n");
    }
    
    for (int i = 0; i < total; i++) {
        printf("%s | %s | Valor: R$ %.2f | Taxa: %.2f%%\n",
                transacoes[i].horario,
                transacoes[i].tipo,
                transacoes[i].valor,
                transacoes[i].taxa);
        }
    
    printf("==============================\n");
    }
    