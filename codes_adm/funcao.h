#define TAM_CPF 11
#define TAM_SENHA 4
#define QTDE_INV 100
#define TAM_CRIPTO 50

// structs
typedef struct { 
    char login[TAM_CPF + 1];
    char senha[TAM_SENHA + 1];
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

typedef struct {
    char cpf[TAM_CPF + 1];
    char nome[50];
    float saldo;
} investidor_individual;


void listar_investidores();

// menu.c
int menu_adm();


// investidor_cadastrar.c
usuario *cadastro_investidor();
void cadastrar_investidor();


// investidor_excluir.c
int excluir_inv(investidor *);
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
