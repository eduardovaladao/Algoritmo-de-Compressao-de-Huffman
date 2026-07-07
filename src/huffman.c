#include <stdio.h>
#include <stdlib.h>
#include "../lib/fila.h"
#include "../lib/arvoreBinaria.h"
#include "../lib/huffman.h"

struct Huffman *comprime(char *str)
{
    FilaPrioridade *fila = criaFila();
    ArvBin esq, dir, raiz;
    int prioridade_esq, prioridade_dir, prioridade_raiz;
    int i, j, k, contador, ja_inserido;

    for (i = 0; str[i] != '\0'; i++)
    {
        ja_inserido = 0;
        for (k = 0; k < i; k++)
            if (str[k] == str[i])
            {
                ja_inserido = 1;
                break;
            }
        if (ja_inserido)
            continue;

        contador = 0;
        for (j = 0; str[j] != '\0'; j++)
            if (str[j] == str[i])
                contador++;

        inserir(fila, criarFolha(str[i], contador), contador);
    }

    while (tamanhoFila(fila) > 1)
    {
        remover(fila, &esq, &prioridade_esq);
        remover(fila, &dir, &prioridade_dir);
        inserir(fila, unirNos(esq, dir), prioridade_esq + prioridade_dir);
    }

    raiz = NULL;
    if (!filaVazia(fila))
        remover(fila, &raiz, &prioridade_raiz);

    struct Huffman *huff = (struct Huffman *)malloc(sizeof(struct Huffman));
    huff->arvore = raiz;

    liberaFila(fila);

    return huff;
}
