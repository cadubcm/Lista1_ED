#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
    char nome[100];
    int idade;
    float altura;
} Pessoa;

int main() {
    Pessoa pessoa;

    printf("Digite o nome: ");
    fgets(pessoa.nome, 99, stdin);

    printf("Digite a idade: ");
    scanf("%d", &pessoa.idade);

    printf("Digite a altura (em cm): ");
    scanf("%f", &pessoa.altura);

    printf("\nDados da Pessoa:\n");
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d anos\n", pessoa.idade);
    printf("Altura: %.2f cm\n", pessoa.altura);

    return 0;
}
