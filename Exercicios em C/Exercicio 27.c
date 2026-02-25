#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float busca(char* arquivo, char* matricula);

int main(){
    char arquivo[] = "alunos.txt";
    char matricula[20];

    printf("Digite a matricula: ");
    scanf("%s", matricula);

    float resultado = busca(arquivo, matricula);

    if(resultado == -1.0)
        printf("Matricula nao encontrada.\n");
    else
        printf("CR = %.2f\n", resultado);

    return 0;
}
float busca(char* arquivo, char* matricula){
    FILE *arq = fopen(arquivo, "r");
    if(arq == NULL){
        printf("ERRO\n");
        exit(1);
    }

    char mat[20];
    float cr;

    while(fscanf(arq, "%s %f", mat, &cr) == 2){
        if(strcmp(mat, matricula) == 0){
            fclose(arq);
            return cr;
        }
    }

    fclose(arq);
    return -1.0;
}
