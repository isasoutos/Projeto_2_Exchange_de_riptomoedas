// Funções para o código do investidor
#define TAM_CPF 11
#define TAM_SENHA 4
#define QTDE_INV 100
#define TAM_CRIPTO 30

// Struct do usuário
typedef struct { 
    char login[TAM_CPF + 1];
    char senha[TAM_SENHA + 1];
} usuario;

typedef struct {
    usuario* vetor[QTDE_INV];
    int qtde;
} investidor;

//typedef struct {
//    char nome[TAM_CRIPTO];
//    float cotacao_inicial;
//    float taxa_compra;
//    float taxa_venda;
//} criptomoeda;

// Struct para valores da carteira e cotações
typedef struct { 
    float bitcoin;
    float ethereum;
    float ripple;
    float saldo_reais;
    float saldo_bit;
    float saldo_eth;
    float saldo_rip;
    char historico [100][100];
    int total_operacao;
} cotacao;

//Funções para o código do investidor para realizar depósito, saque e a visualização do saldo do arquivo deposito_saque.c
void consultar_saldo(cotacao *);
void sacar(cotacao *, usuario *);
void deposito(cotacao *, usuario *);

//Funções para o código do investidor realizar a compra e venda de criptomoedas do arquivo comprar_vender_criptomoedas.c
void vender_criptomoedas(cotacao *);
void comprar_criptomoedas(cotacao *, usuario *);

//Funções para o código do investidor realizar o login do arquivo login.c
int login(usuario *user);

//Funções para o código do investidor realizar a atualização da data e hora do arquivo atualizar_datahora.c
void atual_datahora(char *destino, int tamanho);

//Funções para o código do investidor realizar a visualização do extrato do arquivo extrato.c
void extrato(cotacao *);

//Funções para o código do investidor de atualizar as cotações do arquivo atualizar_cotacao.c
void atualizar_cotacao_bit(cotacao *);
void atualizar_cotacao_eth(cotacao *);
void atualizar_cotacao_rip(cotacao *);

// Funções para o código do administrador para cadastrar e excluir os investidores do arquivo cadastro_excluir_inv.c
usuario *cadastro_investidor();
int cadastrar_investidor (investidor *);
int excluir_inv(investidor *);
int senha_valida(const char *);
int login_existe(const char *login);
int excluir_investidor_arquivo(const char *login);

// Funções de menu do código do arquivo menu.c
int menu_adm();
int menu_cripto();
int menu_inv();