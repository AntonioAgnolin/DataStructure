//Algoritmo de Dijkstra para encontrar o menor caminho em um grafo ponderado representado por
//uma matriz de adjacência, permitindo escolher vértices de origem e destino e 
//exibindo o menor caminho e sua distância total.
#include <stdio.h>
#include <limits.h>

#define V 6  //Número de vértices

//Função para imprimir o menu de opções de vértices
void imprimirMenu() {
    printf("\nMenu de Vertices:\n");
    for (int i = 0; i < V; i++) {
        printf("%d. V%d\n", i, i + 1);
    }
}

//Função para obter o vértice escolhido pelo usuário
int obterVertice() {
    int vertice;
    printf("Digite o número do vértice: ");
    scanf("%d", &vertice);
    return vertice;
}

//Função para encontrar o vértice com a distância mínima do conjunto de vértices ainda não incluídos
int menorDistancia(int distancias[], int conjuntoSPT[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (conjuntoSPT[v] == 0 && distancias[v] <= min) {
            min = distancias[v];
            min_index = v;
        }
    }

    return min_index;
}

//Função para imprimir o caminho mínimo a partir da origem até um vértice
void imprimirCaminho(int caminho[], int j) {
    if (caminho[j] == -1)
        return;

    imprimirCaminho(caminho, caminho[j]);
    printf(" -> V%d ", j + 1); //Adicionado +1 para ajustar a numeração dos vértices
}

//Função para imprimir a solução após executar o algoritmo de Dijkstra
void imprimirSolucao(int distancias[], int origem, int destino, int caminho[]) {
    printf("\nMenor caminho entre V%d e V%d:\n", origem + 1, destino + 1); //Adicionado +1 para ajustar a numeração dos vértices
    printf("V%d -> ", origem + 1); //Adicionado +1 para ajustar a numeração dos vértices
    imprimirCaminho(caminho, destino);
    printf("\nDistância total: %d\n", distancias[destino]);
}

//Função principal que implementa o algoritmo de Dijkstra
void dijkstra(int origem, int destino) {
    int distancias[V];
    int conjuntoSPT[V];
    int caminho[V];

    //Inicializar todas as distâncias como infinito e o conjunto SPT como falso
    for (int i = 0; i < V; i++) {
        distancias[i] = INT_MAX;
        conjuntoSPT[i] = 0;
        caminho[i] = -1;
    }

    //A distância da origem para ela mesma é sempre 0
    distancias[origem] = 0;

    //Encontrar o caminho mínimo para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        int u = menorDistancia(distancias, conjuntoSPT);

        conjuntoSPT[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!conjuntoSPT[v] && grafo[u][v] && distancias[u] != INT_MAX &&
                distancias[u] + grafo[u][v] < distancias[v]) {
                distancias[v] = distancias[u] + grafo[u][v];
                caminho[v] = u;
            }
        }
    }

    imprimirSolucao(distancias, origem, destino, caminho);
}

int main() {
    //Definição do grafo com os pesos das arestas
    int grafo[V][V] = {
        {0, 15, 9, 0, 0, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 4, 0, 0, 3, 16},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0}
    };

    imprimirMenu();

    printf("Escolha o vértice de origem:\n");
    int origem = obterVertice();

    printf("Escolha o vértice de destino:\n");
    int destino = obterVertice();

    //Verificar se os vértices escolhidos são válidos
    if (origem < 0 || origem >= V || destino < 0 || destino >= V) {
        printf("Vértice inválido. Certifique-se de escolher um número entre 0 e %d.\n", V - 1);
        return 1;
    }

    dijkstra(origem, destino);

    return 0;
}
