#include <stdio.h>

int linhas(int m[][3], int linha){
    int somaref = 0;

    for (int j = 0; j < 3; j++){
        somaref += m[0][j];
    }
    for (int i = 1; i < linha; i++){
        int soma = 0;
        for (int j = 0; j <3; j++)
            soma += m[i][j];

        if (soma != somaref)
            return 0;
    }
    return 1;
}

int main(){
    int mat[3][3];

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("Digite mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\nMatriz:\n");
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    if (linhas(mat,3))
        printf("A soma eh a mesma para todas as linhas.\n");
    else
        printf("As linhas nao tem a mesma soma.\n");

    return 0;
}
