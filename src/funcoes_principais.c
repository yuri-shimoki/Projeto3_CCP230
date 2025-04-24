#include "funcoes_principais.h"

#include <stdio.h>

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
                return 0;
        }

        return 0;
}