#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void imprimeVetor(char vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%c ", vet[i]);
    }
    printf("\n");
}

void bubbleSort(char vet[], int tam) {
    int i, j;
    char aux;

    for (i = 0; i < tam - 1; i++) {
        for (j = 0; j < tam - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}


int particiona(char vet[], int inicio, int fim) {
    char pivo = vet[fim]; // deixando o elemento final como pivo
    int i = (inicio - 1);
    char aux;

    for (int j = inicio; j <= fim - 1; j++) {
        if (vet[j] < pivo) {
            i++;
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    }
    // colocando o pivo no lugar certo
    aux = vet[i + 1];
    vet[i + 1] = vet[fim];
    vet[fim] = aux;

    return (i + 1);
}

void quickSort(char vet[], int inicio, int fim) {
    if (inicio < fim) {
        int pi = particiona(vet, inicio, fim);

        quickSort(vet, inicio, pi - 1);
        quickSort(vet, pi + 1, fim);
    }
}

// tem que criar essa funçao para conseguir rodar a qsort padrao do c
int comparaChar(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

int main() {

    char vetorOriginal[] = {'z', 'e', 'b', 'r', 'a', 'c', 'o', 'd', 'e'};
    int tamanho = sizeof(vetorOriginal) / sizeof(vetorOriginal[0]);

    // a gente precisa criar copias pra testar cada metodo separadamente.

    char vetor1[tamanho];
    char vetor2[tamanho];
    char vetor3[tamanho];

    // copiando os dados
    memcpy(vetor1, vetorOriginal, tamanho);
    memcpy(vetor2, vetorOriginal, tamanho);
    memcpy(vetor3, vetorOriginal, tamanho);

    printf("Vetor original: ");
    imprimeVetor(vetorOriginal, tamanho);
    printf("\n------------------\n");

    // primeiro teste : Bolha
    printf("Ordenando com Bubble Sort:\n");
    bubbleSort(vetor1, tamanho);
    imprimeVetor(vetor1, tamanho);

    // segundo teste: QuickSort

    printf("\nOrdenando com QuickSort:\n");
    quickSort(vetor2, 0, tamanho - 1);
    imprimeVetor(vetor2, tamanho);

    // Terceiro teste : qsort do C

    printf("\nOrdenando com qsort (stdlib):\n");
    qsort(vetor3, tamanho, sizeof(char), comparaChar);
    imprimeVetor(vetor3, tamanho);

    return 0;
}
