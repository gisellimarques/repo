/* Questão 1 - Lista 3 __ Giselli Carolini Marques */

#include <stdio.h>
#define PI 3.14159F

void calc_circulo (float r, float *circunferencia, float *area){
    *circunferencia = 2 * PI * r;
    *area = PI * r * r;
}

int main(){
    float r, c, a;

    printf("Raio do circulo: ");
    scanf("%f", &r);

    calc_circulo(r, &c, &a);
    printf("A area do circulo eh: %.2f \n", a);
    printf("A circunferenca do circulo eh: %.2f \n", c);

    return 0;
}
