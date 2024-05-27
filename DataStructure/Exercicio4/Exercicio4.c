//Implementa uma fila utilizando uma lista encadeada
#include <stdio.h>
#include <stdlib.h>

//Definição da estrutura de um nó
typedef struct no {
  int valor;
  struct no *proximo;
} No;

//Função para inserir um valor na fila
void inserir(No **fila, int num) {
  No *aux, *novo = malloc(sizeof(No));
  if (novo) {
    novo->valor = num;
    novo->proximo = NULL;
    if (*fila == NULL) {
      *fila = novo; //Se a fila estiver vazia, o novo nó é o primeiro nó
    } else {
      aux = *fila;
      while (aux->proximo) {
        aux = aux->proximo; //Percorre até o final da fila
      }
      aux->proximo = novo; //Adiciona o novo nó no final da fila
    }
  } else {
    printf("\nErro ao alocar memória.\n");
  }
}

//Função para remover um valor da fila
No *remover(No **fila) {
  No *remove = NULL;
  if (*fila) {
    remove = *fila;
    *fila = remove->proximo; //Segundo nó se torna o primeiro
  } else {
    printf("\nFila vazia.\n");
  }
  return remove;
}

//Função para imprimir os valores da fila
void imprimir(No *fila) {
  while (fila) {
    printf("%d ", fila->valor);
    fila = fila->proximo;
  }
  printf("\n");
}

int main() {
    No *r, *fila = NULL;
    int opcao, valor;

    do {
        printf("\n0 - Sair \n1 - Inserir \n2 - Remover \n3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir(&fila, valor);
            break;
        case 2:
            r = remover(&fila);
            if (r) {
                printf("Removido: %d\n", r->valor);
                free(r);
            }
            break;
        case 3:
            imprimir(fila);
            break;
        default:
            if (opcao != 0)
                printf("\nOpção inválida.\n");
        }
    } while (opcao != 0);

    //Libera a memória de todos os nós restantes na fila
    while (fila) {
        r = remover(&fila);
        free(r);
    }

    return 0;
}
