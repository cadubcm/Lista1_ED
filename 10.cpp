#include <stdio.h>
#include <locale.h>

typedef struct {
    float dolar;
    float euro;
} Moeda;

float converterParaDolar(Moeda m, float taxaCambio) {
    return m.euro * taxaCambio;
}

float converterParaEuro(Moeda m, float taxaCambio) {
    return m.dolar / taxaCambio;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    Moeda m;
    int opcao;
    float taxaCambio;

    printf("Digite a taxa de câmbio atual (1 euro em dólares): ");
    scanf("%f", &taxaCambio);

    do {
        printf("\nMenu:\n");
        printf("1. Converter dólares para euros\n");
        printf("2. Converter euros para dólares\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor em dólares: ");
                scanf("%f", &m.dolar);
                printf("Valor em euros: %.2f\n", converterParaEuro(m, taxaCambio));
                break;
            case 2:
                printf("Digite o valor em euros: ");
                scanf("%f", &m.euro);
                printf("Valor em dólares: %.2f\n", converterParaDolar(m, taxaCambio));
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 3);

    return 0;
}
