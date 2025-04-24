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

        Menus menuAtual = MENU_PRINCIPAL;

        while (menuAtual != SAIR)
        {
                switch (menuAtual)
                {
                case MENU_PRINCIPAL:
                        codigoDeRetorno = menuPrincipal();
                        menuAtual = codigoDeRetorno;

                        if (codigoDeRetorno < 0)
                                menuAtual = MENU_PRINCIPAL;
                        
                        break;
                case CONSULTAR_ESTOQUE:
                        consultarEstoque(&listaDeProdutos);
                        menuAtual = MENU_PRINCIPAL;
                        break;
                case COMPRAR_PRODUTO:
                        comprarProduto(&listaDeProdutos);
                        menuAtual = MENU_PRINCIPAL;
                        break;
                case VENDER_PRODUTO:
                        venderProduto(&listaDeProdutos);
                        menuAtual = MENU_PRINCIPAL;
                        break;
                case CADASTRAR_PRODUTO:
                        cadastrarProduto(&listaDeProdutos);
                        menuAtual = MENU_PRINCIPAL;
                        break;
                case GERAR_RELATORIO_DE_ESTOQUE:
                        gerarRelatorioDeEstoque(&listaDeProdutos);
                        menuAtual = MENU_PRINCIPAL;
                        break;
                }
        }

        codigoDeRetorno = salvarListaDeProdutos(&arquivoDeEstoque, &listaDeProdutos);

        switch (codigoDeRetorno)
        {
        case 1:
        case 2:
        case 3:
                return 4;
                break;
        }

        free(listaDeProdutos.produtos);
        fclose(arquivoDeEstoque);

        return 0;
}