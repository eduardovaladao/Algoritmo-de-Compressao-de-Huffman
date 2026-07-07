#include <stdio.h>
#include <stdlib.h>
#include "../lib/fila.h"
#include "../lib/arvoreBinaria.h"
#include "../lib/huffman.h"

struct Huffman *comprime(char *str)
{
    FilaPrioridade *fila = criaFila();
    ArvBin *arvore = cria_ArvBin();
    char letra_primeiro_menor, letra_segundo_menor;
    int prioridade_primeiro_menor, prioridade_segundo_menor;
    ArvBin arvore_primeiro, arvore_segundo;
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

        inserir(fila, str[i], contador, NULL);
    }

    while (1)
    {
        if (!remover(fila, &letra_primeiro_menor, &prioridade_primeiro_menor, &arvore_primeiro))
            break;

        if (!remover(fila, &letra_segundo_menor, &prioridade_segundo_menor, &arvore_segundo))
        {
            inserir(fila, letra_primeiro_menor, prioridade_primeiro_menor, arvore_primeiro);
            break;
        }

        insere_ArvBin(arvore, prioridade_primeiro_menor + prioridade_segundo_menor,
                      letra_primeiro_menor, prioridade_primeiro_menor,
                      letra_segundo_menor, prioridade_segundo_menor,
                      arvore_primeiro, arvore_segundo);

        inserir(fila, '#', prioridade_primeiro_menor + prioridade_segundo_menor, *arvore);
    }

    struct Huffman *huff = (struct Huffman *)malloc(sizeof(struct Huffman));
    huff->arvore = *arvore;

    liberaFila(fila);
    free(arvore);

    return huff;
}
