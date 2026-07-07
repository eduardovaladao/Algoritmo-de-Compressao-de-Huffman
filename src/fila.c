#include <stdio.h>
#include <stdlib.h>
#include "../lib/fila.h"

struct filaPrioridade
{
    int quantidade;
    Elemento heap[MAX];
};

static void subir(FilaPrioridade *fp, int i)
{
    int pai;
    Elemento aux;

    while (i > 0)
    {
        pai = (i - 1) / 2;

        if (fp->heap[pai].prioridade <= fp->heap[i].prioridade)
            break;

        aux = fp->heap[pai];
        fp->heap[pai] = fp->heap[i];
        fp->heap[i] = aux;

        i = pai;
    }
}

static void descer(FilaPrioridade *fp, int i)
{
    int filhoEsq, filhoDir, menor;
    Elemento aux;

    while (1)
    {
        filhoEsq = 2 * i + 1;
        filhoDir = 2 * i + 2;
        menor = i;

        if (filhoEsq < fp->quantidade &&
            fp->heap[filhoEsq].prioridade < fp->heap[menor].prioridade)
            menor = filhoEsq;

        if (filhoDir < fp->quantidade &&
            fp->heap[filhoDir].prioridade < fp->heap[menor].prioridade)
            menor = filhoDir;

        if (menor == i)
            break;

        aux = fp->heap[i];
        fp->heap[i] = fp->heap[menor];
        fp->heap[menor] = aux;

        i = menor;
    }
}

FilaPrioridade *criaFila()
{
    FilaPrioridade *fp = (FilaPrioridade *)malloc(sizeof(FilaPrioridade));

    if (fp != NULL)
        fp->quantidade = 0;

    return fp;
}

void liberaFila(FilaPrioridade *fp)
{
    free(fp);
}

int filaVazia(FilaPrioridade *fp)
{
    if (fp == NULL)
        return 1;

    return (fp->quantidade == 0);
}

int filaCheia(FilaPrioridade *fp)
{
    if (fp == NULL)
        return 0;

    return (fp->quantidade == MAX);
}

int inserir(FilaPrioridade *fp, char letra, int prioridade)
{
    if (fp == NULL || filaCheia(fp))
        return 0;

    fp->heap[fp->quantidade].dado = letra;
    fp->heap[fp->quantidade].prioridade = prioridade;

    subir(fp, fp->quantidade);

    fp->quantidade++;

    return 1;
}

int remover(FilaPrioridade *fp, char *letra, int *prioridade)
{
    if (fp == NULL || filaVazia(fp))
        return 0;

    *letra = fp->heap[0].dado;
    *prioridade = fp->heap[0].prioridade;

    fp->heap[0] = fp->heap[fp->quantidade - 1];
    fp->quantidade--;

    descer(fp, 0);

    return 1;
}

int consultar(FilaPrioridade *fp, Elemento *e)
{
    if (fp == NULL || filaVazia(fp))
        return 0;

    *e = fp->heap[0];

    return 1;
}