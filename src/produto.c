#include "produto.h"

#include <stdio.h>

int carregarListaDeProdutos(FILE* arquivoDeEstoque, ListaDeProdutos* listaDeProdutos)
{
        int codigoDeRetorno;

        rewind(arquivoDeEstoque);

        fread(&listaDeProdutos->quantidadeDeProdutos, sizeof(unsigned int), 1, arquivoDeEstoque);

        if (ferror(arquivoDeEstoque) != 0)
        {
                puts("Erro ao ler a quantidade de produtos no arquivo de estoque.");
                return 1;
        }

        listaDeProdutos->produtos = malloc(listaDeProdutos->quantidadeDeProdutos + 50);

        fread(listaDeProdutos->produtos, listaDeProdutos->quantidadeDeProdutos + 50, 1, arquivoDeEstoque);

        if (ferror(arquivoDeEstoque) != 0)
        {
                puts("Erro ao carregar produtos do arquivo de estoque.");
                return 2;
        }

        return 0;
}