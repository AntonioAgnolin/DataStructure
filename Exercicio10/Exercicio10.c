//Lista encadeada para armazenar e manipular dados de usuários e veículos.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura para armazenar informações de um usuário
typedef struct {
  char nome[50];
  int idade;
} Usuario;

//Estrutura para armazenar informações de um veículo
typedef struct {
  char marca[50];
  char modelo[50];
  int ano;
} Veiculo;

//Estrutura de nó para a lista encadeada
typedef struct no {
  void* info;
  struct no* proximo;
} No;

//Estrutura da lista encadeada
typedef struct {
  No* inicio;
  No* fim;
  int tam;
} Lista;

//Inicializa uma lista encadeada
void criar_lista(Lista* lista) {
  lista->inicio = NULL;
  lista->fim = NULL;
  lista->tam = 0;
}

//Insere um novo elemento no início da lista
void inserir_inicio(Lista* lista, void* info) {
  No* novo = malloc(sizeof(No));

  if (novo) {
    novo->info = info;
    novo->proximo = lista->inicio;

    if (lista->inicio == NULL) {
      lista->fim = novo;
    }

    lista->inicio = novo;
    lista->tam++;
  } else {
    printf("Erro ao alocar memória.\n");
    exit(EXIT_FAILURE); //Encerra o programa em caso de falha na alocação de memória
  }
}

//Insere um novo elemento no final da lista
void inserir_fim(Lista* lista, void* info) {
  No* novo = malloc(sizeof(No));

  if (novo) {
    novo->info = info;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {
      lista->inicio = novo;
    } else {
      lista->fim->proximo = novo;
    }

    lista->fim = novo;
    lista->tam++;
  } else {
    printf("Erro ao alocar memória.\n");
    exit(EXIT_FAILURE); //Encerra o programa em caso de falha na alocação de memória
  }
}

//Imprime os dados dos usuários armazenados na lista
void imprimir_usuarios(Lista* lista) {
  No* no = lista->inicio;
  printf("\nLista de Usuários:\n");

  while (no) {
    Usuario* usuario = (Usuario*)no->info;
    printf("Nome: %s, Idade: %d\n", usuario->nome, usuario->idade);
    no = no->proximo;
  }
  printf("\n");
}

//Imprime os dados dos veículos armazenados na lista
void imprimir_veiculos(Lista* lista) {
  No* no = lista->inicio;
  printf("\nLista de Veículos:\n");

  while (no) {
    Veiculo* veiculo = (Veiculo*)no->info;
    printf("Marca: %s, Modelo: %s, Ano: %d\n", veiculo->marca, veiculo->modelo, veiculo->ano);
    no = no->proximo;
  }
  printf("\n");
}

//Libera a memória alocada para todos os nós e dados armazenados na lista
void liberar_lista(Lista* lista) {
  No* no = lista->inicio;

  while (no) {
    No* prox = no->proximo;
    free(no->info);
    free(no);
    no = prox;
  }

  lista->inicio = NULL;
  lista->fim = NULL;
  lista->tam = 0;
}

int main(void) {
  int opcao;
  Lista usuarios, veiculos;

  criar_lista(&usuarios);
  criar_lista(&veiculos);

  do {
    printf("\n0 - Sair\n1 - Cadastrar Usuário\n2 - Cadastrar Veículo\n3 - Imprimir Usuários\n4 - Imprimir Veículos\n");
    if (scanf("%d", &opcao) != 1) {
      printf("Entrada inválida.\n");
      while (getchar() != '\n'); //Limpa o buffer de entrada
      continue;
    }

    switch (opcao) {
      case 1: {
        Usuario* usuario = malloc(sizeof(Usuario));
        if (!usuario) {
          printf("Erro ao alocar memória para usuário.\n");
          exit(EXIT_FAILURE); //Encerra o programa em caso de falha na alocação de memória
        }
        printf("Nome: ");
        scanf("%49s", usuario->nome); //Evita estouro de buffer
        printf("Idade: ");
        if (scanf("%d", &usuario->idade) != 1) {
          printf("Entrada inválida.\n");
          free(usuario); //Libera a memória alocada para o usuário
          continue;
        }

        inserir_inicio(&usuarios, usuario);
        break;
      }
      case 2: {
        Veiculo* veiculo = malloc(sizeof(Veiculo));
        if (!veiculo) {
          printf("Erro ao alocar memória para veículo.\n");
          exit(EXIT_FAILURE); //Encerra o programa em caso de falha na alocação de memória
        }
        printf("Marca: ");
        scanf("%49s", veiculo->marca); //Evita estouro de buffer
        printf("Modelo: ");
        scanf("%49s", veiculo->modelo); //Evita estouro de buffer
        printf("Ano: ");
        if (scanf("%d", &veiculo->ano) != 1) {
          printf("Entrada inválida.\n");
          free(veiculo); //Libera a memória alocada para o veículo
          continue;
        }

        inserir_fim(&veiculos, veiculo);
        break;
      }
      case 3:
        imprimir_usuarios(&usuarios);
        break;
      case 4:
        imprimir_veiculos(&veiculos);
        break;
      default:
        if (opcao != 0)
          printf("Opção inválida.\n");
    }
  } while (opcao != 0);

  liberar_lista(&usuarios);
  liberar_lista(&veiculos);

  return 0;
}
