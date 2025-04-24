#include "funcoes_principais.h"

#include <stdio.h>

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