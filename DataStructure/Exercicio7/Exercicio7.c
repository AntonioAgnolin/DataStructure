//Fila com prioridade.
#include <stdio.h>
#include <stdlib.h>

//Definição da estrutura de um nó
typedef struct no {
  int numero;
  struct no *proximo;
} No;

//Definição da estrutura da fila
typedef struct fila {
  No *inicio;
  No *fim;
  int tamanho;
} Fila;

//Inicializa uma fila
void nova_fila(Fila *fila) {
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->tamanho = 0;
}

//Adiciona um número inteiro à fila
void enfileirar(Fila *fila, int n) {
  No *novo_numero = malloc(sizeof(No));

  if (novo_numero) {
    novo_numero->numero = n;
    novo_numero->proximo = NULL;

    if (fila->inicio == NULL) {
      fila->inicio = novo_numero;
      fila->fim = novo_numero;
    } else {
      fila->fim->proximo = novo_numero;
      fila->fim = novo_numero;
    }
    fila->tamanho++;
  } else {
    printf("\nErro ao alocar memória.\n");
  }
}

//Remove o primeiro elemento da fila, decrementando o tamanho
void desenfileirar(Fila *fila) {
  No *remover = NULL;

  if (fila->inicio) {
    remover = fila->inicio;
    fila->inicio = remover->proximo;
    if (fila->inicio == NULL) {
      fila->fim = NULL;
    }
    free(remover);
    fila->tamanho--;
  } else {
    printf("\nFila vazia.\n");
  }
}

//Remove o elemento da fila e retorna o nó removido
No *remover(Fila *fila) {
  No *remove = NULL;

  if (fila->inicio) {
    remove = fila->inicio;
    fila->inicio = remove->proximo;
    if (fila->inicio == NULL) {
      fila->fim = NULL;
    }
    fila->tamanho--;
  } else {
    printf("\nFila vazia.\n");
  }
  return remove;
}

//Insere um número na fila com base em uma regra de prioridade específica
void prioridade(Fila *fila, int num) {
  No *aux, *novo_numero = malloc(sizeof(No));
  if (novo_numero) {
    novo_numero->numero = num;
    novo_numero->proximo = NULL;
    if (fila->inicio == NULL) {
      fila->inicio = novo_numero;
      fila->fim = novo_numero;
    } else {
      if (num > 59) {
        if (fila->inicio->numero < 60) {
          novo_numero->proximo = fila->inicio;
          fila->inicio = novo_numero;
        } else {
          aux = fila->inicio;
          while (aux->proximo && aux->proximo->numero >= 60) {
            aux = aux->proximo;
          }
          novo_numero->proximo = aux->proximo;
          aux->proximo = novo_numero;
          if (novo_numero->proximo == NULL) {
            fila->fim = novo_numero;
          }
        }
      } else {
        fila->fim->proximo = novo_numero;
        fila->fim = novo_numero;
      }
    }
    fila->tamanho++;
  } else {
    printf("\nErro ao alocar memória.\n");
  }
}

//Imprime os elementos da fila
void imprimir(Fila *fila) {
  printf("\nFila:\n");
  No *aux = fila->inicio;
  while (aux) {
    printf("%d ", aux->numero);
    aux = aux->proximo;
  }
  printf("\nFim da Fila\n");
}

int main() {
  int opcao, numero;
  Fila fila;
  No *r;

  nova_fila(&fila);

  do {
    printf("\n0 - Sair\n1 - Enfileirar\n2 - Desenfileirar\n3 - Enfileirar com Prioridade\n4 - Imprimir\n");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Insira um número: ");
      scanf("%d", &numero);
      enfileirar(&fila, numero);
      break;
    case 2:
      r = remover(&fila);
      if (r) {
        printf("Removido: %d\n", r->numero);
        free(r);
      }
      break;
    case 3:
      printf("Insira um número: ");
      scanf("%d", &numero);
      prioridade(&fila, numero);
      break;
    case 4:
      imprimir(&fila);
      break;
    default:
      if (opcao != 0)
        printf("\nOpção inválida.\n");
    }
  } while (opcao != 0);
  return 0;
}
