#include <stdio.h>
#include <locale.h>

typedef struct {
    char titular[100];
    int numeroConta;
    float saldo;
} ContaBancaria;

void depositar(ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Depósito de %.2f realizado com sucesso!\n", valor);
}

void sacar(ContaBancaria *conta, float valor) {
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de %.2f realizado com sucesso!\n", valor);
    } else {
        printf("Saldo insuficiente!\n");
    }
}

void verificarSaldo(ContaBancaria conta) {
    printf("Saldo atual: %.2f\n", conta.saldo);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    ContaBancaria minhaConta;
    int opcao;
    float valor;

    printf("Digite o nome do titular da conta: ");
    scanf(" %[^\n]", minhaConta.titular);
    printf("Digite o número da conta: ");
    scanf("%d", &minhaConta.numeroConta);
    minhaConta.saldo = 0.0;

    do {
        printf("\nMenu:\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Verificar Saldo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor para depósito: ");
                scanf("%f", &valor);
                depositar(&minhaConta, valor);
                break;
            case 2:
                printf("Digite o valor para saque: ");
                scanf("%f", &valor);
                sacar(&minhaConta, valor);
                break;
            case 3:
                verificarSaldo(minhaConta);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    return 0;
}
