#define TAM_CPF 11
#define TAM_SENHA 4
#define QTDE_INV 100
#define TAM_CRIPTO 50

// structs
typedef struct { 
    char login[TAM_CPF + 1];
    char nome[50];
    char senha[TAM_SENHA];
    float saldo;
} usuario;

typedef struct {
    usuario* vetor[QTDE_INV];
    int qtde;
} investidor;


typedef struct {
    char nome[TAM_CRIPTO];
    float cotacao_inicial;
    float taxa_compra;
    float taxa_venda;
} cripto;

// menu.c
int menu_adm();

// investidor_cadastrar.c
void cadastrar_investidor();

// investidor_excluir.c
void excluir_inv();
int excluir_investidor_arquivo(const char *login);

// investidor_login.c
int senha_valida(const char *);
int login_existe(const char *login);


// cripto_existe.c
int cripto_existe(const char *);


//cripto_cadastro.c
void cadastrar_cripto();


// cripto_excluir.c
void excluir_cripto();


// consultar_saldo.c
void consultar_saldo();
