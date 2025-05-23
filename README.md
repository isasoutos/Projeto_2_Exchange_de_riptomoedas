Curso: Ciência de Dados e Inteligência Artificial - CCP230

 - ISABELLE SANTOS SOUZA - 52.224.001-9 
 - MAYUMI K. KOBAYASHI HERNANDES - 52.224.007-6

## O projeto
   - Um projeto de simulação de uma **Exchange de Criptomoedas** desenvolvida em linguagem C.
   - O sistema permite que investidores realizem operações de compra e venda de criptomoedas através de um menu interativo.
   - O sistema também permite que os administradores cadastrem e excluam novas criptomoedas e investidores. Permitindo que acessem informações dos investidores com saldo e extrato.

## Descrição
- Uma **criptomoeda** é um tipo de dinheiro vitual **não emitida por nenhum governo**. Esta aplicação simula uma exchange que trabalha com as seguintes criptomoedas:
   - Bitcoin
   - Ethereum
   - Ripple
- Nosso código permite que os usuários realizem operações como login(sendo cadastrado pelo administrador), consulta de saldo, depósito, saque, compra e venda de moedas, com taxas definidas para cada criptomoeda e a atualização do valor das cotações.

## Funcionalidade
#### Investidor
- Login do investidor criar no código do administrador, entretanto se quiser pode ser utilizado (login: 12345678998 - senha:1234)
- Consultar saldo da carteira (reais, bitcoin, ethereum, ripple).  
- Consultar extrato de operações. 
- Consultar extrato de operações.
- Depositar reais na carteira (com validação da senha).
- Sacar reais (com validação de senha).
- Comprar criptomoedas (com taxas e confirmação). 
- Vender criptomoedas (com taxas e confirmação).
- Atualizar cotação das moedas (variação entre -5% e +5%). 
- Persistência dos dados em arquivos binários.

#### Administrador
 - Login do administrador: administrador - senha: 4321
 - Cadastrar novos investidores (nome, login e senha).
 - Excluir investidor (somente informar seu login e pedirá confirmação).
 - Cadastro de criptomoedas (nome da cripto, taxas de venda e compra).
 - Excluir criptomoeda (informar o nome para excluir e pedirá confirmação).
 - Consultar saldo do investidor (quando informar o login mostrará o saldo em reias).
 - Consultar extrato de um investidor (quando informar o login mostrará as movimentações).
 - Atualizar cotação das moedas (variação entre -5% e +5%).

## Taxas de transação
   - Bitcoin - Taxa de compra: 2% - Taxa de Venda: 3%
   - Ethereum - Taxa de compra: 1% - Taxa de Venda: 2%
   - Ripple - Taxa de compra: 1% - Taxa de Venda: 1%
   - O administrador pode cadastrar qualquer criptomoeda e assim colocando a taxa de venda e de compra

## Tecnologias utilizadas
   - Linguagem C
   - Arquivos binários

##  Compilar e rodar
#### Parte do Investidor
   - Acessar a pasta: cd codes_inv
   - Compilar o programa: gcc *.c 
   - Execute o sistema: ./a.out
#### Parte do Administrador
   - Acessar a pasta: cd codes_adm
   - Compilar o programa: gcc *.c 
   - Execute o sistema: ./a.out
