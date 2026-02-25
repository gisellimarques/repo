#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_NOMES 100
#define TAM_NOME 100

void ler_nomes(char nomes[MAX_NOMES][TAM_NOME], int *qtd);
double calcula_media(char nomes[MAX_NOMES][TAM_NOME], int qtd);
double calcula_variancia(char nomes[MAX_NOMES][TAM_NOME], int qtd, double media);

int main() {
    char nomes[MAX_NOMES][TAM_NOME];
    int qtd = 0;
    double media, variancia;

    ler_nomes(nomes, &qtd);

    if (qtd == 0) {
        printf("\n Nenhum nome foi digitado.\n");
        return 0;
    }

    media = calcula_media(nomes, qtd);
    variancia = calcula_variancia(nomes, qtd, media);

    printf("\n Quantidade de nomes: %d\n", qtd);
    printf("Média do tamanho dos nomes: %.2f\n", media);
    printf("Variância do tamanho dos nomes: %.2f\n", variancia);

    return 0;
}

void ler_nomes(char nomes[MAX_NOMES][TAM_NOME], int *qtd) {
    printf("Digite nomes completos (digite 'fim' para encerrar):\n");

    while (1) {
        printf("Nome %d: ", *qtd + 1);
        fgets(nomes[*qtd], TAM_NOME, stdin);
        nomes[*qtd][strcspn(nomes[*qtd], "\n")] = '\0';

        if (strcmp(nomes[*qtd], "fim") == 0)
            break;

        (*qtd)++;

        if (*qtd >= MAX_NOMES) {
            printf("Limite de nomes atingido.\n");
            break;
        }
    }
}

double calcula_media(char nomes[MAX_NOMES][TAM_NOME], int qtd) {
    double soma = 0.0;
    for (int i = 0; i < qtd; i++) {
        soma += strlen(nomes[i]);
    }
    return soma / qtd;
}

double calcula_variancia(char nomes[MAX_NOMES][TAM_NOME], int qtd, double media) {
    double soma_quadrados = 0.0;
    for (int i = 0; i < qtd; i++) {
        double tamanho = strlen(nomes[i]);
        soma_quadrados += pow(tamanho - media, 2);
    }
    return soma_quadrados / qtd;
}
