# Compilador
CC = gcc

# Arquivos do ADMINISTRADOR
ADMIN_SRC = main_adm.c cadastro_excluir.c menu.c
ADMIN_OUT = adm_programa

# Arquivos do INVESTIDOR
INV_SRC = main_inv.c atualizar_cotacao.c compra_venda.c data_hora.c deposito_saque.c extrato.c login.c menu.c
INV_OUT = inv_programa

# Regra padrão: compilar os dois
all: $(ADMIN_OUT) $(INV_OUT)

# Compilar o programa do administrador
$(ADMIN_OUT): $(ADMIN_SRC)
	$(CC) -o $(ADMIN_OUT) $(ADMIN_SRC)

# Compilar o programa do investidor
$(INV_OUT): $(INV_SRC)
	$(CC) -o $(INV_OUT) $(INV_SRC)

# Limpar arquivos compilados
clean:
	rm -f $(ADMIN_OUT) $(INV_OUT)
