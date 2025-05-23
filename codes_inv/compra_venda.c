#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>

void listar_criptomoedas_compra() {
    FILE *arq = fopen("../codes_adm/criptomoedas.bin", "rb");
    if (!arq) {
        printf("Nenhuma criptomoeda cadastrada.\n");
        return;
    }

    cripto moeda;
    printf("Criptomoedas Cadastradas\n");
    while (fread(&moeda, sizeof(cripto), 1, arq) == 1) {
        printf("Nome: %s\n", moeda.nome);
        printf("Cotação Atual: R$ %.2f\n", moeda.cotacao);
        printf("Taxa de compra: %.2f%%\n\n", moeda.taxa_compra);
    }

    fclose(arq);
}

void listar_criptomoedas_venda() {
    FILE *arq = fopen("../codes_adm/criptomoedas.bin", "rb");
    if (!arq) {
        printf("Nenhuma criptomoeda cadastrada.\n");
        return;
    }

    cripto moeda;
    printf("Criptomoedas Cadastradas\n");
    while (fread(&moeda, sizeof(cripto), 1, arq) == 1) {
        printf("Nome: %s\n", moeda.nome);
        printf("Cotação Atual: R$ %.2f\n", moeda.cotacao);
        printf("Taxa de venda: %.2f%%\n\n", moeda.taxa_venda);
    }

    fclose(arq);
}

void comprar_criptomoeda(cotacao *lista, usuario *user) {
    char nome[TAM_CRIPTO];
    char senha_digitada[TAM_SENHA + 1];
    float valor_compra;
    float valor_liquido;
    float quantidade;
    float taxa;
    int encontrado = 0;

    printf("Saldo disponível: R$ %.2f\n", lista->saldo_reais);

    printf("Digite o nome da criptomoeda que deseja comprar: ");
    scanf(" %[^\n]", nome);

    FILE *arq = fopen("../codes_adm/criptomoedas.bin", "rb");
    if (!arq) {
        printf("Arquivo de criptomoedas não encontrado.\n");
        return;
    }

    cripto moeda;
    while (fread(&moeda, sizeof(cripto), 1, arq) == 1) {
        if (strcmp(moeda.nome, nome) == 0) {
            encontrado = 1;

            printf("Cotação atual: R$ %.2f\n", moeda.cotacao);
            printf("Taxa de compra: %.2f%%\n", moeda.taxa_compra);
            printf("Quanto deseja investir em %s? R$ ", nome);
            scanf("%f", &valor_compra);

            if (valor_compra > lista->saldo_reais) {
                printf("Saldo insuficiente.\n");
                fclose(arq);
                return;
            }

            printf("Digite sua senha para confirmar trasação: ");
            scanf(" %4s", senha_digitada);

            if  (strcmp(user->senha, senha_digitada) != 0) {
                printf("Senha incorreta! Deposito cancelado, tente novamente.\n");
                return;
            } else{
                taxa = valor_compra * (moeda.taxa_compra / 100.0);
                valor_liquido = valor_compra - taxa;
                quantidade = valor_liquido / moeda.cotacao;

                lista->saldo_reais -= valor_compra;

                FILE *fp = fopen("../codes_adm/investidores.bin", "rb+");
                    if (fp) {
                    usuario temp;
                    while (fread(&temp, sizeof(usuario), 1, fp)) {
                if (strcmp(temp.login, user->login) == 0) {
                    temp.saldo = lista->saldo_reais;
                    fseek(fp, -sizeof(usuario), SEEK_CUR);
                    fwrite(&temp, sizeof(usuario), 1, fp);
                    break;
        }
    }
    fclose(fp);
}
    adicionar_saldo_cripto(lista, nome, quantidade);
    lista->saldo_reais -= valor_compra;

                    printf("Compra realizada com sucesso!\n");
                    printf("Valor da compra: R$ %.2f\n", valor_liquido);
                    printf("Novo saldo em reais: R$ %.2f\n", lista->saldo_reais);
                    printf("Saldo de %s: %.5f\n", moeda.nome, quantidade);
                }
        }
    }

    fclose(arq);

    if (!encontrado) {
        printf("Criptomoeda não encontrada.\n");
    }
}

