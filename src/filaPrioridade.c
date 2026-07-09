#include <stdio.h>
#include <stdlib.h>

typedef struct No 
{
  int chave;
  char val;
  struct No *esq;
  struct No *dir;

  // usado somente na fila
  struct No *prox;
} No;

No * criarNo(char val, int chave)
{
  No* novo = (No*) malloc(sizeof(No));

  novo->chave = chave;
  novo->val = val;
  novo->esq = NULL;
  novo->dir = NULL;

  // usado somente na fila
  novo->prox = NULL;

  return novo;
}

void mostrarNo(No* n)
{
  printf("\nID: %p\n", (void*) n);
  printf("Chave: %d\n", n->chave);
  printf("Valor: %c\n", n->val);
  printf("esq: %p\n", n->esq);
  printf("dir: %p\n", n->dir);
}

typedef struct {
    No * inicio;
    int total;
} FilaPrioridade;

FilaPrioridade criarFila()
{
    FilaPrioridade f;
    f.inicio = NULL;
    f.total = 0;
    return f;
}

int estaVazia(FilaPrioridade f)
{
    return f.total == 0 ? 1 : 0;
}

int push(FilaPrioridade *f, No *no)
{       
    if (no == NULL)
        return 0;

    if (estaVazia(*f))
    {
        no->prox = NULL;
        f->inicio = no;
        f->total++;
        return 1;
    }

    No * anterior = NULL;
    No * atual = f->inicio;

    // operacoes com ponteiros
    while (atual != NULL && atual->chave <= no->chave)
    {
        anterior = atual;
        atual = atual->prox;
    }

    no->prox = atual;

    if (anterior == NULL)
        f->inicio = no;
    else
        anterior->prox = no;

    f->total++;

    return 1;
}

No * pop(FilaPrioridade *f)
{
    if (estaVazia(*f))
        return NULL;
    
    No * no = f->inicio;

    f->inicio = f->inicio->prox;
    f->total--;

    no->prox = NULL;

    return no;
}

int tamanho(FilaPrioridade *f)
{
    return f->total;
}

void destruirFila(FilaPrioridade *f)
{
    No *atual, *anterior;
    atual = f->inicio;

    while (atual != NULL)
    {
        anterior=atual;
        atual=atual->prox;
        free(anterior);
    }

    f->inicio = NULL;
}
