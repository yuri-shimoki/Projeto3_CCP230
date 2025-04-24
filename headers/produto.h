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

int carregarDadosDeProduto(FILE* arquivoDeEstoque, const char* nomeDoProduto);
int carregarDadosDeProduto(FILE* arquivoDeEstoque, unsigned int codigoDoProduto);
int salvarDadosDeProduto(FILE* arquivoDeEstoque, Produto* produto);