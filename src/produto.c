#include "produto.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

        listaDeProdutos->produtos = (Produto*) malloc(listaDeProdutos->quantidadeDeProdutos);

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

        abrirArquivoParaLeituraEEscrita(arquivoDeEstoque, "estoque.bin");

        fwrite(&listaDeProdutos->quantidadeDeProdutos, sizeof(unsigned int), 1, *arquivoDeEstoque);

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

int buscarProdutoPorNome(const char* nomeDoProduto, ListaDeProdutos* listaDeProdutos, Produto* produtoRequisitado)
{
        for (int i = 0; i < listaDeProdutos->quantidadeDeProdutos; ++i)
        {
                if (strcmp(listaDeProdutos->produtos[i].nome, nomeDoProduto) == 0)
                {
                        *produtoRequisitado = listaDeProdutos->produtos[i];
                        return 0;
                }
        }

        return 1;
}

int buscarProdutoPorCodigo(unsigned int codigoDoProduto, ListaDeProdutos* listaDeProdutos, Produto* produtoRequisitado)
{
        for (int i = 0; i < listaDeProdutos->quantidadeDeProdutos; ++i)
        {
                if (listaDeProdutos->produtos[i].codigo == codigoDoProduto)
                {
                        *produtoRequisitado = listaDeProdutos->produtos[i];
                        return 0;
                }
        }

        return 1;
}