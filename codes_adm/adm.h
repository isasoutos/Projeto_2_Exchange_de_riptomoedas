#define TAM_CPF 11
#define TAM_SENHA 4
#define QTDE_INV 100

typedef struct {
    char login[TAM_CPF + 1];
    char senha[TAM_SENHA + 1];
} cadastro_inv;

typedef struct {
    cadastro_inv* vetor[QTDE_INV];
    int qtde;
} investidor;

int menu();

cadastro_inv *cadastro_investidor();
int cadastrar_investidor (investidor *, cadastro_inv *);
int excluir_inv(investidor *);