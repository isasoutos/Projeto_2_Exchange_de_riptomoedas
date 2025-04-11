#define TAM_CPF 11
#define TAM_SENHA 4

typedef struct { // Struct do usuário
    char CPF[TAM_CPF + 1];    // +1 para o '\0'
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

int menu();

void deposito(cotacao *, usuario *);

int cripto();

void comprar_criptomoedas(cotacao *, usuario *);

void atualizar_cotacao(cotacao *);

void sacar(cotacao *, usuario *);

void atual_datahora(char *destino, int tamanho);

void vender_criptomoedas(cotacao *);

void extrato(cotacao *);