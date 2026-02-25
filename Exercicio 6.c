/* Questão 6 - Lista 2 __ Giselli Carolini Marques */

#include <stdio.h>
#include <stdlib.h> //biblioteca pra rand e srand
#include <time.h>

int main(){

    srand(time(NULL));
    int num_sorteado = (rand() % 100) + 1;
    int num, cont = 0;
    do{
        printf("Adivinhe que numero sera sorteado (de 1 a 100): ");
        scanf("%d", &num);
        cont++;

        if (num != num_sorteado){
            if (num > num_sorteado){
                printf("O numero sorteado eh menor do que o digitado! \n");
            }else {
                printf("O numero sorteado eh maior do que o digitado! \n");
            }
        }
    }while(num != num_sorteado);

    if (num == num_sorteado){
        printf("Acertou! Voce tentou %d vezes. \n", cont);
    }

    return 0;

}
