#include <stdio.h>
#include <stdlib.h>

int main() {
    char nomeArquivo[100];
    FILE *arq;
    float numero;
    float *vetor = NULL;
    int capacidade = 10;
    int qtd = 0;

    vetor = (float*) malloc(capacidade * sizeof(float));
    if (vetor == NULL){printf("Falta memória!\n"); exit(1);}

    printf("Nome do arquivo: ");
    scanf("%s", nomeArquivo);

    arq = fopen(nomeArquivo, "r");
    if (arq == NULL){printf("Erro ao abrir o arquivo!\n"); exit(1);}

    while (fscanf(arq, "%f", &numero) == 1) {
        if (qtd == capacidade) {
            capacidade *= 2;
            vetor = (float*) realloc(vetor, capacidade * sizeof(float));
            if (vetor == NULL){printf("Falta memória!\n"); exit(1);}
        }

        vetor[qtd] = numero;
        qtd++;
    }

    fclose(arq);

    if (qtd == 0) {
        printf("Nenhum número encontrado no arquivo.\n");
        free(vetor);
        return 0;
    }
    float soma = 0;
    for (int i = 0; i < qtd; i++)
        soma += vetor[i];

    float media = soma / qtd;

    printf("\nQuantidade de numeros lidos: %d\n", qtd);
    printf("Média dos valores: %.2f\n", media);

    free(vetor);
    return 0;
}
