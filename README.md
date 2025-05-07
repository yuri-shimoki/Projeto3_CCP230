# Projeto 3 de CCP230

## Objetivo

O objetivo deste projeto é criar um programa gerenciador de um estoque de produtos.

Esse programa deve atender aos seguintes requisitos:
- Cadastro de Produtos: O sistema deve permitir o cadastro de produtos com informações como código, nome, descrição, quantidade em estoque e preço unitário.
- Controle de Entrada e Saída de Produtos: Deve ser possível registrar a entrada (compra) e saída (venda) de produtos, alterando a quantidade em estoque de acordo com essas operações.
- Consulta de Estoque: O sistema deve permitir a consulta dos produtos em estoque, com a possibilidade de pesquisar por código ou nome.
- Relatório de Estoque: O sistema deve gerar relatórios simples com a listagem de todos os produtos em estoque, mostrando informações como nome, quantidade disponível e preço total (quantidade * preço unitário). Estes relatórios devem ser salvos em um arquivo de texto simples.
Persistência de Dados: Os dados dos produtos devem ser armazenados em arquivos binários para garantir que, ao fechar o programa, as informações não se percam.
- Interface Simples: O programa deve oferecer uma interface de linha de comando (CLI) que seja intuitiva e fácil de usar, com menus para navegação.

## Compilação e Execução

Para compilar o projeto, primeiramente utilize o comando:

```cd <caminho da pasta raiz>```

Para ir até a pasta raiz do projeto, e, em seguida, utilize o comando:

```gcc -Ofast -I headers/ src/*.c -o aplicativo```

Para compilar o projeto e produzir um executável chamado `aplicativo.exe`, no Windows.

Após isso, para executar o programa, basta escrever a seguinte linha no terminal:

```.\aplicativo.exe```

## Como Usar o Programa

O programa começa no menu principal, que permite que você escolha qual ação deseja realizar dentre visualizar estoque; cadastrar, comprar e vender produto; e gerar relatório de estoque.

A visualização de estoque pode ser feita por código do produto ou pelo seu nome. O cadastramento de produto irá pedir que você digite o nome, descrição, quantidade em estoque e valor unitário do produto. Comprar um produto irá fazer sua quantidade em estoque aumentar, enquanto vender um produto irá fazê-la diminuir.

O relatório de estoque é um arquivo `.txt` listando todos os produtos no estoque, suas informações e o valor total em estoque de cada produto (quantidade em estoque * valor unitário).

## Participantes do Projeto

Yuri da Silva Shimoki, RA: 24.224.002-6.
