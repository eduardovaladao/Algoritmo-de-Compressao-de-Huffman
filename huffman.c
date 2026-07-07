#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	mostrarArvore(arv);
}



int main (int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Modo de uso: %s 'conteudo'", argv[0]);
		return 1;
	}
	
	huffman(argv[1]);
}
