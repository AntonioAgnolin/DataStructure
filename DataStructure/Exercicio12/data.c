#include <stdio.h>
#include "data.h"

void imprimirData(Data d){
    printf("%d/%d/%d", d.dia, d.mes, d.ano);
}

Data lerData(){
    Data d;
    printf("\nDigite a data no formato DD MM AAAA: ");
    scanf("%d/%d/%d", &d.dia, &d.mes, &d.ano);
    getchar();
    return d;
}