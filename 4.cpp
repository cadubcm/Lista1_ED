#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100
#define TAM_NOME 100
#define TAM_TELEFONE 15

typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
} Contato;

Contato listaDeContatos[MAX_CONTATOS];
int contadorContatos = 0;

void adicionarContato() {
    if (contadorContatos < MAX_CONTATOS) {
        printf("Digite o nome: ");
        scanf(" %[^\n]", listaDeContatos[contadorContatos].nome);
        printf("Digite o telefone: ");
        scanf(" %[^\n]", listaDeContatos[contadorContatos].telefone);
        contadorContatos++;
    } else {
        printf("Lista de contatos esta cheia.\n");
    }
}

void listarContatos() {
    printf("\nLista de Contatos:\n");
    for (int i = 0; i < contadorContatos; i++) {
        printf("Nome: %s, Telefone: %s\n", listaDeContatos[i].nome, listaDeContatos[i].telefone);
    }
}

void buscarContato() {
    char nomeBusca[TAM_NOME];
    printf("Digite o nome do contato que deseja buscar: ");
    scanf(" %[^\n]", nomeBusca);
    for (int i = 0; i < contadorContatos; i++) {
        if (strcmp(nomeBusca, listaDeContatos[i].nome) == 0) {
            printf("Nome: %s, Telefone: %s\n", listaDeContatos[i].nome, listaDeContatos[i].telefone);
            return;
        }
    }
    printf("Contato nao encontrado.\n");
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Contato\n");
        printf("2. Listar Todos os Contatos\n");
        printf("3. Buscar Contato por Nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarContato(); break;
            case 2: listarContatos(); break;
            case 3: buscarContato(); break;
            case 4: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    return 0;
}
