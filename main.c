#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils/utils.h"
#include "sorts/sorts.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int modo = atoi(argv[1]);
    int tamanhoVetor = atoi(argv[2]);

    item_t* vetor = criarVetor(tamanhoVetor, modo);

    double tempo = calcularTempo(vetor, tamanhoVetor, quickSort);

    if(estaOrdenado(vetor, tamanhoVetor))
    {
        printf("Vetor Ordenado!\n");
        printf("Tempo quickSort: %.3fs\n", tempo);
    }

    destruirVetor(&vetor);

    return EXIT_SUCCESS;
}
