/* Questão 3 - Lista 6 _ Giselli Carolini Marques */

#include <stdio.h>
#include <stdlib.h>

int *aprovados (int n, int *mat, float *notas, int *tam){
    int contador = 0;

    for (int i=0; i < n; i++){
        if (notas[i] >= 5.0){
            contador++;
        }
    }
    *tam = contador;

    int *vetor = (int *) malloc(contador * sizeof(int));
    if (vetor == NULL) {printf("Falta memoria \n"); exit(1);}

    int x = 0;
    for (int i = 0; i < n; i++){
        if (notas[i] >= 5.0){
            vetor[x] = mat[i];
            x++;
        }
    }
    return vetor;
}
int main(){
    int n = 10;
    int mat[] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    float notas[] = {8.1, 6.5, 4.7, 9.8, 3.6, 7.4, 2.3, 1.8, 5.6, 8.9};
    int tam;

    int *apvd_final = aprovados(n, mat, notas, &tam);

    if (apvd_final != NULL){
        printf("Alunos aprovados ( %d): \n", tam);
        for (int i = 0; i < tam; i++){
            printf("Matricula: %d \n", apvd_final[i]);
        }
        free(apvd_final);
    }
    return 0;
}
