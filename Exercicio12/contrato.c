#include <stdio.h>
#include "contrato.h"

void imprimirContrato(Contrato c){
    printf("\tDados do Contrato\n");
    printf("\nContrato: %d", c.codigo);
    printf("\nData de admissão: ");
    imprimirData(c.dataAss);
    printf("\nCargo: %s", c.cargo);
    printf("\nSalário: %.2f\n", c.salario);
}

Contrato lerContrato(){
    Contrato c;
    printf("\nData de assinatura: ");
    c.dataAss = lerData();
    printf("\nCargo: ");
    fgets(c.cargo, 50, stdin);
    printf("\nSalário: ");
    scanf("%f", &c.salario);
    getchar();
    return c;
}