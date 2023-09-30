#include <stdio.h>
#include <locale.h>

typedef struct {
    char nome[100];
    float preco;
    int quantidadeEstoque;
} Produto;

void comprar(Produto *p, int quantidade) {
    if (quantidade <= p->quantidadeEstoque) {
        float totalCompra = quantidade * p->preco;
        p->quantidadeEstoque -= quantidade;
        printf("Compra realizada com sucesso!\n");
        printf("Total da compra: %.2f\n", totalCompra);
    } else {
        printf("Quantidade solicitada indisponível em estoque.\n");
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    Produto produto;

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", produto.nome);
    printf("Digite o preço do produto: ");
    scanf("%f", &produto.preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto.quantidadeEstoque);

    int opcao, quantidadeCompra;

    do {
        printf("\nMenu:\n");
        printf("1. Comprar produto\n");
        printf("2. Ver informações do produto\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a quantidade que deseja comprar: ");
                scanf("%d", &quantidadeCompra);
                comprar(&produto, quantidadeCompra);
                break;
            case 2:
                printf("\nNome do produto: %s\n", produto.nome);
                printf("Preço: %.2f\n", produto.preco);
                printf("Quantidade em estoque: %d\n", produto.quantidadeEstoque);
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
