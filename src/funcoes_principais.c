#include "funcoes_principais.h"

#include <stdio.h>

void pressioneEnterParaContinuar(void)
{
        printf("Pressione ENTER para continuar.\n");
        while (getchar() != '\n');
        getchar();
}