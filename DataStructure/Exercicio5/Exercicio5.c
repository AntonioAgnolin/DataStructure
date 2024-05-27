//Define e manipula uma fila usando uma lista encadeada.
#include <stdio.h>
#include <stdlib.h>

//Definição da estrutura de um nó
typedef struct no {
    int valor;
    struct no *proximo;
} No;

//Definição da estrutura da fila
typedef struct {
    No *prim;
    No *fim;
    int tam;
} Fila;

//Função para inicializar uma fila
void criar_fila(Fila *fila) {
    fila->prim = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

//Função para inserir um valor na fila
void inserir(Fila *fila, int num) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = num;
        novo->proximo = NULL;
        if (fila->prim == NULL) {
            fila->prim = novo;
            fila->fim = novo;
        } else {
            fila->fim->proximo = novo;
            fila->fim = novo;
        }
        fila->tam++;
    } else {
        printf("\nErro ao alocar memória.\n");
    }
}

//Função para remover um valor da fila
int remover(Fila *fila) {
    if (fila->prim != NULL) {
        No *remover = fila->prim;
        int valor = remover->valor;
        fila->prim = remover->proximo;
        if (fila->prim == NULL) {
            fila->fim = NULL;
        }
        free(remover);
        fila->tam--;
        return valor;
    } else {
        printf("\nFila vazia.\n");
        return -1; //Indicador de erro
    }
}

//Função para imprimir os valores da fila
void imprimir(Fila *fila) {
    No *atual = fila->prim;
    while (atual) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    Fila fila;
    criar_fila(&fila);

    inserir(&fila, 10);
    inserir(&fila, 20);
    inserir(&fila, 30);

    imprimir(&fila); //Deve imprimir: 10 20 30

    int valor_removido = remover(&fila);
    if (valor_removido != -1) {
        printf("Removido: %d\n", valor_removido);
    }

    imprimir(&fila); //Deve imprimir: 20 30

    valor_removido = remover(&fila);
    if (valor_removido != -1) {
        printf("Removido: %d\n", valor_removido);
    }

    imprimir(&fila); //Deve imprimir: 30

    valor_removido = remover(&fila);
    if (valor_removido != -1) {
        printf("Removido: %d\n", valor_removido);
    }

    imprimir(&fila); //Deve imprimir: nada, pois a fila está vazia

    return 0;
}
