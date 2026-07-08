#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../libraries/no.h"
#include "../libraries/arvoreHuffman.h"

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
		No *raiz = criarNo('#', a->chave + b->chave);
		raiz->esq = a;
		raiz->dir = b;

		//remove da lista as folhas
		for (int i = 2; i < tam_f; i++) f[i-2] = f[i];
		tam_f -= 2;

		//adiciona a mini-arvore na lista
		f[tam_f] = raiz;
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

// mostra arvore
void mostrarArvore(No* n)
{
  if (n == NULL) return;

  mostrarArvore(n->esq);
  mostrarNo(n);
  mostrarArvore(n->dir);
}

//Compreesão simples para o print
void compressorSimples(char *input, char tabela[256][128])
{
  printf("%s\n", input);
  for (int i = 0; input[i] != '\0'; i++)
    printf("%s", tabela[(unsigned char)input[i]]);
  printf("\n");
}

void huffman(char *input, int verbosity, int simple_out)
{
	int t = 0;
	//calculo tamanho da str
	for (int i = 0; input[i] != '\0'; i++) t++;

	No *fila[256];
	int t_fila = 0;

	int freq[256] = {0};

	//Soma de acordo com a frequencia
	for (int i = 0; input[i] != '\0'; i++)
    freq[(unsigned char) input[i]]++;

	//Adiciona na fila o que aparece
	for (int i = 0; i < 256; i++) if (freq[i] > 0) 
    fila[t_fila++] = criarNo((char)i, freq[i]);

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