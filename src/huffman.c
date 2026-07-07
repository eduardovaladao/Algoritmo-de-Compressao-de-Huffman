#include <stdio.h>
#include <stdlib.h>
#include "../lib/fila.h"
#include "../lib/arvoreBinaria.h"

typedef struct Huffman
{
    ArvBin arvore;
    int codigo;
} Huffman;

struct Huffman *comprime(char *str)
{
    FilaPrioridade *fila = criaFila();
    ArvBin *arvore = cria_ArvBin();
    int codigo;

    for (int i = 0; str[i] != '\0'; i++)
    {
        int contador = 1;

        for (int j = 0; str[j] != '\0'; j++)
            if (str[j] == str[i])
                contador++;

        inserir(&fila, str[i], contador);
    }

    while (filaVazia(&fila) != 0)
    {
        char letra_primeiro_menor, letra_segundo_menor;
        int prioridade_primeiro_menor, prioridade_segundo_menor;

        remover(&fila, &letra_primeiro_menor, &prioridade_primeiro_menor);
        remover(&fila, &letra_segundo_menor, &prioridade_segundo_menor);

        int soma_prioridade = prioridade_primeiro_menor + prioridade_segundo_menor;

        insere_ArvBin(arvore, soma_prioridade, letra_primeiro_menor, prioridade_primeiro_menor, letra_segundo_menor, prioridade_segundo_menor);

        inserir(&fila, '#', soma_prioridade);
    }

    struct Huffman *huff = (Huffman *)malloc(sizeof(Huffman));
    huff->arvore = arvore;
    huff->codigo = codigo;

    return huff;
}

// Huffman(frequencias)

//     fila = criarFilaPrioridade()

//                para cada símbolo
//            criar nó
//            inserir na fila

//            enquanto tamanho(fila) > 1

//            x = removerMenor(fila)
//                y = removerMenor(fila)

//                    z = novoNo()

//                            z.freq = x.freq + y.freq

//                                              z.esq = x z.dir = y

//     inserir(fila, z)

// retornar removerMenor(fila)