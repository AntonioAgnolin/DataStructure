#ifndef HASH_H
#define HASH_H

#include "pessoa.h"  

//Declaração das funções relacionadas a hash
void inicializarTabela(Pessoa t[], int tam);
int funcaoHash(int chave, int tam);
int funcaoHashString(char str[], int tam);
void inserir(Pessoa t[], char chave[], int tam);
Pessoa* busca(Pessoa t[], char chave[], int tam);
void imprimir(Pessoa t[], int tam);

#endif
