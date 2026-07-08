#ifndef NO_H
#define NO_H

typedef struct No 
{
  int chave;
  char val;
  struct No *esq;
  struct No *dir;
} No;

No * criarNo(char val, int chave);

void mostrarNo(No* n);

#endif
