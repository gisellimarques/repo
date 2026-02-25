#include <stdio.h>


// considerando que no exemplo do exercicio ele fornece matrizes 3x4, a gente pode definir o numero de linhas e colunas como constantes
#define numeroDeLinhas 3
#define numeroDeColunas 4



void leituraDeMatriz(int mat[][numeroDeColunas], const char *nome);
void somaDasMatrizes(int m1[][numeroDeColunas], int m2[][numeroDeColunas], int matrizResultado[][numeroDeColunas]);
void imprimirMatriz(int mat[][numeroDeColunas], const char *nome);


int main() {

    int A[numeroDeLinhas][numeroDeColunas];
    int B[numeroDeLinhas][numeroDeColunas];
    int C[numeroDeLinhas][numeroDeColunas];

    leituraDeMatriz(A, "Matriz A");
    leituraDeMatriz(B, "Matriz B");

    somaDasMatrizes(A, B, C);

    imprimirMatriz(C, "Resultado da Soma (Matriz A + Matriz B)");

    return 0;
}



// definindo as funçoes que fizemos de prototipo no começo

void leituraDeMatriz(int mat[][numeroDeColunas], const char *nome) {
    printf("Entrada de Dados: %s \n", nome);
    for (int i = 0; i < numeroDeLinhas; i++) {
        for (int j = 0; j < numeroDeColunas; j++) {
            printf("Posicao [%d][%d] de %s: ", i, j, nome);
            scanf("%d", &mat[i][j]);
            }
        }
    }



void somaDasMatrizes(int m1[][numeroDeColunas], int m2[][numeroDeColunas], int matrizResultado[][numeroDeColunas]) {
    for (int i = 0; i < numeroDeLinhas; i++) {
        for (int j = 0; j < numeroDeColunas; j++) {
            matrizResultado[i][j] = m1[i][j] + m2[i][j];
        }
    }
}


void imprimirMatriz(int mat[][numeroDeColunas], const char *nome) {
    printf("%s \n", nome);
    for (int i = 0; i < numeroDeLinhas; i++) {
        for (int j = 0; j < numeroDeColunas; j++) {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}
