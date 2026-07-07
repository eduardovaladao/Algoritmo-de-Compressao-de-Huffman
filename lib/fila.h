#ifndef FILAPRIORIDADE_H
#define FILAPRIORIDADE_H

#include "arvoreBinaria.h"

#define MAX 100

typedef struct
{
    char dado;
    int prioridade;
    ArvBin arvore;
} Elemento;

typedef struct filaPrioridade FilaPrioridade;

FilaPrioridade *criaFila();

void liberaFila(FilaPrioridade *fp);

int filaVazia(FilaPrioridade *fp);

int filaCheia(FilaPrioridade *fp);

int inserir(FilaPrioridade *fp, char letra, int prioridade, ArvBin arvore);

int remover(FilaPrioridade *fp, char *letra, int *prioridade, ArvBin *arvore);

int consultar(FilaPrioridade *fp, Elemento *e);

#endif
