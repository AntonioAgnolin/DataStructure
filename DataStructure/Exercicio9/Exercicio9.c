//Lista circular duplamente encadeada com inserção ordenada, remoção, busca e impressão.
#include <stdio.h>
#include <stdlib.h>

//Definição da estrutura de um nó
typedef struct no {
  int valor;
  struct no *proximo;
} No;

//Definição da estrutura da lista
typedef struct {
  No *inicio;
  No *fim;
  int tam;
} Lista;

//Função para criar uma nova lista
void criar_lista(Lista* lista) {
  lista->inicio = NULL;
  lista->fim = NULL;
  lista->tam = 0;
}

//Função para inserir um elemento no início da lista
void inserir_inicio(Lista *lista, int num) {
  No *novo = malloc(sizeof(No));

  if (novo) {
    novo->valor = num;
    if (lista->inicio == NULL) {
      novo->proximo = novo; //Se a lista estiver vazia, o próximo nó aponta para ele mesmo
      lista->fim = novo; //Fim também é o novo nó, pois só há um nó na lista
    } else {
      novo->proximo = lista->inicio; //Próximo nó do novo nó é o início da lista
      lista->fim->proximo = novo; //Próximo do último nó passa a ser o novo nó
    }
    lista->inicio = novo; //Novo nó se torna o início da lista
    lista->tam++;
  } else {
    printf("Erro ao alocar memória.\n");
  }
}

// Função para inserir um elemento no fim da lista
void inserir_fim(Lista *lista, int num) {
  No *novo = malloc(sizeof(No));

  if (novo) {
    novo->valor = num;
    if (lista->inicio == NULL) {
      novo->proximo = novo; //Se a lista estiver vazia, o próximo nó aponta para ele mesmo
      lista->inicio = novo; //Início também é o novo nó, pois só há um nó na lista
    } else {
      novo->proximo = lista->inicio; //Próximo nó do novo nó é o início da lista
      lista->fim->proximo = novo; //Próximo do último nó passa a ser o novo nó
    }
    lista->fim = novo; //Novo nó se torna o fim da lista
    lista->tam++;
  } else {
    printf("Erro ao alocar memória.\n");
  }
}

// Função para inserir um elemento de forma ordenada na lista
void inserir_ordenado(Lista *lista, int num) {
  No *novo = malloc(sizeof(No));

  if (novo) {
    novo->valor = num;
    if (lista->inicio == NULL || num <= lista->inicio->valor) {
      inserir_inicio(lista, num); //Se a lista estiver vazia ou o novo valor for menor ou igual ao início da lista, insere no início
    } else if (num >= lista->fim->valor) {
      inserir_fim(lista, num); //Se o novo valor for maior ou igual ao fim da lista, insere no fim
    } else {
      No *aux = lista->inicio;
      while (aux->proximo != lista->inicio && aux->proximo->valor < num) {
        aux = aux->proximo; //Avança na lista até encontrar a posição correta para inserir
      }
      novo->proximo = aux->proximo; //Próximo do novo nó aponta para o próximo nó do nó auxiliar
      aux->proximo = novo; //Próximo nó do nó auxiliar aponta para o novo nó
      lista->tam++;
    }
  } else {
    printf("Erro ao alocar memória.\n");
  }
}

//Função para remover um elemento específico da lista
No* remover(Lista *lista, int num) {
  No *aux = lista->inicio, *removido = NULL;

  if (aux != NULL) {
    if (aux->valor == num) {
      removido = aux;
      if (aux->proximo == aux) { //Se só houver um elemento na lista
        lista->inicio = NULL;
        lista->fim = NULL;
      } else {
        lista->inicio = aux->proximo; //Próximo nó do início passa a ser o próximo do nó atual
        lista->fim->proximo = lista->inicio; //Próximo nó do último nó passa a ser o início da lista
      }
      lista->tam--;
    } else {
      while (aux->proximo != lista->inicio && aux->proximo->valor != num) {
        aux = aux->proximo; //Avança na lista até encontrar o nó anterior ao que será removido
      }
      if (aux->proximo != lista->inicio) {
        removido = aux->proximo;
        aux->proximo = aux->proximo->proximo; //Pula o nó que será removido
        lista->tam--;
      }
    }
  }
  return removido;
}

//Função para buscar um elemento na lista
No* buscar(Lista *lista, int num) {
  No *aux = lista->inicio;
  do {
    if (aux->valor == num) {
      return aux;
    }
    aux = aux->proximo;
  } while (aux != lista->inicio);
  return NULL; //Retorna NULL se o elemento não for encontrado
}

//Função para imprimir os elementos da lista
void imprimir(Lista lista) {
  No *aux = lista.inicio;
  printf("\nLista circular tam %d: ", lista.tam);
  if (aux != NULL) {
    do {
      printf("%d ", aux->valor);
      aux = aux->proximo;
    } while (aux != lista.inicio); //Percorre a lista até voltar ao início
    printf("\n");
  } else {
    printf("Lista vazia.\n");
  }
}

int main(void) {
  int opcao, valor;
  Lista lista;
  criar_lista(&lista);

  do {
    printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n4 - Buscar\n");
    scanf("%d", &opcao);

    switch(opcao) {
      case 1:
        printf("Valor: ");
        scanf("%d", &valor);
        inserir_ordenado(&lista, valor);
        break;
      case 2:
        printf("Valor: ");
        scanf("%d", &valor);
        No *removido = remover(&lista, valor);
        if (removido) {
          printf("Elemento removido: %d\n", removido->valor);
          free(removido);
        } else {
          printf("Elemento não encontrado.\n");
        }
        break;
      case 3:
        imprimir(lista);
        break;
      case 4:
        printf("Valor: ");
        scanf("%d", &valor);
        No *buscado = buscar(&lista, valor);
        if (buscado) {
          printf("Elemento encontrado: %d\n", buscado->valor);
        } else {
          printf("Elemento não encontrado.\n");
        }
        break;  
      default:
        if (opcao != 0)
          printf("Opção inválida.\n");
    }
  } while (opcao != 0);
  return 0;
}
