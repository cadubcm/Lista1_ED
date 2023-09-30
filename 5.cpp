#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_LIVROS 100
#define TAM_TITULO 100
#define TAM_AUTOR 100

typedef struct {
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    int anoPublicacao;
} Livro;

Livro biblioteca[MAX_LIVROS];
int contadorLivros = 0;

void adicionarLivro() {
    if (contadorLivros < MAX_LIVROS) {
        printf("Digite o t�tulo do livro: ");
        scanf(" %[^\n]", biblioteca[contadorLivros].titulo);
        printf("Digite o nome do autor: ");
        scanf(" %[^\n]", biblioteca[contadorLivros].autor);
        printf("Digite o ano de publica��o: ");
        scanf("%d", &biblioteca[contadorLivros].anoPublicacao);
        contadorLivros++;
    } else {
        printf("Biblioteca est� cheia.\n");
    }
}

void listarLivros() {
    printf("\nLista de Livros:\n");
    for (int i = 0; i < contadorLivros; i++) {
        printf("T�tulo: %s, Autor: %s, Ano: %d\n", biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].anoPublicacao);
    }
}

void buscarLivroPorAutor() {
    char autorBusca[TAM_AUTOR];
    int encontrou = 0;

    printf("Digite o nome do autor que deseja buscar: ");
    scanf(" %[^\n]", autorBusca);

    for (int i = 0; i < contadorLivros; i++) {
        if (strcmp(autorBusca, biblioteca[i].autor) == 0) {
            printf("T�tulo: %s, Ano: %d\n", biblioteca[i].titulo, biblioteca[i].anoPublicacao);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum livro do autor '%s' foi encontrado.\n", autorBusca);
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Todos os Livros\n");
        printf("3. Buscar Livros por Autor\n");
        printf("4. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarLivro(); break;
            case 2: listarLivros(); break;
            case 3: buscarLivroPorAutor(); break;
            case 4: printf("Saindo...\n"); break;
            default: printf("Op��o inv�lida.\n");
        }
    } while (opcao != 4);

    return 0;
}
