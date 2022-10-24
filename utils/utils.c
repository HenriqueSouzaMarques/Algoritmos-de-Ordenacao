#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

item_t* criarVetor(int tamanhoVetor, int modo)
{
    item_t* vetor = (item_t*)malloc(tamanhoVetor * sizeof(item_t));

    embaralharVetor(vetor, tamanhoVetor, modo);

    return vetor;
}

void embaralharVetor(item_t* vetor, int tamanhoVetor, int modo)
{
    if(vetor == NULL) exit(1);

    if(modo == 0)
    {
        for(int i = 0; i < tamanhoVetor; ++i)
        {
            vetor[i] = rand() % VALOR_MAX;
        }
    }
    else if(modo == 1)
    {
        for(int i = 0; i < tamanhoVetor; ++i)
        {
            vetor[i] = i;
        }
    }
    else if(modo == 2)
    {
        for(int i = 0; i < tamanhoVetor; ++i)
        {
            vetor[i] = tamanhoVetor - i;
        }
    }
}

void printarVetor(item_t* vetor, int tamanhoVetor)
{
    if(vetor == NULL) exit(1);

    for(int i = 0; i < tamanhoVetor; ++i)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void trocarItens(item_t* itemA, item_t* itemB)
{
    if(itemA == NULL || itemB == NULL) return;

    item_t aux = *itemA;
    *itemA = *itemB;
    *itemB = aux;
}

BOOL estaOrdenado(item_t* vetor, int tamanhoVetor)
{
    if(vetor == NULL) exit(1);

    for(int i = 0; i < tamanhoVetor - 1; ++i)
    {
        if(vetor[i] > vetor[i + 1]) return FALSE;
    }

    return TRUE;
}

double calcularTempo(item_t* vetor, int tamanhoVetor, void (*sorting)(item_t*, int))
{
    if(vetor == NULL) exit(1);

    clock_t inicio, fim;

    inicio = clock();
    sorting(vetor, tamanhoVetor);
    fim = clock();

    return ((fim - inicio) / (double)CLOCKS_PER_SEC);
}

void destruirVetor(item_t** vetor)
{
    if(vetor == NULL || *vetor == NULL) return;

    free(*vetor);

    *vetor = NULL;
}