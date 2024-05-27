//Cria uma estrutura para representar datas, e depois imprime a data.
#include <stdio.h>

//Definição da estrutura para representar datas
typedef struct {
    int dia, mes, ano;
} Data;

//Função para imprimir a data no formato dia/mês/ano
void imprimirData(Data *x) {
    printf("%d/%d/%d\n", x->dia, x->mes, x->ano);
}

int main(void) {
    Data data;
    Data *p;

    p = &data;

    printf("Endereço de data: %p\tConteúdo de p: %p\n", (void *)&data, (void *)p);
    data.dia = 7;
    data.mes = 2;
    data.ano = 2023;

    imprimirData(p);
    printf("%d/%d/%d\n", data.dia, data.mes, data.ano);

    return 0;
}
