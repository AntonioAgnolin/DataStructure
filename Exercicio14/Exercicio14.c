//Árvore binária de busca com inserção, impressão em pré-ordem, in-ordem e pós-ordem, 
//busca, cálculo da altura, quantidade de nós e remoção.
#include <stdio.h>
#include <stdlib.h>

//Estrutura de um nó da árvore
typedef struct no {
  int valor;
  struct no *direita, *esquerda;
} NoArv;

//Função para inserir um valor em uma árvore binária de busca
void inserir(NoArv **raiz, int num) {
  if (*raiz == NULL) {
    *raiz = malloc(sizeof(NoArv));
    (*raiz)->valor = num;
    (*raiz)->esquerda = NULL;
    (*raiz)->direita = NULL;
  } else {
    if (num < (*raiz)->valor)
      inserir(&((*raiz)->esquerda), num);
    else
      inserir(&((*raiz)->direita), num);
  }
}

//Função para imprimir a árvore em pré-ordem
void imprimir_pre_ordem(NoArv *raiz) {
  if (raiz) {
    printf("%d ", raiz->valor);
    imprimir_pre_ordem(raiz->esquerda);
    imprimir_pre_ordem(raiz->direita);
  }
}

//Função para imprimir a árvore em ordem simétrica
void imprimir_in_ordem(NoArv *raiz) {
  if (raiz) {
    imprimir_in_ordem(raiz->esquerda);
    printf("%d ", raiz->valor);
    imprimir_in_ordem(raiz->direita);
  }
}

//Função para imprimir a árvore em pós-ordem
void imprimir_pos_ordem(NoArv *raiz) {
  if (raiz) {
    imprimir_pos_ordem(raiz->esquerda);
    imprimir_pos_ordem(raiz->direita);
    printf("%d ", raiz->valor);
  }
}

//Função para buscar um valor na árvore
NoArv* buscar(NoArv *raiz, int num) {
  if (raiz) {
    if (num == raiz->valor)
      return raiz;
    else if (num < raiz->valor)
      return buscar(raiz->esquerda, num);
    else
      return buscar(raiz->direita, num);
  }
  return NULL;
}

//Função para calcular a altura da árvore
int altura(NoArv *raiz) {
  if (raiz == NULL)
    return -1;
  else {
    int esq = altura(raiz->esquerda);
    int dir = altura(raiz->direita);
    if (esq > dir)
      return esq + 1;
    else
      return dir + 1;
  }
}

//Função para contar o número de nós na árvore
int quantidade_nos(NoArv *raiz) {
  if (raiz == NULL)
    return 0;
  else
    return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

//Função para remover um nó da árvore
NoArv* remover(NoArv *raiz, int chave) {
  if (raiz == NULL) {
    printf("Valor não encontrado.\n");
    return NULL;
  } else {
    if (raiz->valor == chave) {
      if (raiz->esquerda == NULL && raiz->direita == NULL) {
        free(raiz);
        printf("Elemento removido: %d\n", chave);
        return NULL;
      } else {
        if (raiz->esquerda != NULL && raiz->direita != NULL) {
          NoArv *aux = raiz->esquerda;
          while (aux->direita != NULL)
            aux = aux->direita;
          raiz->valor = aux->valor;
          aux->valor = chave;
          printf("Elemento trocado: %d\n", chave);
          raiz->esquerda = remover(raiz->esquerda, chave);
          return raiz;
        } else {
          NoArv *aux;
          if (raiz->esquerda != NULL)
            aux = raiz->esquerda;
          else
            aux = raiz->direita;
          free(raiz);
          printf("Elemento com 1 filho removido: %d\n", chave);
          return aux;
        }
      }
    } else {
      if (chave < raiz->valor)
        raiz->esquerda = remover(raiz->esquerda, chave);
      else
        raiz->direita = remover(raiz->direita, chave);
      return raiz;
    }
  }
}

int main(void) {
  NoArv *busca, *raiz = NULL;
  int opcao, valor;

  do {
    printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n3 - Buscar\n4 - Altura\n5 - Quantidade de Nós\n6 - Remover\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        printf("Valor a ser inserido: ");
        scanf("%d", &valor);
        inserir(&raiz, valor);
        break;
      case 2:
        printf("\nPré-ordem: ");
        imprimir_pre_ordem(raiz);
        printf("\nIn-ordem: ");
        imprimir_in_ordem(raiz);
        printf("\nPós-ordem: ");
        imprimir_pos_ordem(raiz);
        printf("\n");
        break;
      case 3:
        printf("\nValor a ser buscado: ");
        scanf("%d", &valor);
        busca = buscar(raiz, valor);
        if (busca)
          printf("\nValor encontrado: %d\n", busca->valor);
        else
          printf("\nValor não encontrado.\n");
        break;
      case 4:
        printf("\nAltura da árvore: %d\n", altura(raiz));
        break;
      case 5:
        printf("\nQuantidade de nós na árvore: %d\n", quantidade_nos(raiz));
        break;
      case 6:
        printf("\nValor a ser removido: ");
        scanf("%d", &valor);
        raiz = remover(raiz, valor);
        break;
      default:
        if (opcao != 0)
          printf("\nOpção inválida.\n");
    }
  } while (opcao != 0);

  return 0;
}
