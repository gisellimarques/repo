#include <stdio.h>

#define N 3 // Tamanho da matriz (3x3)

void lerMatriz(int mat[N][N], char nome);
void imprimirMatriz(int mat[N][N]);
void somarMatrizes(int A[N][N], int B[N][N], int resultado[N][N]);
void somarDiagonais(int mat[N][N], int *somaPrincipal, int *somaSecundaria);
void multiplicarMatrizes(int A[N][N], int B[N][N], int resultado[N][N]);

int main() {
    int matA[N][N], matB[N][N];
    int resSoma[N][N], resMult[N][N];
    int dp, ds;
    printf("Digite os valores da Matriz A:\n");
    lerMatriz(matA, 'A');

    printf("\nDigite os valores da Matriz B:\n");
    lerMatriz(matB, 'B');

    // a) Soma das Matrizes
    somarMatrizes(matA, matB, resSoma);
    printf("\n[A] Resultado da Soma (A + B):\n");
    imprimirMatriz(resSoma);

    // b) Soma das Diagonais
    printf("\n[B] Analise das Diagonais:\n");

    somarDiagonais(matA, &dp, &ds);
    printf("Matriz A -> Diagonal Principal: %d | Diagonal Secundaria: %d\n", dp, ds);

    somarDiagonais(matB, &dp, &ds);
    printf("Matriz B -> Diagonal Principal: %d | Diagonal Secundaria: %d\n", dp, ds);

    // c) Multiplicação das Matrizes
    multiplicarMatrizes(matA, matB, resMult);
    printf("\n[C] Resultado da Multiplicacao (A * B):\n");
    imprimirMatriz(resMult);

    return 0;
}

//Implementação das funções

// Função auxiliar para ler a matriz
void lerMatriz(int mat[N][N], char nome) {
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%c[%d][%d]: ", nome, i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Função auxiliar para imprimir a matriz
void imprimirMatriz(int mat[N][N]) {
    int i, j;
    for(i = 0; i < N; i++) {
        printf("| ");
        for(j = 0; j < N; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("|\n");
    }
}

// a) Soma de duas matrizes
void somarMatrizes(int A[N][N], int B[N][N], int resultado[N][N]) {
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
}

// b) Soma das diagonais
void somarDiagonais(int mat[N][N], int *somaPrincipal, int *somaSecundaria) {
    *somaPrincipal = 0;
    *somaSecundaria = 0;

    int i;
    for(i = 0; i < N; i++) {
        *somaPrincipal += mat[i][i];
        *somaSecundaria += mat[i][N - 1 - i];
    }
}

// c) Multiplicação de matrizes
void multiplicarMatrizes(int A[N][N], int B[N][N], int resultado[N][N]) {
    int i, j, k;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            resultado[i][j] = 0;
            for(k = 0; k < N; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
