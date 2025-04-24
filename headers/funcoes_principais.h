#pragma once

#include <stdio.h>

#include "produto.h"

typedef enum
{
        MENU_PRINCIPAL,
        CONSULTAR_ESTOQUE,
        COMPRAR_PRODUTO,
        VENDER_PRODUTO,
        GERAR_RELATORIO_DE_ESTOQUE,
        SAIR
} Menus;

int menuPrincipal();

int consultarEstoque(ListaDeProdutos* listaDeProdutos);

int comprarProduto(ListaDeProdutos* listaDeProdutos);
int venderProduto(ListaDeProdutos* listaDeProdutos);

int cadastrarProduto(ListaDeProdutos* listaDeProdutos);
void gerarRelatorioDeEstoque(ListaDeProdutos* produto);

void pressioneEnterParaContinuar(void);
int abrirArquivoParaLeituraEEscrita(FILE** arquivo, const char* nome);