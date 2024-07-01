//Lista duplamente encadeada com inserção, remoção, busca e impressão.
#include <stdio.h>
#include <stdlib.h>

//Definição da estrutura de um nó
typedef struct no {
  int valor;
  struct no *proximo;
  struct no *anterior;
} No;

//Definição da estrutura da lista
typedef struct lista {
  No *inicio;
  int tam;
} Lista;

//Função para criar uma nova lista
void criar_lista(Lista *lista) {
  lista->inicio = NULL;
  lista->tam = 0;
}

//Função para inserir um elemento no início da lista
void inserir_inicio(Lista *lista, int num) {
  No *novo = malloc(sizeof(No));

  if (novo) {
    novo->valor = num;
    novo->proximo = lista->inicio;
    novo->anterior = NULL;

    if (lista->inicio != NULL) {
      lista->inicio->anterior = novo;
    }
    lista->inicio = novo;
    lista->tam++;
  } else {
    printf("Erro ao alocar memória.\n");
  }
}

//Função para inserir um elemento no fim da lista
void inserir_fim(Lista *lista, int num) {
  No *aux, *novo = malloc(sizeof(No));

  if (novo) {
    novo->valor = num;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {
      novo->anterior = NULL;
      lista->inicio = novo;
    } else {
      aux = lista->inicio;
      while (aux->proximo) {
        aux = aux->proximo;
      }
      aux->proximo = novo;
      novo->anterior = aux;
    }
    lista->tam++;
  } else {
    printf("Erro ao alocar memória.\n");
  }
}

//Função para inserir um elemento no meio da lista, após um elemento específico
void inserir_meio(Lista *lista, int num, int ant) {
  No *aux, *novo = malloc(sizeof(No));

  if (novo) {
    novo->valor = num;

    if (lista->inicio == NULL) {
      novo->proximo = NULL;
      novo->anterior = NULL;
      lista->inicio = novo;
    } else {
      aux = lista->inicio;
      while (aux->valor != ant && aux->proximo) {
        aux = aux->proximo;
      }
      novo->proximo = aux->proximo;
      if (aux->proximo) {
        aux->proximo->anterior = novo;
      }
      novo->anterior = aux;
      aux->proximo = novo;
    }
    lista->tam++;
  } else {
    printf("Erro ao alocar memória.\n");
  }
}

//Função para inserir um elemento de forma ordenada na lista
void inserir_ordenado(Lista *lista, int num) {
  No *aux, *novo = malloc(sizeof(No));

  if (novo) {
    novo->valor = num;

    if (lista->inicio == NULL || novo->valor < lista->inicio->valor) {
      novo->proximo = lista->inicio;
      novo->anterior = NULL;
      if (lista->inicio != NULL) {
        lista->inicio->anterior = novo;
      }
      lista->inicio = novo;
    } else {
      aux = lista->inicio;
      while (aux->proximo && novo->valor > aux->proximo->valor) {
        aux = aux->proximo;
      }
      novo->proximo = aux->proximo;
      if (aux->proximo) {
        aux->proximo->anterior = novo;
      }
      novo->anterior = aux;
      aux->proximo = novo;
    }
    lista->tam++;
  } else {
    printf("Erro ao alocar memória.\n");
  }
}

//Função para remover um elemento específico da lista
No* remover(Lista *lista, int num) {
  No *aux, *no = NULL;

  if (lista->inicio) {
    if (lista->inicio->valor == num) {
      no = lista->inicio;
      lista->inicio = no->proximo;
      if (lista->inicio) {
        lista->inicio->anterior = NULL;
      }
      lista->tam--;
    } else {
      aux = lista->inicio;
      while (aux->proximo && aux->proximo->valor != num) {
        aux = aux->proximo;
      }
      if (aux->proximo) {
        no = aux->proximo;
        aux->proximo = no->proximo;
        if (aux->proximo) {
          aux->proximo->anterior = aux;
        }
        lista->tam--;
      }
    }
  }
  return no;
}

//Função para buscar um elemento na lista
No* buscar(Lista *lista, int num) {
  No *aux = lista->inicio;
  while (aux && aux->valor != num) {
    aux = aux->proximo;
  }
  return aux;
}

//Função para imprimir os elementos da lista
void imprimir(Lista lista) {
  No *no = lista.inicio;
  printf("\nTamanho da Lista: %d\n", lista.tam);
  while (no) {
    printf("%d ", no->valor);
    no = no->proximo;
  }
  printf("\n\n");
}

int main(void) {
  int opcao, valor, anterior;
  No *no;
  Lista lista;

  criar_lista(&lista);

  do {
    printf("\n0 - Sair\n1 - Inserir no início\n2 - Inserir no fim\n3 - Inserir no meio\n4 - Inserir ordenado\n5 - Remover\n6 - Imprimir\n7 - Buscar\n");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        printf("Valor: ");
        scanf("%d", &valor);
        inserir_inicio(&lista, valor);
        break;
      case 2:
        printf("Valor: ");
        scanf("%d", &valor);
        inserir_fim(&lista, valor);
        break;
      case 3:
        printf("Valor a ser inserido e valor de referência: ");
        scanf("%d %d", &valor, &anterior);
        inserir_meio(&lista, valor, anterior);
        break;
      case 4:
        printf("Valor: ");
        scanf("%d", &valor);
        inserir_ordenado(&lista, valor);
        break;
      case 5:
        printf("Remover valor: ");
        scanf("%d", &valor);
        no = remover(&lista, valor);
        if (no) {
          printf("Elemento removido: %d\n", no->valor);
          free(no);
        } else {
          printf("Elemento não encontrado.\n");
        }
        break;
      case 6:
        imprimir(lista);
        break;
      case 7:
        printf("Buscar valor: ");
        scanf("%d", &valor);
        no = buscar(&lista, valor);
        if (no) {
          printf("Elemento encontrado: %d\n", no->valor);
        } else {
          printf("Elemento não encontrado.\n");
        }
        break;
      default:
        if (opcao != 0) {
          printf("Opção inválida.\n");
        }
    }
  } while (opcao != 0);

  return 0;
}
