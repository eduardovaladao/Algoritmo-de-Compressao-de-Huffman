#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

struct NO
{
	char info;
	int freq;
	struct NO *esq;
	struct NO *dir;
};

typedef struct NO *ArvBin;

ArvBin *cria_ArvBin();

int insere_ArvBin(ArvBin *raiz, int prioridade, char letra_primeiro_menor, int prioridade_primeiro_menor, char letra_segundo_menor, int prioridade_segundo_menor, ArvBin arvore_primeiro, ArvBin arvore_segundo);

int estaVazia_ArvBin(ArvBin *raiz);

int consulta_ArvBin(ArvBin *raiz, int valor);

#endif
