#ifndef PESSOA_H
#define PESSOA_H

#include "data.h"
#include "endereco.h"
#include "contrato.h"

//Definição da estrutura Pessoa
typedef struct {
    char nome[50];
    int cpf;
    Data dataNasc;
    Endereco end;
    Contrato contr;
} Pessoa;

//Declaração das funções relacionadas a Pessoa
void imprimirPessoa(Pessoa p);
Pessoa lerPessoa();

#endif
