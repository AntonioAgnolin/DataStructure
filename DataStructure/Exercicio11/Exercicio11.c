//Lista circular duplamente encadeada com inserção ordenada, remoção, busca e impressão em ordem crescente ou decrescente.
#include <stdio.h>
#include <stdlib.h>

//Definição da estrutura do nó
typedef struct No {
    int valor;
    struct No* anterior;
    struct No* proximo;
} No;

//Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    return novoNo;
}

//Definição da estrutura da lista duplamente encadeada
typedef struct DoublyLinkedList {
    No* topo;
} DoublyLinkedList;

//Função para inserir um valor na lista mantendo a ordenação
void inserirOrdenado(DoublyLinkedList* lista, int valor) {
    No* novoNo = criarNo(valor);

    //Caso a lista esteja vazia
    if (lista->topo == NULL) {
        lista->topo = novoNo;
        novoNo->proximo = novoNo;
        novoNo->anterior = novoNo;
    } else if (valor <= lista->topo->valor) { //Inserção no início
        No* ultimo = lista->topo->anterior;
        novoNo->proximo = lista->topo;
        novoNo->anterior = ultimo;
        ultimo->proximo = novoNo;
        lista->topo->anterior = novoNo;
        lista->topo = novoNo;
    } else { //Inserção no meio ou fim
        No* atual = lista->topo->proximo;
        while (atual != lista->topo && valor > atual->valor) {
            atual = atual->proximo;
        }

        No* anterior = atual->anterior;
        novoNo->proximo = atual;
        novoNo->anterior = anterior;
        anterior->proximo = novoNo;
        atual->anterior = novoNo;
    }
}

//Função para remover um valor da lista
void removerNo(DoublyLinkedList* lista, int valor) {
    if (lista->topo == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    No* atual = lista->topo;

    do {
        if (atual->valor == valor) {
            if (atual == lista->topo && atual->proximo == lista->topo) {
                lista->topo = NULL;
            } else {
                No* anterior = atual->anterior;
                No* proximo = atual->proximo;

                anterior->proximo = proximo;
                proximo->anterior = anterior;

                if (atual == lista->topo) {
                    lista->topo = proximo;
                }
            }

            free(atual);
            printf("Elemento %d removido com sucesso.\n", valor);
            return;
        }

        atual = atual->proximo;
    } while (atual != lista->topo);

    printf("O elemento %d não está presente na lista.\n", valor);
}

//Função para buscar um valor na lista
No* buscar(DoublyLinkedList* lista, int valor) {
    if (lista->topo == NULL) {
        return NULL;
    }

    No* atual = lista->topo;

    do {
        if (atual->valor == valor) {
            return atual;
        }

        atual = atual->proximo;
    } while (atual != lista->topo);

    return NULL;
}

//Função para imprimir a lista em ordem crescente
void imprimirCrescente(DoublyLinkedList* lista) {
    if (lista->topo == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Lista (crescente): ");
    No* atual = lista->topo;

    do {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    } while (atual != lista->topo);

    printf("\n");
}

//Função para imprimir a lista em ordem decrescente
void imprimirDecrescente(DoublyLinkedList* lista) {
    if (lista->topo == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Lista (decrescente): ");
    No* atual = lista->topo->anterior;

    do {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    } while (atual != lista->topo->anterior);

    printf("\n");
}

int main() {
    DoublyLinkedList lista;
    lista.topo = NULL;

    int opcao = 0;
    int numero;

    while (opcao != 6) {
        printf("\nSelecione uma opcao:\n");
        printf("1. Inserir ordenado\n");
        printf("2. Remover\n");
        printf("3. Buscar\n");
        printf("4. Imprimir crescente\n");
        printf("5. Imprimir decrescente\n");
        printf("6. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero a ser inserido: ");
                scanf("%d", &numero);
                inserirOrdenado(&lista, numero);
                break;
            case 2:
                printf("Digite o numero a ser removido: ");
                scanf("%d", &numero);
                removerNo(&lista, numero);
                break;
            case 3:
                printf("Digite o numero a ser buscado: ");
                scanf("%d", &numero);
                No* encontrado = buscar(&lista, numero);
                if (encontrado != NULL) {
                    printf("Elemento %d encontrado na lista.\n", numero);
                } else {
                    printf("Elemento %d nao encontrado na lista.\n", numero);
                }
                break;
            case 4:
                imprimirCrescente(&lista);
                break;
            case 5:
                imprimirDecrescente(&lista);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
