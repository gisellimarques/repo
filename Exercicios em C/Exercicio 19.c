#include <stdio.h>

typedef struct {
    char nome[50];
    float media;
} ALUNO;

void ordena(ALUNO turma[], int tam) {
    int i, foraOrdem, jaOrdenados = 0;
    ALUNO temp;

    do {
        foraOrdem = 0;
        for (i = 0; i < tam - 1 - jaOrdenados; i++) {
            if (turma[i].media > turma[i+1].media) {
                temp = turma[i];
                turma[i] = turma[i+1];
                turma[i+1] = temp;
                foraOrdem = 1;
            }
        }
        jaOrdenados++;
    } while (foraOrdem);
}

int main() {
    ALUNO turma[5] = {
        {"Leticia", 7.5},
        {"Rebecca", 5.0},
        {"Rodrigo", 9.2},
        {"Daniel", 4.5},
        {"Fernanda", 6.0}
    };

    int tamanho = 5;
    int i;

    printf("--- Antes da Ordenacao ---\n");
    for(i = 0; i < tamanho; i++) {
        printf("%s: %.2f\n", turma[i].nome, turma[i].media);
    }

    ordena(turma, tamanho);

    printf("\n--- Depois da Ordenacao (Crescente) ---\n");
    for(i = 0; i < tamanho; i++) {
        printf("%s: %.2f\n", turma[i].nome, turma[i].media);
    }

    return 0;
}
