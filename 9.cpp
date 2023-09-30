#include <stdio.h>
#include <locale.h>
#include <time.h>

typedef struct {
    char nome[100];
    char cargo[100];
    float salario;
    int diaAdmissao;
    int mesAdmissao;
    int anoAdmissao;
} Funcionario;

void darAumento(Funcionario *f, float porcentagem) {
    f->salario += f->salario * (porcentagem / 100.0);
}

int calcularTempoNaEmpresa(Funcionario f) {
    time_t t;
    struct tm *infoAtual, infoAdmissao;

    time(&t);
    infoAtual = localtime(&t);

    infoAdmissao.tm_mday = f.diaAdmissao;
    infoAdmissao.tm_mon = f.mesAdmissao - 1;
    infoAdmissao.tm_year = f.anoAdmissao - 1900;

    // Calcula a diferen�a em anos
    int anos = infoAtual->tm_year + 1900 - f.anoAdmissao;
    if (infoAtual->tm_mon < infoAdmissao.tm_mon ||
       (infoAtual->tm_mon == infoAdmissao.tm_mon && infoAtual->tm_mday < infoAdmissao.tm_mday)) {
        anos--;
    }

    return anos;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    Funcionario funcionario;

    printf("Digite o nome do funcion�rio: ");
    scanf(" %[^\n]", funcionario.nome);

    printf("Digite o cargo do funcion�rio: ");
    scanf(" %[^\n]", funcionario.cargo);

    printf("Digite o sal�rio do funcion�rio: ");
    scanf("%f", &funcionario.salario);

    printf("Digite a data de admiss�o (dd mm aaaa): ");
    scanf("%d %d %d", &funcionario.diaAdmissao, &funcionario.mesAdmissao, &funcionario.anoAdmissao);

    printf("\nO funcion�rio %s est� na empresa h� %d anos.\n", funcionario.nome, calcularTempoNaEmpresa(funcionario));

    float porcentagem;
    printf("\nDigite a porcentagem de aumento: ");
    scanf("%f", &porcentagem);
    darAumento(&funcionario, porcentagem);

    printf("Sal�rio ap�s aumento: %.2f\n", funcionario.salario);

    return 0;
}
