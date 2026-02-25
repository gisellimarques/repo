#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    char nomeDoArquivo[50];
    FILE *arq;


    for (i = 1; i <= 10; i++) {

        sprintf(nomeDoArquivo, "teste%02d.txt", i);


        arq = fopen(nomeDoArquivo, "w");

        // checando se teve algum erro na criação do arquivo
        if (arq == NULL) {
            printf("Erro ao criar o arquivo %s\n", nomeDoArquivo);
            return 1;
        }

        fprintf(arq, "Texto do arquivo %d", i);

        // fecha o arquivo salvando ele
        fclose(arq);

        printf("Arquivo %s criado com sucesso.\n", nomeDoArquivo);
    }

    printf("\nTodos os 10 arquivos foram gerados!\n");

    return 0;
}
