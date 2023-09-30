#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
    int valorInteiro;
    float valorFloat;
    char letra;
} Tipo;

int main() {
    Tipo exemplo;

    exemplo.valorInteiro = 10;
    exemplo.valorFloat = 3.14;
    exemplo.letra = 'A';

    printf("Inteiro: %d\n", exemplo.valorInteiro);
    printf("Ponto Flutuante: %.2f\n", exemplo.valorFloat);
    printf("Letra: %c\n", exemplo.letra);

    return 0;
}
