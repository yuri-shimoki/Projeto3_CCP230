#pragma once

#include <stdio.h>

#include "produto.h"

int consultarEstoque(ListaDeProdutos* listaDeProdutos);

int comprarProduto(ListaDeProdutos* listaDeProdutos);
int venderProduto(ListaDeProdutos* listaDeProdutos);

int cadastrarProduto(ListaDeProdutos* listaDeProdutos);
void gerarRelatorioDeEstoque(ListaDeProdutos* produto);

void pressioneEnterParaContinuar(void);