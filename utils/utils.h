#ifndef UTILS_H
#define UTILS_H

#include <time.h>

typedef int item_t;

#define VALOR_MAX 1000

#define BOOL char
#define TRUE 1
#define FALSE 0


/* MODO 0: disposição aleatória
   MODO 1: disposição crescente
   MODO 2: disposição decrescente
*/
item_t* criarVetor(int tamanhoVetor, int modo);
void embaralharVetor(item_t* vetor, int tamanhoVetor, int modo);

void printarVetor(item_t* vetor, int tamanhoVetor);

void trocarItens(item_t* itemA, item_t* itemB);

BOOL estaOrdenado(item_t* vetor, int tamanhoVetor);

double calcularTempo(item_t* vetor, int tamanhoVetor, void (*sorting)(item_t*, int));

void destruirVetor(item_t** vetor);

#endif // UTILS_H