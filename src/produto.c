#include "produto.h"

#include <stdio.h>

#include "funcoes_principais.h"

int carregarListaDeProdutos(FILE* arquivoDeEstoque, ListaDeProdutos* listaDeProdutos)
{
        rewind(arquivoDeEstoque);

        fread(&listaDeProdutos->quantidadeDeProdutos, sizeof(unsigned int), 1, arquivoDeEstoque);

        if (ferror(arquivoDeEstoque) != 0)
        {
                puts("Erro ao ler a quantidade de produtos no arquivo de estoque.");
                return 1;
        }

        listaDeProdutos->produtos = malloc(listaDeProdutos->quantidadeDeProdutos + 50);

        fread(listaDeProdutos->produtos, listaDeProdutos->quantidadeDeProdutos, 1, arquivoDeEstoque);

        if (ferror(arquivoDeEstoque) != 0)
        {
                puts("Erro ao carregar produtos do arquivo de estoque.");
                return 2;
        }

        return 0;
}

int salvarListaDeProdutos(FILE** arquivoDeEstoque, ListaDeProdutos* listaDeProdutos)
{
        if (remove("estoque.bin") != 0)
        {
                puts("Erro ao sobrescrever arquivo de estoque.");
                return 1;
        }

        abrirArquivoParaLeituraEEscrita(&arquivoDeEstoque, "estoque.bin");

        fwrite(listaDeProdutos->quantidadeDeProdutos, sizeof(unsigned int), 1, *arquivoDeEstoque);

        if (ferror(*arquivoDeEstoque) != 0)
        {
                puts("Erro ao escrever a quantidade de produtos no arquivo de estoque.");
                return 2;
        }

        fwrite(listaDeProdutos->produtos, listaDeProdutos->quantidadeDeProdutos, 1, *arquivoDeEstoque);

        if (ferror(*arquivoDeEstoque) != 0)
        {
                puts("Erro ao salvar produtos no arquivo de estoque.");
                return 3;
        }

        return 0;
}