#ifndef SORTS_H
#define SORTS_H

#include "../utils/utils.h"
#include "../utils/queue.h" /* Uso no Bucket Sort */

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
void bucketSort(item_t* vetor, int tamanhoVetor);
void radixSort(item_t* vetor, int tamanhoVetor);

/* Base utilizada no radixSort. Utilizar sempre alguma potência de 2 maior ou igual a 32 */
#define BASE 256



#endif //SORTS_H