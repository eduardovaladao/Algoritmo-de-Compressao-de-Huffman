#include <stdio.h>
#include "../lib/huffman.h"
#include "../lib/arvoreBinaria.h"

static void imprimeArvore(ArvBin raiz, int nivel)
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

static void imprimeCodigos(ArvBin raiz)
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

int main()
{
    char str[200];
    struct Huffman *h;

    printf("Digite a palavra: ");
    scanf("%s", str);

    h = comprime(str);

    printf("\nArvore de Huffman:\n");
    imprimeArvore(h->arvore, 0);

    printf("\nCodigos:\n");
    imprimeCodigos(h->arvore);

    return 0;
}
