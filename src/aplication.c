#include <string.h>
#include <stdio.h>

#include "../libraries/arvoreHuffman.h"

int verbosity = 0;
int simple_out = 0;

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

	huffman(argv[argc-1], verbosity, simple_out);
  return 0;
}