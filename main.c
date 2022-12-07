#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorts/sorts.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    if(argc != 3)
    {
        printf("Informar o tamanho do vetor e o modo de criação!\n");

        return EXIT_FAILURE;
    }

    int modo = atoi(argv[1]);
    int tamanhoVetor = atoi(argv[2]);

    item_t* vetor = criarVetor(tamanhoVetor, modo);

    double tempo = calcularTempo(vetor, tamanhoVetor, bucketSort);

    if(estaOrdenado(vetor, tamanhoVetor))
    {
        printf("Vetor ordenado!\n");
        printf("Tempo de execução: %.3lfs\n", tempo);
    }

    destruirVetor(&vetor);

    return EXIT_SUCCESS;
}
