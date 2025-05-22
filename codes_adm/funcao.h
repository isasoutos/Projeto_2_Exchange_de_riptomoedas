#define TAM_CPF 11
#define TAM_SENHA 4
#define QTDE_INV 100
#define TAM_CRIPTO 50

// Struct do usuário
typedef struct { 
    char login[TAM_CPF + 1];
    char senha[TAM_SENHA + 1];
} usuario;

typedef struct {
    usuario* vetor[QTDE_INV];
    int qtde;
} investidor;

// Struct para o cadastro de criptomoedas
typedef struct {
    char nome[TAM_CRIPTO];
    float cotacao_inicial;
    float taxa_compra;
    float taxa_venda;
} cripto;

// Funções de menu do código (arquivo menu.c)
int menu_adm();

// Funções para o código do administrador para cadastrar e excluir os investidores (arquivo cadastro_excluir_inv.c)
usuario *cadastro_investidor();
int cadastrar_investidor (investidor *);
int excluir_inv(investidor *);
int senha_valida(const char *);
int login_existe(const char *login);
int excluir_investidor_arquivo(const char *login);

// Funções do código para o cadastro de criptomoedas (arquivo criptomoedas.c)
int cripto_existe(const char *);
void cadastrar_cripto();
void excluir_cripto();
