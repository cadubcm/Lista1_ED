#include <stdio.h>
#include <locale.h>

typedef struct {
    char nome[100];
    char matricula[20];
    float notas[3];
} Estudante;

float calcularMedia(Estudante aluno) {
    float soma = 0.0;
    for (int i = 0; i < 3; i++) {
        soma += aluno.notas[i];
    }
    return soma / 3.0;
}

int estaAprovado(Estudante aluno) {
    return calcularMedia(aluno) >= 7.0;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    Estudante aluno;

    printf("Digite o nome do estudante: ");
    scanf(" %[^\n]", aluno.nome);

    printf("Digite a matrícula do estudante: ");
    scanf(" %[^\n]", aluno.matricula);

    for (int i = 0; i < 3; i++) {
        printf("Digite a nota da disciplina %d: ", i + 1);
        scanf("%f", &aluno.notas[i]);
    }

    printf("\nMédia do aluno %s: %.2f\n", aluno.nome, calcularMedia(aluno));
    if (estaAprovado(aluno)) {
        printf("Status: Aprovado\n");
    } else {
        printf("Status: Reprovado\n");
    }

    return 0;
}
