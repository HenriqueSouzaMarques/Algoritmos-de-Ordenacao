#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

int* criarVetorContagem(item_t* vetor, int tamanhoVetor, int amplitude, int min)
{
    int* vetorContagem = (int*)calloc(amplitude, sizeof(int));
    assert(vetorContagem != NULL);

    for(int i = 0; i < tamanhoVetor; ++i)
    {
        vetorContagem[vetor[i] - min]++;
    }

    return vetorContagem;
}

void contarAcumulado(int* vetorContagem, int amplitude)
{
    int total = 0;
    for(int i = 0; i < amplitude; ++i)
    {
        int contagemAnterior = vetorContagem[i];

        vetorContagem[i] = total;

        total += contagemAnterior;
    }
}

void posicionarElementos(item_t* vetor, item_t* copia, int* vetorContagem, int tamanhoVetor, int min)
{
    for(int i = 0; i < tamanhoVetor; ++i)
    {
        vetor[vetorContagem[copia[i] - min]] = copia[i];

        vetorContagem[copia[i] - min]++;
    }   
}

void countingSort(item_t* vetor, int tamanhoVetor)
{
    if(vetor == NULL) return;

    int min = vetor[0];
    int max = vetor[0];

    item_t* copia = (item_t*)malloc(tamanhoVetor * sizeof(item_t));
    assert(copia != NULL);

    for(int i = 0; i < tamanhoVetor; ++i)
    {
        copia[i] = vetor[i];

        if(vetor[i] > max) max = vetor[i];
        else if(vetor[i] < min) min = vetor[i];
    }

    int amplitude = (max - min) + 1;

    int* vetorContagem = criarVetorContagem(vetor, tamanhoVetor, amplitude, min);

    contarAcumulado(vetorContagem, amplitude);
    
    posicionarElementos(vetor, copia, vetorContagem, tamanhoVetor, min);

    free(vetorContagem);

    free(copia);
}


queue_t** criarBuckets(int amplitude)
{
    queue_t** buckets = (queue_t**)malloc(amplitude * sizeof(queue_t*));
    assert(buckets != NULL);

    for(int i = 0; i < amplitude; ++i)
    {
        buckets[i] = createQueue();
    }

    return buckets;
}

void posicionarBuckets(item_t* vetor, queue_t** buckets, int amplitude)
{
    int k = 0;
    for(int i = 0; i < amplitude; ++i)
    {
        while(!isEmpty(buckets[i]))
        {
            element elementoAtual = pop(buckets[i]);
            vetor[k++] = elementoAtual;
        }

        free(buckets[i]);
    }

    free(buckets);
}

void bucketSort(item_t* vetor, int tamanhoVetor)
{
    if(vetor == NULL) return;

    int min = vetor[0];
    int max = vetor[0];

    for(int i = 0; i < tamanhoVetor; ++i)
    {
        if(vetor[i] > max) max = vetor[i];
        else if(vetor[i] < min) min = vetor[i];
    }

    int amplitude = (max - min) + 1;

    queue_t** buckets = criarBuckets(amplitude);

    for(int i = 0; i < tamanhoVetor; ++i)
    {
        push(buckets[vetor[i] - min], vetor[i]);
    }

    posicionarBuckets(vetor, buckets, amplitude);
}