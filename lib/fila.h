#define TAM_MAX 255

typedef int TipoValor;

typedef struct {
    TipoValor itens[TAM_MAX]; // vetor relacional
    int inicio;
    int fim;
    int total;
} Fila;

void inicializarFila(Fila *f);
int vazia(Fila *f);
int cheia(Fila *f);
int pop(Fila *f, int valor);
int push(Fila *f, int *valor);
int tamanhoFila(Fila *f);