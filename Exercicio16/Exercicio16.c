//Interface com algoritmos de ordenação Bubble Sort, Insertion Sort, Selection Sort, 
//Merge Sort e QuickSort.
#include <stdio.h>
#include <stdlib.h>

//Função para imprimir o menu de opções de ordenação
void imprimirMenu() {
    printf("\nMenu de Ordenacao:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Merge Sort\n");
    printf("5. QuickSort\n");
    printf("6. Sair\n");
}

//Função para trocar dois elementos de posição em um array
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Implementação do algoritmo Bubble Sort
void bubbleSort(int arr[], int n, int *comparacoes) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparacoes)++;
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

//Implementação do algoritmo Insertion Sort
void insertionSort(int arr[], int n, int *comparacoes) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            (*comparacoes)++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

//Implementação do algoritmo Selection Sort
void selectionSort(int arr[], int n, int *comparacoes) {
    int i, j, indice_minimo;
    for (i = 0; i < n - 1; i++) {
        indice_minimo = i;
        for (j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (arr[j] < arr[indice_minimo]) {
                indice_minimo = j;
            }
        }
        trocar(&arr[indice_minimo], &arr[i]);
    }
}

//Implementação do algoritmo Merge Sort
void merge(int arr[], int l, int m, int r, int *comparacoes) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        (*comparacoes)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//Implementação do algoritmo Merge Sort
void mergeSort(int arr[], int l, int r, int *comparacoes) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparacoes);
        mergeSort(arr, m + 1, r, comparacoes);
        merge(arr, l, m, r, comparacoes);
    }
}

//Função para particionar o array no algoritmo QuickSort
int particionar(int arr[], int baixo, int alto, int *comparacoes) {
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        (*comparacoes)++;
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

//Implementação do algoritmo QuickSort
void quickSort(int arr[], int baixo, int alto, int *comparacoes) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto, comparacoes);
        quickSort(arr, baixo, pi - 1, comparacoes);
        quickSort(arr, pi + 1, alto, comparacoes);
    }
}

//Função para imprimir os elementos de um array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int escolha;
    do {
        imprimirMenu();
        printf("Escolha uma opcao (1-6): ");
        scanf("%d", &escolha);

        //Solicita o tamanho do array
        printf("Digite o tamanho do array: ");
        int n;
        scanf("%d", &n);

        int arr[n];

        //Solicita os elementos do array
        printf("Digite os elementos do array:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int comparacoes = 0;

        switch (escolha) {
            case 1:
                bubbleSort(arr, n, &comparacoes);
                printf("Bubble Sort: ");
                imprimirArray(arr, n);
                break;
            case 2:
                insertionSort(arr, n, &comparacoes);
                printf("Insertion Sort: ");
                imprimirArray(arr, n);
                break;
            case 3:
                selectionSort(arr, n, &comparacoes);
                printf("Selection Sort: ");
                imprimirArray(arr, n);
                break;
            case 4:
                mergeSort(arr, 0, n - 1, &comparacoes);
                printf("Merge Sort: ");
                imprimirArray(arr, n);
                break;
            case 5:
                quickSort(arr, 0, n - 1, &comparacoes);
                printf("QuickSort: ");
                imprimirArray(arr, n);
                break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

        printf("Total de comparacoes: %d\n", comparacoes);

    } while (escolha != 6);

    return 0;
}
