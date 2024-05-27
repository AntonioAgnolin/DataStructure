#ifndef ENDERECO_H
#define ENDERECO_H

//Definição da estrutura Endereço
typedef struct {
    char rua[50];
    char bairro[50];
    char cidade[50];
    char pais[50];
    int num, cep;
} Endereco;

//Declaração das funções relacionadas a Endereço
void imprimirEndereco(Endereco end);
Endereco lerEndereco();

#endif
