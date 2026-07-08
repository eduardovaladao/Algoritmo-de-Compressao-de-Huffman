#ifndef ARVORE_HUFFMAN
#define ARVORE_HUFFMAN

#include <stdlib.h>
#include <string.h>

#include "../libraries/no.h"
#include "../libraries/filaPrioridade.h"

No* criarArv(FilaPrioridade *f);

// mostra arvore
void mostrarArvore(No* n);

//Compreesão simples para o print
void huffman(char *input, int verbosity, int simple_out);

#endif