#ifndef SORTS_H
#define SORTS_H

#include "../utils/utils.h"

void bubbleSort(item_t* vetor, int tamanhoVetor);

void insertionSort(item_t* vetor, int tamanhoVetor);
void selectionSort(item_t* vetor, int tamanhoVetor);
void shellSort(item_t* vetor, int tamanhoVetor);

void mergeSort(item_t* vetor, int tamanhoVetor);

void quickSort(item_t* vetor, int tamanhoVetor);

#endif //SORTS_H