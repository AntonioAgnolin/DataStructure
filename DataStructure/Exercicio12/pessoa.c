#include <stdio.h>
#include "data.h"
#include "pessoa.h"

void imprimirPessoa(Pessoa p) {
    printf("\tDados da pessoa\n");
    if (strlen(p.nome) > 0) {
        printf("Nome: %s\n", p.nome);
        printf("CPF: %d\n", p.cpf);
        printf("Data de Nascimento: ");
        imprimirData(p.dataNasc);
        imprimirEndereco(p.end);
        imprimirContrato(p.contr);
    } else {
        printf("Pessoa não encontrada.\n");
    }
}

Pessoa lerPessoa() {
    Pessoa p;
    printf("\nNome: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';
    printf("\nCPF: ");
    scanf("%d", &p.cpf);
    printf("\nData de Nascimento: ");
    p.dataNasc = lerData();
    p.contr = lerContrato();
    p.end = lerEndereco();
    getchar();
    return p;
}