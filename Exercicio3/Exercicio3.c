//Copia a string de origem para o destino.
#include <stdio.h>
#include <stdlib.h>

//Função personalizada para copiar uma string de origem para destino
int strcpy(char *destino, const char *origem) {
    int i = 0;
    
    while (*(origem + i) != '\0') {
        *(destino + i) = *(origem + i);
        i++;
    }
    
    *(destino + i) = '\0';
    return i;
}

int main(void) {
    char origem[] = "String de origem";
    char destino[50]; 
    
    int num_caracteres_copiados = strcpy(destino, origem);

    printf("String copiada: %s\n", destino);
    printf("Número de caracteres copiados: %d\n", num_caracteres_copiados);

    return 0;
}
