#include "../lib/arvoreBinaria.h"
#include "../lib/huffman.h"

int main()
{
    char str[200];
    printf("Digite a palavra");
    scanf("%s", str);

    struct Huffman *h = comprime(str);

    printf("O resultado codificado eh: %s", h->codigo);

    return 0;
}