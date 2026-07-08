#ifndef NO
#define NO

typedef struct No 
{
  int chave;
  char val;
  struct No *esq;
  struct No *dir;

  // usado somente na fila
  struct No *prox;
} No;

No * criarNo(char val, int chave);

void mostrarNo(No* n);

#endif