void venda_criptomoeda(cotacao *lista, usuario *user) {
    char nome[TAM_CRIPTO];
    char senha_digitada[TAM_SENHA + 1];
    float quantidade_venda;
    float valor_bruto;
    float valor_liquido;
    float taxa;
    int encontrado = 0;

    printf("Digite o nome da criptomoeda que deseja vender: ");
    scanf(" %[^\n]", nome);

    FILE *arq = fopen("../codes_adm/criptomoedas.bin", "rb");
    if (!arq) {
        printf("Arquivo de criptomoedas não encontrado.\n");
        return;
    }

    cripto moeda;
    while (fread(&moeda, sizeof(cripto), 1, arq) == 1) {
        if (strcmp(moeda.nome, nome) == 0) {
            encontrado = 1;

            printf("Cotação atual: R$ %.2f\n", moeda.cotacao);
            printf("Taxa de venda: %.2f%%\n", moeda.taxa_venda); 
            printf("Quanto %s deseja vender? Quantidade: ", nome);
            scanf("%f", &quantidade_venda);

            float saldo_usuario_cripto = 0.0;
            for (int i = 0; i < lista->qtd_criptos; i++) {
            if (strcmp(lista->criptos[i].nome, nome) == 0) {
            saldo_usuario_cripto = lista->criptos[i].saldo;
            break;
        }
    }

            if (quantidade_venda > saldo_usuario_cripto) {
                printf("Saldo insuficiente da criptomoeda para venda.\n");
                fclose(arq);
                return;
            }

            printf("Digite sua senha para confirmar a transação: ");
            scanf(" %s", senha_digitada);

            if (strcmp(user->senha, senha_digitada) != 0) {
                printf("Senha incorreta! Venda cancelada, tente novamente.\n");
                fclose(arq);
                return;
            }

            valor_bruto = quantidade_venda * moeda.cotacao;
            taxa = valor_bruto * (moeda.taxa_venda / 100.0);
            valor_liquido = valor_bruto - taxa;

            if (strcmp(moeda.nome, "Bitcoin") == 0)
                lista->saldo_bit -= quantidade_venda;
            else if (strcmp(moeda.nome, "Ethereum") == 0)
                lista->saldo_eth -= quantidade_venda;
            else if (strcmp(moeda.nome, "Ripple") == 0)
                lista->saldo_rip -= quantidade_venda;

            lista->saldo_reais += valor_liquido;

            FILE *fp = fopen("../codes_adm/investidores.bin", "rb+");
            if (fp) {
            usuario temp;
            while (fread(&temp, sizeof(usuario), 1, fp)) {
                if (strcmp(temp.login, user->login) == 0) {
                    temp.saldo = lista->saldo_reais;
                    fseek(fp, -sizeof(usuario), SEEK_CUR);
                     fwrite(&temp, sizeof(usuario), 1, fp);
                    break;
        }
    }
    fclose(fp);
}

            printf("Compra realizada com sucesso!\n");
            printf("Valor recebido: R$ %.2f\n", valor_liquido);
            printf("Novo saldo em reais: R$ %.2f\n", lista->saldo_reais);
            printf("Saldo de %s: %.2f\n", moeda.nome, quantidade_venda);

            break;
        }
        if (remover_saldo_cripto(lista, nome, quantidade_venda)) {
        lista->saldo_reais += valor_liquido;
        } else {
        printf("Saldo insuficiente ou cripto não encontrada.\n");
        }
    }

    fclose(arq);

    if (!encontrado) {
        printf("Criptomoeda não encontrada.\n");
    }
}
