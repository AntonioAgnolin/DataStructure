//Estrutura de uma árvore binária de busca com impressão em pré-ordem, in-ordem e pós-ordem.
#include <stdio.h>
#include <stdlib.h>

//Estrutura de um nó da árvore
typedef struct no {
  int valor;
  struct no *direita, *esquerda;
} NoArv;

//Versão 1 da função para inserir um valor em uma árvore binária de busca
NoArv* inserir_v1(NoArv *raiz, int num) {
  if(raiz == NULL) {
    //Criando um novo nó se a raiz for nula
    NoArv *aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    return aux;
  } else {
    //Inserindo recursivamente à esquerda ou à direita
    if(num < raiz->valor)
      raiz->esquerda = inserir_v1(raiz->esquerda, num);
    else
      raiz->direita = inserir_v1(raiz->direita, num);
    return raiz;
  }
}

//Função para imprimir a árvore em pré-ordem
void imprimir_pre_ordem(NoArv *raiz) {
  if(raiz) {
    printf("%d ", raiz->valor);
    imprimir_pre_ordem(raiz->esquerda);
    imprimir_pre_ordem(raiz->direita);
  }
}

//Função para imprimir a árvore em ordem simétrica
void imprimir_in_ordem(NoArv *raiz) {
  if(raiz) {
    imprimir_in_ordem(raiz->esquerda);
    printf("%d ", raiz->valor);
    imprimir_in_ordem(raiz->direita);
  }
}

//Função para imprimir a árvore em pós-ordem
void imprimir_pos_ordem(NoArv *raiz) {
  if(raiz) {
    imprimir_pos_ordem(raiz->esquerda);
    imprimir_pos_ordem(raiz->direita);
    printf("%d ", raiz->valor);
  }
}

//Versão 2 da função para inserir um valor em uma árvore binária de busca
void inserir_v2(NoArv **raiz, int num) {
  if(*raiz == NULL) {
    *raiz = malloc(sizeof(NoArv));
    (*raiz)->valor = num;
    (*raiz)->esquerda = NULL;
    (*raiz)->direita = NULL;
  } else {
    if(num < (*raiz)->valor)
      inserir_v2(&((*raiz)->esquerda), num);
    else
      inserir_v2(&((*raiz)->direita), num);
  }
}
    
int main(void) {
  NoArv *raiz = NULL;

  //Inserindo valores na árvore
  raiz = inserir_v1(raiz, 24);
  raiz = inserir_v1(raiz, 32);
  raiz = inserir_v1(raiz, 10);
  raiz = inserir_v1(raiz, 5);
  raiz = inserir_v1(raiz, 29);
  raiz = inserir_v1(raiz, 12);
  raiz = inserir_v1(raiz, 35);
  raiz = inserir_v1(raiz, 39);

  //Imprimindo a árvore em diferentes ordens
  printf("Pre-Ordem: ");
  imprimir_pre_ordem(raiz);
  printf("\n");

  printf("In-Ordem: ");
  imprimir_in_ordem(raiz);
  printf("\n");

  printf("Pos-Ordem: ");
  imprimir_pos_ordem(raiz);
  printf("\n");
}
