#ifndef SORTS_H
#define SORTS_H

#include "../utils/utils.h"


/* O(n²) */
void bubbleSort(item_t* vetor, int tamanhoVetor);
void insertionSort(item_t* vetor, int tamanhoVetor);
void selectionSort(item_t* vetor, int tamanhoVetor);
void shellSort(item_t* vetor, int tamanhoVetor);

/* O(nlogn) */
void mergeSort(item_t* vetor, int tamanhoVetor);
void quickSort(item_t* vetor, int tamanhoVetor);
void heapSort(item_t* vetor, int tamanhoVetor);


/* O(n) */
void countingSort(item_t* vetor, int tamanhoVetor);




#endif //SORTS_H