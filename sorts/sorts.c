#include <stdio.h>
#include <stdlib.h>

#include "sorts.h"

void bubbleSort(item_t* vetor, int tamanhoVetor)
{
    if(vetor == NULL) return;

    int trocou;

    for(int i = 0; i < tamanhoVetor - 1; ++i)
    {
        trocou = 0;
        for(int j = 0; j < tamanhoVetor - 1 - i; ++j)
        {
            if(vetor[j] > vetor[j + 1])
            {
                trocarItens(&vetor[j], &vetor[j + 1]);
                trocou = 1;
            }
        }

        if(!trocou) break;
    }
}

void insertionSort(item_t* vetor, int tamanhoVetor)
{
    if(vetor == NULL) return;

    int j;
    item_t chave;

    for(int i = 1; i < tamanhoVetor; ++i)
    {
        chave = vetor[i];
        j = i - 1;

        while(j >= 0 && chave < vetor[j])
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

void selectionSort(item_t* vetor, int tamanhoVetor)
{
    if(vetor == NULL) return;

    int indexMenorAtual;

    for(int i = 0; i < tamanhoVetor; ++i)
    {
        indexMenorAtual = i;

        for(int j = i + 1; j < tamanhoVetor; ++j)
        {
            if(vetor[j] < vetor[indexMenorAtual])
            {
                indexMenorAtual = j;
            }
        }

        trocarItens(&vetor[i], &vetor[indexMenorAtual]);
    }
}

void shellSort(item_t* vetor, int tamanhoVetor)
{
    if(vetor == NULL) return;

    int gap = 1;

    while(gap < tamanhoVetor)
    {
        gap *= 2;
    }

    gap = (gap / 2) - 1;

    int j;
    item_t chave;

    while(gap > 0)
    {
        for(int i = gap; i < tamanhoVetor; ++i)
        {
            chave = vetor[i];
            j = i - gap;

            while(j >= 0 && chave < vetor[j])
            {
                vetor[j + gap] = vetor[j];
                j -= gap;
            }
            vetor[j + gap] = chave;
        }

        gap /= 2;
    }
}

void intercalar(item_t* vetor, int inicio, int centro, int fim)
{
    item_t* vetorAux = (item_t*)malloc(sizeof(int) * ((fim - inicio) + 1));

    if(vetorAux == NULL) exit(1);

    int i = inicio;
    int j = centro + 1;
    int k = 0;

    while(i <= centro && j <= fim)
    {
        if(vetor[j] >= vetor[i])
        {
            vetorAux[k] = vetor[i];
            i++;
        }
        else
        {
            vetorAux[k] = vetor[j];
            j++;
        }

        k++;
    }

    while(i <= centro)
    {
        vetorAux[k] = vetor[i];
        k++;
        i++;
    }

    while(j <= fim)
    {
        vetorAux[k] = vetor[j];
        k++;
        j++;
    }

    for(int i = inicio, k = 0; i <= fim; ++i, ++k)
    {
        vetor[i] = vetorAux[k];
    }

    free(vetorAux);
}

void dividir_conquistar(item_t* vetor, int inicio, int fim)
{
    if(inicio >= fim) return;

    int centro = (inicio + fim) / 2;

    dividir_conquistar(vetor, inicio, centro);
    dividir_conquistar(vetor, centro + 1, fim);

    intercalar(vetor, inicio, centro, fim);
}

void mergeSort(item_t* vetor, int tamanhoVetor)
{
    if(vetor == NULL) return;

    vetor[0] = -1;

    dividir_conquistar(vetor, 0, tamanhoVetor - 1);
}


void _quickSort(item_t* vetor, int inicio, int fim)
{
    if(inicio >= fim) return;

    /* Escolhendo o pivo de forma aleatória e colocando no início do vetor */
    int pivo = (rand() % (fim - inicio)) + inicio;
    trocarItens(&vetor[inicio], &vetor[pivo]);

    pivo = inicio;
    int i = inicio + 1;
    int j = fim;

    while(i <= j)
    {
        while(i <= j && vetor[i] <= vetor[pivo]) i++;

        while(vetor[j] > vetor[pivo]) j--;

        if(j > i)
        {
            trocarItens(&vetor[i], &vetor[j]);
            i++;
            j--;
        }
    }

    trocarItens(&vetor[j], &vetor[inicio]);

    _quickSort(vetor, inicio, j - 1);
    _quickSort(vetor, j + 1, fim);
}

void quickSort(item_t* vetor, int tamanhoVetor)
{
    if(vetor == NULL) return;

    _quickSort(vetor, 0, tamanhoVetor - 1);
}


void heapMax(item_t* vetor, int pai, int tamanhoVetor)
{
    int filho = (2 * pai) + 1;

    if(filho >= tamanhoVetor) return;

    if(filho + 1 < tamanhoVetor && vetor[filho + 1] > vetor[filho])
    {
        filho = filho + 1;
    }

    if(vetor[filho] > vetor[pai])
    {
        trocarItens(&vetor[filho], &vetor[pai]);

        heapMax(vetor, filho, tamanhoVetor);
    }
}

void heapSort(item_t* vetor, int tamanhoVetor)
{
    if(vetor == NULL) return;   

    for(int i = tamanhoVetor / 2; i >= 0; --i)
    {
        heapMax(vetor, i, tamanhoVetor);
    }

    while(tamanhoVetor > 0)
    {
        trocarItens(&vetor[0], &vetor[tamanhoVetor - 1]);
        tamanhoVetor--;

        heapMax(vetor, 0, tamanhoVetor);
    }

}