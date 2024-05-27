//Manipulação de sequências de DNA utilizando uma fila e uma pilha.
#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 101 //Definimos 100+1 para incluir o caractere nulo

//Definição da estrutura de um nó
typedef struct no {
    char dados;
    struct no *proximo;
} No;

//Definição da estrutura da fila
typedef struct fila {
    No *inicio;
    No *fim;
} Fila;

//Definição da estrutura da pilha
typedef struct pilha {
    No *topo;
} Pilha;

//Adiciona um elemento no final da fila
void enfileirar(Fila *f, char dados) {
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->dados = dados;
    novo_no->proximo = NULL;

    if (f->fim == NULL) {
        f->inicio = novo_no;
        f->fim = novo_no;
    } else {
        f->fim->proximo = novo_no;
        f->fim = novo_no;
    }
}

//Remove e retorna o elemento do início da fila
char desenfileirar(Fila *f) {
    if (f->inicio == NULL) {
        printf("A fila está vazia!\n");
        return 0;
    }

    No *temp = f->inicio;
    char dados = temp->dados;
    f->inicio = f->inicio->proximo;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    return dados;
}

//Adiciona um elemento no topo da pilha
void empilhar(Pilha *p, char dados) {
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->dados = dados;
    novo_no->proximo = p->topo;
    p->topo = novo_no;
}

//Remove e retorna o elemento do topo da pilha
char desempilhar(Pilha *p) {
    if (p->topo == NULL) {
        printf("A pilha está vazia!\n");
        return 0;
    }

    No *temp = p->topo;
    char dados = temp->dados;
    p->topo = p->topo->proximo;
    free(temp);
    return dados;
}

int main() {
    char dna[TAM_MAX];
    int n;
    printf("Defina o tamanho da sequência de DNA: ");
    scanf("%d", &n);
    printf("Insira a sequência do DNA: ");
    scanf("%s", dna);

    Fila f = {NULL, NULL};
    Pilha p = {NULL};

    for (int i = 0; i < n; i++) {
        enfileirar(&f, dna[i]);
    }

    while (f.inicio != NULL) {
        char nucleotideo = desenfileirar(&f);
        switch (nucleotideo) {
        case 'A':
            empilhar(&p, 'T');
            break;
        case 'C':
            empilhar(&p, 'G');
            break;
        case 'T':
            empilhar(&p, 'A');
            break;
        case 'G':
            empilhar(&p, 'C');
            break;
        default:
            printf("Nucleotídeo inválido!\n");
            return 0;
        }
    }
    char *dna_reverso = (char *)malloc((n + 1) * sizeof(char)); //+1 para o nulo
    for (int i = 0; i < n; i++) {
        dna_reverso[i] = desempilhar(&p);
    }
    dna_reverso[n] = '\0'; //Terminando a string com o caractere nulo

    printf("Sequência original do DNA: %s \n", dna);
    printf("Sequência inversa do DNA: %s \n", dna_reverso);

    free(dna_reverso);
    return 0;
}
