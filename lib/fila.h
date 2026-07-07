#ifndef FILAPRIORIDADE_H
#define FILAPRIORIDADE_H

#define MAX 100

typedef struct
{
    char dado;
    int prioridade;
} Elemento;

typedef struct filaPrioridade FilaPrioridade;

FilaPrioridade *criaFila();

void liberaFila(FilaPrioridade *fp);

int filaVazia(FilaPrioridade *fp);

int filaCheia(FilaPrioridade *fp);

// Insere elemento
int inserir(FilaPrioridade *fp, int dado, int prioridade);

// Remove elemento de maior prioridade
int remover(FilaPrioridade *fp, char *letra, int *prioridade);

// Consulta elemento de maior prioridade
int consultar(FilaPrioridade *fp, Elemento *e);

#endif