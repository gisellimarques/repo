/* Questão 8 - Lista 1 __ Giselli Carolini Marques */
#include <stdio.h>

int total_de_notas(int valor){
    int cedulas[] = {100, 50, 20, 10, 5, 2, 1}, cont_cedulas = 0;

    for(int i = 0; i < 7; i++) {
        cont_cedulas += valor /cedulas[i];
        valor = valor % cedulas[i];
    }
    return cont_cedulas;
}

int main() {
    float valor_usuario;
    int valor;

    printf("Valor em reais: R$");
    scanf("%f", &valor_usuario);

    valor = (int) valor_usuario;

    int min_notas = total_de_notas(valor);
    printf("O minimo de notas usadas sera: %d \n", min_notas);

    return 0;
}
