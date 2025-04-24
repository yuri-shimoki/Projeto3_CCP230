#include "funcoes_principais.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int menuPrincipal(void)
{
        printf("---[MENU PRINCIPAL]---\nDigite qual opcao abaixo deseja realizar:\n1. Consultar estoque\n2. Comprar produto\n3. Vender produto\n4. Cadastrar produto\n5. Gerar relatorio de estoque\n0. Sair\nDigite um numero: ");

        int opcaoDigitada;
        scanf("%i", &opcaoDigitada);

        printf("\n");

        if (opcaoDigitada < 0 || opcaoDigitada > 5)
        {
                puts("O valor digitado nao e um numero de 0 a 5.\n");
                pressioneEnterParaContinuar();
                return -2;
        }

        return opcaoDigitada;
}

int consultarEstoque(ListaDeProdutos* listaDeProdutos)
{
        printf("Qual tipo de pesquisa deseja realizar?\n1. Por nome do produto\n2. Por codigo do produto\nDigite sua resposta: ");
        int opcaoDigitada;
        scanf("%i", &opcaoDigitada);

        printf("\n");

        if (opcaoDigitada < 1 || opcaoDigitada > 2)
        {
                puts("O valor digitado nao e um numero de 1 a 2.\n");
                pressioneEnterParaContinuar();
                return -2;
        }

        if (opcaoDigitada == 1)
        {
                printf("Digite o nome do produto: ");

                char nomeDoProduto[255];
                scanf(" %254s", nomeDoProduto);

                char* primeiroNaoEspaco = NULL;
                for (char* c = nomeDoProduto; *c != '\0'; ++c)
                {
                        if (*c == ' ')
                                continue;

                        if (primeiroNaoEspaco == NULL)
                                primeiroNaoEspaco = c;

                        *c = tolower(*c);
                }

                Produto produtoRequisitado;
                int codigoDeRetorno;
                codigoDeRetorno = buscarProdutoPorNome(primeiroNaoEspaco, listaDeProdutos, &produtoRequisitado);

                if (codigoDeRetorno < 0)
                {
                        puts("O codigo digitado nao corresponde a um produto existente.\n");
                        pressioneEnterParaContinuar();
                        return -3;
                }

                printf("---[Resultado da Consulta]---\nCodigo do produto: %i\nNome do produto: %s\nPreco unitario: %f\nQuantidade em estoque: %i\nDescricao: %s\n\n",
                        produtoRequisitado.codigo,
                        produtoRequisitado.nome,
                        produtoRequisitado.precoUnitario,
                        produtoRequisitado.quantidadeEmEstoque,
                        produtoRequisitado.descricao);
        }

        if (opcaoDigitada == 2)
        {
                printf("Digite o codigo do produto: ");
                scanf("%i", &opcaoDigitada);

                Produto produtoRequisitado;
                int codigoDeRetorno;
                codigoDeRetorno = buscarProdutoPorCodigo(opcaoDigitada, listaDeProdutos, &produtoRequisitado);

                if (codigoDeRetorno < 0)
                {
                        puts("O codigo digitado nao corresponde a um produto existente.\n");
                        pressioneEnterParaContinuar();
                        return -3;
                }

                printf("---[Resultado da Consulta]---\nCodigo do produto: %i\nNome do produto: %s\nPreco unitario: %f\nQuantidade em estoque: %i\nDescricao: %s\n\n",
                        produtoRequisitado.codigo,
                        produtoRequisitado.nome,
                        produtoRequisitado.precoUnitario,
                        produtoRequisitado.quantidadeEmEstoque,
                        produtoRequisitado.descricao);
        }
        
        return 0;
}

int comprarProduto(ListaDeProdutos* listaDeProdutos)
{
        int codigoDoProduto;
        printf("Digite o codigo do produto: ");
        scanf("%i", &codigoDoProduto);

        Produto produtoRequisitado;
        int codigoDeRetorno;
        codigoDeRetorno = buscarProdutoPorCodigo(codigoDoProduto, listaDeProdutos, &produtoRequisitado);

        if (codigoDeRetorno < 0)
        {
                puts("O codigo digitado nao corresponde a um produto existente.\n");
                pressioneEnterParaContinuar();
                return -1;
        }

        int quantidadeASerComprada;
        printf("Digite a quantidade que deseja comprar: ");
        scanf("%i", &quantidadeASerComprada);

        if (quantidadeASerComprada > produtoRequisitado.quantidadeEmEstoque)
        {
                puts("Nao e possivel comprar mais produtos do que ha em estoque.\n");
                pressioneEnterParaContinuar();
                return -2;
        }

        if (quantidadeASerComprada < 0)
        {
                puts("Nao e possivel comprar uma quantidade negativa de produtos.\n");
                pressioneEnterParaContinuar();
                return -3;
        }

        listaDeProdutos->produtos[codigoDeRetorno].quantidadeEmEstoque -= quantidadeASerComprada;

        return 0;
}

int venderProduto(ListaDeProdutos* listaDeProdutos)
{
        int codigoDoProduto;
        printf("Digite o codigo do produto: ");
        scanf("%i", &codigoDoProduto);

        Produto produtoRequisitado;
        int codigoDeRetorno;
        codigoDeRetorno = buscarProdutoPorCodigo(codigoDoProduto, listaDeProdutos, &produtoRequisitado);

        if (codigoDeRetorno < 0)
        {
                puts("O codigo digitado nao corresponde a um produto existente.\n");
                pressioneEnterParaContinuar();
                return -1;
        }

        int quantidadeASerVendida;
        printf("Digite a quantidade que deseja vender: ");
        scanf("%i", &quantidadeASerVendida);

        if (quantidadeASerVendida < 0)
        {
                puts("Nao e possivel vender uma quantidade negativa de produtos.\n");
                pressioneEnterParaContinuar();
                return -2;
        }

        listaDeProdutos->produtos[codigoDeRetorno].quantidadeEmEstoque += quantidadeASerVendida;

        return 0;
}

int cadastrarProduto(ListaDeProdutos* listaDeProdutos)
{
        Produto produto;

        produto.codigo = 0;
        for (int i = 0; i < listaDeProdutos->quantidadeDeProdutos; ++i)
                if (produto.codigo < listaDeProdutos->produtos[i].codigo)
                        produto.codigo = listaDeProdutos->produtos[i].codigo;

        ++produto.codigo;

        printf("Digite o nome do produto: ");
        
}

void gerarRelatorioDeEstoque(ListaDeProdutos* produto)
{

}

void pressioneEnterParaContinuar(void)
{
        printf("Pressione ENTER para continuar.\n");
        while (getchar() != '\n');
        getchar();
}

int abrirArquivoParaLeituraEEscrita(FILE** arquivo, const char* nome)
{
        *arquivo = fopen(nome, "rb+");
        if (*arquivo == NULL)
        {
                *arquivo = fopen(nome, "wb+");
                if (*arquivo == NULL)
                        return 1;

                rewind(*arquivo);
                return 2;
        }

        return 0;
}