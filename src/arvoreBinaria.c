#include <stdio.h>
#include <stdlib.h>
#include "../lib/arvoreBinaria.h"

struct NO
{
	char info;
	int freq;
	struct NO *esq;
	struct NO *dir;
};

ArvBin *cria_ArvBin()
{
	ArvBin *raiz = (ArvBin *)malloc(sizeof(ArvBin));
	if (raiz != NULL)
		*raiz = NULL;
	return raiz;
}

int estaVazia_ArvBin(ArvBin *raiz)
{
	if (raiz == NULL)
		return 1;
	if (*raiz == NULL)
		return 1;
	return 0;
}

int insere_ArvBin(ArvBin *raiz, int prioridade, char letra_primeiro_menor, int prioridade_primeiro_menor, char letra_segundo_menor, int prioridade_segundo_menor)
{
	if (raiz == NULL)
		return 0;
	struct NO *novo;
	novo = (struct NO *)malloc(sizeof(struct NO));
	if (novo == NULL)
		return 0;
	novo->info = '#';
	novo->freq = prioridade;
	novo->esq = (struct NO *)malloc(sizeof(struct NO));
	novo->dir = (struct NO *)malloc(sizeof(struct NO));
	if (novo->esq == NULL || novo->dir == NULL)
		return 0;
	novo->esq->info = letra_primeiro_menor;
	novo->esq->freq = prioridade_primeiro_menor;
	novo->esq->esq = NULL;
	novo->esq->dir = NULL;
	novo->dir->info = letra_segundo_menor;
	novo->dir->freq = prioridade_segundo_menor;
	novo->dir->esq = NULL;
	novo->dir->dir = NULL;

	if (*raiz == NULL)
		*raiz = novo;
	// else

	return 1;
}

int consulta_ArvBin(ArvBin *raiz, int valor)
{
	if (raiz == NULL)
		return 0;
	struct NO *atual = *raiz;
	while (atual != NULL)
	{
		if (valor == atual->info)
		{
			return 1;
		}
		if (valor > atual->info)
			atual = atual->dir;
		else
			atual = atual->esq;
	}
	return 0;
}

ArvBin criarFolha(char c, int freq)
{
	struct NO *novo = (struct NO *)malloc(sizeof(struct NO));
	if (novo == NULL)
		return NULL;
	novo->info = c;
	novo->freq = freq;
	novo->esq = NULL;
	novo->dir = NULL;
	return novo;
}

ArvBin unirNos(ArvBin esq, ArvBin dir)
{
	struct NO *novo = (struct NO *)malloc(sizeof(struct NO));
	if (novo == NULL)
		return NULL;
	novo->info = '#';
	novo->freq = esq->freq + dir->freq;
	novo->esq = esq;
	novo->dir = dir;
	return novo;
}

void imprimeArvore(ArvBin raiz, int nivel)
{
	int i;

	if (raiz == NULL)
		return;

	for (i = 0; i < nivel; i++)
		printf("  ");

	if (raiz->info == '#')
		printf("[interno freq=%d]\n", raiz->freq);
	else
		printf("'%c' (freq=%d)\n", raiz->info, raiz->freq);

	imprimeArvore(raiz->esq, nivel + 1);
	imprimeArvore(raiz->dir, nivel + 1);
}

static void imprimeCodigosRec(ArvBin raiz, char codigo[], int profundidade)
{
	if (raiz == NULL)
		return;

	if (raiz->esq == NULL && raiz->dir == NULL)
	{
		codigo[profundidade] = '\0';
		printf("'%c': %s\n", raiz->info, codigo);
		return;
	}

	codigo[profundidade] = '0';
	imprimeCodigosRec(raiz->esq, codigo, profundidade + 1);
	codigo[profundidade] = '1';
	imprimeCodigosRec(raiz->dir, codigo, profundidade + 1);
}

void imprimeCodigos(ArvBin raiz)
{
	char codigo[100];

	if (raiz == NULL)
		return;

	if (raiz->esq == NULL && raiz->dir == NULL)
	{
		printf("'%c': \n", raiz->info);
		return;
	}

	imprimeCodigosRec(raiz, codigo, 0);
}