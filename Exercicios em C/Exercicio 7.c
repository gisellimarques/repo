#include <stdio.h>

#define N 4

void lerMatriz(int m[N][N]) {
    printf("Digite os elementos da matriz %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &m[i][j]);
        }
    }
}

void transposta(int m[N][N], int t[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            t[j][i] = m[i][j];  // troca linha por coluna
        }
    }
}

void imprimirMatriz(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[N][N];
    int trans[N][N];

    lerMatriz(matriz);
    transposta(matriz, trans);

    printf("\nMatriz Original:\n");
    imprimirMatriz(matriz);

    printf("\nMatriz Transposta:\n");
    imprimirMatriz(trans);

    return 0;
}
