/* Questão 4 - Lista 5 __ Giselli Carolini Marques */

#include <stdio.h>

int main(){
    char palavra[] = "Giselli";
    int cont = 0;

    while (palavra[cont] != '\0'){
        cont++;
    }

    printf("Primeira letra: %c \n", palavra[0]);
    printf("Ultima letra: %c \n", palavra[6]);
    printf("A palavra tem %d letras. \n", cont);

    return 0;
}
