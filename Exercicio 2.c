/* Questão 2 - Lista 1 __ Giselli Carolini Marques*/
#include <stdio.h>
int main(){
    int numeros[3], pares[3], cont_par = 0;

    printf("Digite tres numeros: ");
    scanf("%d %d %d", &numeros[0], &numeros[1], &numeros[2]);

    int menor = numeros[0], maior = numeros[0];
    float media = (numeros[0] + numeros[1] + numeros[2]) / 3.0;

    for (int i = 0; i < 3; i++){
        if (numeros[i] > maior){
            maior = numeros[i];
        }
        if (numeros[i] < menor){
            menor = numeros[i];
        }
        if (numeros[i] % 2 == 0){
            pares[cont_par] = numeros[i];
            cont_par++;
        }
    }
    printf("O maior numero eh: %d \n", maior);
    printf("O menor numero eh: %d \n", menor);
    printf("A media dos numeros eh: %.2f \n", media);

    printf("Os numeros pares sao: ");
    if (cont_par == 0){
        printf("Nenhum par encontrado! \n");
    }else{
        for (int i = 0; i < cont_par; i++){
            printf("%d ", pares[i]);
        }
    }

    return 0;

}
