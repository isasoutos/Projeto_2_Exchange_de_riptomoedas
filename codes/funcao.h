#define TAM_CPF 11
#define TAM_SENHA 4
#define TAM_EXTRATO 150

typedef struct { // Struct do usuário
    char CPF[TAM_CPF + 1];    // +1 para o '\0'
    char senha[TAM_SENHA + 1];
} usuario;


typedef struct {
    char tipo[30];        
    float valor;
    float taxa;
    char horario[20];  
} Transacao;

typedef struct { // Struct para valores da carteira e cotações
    float bitcoin;
    float ethereum;
    float ripple;
    float saldo_reais;
    float saldo_bit;
    float saldo_eth;
    float saldo_rip;
} cotacao;


void consultar_saldo(cotacao *);

void vender_criptomoedas(cotacao *);

int login(usuario *user);

int menu();

void deposito(cotacao *, usuario *);

int cripto();

void comprar_criptomoedas(cotacao *, usuario *);

void atualizar_cotacao(cotacao *);

void sacar(cotacao *, usuario *);

void atual_datahora();

void registrar_extrato(char extrato[][100], int *qtd, const char *mensagem);

void exibir_extrato(char extrato[][100], int qtd);

