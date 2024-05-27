#include <stdio.h>
#include "endereco.h"

void imprimirEndereco(Endereco end){
    printf("\tDados do Endereco\n");
    printf("\nRua: %s", end.rua);
    printf("\nNúmero: %d", end.num);
    printf("\nBairro: %s", end.bairro);
    printf("\nCidade: %s", end.cidade);
    printf("\nPaís: %s", end.pais);
    printf("\nCEP: %d\n", end.cep);
}

Endereco lerEndereco(){
    Endereco end;
    printf("\nRua: ");
    fgets(end.rua, 50, stdin);
    printf("\nNº: ");
    scanf("%d", &end.num);
    getchar();
    printf("\nBairro: ");
    fgets(end.bairro, 50, stdin);
    printf("\nCEP: ");
    scanf("%d", &end.cep);
    getchar();
    printf("\nCidade: ");
    fgets(end.cidade, 50, stdin);
    printf("\nPais: ");
    fgets(end.pais, 50, stdin);
    return end;

    getchar();
    return end;
}