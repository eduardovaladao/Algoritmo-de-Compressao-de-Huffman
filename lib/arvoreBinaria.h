typedef struct NO *ArvBin;

ArvBin *cria_ArvBin();

int insere_ArvBin(ArvBin *raiz, int prioridade, char letra_primeiro_menor, int prioridade_primeiro_menor, char letra_segundo_menor, int prioridade_segundo_menor);

int estaVazia_ArvBin(ArvBin *raiz);

int consulta_ArvBin(ArvBin *raiz, int valor);