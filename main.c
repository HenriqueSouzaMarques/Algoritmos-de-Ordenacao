#include <stdio.h>
#include <stdlib.h>

#include "utils/utils.h"
#include "sorts/sorts.h"

int main(int argc, char *argv[])
{
    int modo = atoi(argv[1]);
    int tamanhoVetor = atoi(argv[2]);

    item_t* vetor = criarVetor(tamanhoVetor, modo);

    double tempo = calcularTempo(vetor, tamanhoVetor, mergeSort);

    printf("TEMPO mergeSort: %.3fs\n", tempo);

    destruirVetor(&vetor);

    return 0;
}
