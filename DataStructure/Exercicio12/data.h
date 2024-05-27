#ifndef DATA_H
#define DATA_H

//Definição da estrutura Data
typedef struct {
    int dia, mes, ano;
} Data;

//Declaração das funções relacionadas a Data
void imprimirData(Data d);
Data lerData();

#endif
