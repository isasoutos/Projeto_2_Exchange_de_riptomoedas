typedef struct 
{
    float bitcoin;
    float ethereum;
    float ripple;
    float saldo_reais;
    float saldo_bit;
    float saldo_eth;
    float saldo_rip;
    int qtde;
} cotacao;

void consultar_saldo(cotacao *);

int menu();

void deposito(cotacao *);