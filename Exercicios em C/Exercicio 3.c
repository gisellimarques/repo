#include <stdio.h>
#include <string.h>
#define MAX 50

int main(void)
{
    char texto[MAX + 2], temp;
    int tam, i;
    gets(texto); //lê o que foi digitado pelo usário no caso romeu.
    tam = strlen(texto); //obtém o tamanho da palavra
    for(i=0;i<tam;i++){
        temp = texto[i]; // a variavel temp guardará os caracteres de romeu
        texto[i] = texto[tam-1-i]; // a palavra romeu será invertida incorretamente, pois os valores originais estão sendo sobrescritos,ou seja,
        //não estão sendo preservados e devido a isso não há uma inversão correta. Nesta linha em especifico (se fosse somente ela) seria impresso uemeu.
        texto[strlen(texto)-1-i] = temp; // a palavra romeu voltará ao normal devido a temp ter guardado o valor inicial e o for fazer com que seja invertido duas vezes, ou seja, vai inverter e reverter a palavra.
    }
    puts(texto); //imprimirá a palavra digitada. No caso romeu.
    return 0;
}
