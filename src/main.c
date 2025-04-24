#include <stdio.h>
#include <stdlib.h>

#include "funcoes_principais.h"
#include "produto.h"

int main(void)
{
        int codigoDeRetorno;

        FILE* arquivoDeEstoque;
        codigoDeRetorno = abrirArquivoParaLeituraEEscrita(&arquivoDeEstoque, "estoque.bin");

        switch (codigoDeRetorno)
        {
        case 1:
                puts("Nao foi possivel abrir o arquivo de estoque.");
                return 1;
                break;
        case 2:
                unsigned int temp = 0;
                fwrite(&temp, sizeof(unsigned int), 1, arquivoDeEstoque);
                if (ferror(arquivoDeEstoque) != 0)
                {
                        puts("Erro ao escrever valor padrao para o arquivo de estoque.");
                        return 2;
                }
                break;
        }

        ListaDeProdutos listaDeProdutos;

        codigoDeRetorno = carregarListaDeProdutos(arquivoDeEstoque, &listaDeProdutos);

        switch (codigoDeRetorno)
        {
        case 1:
        case 2:
                return 3;
                break;
        }

        

        free(listaDeProdutos.produtos);
        fclose(arquivoDeEstoque);

        return 0;
}