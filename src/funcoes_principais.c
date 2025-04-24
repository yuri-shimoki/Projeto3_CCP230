#include "funcoes_principais.h"

#include <stdio.h>
#include <ctype.h>

int menuPrincipal(void)
{
        printf("---[MENU PRINCIPAL]---\nDigite qual opcao abaixo deseja realizar:\n1. Consultar estoque\n2. Comprar produto\n3. Vender produto\n4. Gerar relatorio de estoque\n0. Sair\nDigite um numero: ");

        int opcaoDigitada;
        scanf("%i", &opcaoDigitada);

        printf("\n");

        if (isdigit(opcaoDigitada) == 0)
                return -1;

        if (opcaoDigitada < 0 || opcaoDigitada > 4)
                return -2;

        return opcaoDigitada;
}

int cadastrarProduto(ListaDeProdutos* listaDeProdutos)
{
        // Se a quantidade de produtos != 0 e qdp % 50 == 0, alocar mais espaço
}

void pressioneEnterParaContinuar(void)
{
        printf("Pressione ENTER para continuar.\n");
        while (getchar() != '\n');
        getchar();
}

int abrirArquivo(FILE** arquivo, const char* nome)
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