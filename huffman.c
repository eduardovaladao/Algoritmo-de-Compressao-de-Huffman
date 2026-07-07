#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verbosity = 0;
int simple_out = 0;

typedef struct no 
{
  int chave;
  char val;
  struct no *esq;
  struct no *dir;
} No;

No* criarNo(char val, int chave)
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

void mostrarArvore(No* n)
{
  if (n == NULL) return;

  mostrarArvore(n->esq);
  mostrarNo(n);
  mostrarArvore(n->dir);
}

void bubblesort(No **f, int f_t){
	for (int i = 0; i < f_t - 1; i ++)
		for (int j = 0; j < f_t - i - 1; j++)
			if (f[j]->chave > f[j+1]->chave)
			{
				No *tmp = f[j];
				f[j] = f[j+1];
				f[j+1] = tmp;
			}
}

No* criarArv(No **fila, int tam_f)
{
	No **f = fila;
	while (tam_f > 1)
	{
		//ordena por prioridade (crescente)
		bubblesort(f, tam_f);

		//separa os 2 menores para folha
		No *a = f[0];
		No *b = f[1];

		//cria uma mini-arvore
		No *pai = criarNo('#', a->chave + b->chave);
		pai->esq = a;
		pai->dir = b;

		//remove da lista as folhas
		for (int i = 2; i < tam_f; i++) f[i-2] = f[i];
		tam_f -= 2;

		//adiciona a mini-arvore na lista
		f[tam_f] = pai;
		tam_f++;
	}

  return f[0];
}

void gerarCodigo(No* no, char cod[], int prof, char tabela[256][128])
{
  //Se a arvore não for criada
  if (no == NULL) return;

  //Se for folha
  if (no->esq == NULL && no->dir == NULL)
  {
    cod[prof] = '\0';
    int i = 0;
    do {
      tabela[(unsigned char)no->val][i] = cod[i]; 
      i++;
    } while (cod[i-1]!='\0'); // preferi usar isso ao inves do strdup
    return;
  } 

  //Para pesquisar os codigos da direita
  cod[prof] = '1';
  gerarCodigo(no->dir, cod, prof+1, tabela);

  //Para pesquisar os codigos da esquerda
  cod[prof] = '0';
  gerarCodigo(no->esq, cod, prof+1, tabela);
}

//Compreesão simples para o print
void compressorSimples(char *input, char tabela[256][128])
{
  printf("%s\n", input);
  for (int i = 0; input[i] != '\0'; i++)
    printf("%s", tabela[(unsigned char)input[i]]);
  printf("\n");
}

void huffman(char *input)
{
	int t = 0;
	//calculo tamanho da str
	for (int i = 0; input[i] != '\0'; i++) t++;

	No *fila[256];
	int t_fila = 0;

	//separa os caracteres individuais
	/*for(int i = 0; str[i]!= '\0'; i++) optei por tabela ascii por performance
	{
		int exist = 0;
		for (int j = 0; j < t_fila; j++) if (fila[j]->val == str[i]) exist = 1;
		if (exist == 0) 
		{ 
			fila[t_fila] = criarNo(str[i], 0);
			t_fila++; 
		}
	}

	//conta a frequencia
	for (int i = 0; str[i] != '\0'; i++)
	{
		for (int j = 0; j < t_fila; j++)
			if (fila[j]->val == str[i]) fila[j]->chave++;
	}

	for (int i = 0; i < t_fila; i++)
	{
		printf("caractere %c aparece %d vezes\n", fila[i]->val, fila[i]->chave);
	}*/

	int freq[256] = {0};

	//Soma de acordo com a frequencia
	for (int i = 0; input[i] != '\0'; i++) freq[(unsigned char) input[i]]++;

	//Adiciona na fila o que aparece
	for (int i = 0; i < 256; i++) if (freq[i] > 0) fila[t_fila++] = criarNo((char)i, freq[i]);

	No *arv = criarArv(fila, t_fila);

	if (verbosity) 
  {
    printf("\n[+] Arvore binaria\n");
    mostrarArvore(arv);
  }

  char tabela[256][128] = {0};
  char codigo[128];

  gerarCodigo(arv, codigo, 0, tabela);

  if (verbosity)
  {
    printf("\n[+] Mapeamento dos caracteres\n");
    for (int i = 0; i < 256; i++) 
      if (tabela[i][0] != '\0')
        printf("%c -> %s\n", i, tabela[i]);
  }

  if (simple_out) compressorSimples(input, tabela);
}

void mostraAjuda(char *nomeprograma)
{
	printf("Modo de uso: %s -v -sO 'conteudo'\n", nomeprograma);
  printf("-v   Mostra o código com verbosidade\n");
  printf("-cS  Compressão simples, somente mostrando na tela\n");
  printf("-h   Mostra opções de uso\n");
}

int main (int argc, char **argv)
{
	if (argc < 2)
	{
    mostraAjuda(argv[0]);
		return 1;
	}

  for (int i = 0; i < argc; i++)
  {
    if (strcmp(argv[i], "-v") == 0) verbosity = 1;
    if (strcmp(argv[i], "-sO") == 0) simple_out = 1;
    if (strcmp(argv[i], "-h") == 0) {mostraAjuda(argv[0]); return 0;}
  }

	huffman(argv[argc-1]);
  return 0;
}
