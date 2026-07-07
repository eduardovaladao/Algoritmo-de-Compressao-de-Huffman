#include <stdio.h>
#include <stdlib.h>
#include "../lib/arvoreBinaria.h"

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

int insere_ArvBin(ArvBin *raiz, int prioridade, char letra_primeiro_menor, int prioridade_primeiro_menor, char letra_segundo_menor, int prioridade_segundo_menor, ArvBin arvore_primeiro, ArvBin arvore_segundo)
{
	struct NO *novo;

	if (raiz == NULL)
		return 0;

	novo = (struct NO *)malloc(sizeof(struct NO));
	if (novo == NULL)
		return 0;

	novo->info = '#';
	novo->freq = prioridade;

	if (arvore_primeiro != NULL)
		novo->esq = arvore_primeiro;
	else
	{
		novo->esq = (struct NO *)malloc(sizeof(struct NO));
		if (novo->esq == NULL)
			return 0;
		novo->esq->info = letra_primeiro_menor;
		novo->esq->freq = prioridade_primeiro_menor;
		novo->esq->esq = NULL;
		novo->esq->dir = NULL;
	}

	if (arvore_segundo != NULL)
		novo->dir = arvore_segundo;
	else
	{
		novo->dir = (struct NO *)malloc(sizeof(struct NO));
		if (novo->dir == NULL)
			return 0;
		novo->dir->info = letra_segundo_menor;
		novo->dir->freq = prioridade_segundo_menor;
		novo->dir->esq = NULL;
		novo->dir->dir = NULL;
	}

	*raiz = novo;

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
