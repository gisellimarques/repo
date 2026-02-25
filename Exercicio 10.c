/* Questão 11 - Lista 4 __ Giselli Carolini Marques */

#include <stdio.h>

int main(){
    char op[20];
    int v1[20], v2[20], results[20];

    printf("Digite os valores do primeiro vetor: \n");
    for (int i = 0; i < 20; i++){
        scanf(" %d", &v1[i]);
    }
    printf("Digite os valores do segundo vetor: \n");
    for (int i = 0; i < 20; i++){
        scanf(" %d", &v2[i]);
    }
    printf("Operacoes a serem feitas: \n");
    for (int i = 0; i < 20; i++){
        scanf(" %c", &op[i]);
    }

    for(int i = 0; i < 20; i++){
        if (op[i] == '+'){
            results[i] = v1[i] + v2[i];
        }else if(op[i] == '-'){
            results[i] = v1[i] - v2[i];
        }else if(op[i] == '/'){
            if (v2[i] != 0) {
                results[i] = v1[i] / v2[i];
            }else {
                printf("Erro de divisao por zero no indice %d! \n", i);
                results[i] = 0;
            }
        }else if(op[i] == '*'){
            results[i] = v1[i] * v2[i];
        }
    }
    printf("\n Calculos: \n");
    for (int i = 0; i < 20; i++) {
        printf("%d %c %d = %d \n", v1[i], op[i], v2[i], results[i]);
    }
    return 0;
}
