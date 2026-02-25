#include <stdio.h>

void inicializarVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = (i + 1) * 5;  // múltiplos de 5
    }
}

void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int n = 10;
    int vetor[n];

    inicializarVetor(vetor, n);
    imprimirVetor(vetor, n);

    return 0;
}
