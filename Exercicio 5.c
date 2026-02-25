/* Questão 5 - Lista 4 __ Giselli Carolini Marques */

#include <stdio.h>

void calcula_corrida (float dist, float *b1, float *b2){
    *b1 = 4.95 + (dist * 2.50);
    *b2 = 4.95 + (dist * 3.00);
}

int main(){
    float d, b1, b2;
    printf("Distancia (em km): ");
    scanf("%f", &d);

    calcula_corrida(d, &b1, &b2);
    printf("Valor da corrida na bandeira 1: %.2f\n", b1);
    printf("Valor da corrida na bandeira 2: %.2f\n", b2);

    return 0;
}
