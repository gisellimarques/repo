#include <stdio.h>
#include <string.h>

// SERÁ IMPRESSO "etset Otimo"

int main (void) {

    char *frase = "Otimo teste"; // define um ponteiro para o primeiro endereço da string.


    char *p , misterio[80];  // Aqui ele inicializa tanto um ponteiro auxiliar

    // como uma outra array com tamanho definido.

    int i = 0; // inicializando i que vai servir como contador depois



    int j = 0; // mesma coisa do i





    p = frase + strlen ( frase ) - 1; // aqui ele pega o endereço do ultimo

    // caractere de frase (e) e passa para o p.





    while (*p != ' ') {

        misterio[i] = *p;

        i ++;

        p --;

    } // aqui ele fez um loop pra ir montando o array misterio, Ele basicamente

    // vai pegando os caracteres do array Frase de tras pra frente até se deparar

    // com um espaço, ficando "etset".





    misterio[i] = ' ';

    i ++; // Aqui ele coloca um espaço depois do ultimo caractere do array misterio

    // e incrementa o I para já ir colocando novos caracteres logo depois do espaço





    while ( frase[j] != ' ') {

        misterio [i] = frase[j];

        j ++;

        i ++;

    } // aqui ele faz um loop pra dar continuidade ao array misterio, pegando os

    // caracteres iniciais do array "frase" indo até se deparar com um espaço,

    // ficando "Otimo".





    misterio[i] = '\0'; // finalizou a string



    puts (misterio); // aqui ele le o array misterio caractere por caractere, ficando com a saída: "etset Otimo"



    return 0;

}
