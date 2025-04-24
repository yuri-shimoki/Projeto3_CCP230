#pragma once

#include <stdio.h>

typedef struct
{
        unsigned int codigo;
        char nome[255];
        char descricao[1023];
        unsigned int quantidadeEmEstoque;
        float precoUnitario;
} Produto;

typedef struct
{
        unsigned int quantidadeDeProdutos;
        Produto* produtos;
} ListaDeProdutos;

int carregarListaDeProdutos(FILE* arquivoDeEstoque, ListaDeProdutos* listaDeProdutos);
int salvarListaDeProdutos(FILE** arquivoDeEstoque, ListaDeProdutos* listaDeProdutos);

int buscarProdutoPorNome(const char* nomeDoProduto, Produto* dadosDoProduto);
int buscarProdutoPorCodigo(unsigned int codigoDoProduto, Produto* dadosDoProduto);