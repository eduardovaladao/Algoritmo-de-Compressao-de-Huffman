#include <stdio.h>
#include <stdlib.h>

typedef struct No 
{
  int chave;
  char val;
  struct No *esq;
  struct No *dir;
} No;

No * criarNo(char val, int chave)
{
  No* novo = (No*) malloc(sizeof(No));

  novo->chave = chave;
  novo->val = val;
  novo->esq = NULL;
  novo->dir = NULL;

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