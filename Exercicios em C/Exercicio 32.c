#include <stdio.h>

int somaImpares(int v[], int n) {
    if (n == 0)
        return 0;

    int resto = somaImpares(v, n - 1);

    if (v[n - 1] % 2 != 0)
        resto += v[n - 1];

    return resto;
}

void imprimeSomaImpares(int v[], int n) {
    int soma = somaImpares(v, n);
    printf("Soma dos ímpares = %d\n", soma);
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 7, 8};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    imprimeSomaImpares(vetor, n);

    return 0;
}
