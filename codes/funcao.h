// Funções para o código do investidor
#define TAM_CPF 11
#define TAM_SENHA 4

typedef struct { // Struct do usuário
    char login[TAM_CPF + 1];    // +1 para o '\0'
    char senha[TAM_SENHA + 1];
} usuario;


typedef struct { // Struct para valores da carteira e cotações
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


void consultar_saldo(cotacao *);

void vender_criptomoedas(cotacao *);

int login(usuario *user);

int menu_inv();

void deposito(cotacao *, usuario *);

int cripto();

void comprar_criptomoedas(cotacao *, usuario *);

void atualizar_cotacao_bit(cotacao *);

void atualizar_cotacao_eth(cotacao *);

void atualizar_cotacao_rip(cotacao *);

void sacar(cotacao *, usuario *);

void atual_datahora(char *destino, int tamanho);

void vender_criptomoedas(cotacao *);

void extrato(cotacao *);


void menuInvestidor();

// Funções para o código do administrador
#define TAM_CPF 11
#define TAM_SENHA 4
#define QTDE_INV 100

typedef struct {
    usuario* vetor[QTDE_INV];
    int qtde;
} investidor;

usuario *cadastro_investidor();
int cadastrar_investidor (investidor *);
int excluir_inv(investidor *);
int senha_valida(const char *);
int login_existe(const char *login);
int excluir_investidor_arquivo(const char *login);

void menuAdministrador();

int menu_principal();
int menu_adm();
int cripto();