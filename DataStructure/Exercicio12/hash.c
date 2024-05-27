#include <stdio.h>
#include <string.h>
#include "hash.h"

//Inicializa a tabela hash
void inicializarTabela(Pessoa t[], int tam){
    int i;

    for (i = 0; i < tam; i++)
        strcpy(t[i].nome, "");
}

//Função de hash para inteiros
int funcaoHash(int chave, int tam){
    return chave % tam;
}

//Função de hash para strings
int funcaoHashString(char str[], int tam){
    int soma = 0;
    for (int i = 0; str[i] != '\0'; i++)
        soma += str[i];
    return soma % tam;
}

//Insere uma pessoa na tabela hash
void inserir(Pessoa t[], char chave[], int tam){
    Pessoa p;
    p = lerPessoa();
    int id = funcaoHashString(chave, tam);
    while (strlen(t[id].nome) > 0){
        id = funcaoHashString(id + 1, tam);
    } 
    t[id] = p;
}

//Busca uma pessoa na tabela hash
Pessoa* busca(Pessoa t[], char chave[], int tam){
    int id = funcaoHashString(chave, tam);
    printf("\nIndice gerado: %d\n", id);
    while (strlen(t[id].nome) > 0){
        if (strcmp(t[id].nome, chave) == 0)
            return &t[id];
        else
            id = funcaoHashString(id + 1, tam);
    }
    return NULL;
}

//Imprime a tabela hash
void imprimir(Pessoa t[], int tam){
    int i;
    for (i = 0; i < tam; i++){
        printf("%d\n", i);
        if (t[i].cpf != 0)
            imprimirPessoa(t[i]);
        printf("\n----------\n");
    }
}
