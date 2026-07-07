#include <stdio.h>
#include "../lib/huffman.h"
#include "../lib/arvoreBinaria.h"

int main()
{
    char str[200];
    struct Huffman *h;

    printf("Digite a palavra: ");
    scanf("%s", str);

    h = comprime(str);

    printf("\nArvore de Huffman:\n");
    imprimeArvore(h->arvore, 0);

    printf("\nCodigos:\n");
    imprimeCodigos(h->arvore);

    return 0;
}
