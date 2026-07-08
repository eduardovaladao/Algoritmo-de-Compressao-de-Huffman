#ifndef FILA_PRIORIDADE
#define FILA_PRIORIDADE

#include "../libraries/no.h"

#include <stdlib.h>

typedef struct {
    No * inicio;
    int total;
} FilaPrioridade;

FilaPrioridade criarFila();

int estaVazia(FilaPrioridade f);

int push(FilaPrioridade *f, No *no);

No * pop(FilaPrioridade *f);

int tamanho(FilaPrioridade *f);

void destruirFila(FilaPrioridade *f);

#endif