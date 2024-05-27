//Árvore binária de busca com inserção de nós de três maneiras diferentes, 
//impressão pré-ordem, in-ordem e pós-ordem, busca de um valor na árvore e 
//cálculo da altura da árvore.
#include <stdio.h>
#include <stdlib.h>

//Estrutura de um nó da árvore
typedef struct no {
  int valor;
  struct no *direita, *esquerda;
} NoArv;

//Função para inserir um nó na árvore de forma recursiva
NoArv* inserir_v1(NoArv *raiz, int num) {
  if(raiz == NULL) {
    NoArv *aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    return aux;
  } else {
    if(num < raiz->valor)
      raiz->esquerda = inserir_v1(raiz->esquerda, num);
    else
      raiz->direita = inserir_v1(raiz->direita, num);
    return raiz;
  }
}

//Função para inserir um nó na árvore de forma recursiva usando ponteiros duplos
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

//Função para inserir um nó na árvore de forma iterativa
void inserir_v3(NoArv **raiz, int num) {
  NoArv *aux = *raiz;
  while (aux) {
    if(num < aux->valor)
      raiz = &aux->esquerda;
    else
      raiz = &aux->direita;
    aux = *raiz;
  }
  aux = malloc(sizeof(NoArv));
  aux->valor = num;
  aux->esquerda = NULL;
  aux->direita = NULL;
  *raiz = aux;
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

//Função para buscar um valor na árvore de forma recursiva
NoArv* buscar_v1(NoArv *raiz, int num) {
  if(raiz) {
    if(num == raiz->valor)
      return raiz;
    else if(num < raiz->valor)
      return buscar_v1(raiz->esquerda, num);
    else
      return buscar_v1(raiz->direita, num);
  }
  return NULL;
}

//Função para buscar um valor na árvore de forma iterativa
NoArv* buscar_v2(NoArv *raiz, int num) {
  while(raiz) {
    if(num == raiz->valor)
      return raiz;
    else if(num < raiz->valor)
      raiz = raiz->esquerda;
    else
      raiz = raiz->direita;
  }
  return NULL;
}

//Função para calcular a altura da árvore
int altura(NoArv *raiz) {
  if(raiz == NULL) {
    return -1;
  } else {
    int esq = altura(raiz->esquerda);
    int dir = altura(raiz->direita);
    if(esq > dir)
      return esq + 1;
    else
      return dir + 1;
  }
}

int main(void) {
  NoArv *raiz = NULL;
  int opcao, valor;

  do {
    printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n");
    scanf("%d", &opcao);

    switch(opcao) {
      case 1:
        printf("\nValor: ");
        scanf("%d", &valor);
        inserir_v2(&raiz, valor); //Escolha qualquer função de inserção aqui
        break;
      case 2:
        printf("\nPré-ordem\n");
        imprimir_pre_ordem(raiz);
        printf("\nOrdem\n");
        imprimir_in_ordem(raiz);
        printf("\nPós-ordem\n");
        imprimir_pos_ordem(raiz);
        break;
      case 3:
        printf("\nValor (busca): ");
        scanf("%d", &valor);
        NoArv *busca = buscar_v2(raiz, valor); //Escolha qualquer função de busca aqui
        if (busca)
          printf("\nValor encontrado: %d\n", busca->valor);
        else
          printf("\nValor não encontrado.\n");
        break;
      default:
        if(opcao != 0)
          printf("\nOpção inválida.");
    }
  } while(opcao != 0);
}
