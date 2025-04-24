#include "funcoes_principais.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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

                char nomeDoProduto[255], nomeDoProdutoTrimmed[255];
                scanf(" %254s", nomeDoProduto);

                int indiceInicial, indiceFinal;
                trim(nomeDoProduto, &indiceInicial, &indiceFinal);

                for (int i = indiceInicial; i != indiceFinal + 1; ++i)
                        nomeDoProdutoTrimmed[i - indiceInicial] = tolower(nomeDoProduto[i]);
                
                nomeDoProdutoTrimmed[indiceFinal + 1 - indiceInicial] = '\0';

                Produto produtoRequisitado;
                int codigoDeRetorno;
                codigoDeRetorno = buscarProdutoPorNome(nomeDoProdutoTrimmed, listaDeProdutos, &produtoRequisitado);

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

        char nomeDoProduto[255];
        scanf(" %254s", nomeDoProduto);

        int indiceInicial, indiceFinal;
        trim(nomeDoProduto, &indiceInicial, &indiceFinal);

        for (int i = indiceInicial; i != indiceFinal + 1; ++i)
                produto.nome[i - indiceInicial] = tolower(nomeDoProduto[i]);
        
        produto.nome[indiceFinal + 1 - indiceInicial] = '\0';

        printf("Digite o preco unitario do produto: ");

        int n;
        n = scanf("%f", &produto.precoUnitario);

        if (n == 0 || produto.precoUnitario < 0.0f)
        {
                puts("O preco unitario digitado e invalido.\n");
                pressioneEnterParaContinuar;
                return -1;
        }

        printf("Digite a quantidade em estoque do produto: ");

        n = scanf("%i", &produto.quantidadeEmEstoque);

        if (n == 0)
        {
                puts("A quantidade em estoque digitada e invalida.\n");
                pressioneEnterParaContinuar;
                return -2;
        }

        printf("Digite a descricao do produto: ");
        scanf(" %1022s", produto.descricao);

        ++listaDeProdutos->quantidadeDeProdutos;
        Produto* novoBlocoDeProdutos = (Produto*) malloc(listaDeProdutos->quantidadeDeProdutos);
        memcpy(novoBlocoDeProdutos, listaDeProdutos->produtos, sizeof(Produto) * (listaDeProdutos->quantidadeDeProdutos - 1));

        free(listaDeProdutos->produtos);
        listaDeProdutos->produtos = novoBlocoDeProdutos;

        listaDeProdutos->produtos[listaDeProdutos->quantidadeDeProdutos-1] = produto;

        return 0;
}

int gerarRelatorioDeEstoque(ListaDeProdutos* listaDeProdutos)
{
        FILE* arquivoDeRelatorio = fopen("relatorio.txt", "w");

        if (ferror(arquivoDeRelatorio) != 0)
        {
                puts("Falha ao abrir arquivo de relatorio.\n");
                pressioneEnterParaContinuar();
                return -1;
        }

        for (int i = 0; i < listaDeProdutos->quantidadeDeProdutos; ++i)
        {
                Produto produto = listaDeProdutos->produtos[i];

                fprintf(arquivoDeRelatorio, "------------------------\nCodigo do produto: %i\nNome do produto: %s\nPreco unitario: %f\nQuantidade em estoque: %i\nValor total: %f\nDescricao: %s\n\n",
                        produto.codigo,
                        produto.nome,
                        produto.precoUnitario,
                        produto.quantidadeEmEstoque,
                        produto.precoUnitario * ((float) produto.quantidadeEmEstoque),
                        produto.descricao);

                if (ferror(arquivoDeRelatorio) != 0)
                {
                        puts("Falha ao escrever no arquivo de relatorio.\n");
                        pressioneEnterParaContinuar();
                        return -2;
                }
        }
        
        return 0;
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

void trim(char* string, int* indiceInicialPtr, int* indiceFinalPtr)
{
        int indiceInicial = 0;
        for (char* c = string; *c != '\0'; ++c)
        {
                if (*c == ' ')
                        ++indiceInicial;
                else
                        break;
        }

        int indiceFinal = strlen(string) - 1;
        for (char* c = &string[indiceFinal]; *c != indiceInicial; --c)
        {
                if (*c == ' ')
                        --indiceFinal;
                else
                        break;
        }

        *indiceInicialPtr = indiceInicial;
        *indiceFinalPtr = indiceFinal;
}