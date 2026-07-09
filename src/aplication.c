#include <string.h>
#include <stdio.h>

#include "../libraries/arvoreHuffman.h"

int verbosity = 0;
int simple_out = 0;

void mostraAjuda(char *nomeprograma)
{
	printf("Modo de uso: %s -v -sO 'conteudo'\n", nomeprograma);
	printf("-v   Mostra o código com verbosidade\n");
	printf("-sO  Compressão simples, somente mostrando na tela\n");
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

	//ultimo argumento -> caminho do arquivo
	char *caminhoArquivo = argv[argc-1];

	FILE *arquivo = fopen(caminhoArquivo, "r");

	if(arquivo==NULL)
	{
		printf("Erro ao abrir arquivo: %s\n", caminhoArquivo);
		return 1;
	}

	//para descobrir o tamanho do arquivo
	fseek(arquivo, 0, SEEK_END); //move o cursor para o final do arquivo
	long tamanho = ftell(arquivo); //descobre o tamanho do arquivo em bytes ate aquela posicao (ultima, ja que estamos no final do arquivo)
	fseek(arquivo, 0, SEEK_SET); //move o cursor de volta para o inicio

	char *buffer = (char *) malloc(tamanho+1);
	if(buffer==NULL) return 1;

	//le o arquivo e armazena em buffer
	fread(buffer, 1, tamanho, arquivo);
	buffer[tamanho] = '\0'; //fim da string
	fclose(arquivo);


	huffman(buffer, verbosity, simple_out);
	return 0;
}