#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Ponto;

float distancia(Ponto p1, Ponto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

float inclinacao(Ponto p1, Ponto p2) {
    if(p2.x - p1.x == 0) {
        printf("Inclinação é indefinida (reta vertical).\n");
        return 0;
    }
    return (p2.y - p1.y) / (p2.x - p1.x);
}

int main() {
    Ponto p1, p2;

    printf("Digite as coordenadas de P1 (x y): ");
    scanf("%f %f", &p1.x, &p1.y);
    
    printf("Digite as coordenadas de P2 (x y): ");
    scanf("%f %f", &p2.x, &p2.y);

    printf("Distancia entre P1 e P2: %.2f\n", distancia(p1, p2));
    printf("Inclinacao da reta conectando P1 e P2: %.2f\n", inclinacao(p1, p2));

    return 0;
}
