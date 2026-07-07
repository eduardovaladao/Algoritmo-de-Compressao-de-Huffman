#ifndef FILAPRIORIDADE_H
#define FILAPRIORIDADE_H

#include "arvoreBinaria.h"

#define MAX 100

typedef struct
{
    ArvBin no;
    int prioridade;
} Elemento;

typedef struct filaPrioridade FilaPrioridade;

FilaPrioridade *criaFila();

void liberaFila(FilaPrioridade *fp);

int filaVazia(FilaPrioridade *fp);

int filaCheia(FilaPrioridade *fp);

// Insere elemento
int inserir(FilaPrioridade *fp, ArvBin no, int prioridade);

// Remove elemento de menor prioridade
int remover(FilaPrioridade *fp, ArvBin *no, int *prioridade);

int tamanhoFila(FilaPrioridade *fp);

// Consulta elemento de maior prioridade
int consultar(FilaPrioridade *fp, Elemento *e);

#endif