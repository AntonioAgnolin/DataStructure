//Cria um vetor de 10 elementos inteiros, inicializa seus valores e imprime os elementos.
#include <stdio.h>

void imprimir(int vetor[], int tamanho);
void teste(int vetor[], int tamanho);

int main (void) {
  int vetor[10] = {12, 15, 14, 45, 13, 10, 22, 18, 30, 27};
  int tamanho = sizeof(vetor)/sizeof(int);

  imprimir(vetor, tamanho);
  teste(vetor, tamanho);
}