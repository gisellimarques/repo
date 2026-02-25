#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    float x = *(float*)a;
    float y = *(float*)b;
    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}

int main() {
    FILE *f = fopen("numeros.txt", "r");
    if (!f) {
        printf("ERRO ao abrir numeros.txt\n");
        return 1;
    }

    float *vet = NULL;
    int n = 0;
    float temp;

    // Lê até acabar o arquivo
    while (fscanf(f, "%f", &temp) == 1) {
        vet = (float*) realloc(vet, (n+1) * sizeof(float));
        vet[n] = temp;
        n++;
    }
    fclose(f);

    // Ordena
    qsort(vet, n, sizeof(float), cmp);

    // Grava binário
    FILE *b = fopen("numeros.bin", "wb");
    if (!b) {
        printf("ERRO ao abrir numeros.bin\n");
        return 1;
    }

    fwrite(vet, sizeof(float), n, b);
    fclose(b);

    free(vet);

    printf("Processo concluído. %d números gravados em numeros.bin\n", n);

    return 0;
}
