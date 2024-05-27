#ifndef CONTRATO_H
#define CONTRATO_H

#include "data.h"

//Definição da estrutura Contrato
typedef struct {
    int codigo;
    Data dataAss;
    char cargo[50];
    float salario;
} Contrato;

//Declaração das funções relacionadas a Contrato
void imprimirContrato(Contrato c);
Contrato lerContrato();

#endif
