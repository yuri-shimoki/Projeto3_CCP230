#pragma once

#include <stdio.h>

#include "produto.h"

typedef enum
{
        SAIR = 0,
        CONSULTAR_ESTOQUE,
        COMPRAR_PRODUTO,
        VENDER_PRODUTO,
        CADASTRAR_PRODUTO,
        GERAR_RELATORIO_DE_ESTOQUE,
        MENU_PRINCIPAL
} Menus;

int menuPrincipal(void);

int consultarEstoque(ListaDeProdutos* listaDeProdutos);

int comprarProduto(ListaDeProdutos* listaDeProdutos);
int venderProduto(ListaDeProdutos* listaDeProdutos);

int cadastrarProduto(ListaDeProdutos* listaDeProdutos);
void gerarRelatorioDeEstoque(ListaDeProdutos* produto);

void pressioneEnterParaContinuar(void);
int abrirArquivoParaLeituraEEscrita(FILE** arquivo, const char* nome);
void trim(char* string, int* indiceInicial, int* indiceFinal);