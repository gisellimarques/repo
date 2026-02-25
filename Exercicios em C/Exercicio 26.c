#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media(char* mat, char* nome_arquivo);

int main() {

    FILE *f = fopen("notas_teste.txt", "w");
    fprintf(f, "9010087-2 2.0 4.3 6.5\n");
    fprintf(f, "8820324-3 7.0 8.2 8.5\n");
    fprintf(f, "9210478-5 6.0 7.5 7.8\n");
    fprintf(f, "9020256-8 3.0 0.5 4.2\n");
    fclose(f);

    char matriculaBusca[20];
    char arquivo[] = "notas_teste.txt";

    printf("Digite a matricula do aluno (ex: 1234567-8): ");
    scanf("%s", matriculaBusca);

    float resultado = media(matriculaBusca, arquivo);

    if (resultado == -1.0) {
        printf("\nAluno com matricula %s nao encontrado.\n", matriculaBusca);
    } else {
        printf("\n--- Resultado ---\n");
        printf("Matricula: %s\n", matriculaBusca);
        printf("Media final: %.2f\n", resultado);
    }

    return 0;
}

float media(char* mat, char* nome_arquivo) {
    FILE *arq;
    char mat_lida[20];
    float p1, p2, p3;

    arq = fopen(nome_arquivo, "r");

    if (arq == NULL) {
        printf("ERRO: Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }

    while (fscanf(arq, "%s %f %f %f", mat_lida, &p1, &p2, &p3) == 4) {
        if (strcmp(mat_lida, mat) == 0) {
            fclose(arq);
            return (p1 + p2 + p3) / 3.0;
        }
    }

    fclose(arq);
    return -1.0;
}
