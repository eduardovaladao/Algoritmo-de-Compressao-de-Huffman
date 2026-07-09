#ifndef FILA_PRIORIDADE
#define FILA_PRIORIDADE

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