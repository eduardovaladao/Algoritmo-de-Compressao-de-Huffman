#include <stdio.h>
#include <stdlib.h>
#include "../lib/ArvoreBinaria.h"

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
	novo->dir->info = letra_primeiro_menor;
	novo->dir->freq = prioridade_primeiro_menor;
	novo->dir->info = letra_segundo_menor;
	novo->dir->freq = prioridade_segundo_menor;

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