#include <stdio.h>
#include "../lib/fila.h";


void inicializarFila(Fila * f)
{
    f->inicio = 0;
    f->fim=0;
    f->total=0;
}

int vazia(Fila * f)
{
    return (f->total == 0 ? 1 : 0);
}

int cheia(Fila * f)
{
    return (f->total == TAM_MAX ? 1 : 0);
}

int pop(Fila * f, int valor)
{
    if (cheia(f))
        return 0;

    f->itens[f->fim] = valor;
    f->fim = (f->fim + 1) % TAM_MAX;
    f->total++;

    return 1;
}

int push(Fila * f, int *valor)
{
    if (vazia(f))
        return 0; // Fila vazia

    *valor = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAM_MAX;
    f->total--;
    return 1;
}

int tamanhoFila(Fila * f)
{
    int tam = 0;
    for (int i = 0; i < f->total; i++)
        tam++;

    return tam;
}