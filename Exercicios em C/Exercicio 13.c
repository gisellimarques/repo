#define MAX 4
#define MAXNOME 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void atribui(char **nomes, int indice, char *nome){

    strcpy(nomes[indice], nome);

}
char * get_sobrenome(char *nome){

    char *sobrenome = strrchr(nome, ' ');

    if(sobrenome!=NULL){
        return sobrenome + 1;
    }else{
        return nome;
    }
}

main()
{
    int i;
    char **nomes;
    char *sobrenome;

    nomes = (char **) malloc(MAX * sizeof(char *));
    for (i = 0; i < MAX; i++) {
        nomes[i] = (char *) malloc(sizeof(char) * MAXNOME);
    }

    atribui(nomes, 0, "Fulano Silva");
    atribui(nomes, 1, "Maria do Carmo");
    atribui(nomes, 2, "Beltrano Belmonte");
    atribui(nomes, 3, "Pedro dos Santos");

    for (i = 0; i < MAX; i++) {
        sobrenome = get_sobrenome(nomes[i]);
        printf("\n%s ", sobrenome);
        printf(" %d", strlen(sobrenome) > 5 ? i : 0); /* irá imprimir os sobrenomes e logo após os indices dos sobrenomes que forem maiores que 5 e os sobrenomes que forem menores imprimirá somente 0.
        Nesse em caso específico imprimirá: Silva  0
                                            Carmo  0
                                            Belmonte  2
                                            Santos  3*/
    }

    printf("\n%c", nomes[0][3]); // Imprimirá o "a" do nome Fulano. Pois o 0 representa o indice do primeiro nome e o 3 a posição do caractere desejado dentro nome.
}

