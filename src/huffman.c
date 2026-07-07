#include <stdio.h>
#include <stdlib.h>

// Huffman(frequencias)

//     fila = criarFilaPrioridade()

//                para cada símbolo
//            criar nó
//            inserir na fila

//            enquanto tamanho(fila) > 1

//            x = removerMenor(fila)
//                y = removerMenor(fila)

//                    z = novoNo()

//                            z.freq = x.freq + y.freq

//                                              z.esq = x z.dir = y

//     inserir(fila, z)

// retornar removerMenor(fila)