#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "arvoreBinaria.h"

typedef struct Huffman
{
    ArvBin arvore;
} Huffman;

struct Huffman *comprime(char *str);

#endif
