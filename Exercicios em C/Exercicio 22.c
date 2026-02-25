#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
    char nome[81];
    float valor_hora;
    int horas_mes;
} Funcionario;

void carrega(int n, Funcionario **vet, char *arquivo) {
    FILE *f = fopen(arquivo, "r");
    if (f == NULL) {
        printf("ERRO\n");
        exit(1);    // encerra o programa
    }

    char linha[200];
    int i = 0;

    while (i < n) {
        // ----- Lê o nome -----
        if (fgets(linha, sizeof(linha), f) == NULL)
            break; // acabou o arquivo

        // remove '\n'
        linha[strcspn(linha, "\n")] = '\0';

        // aloca um Funcionario
        vet[i] = (Funcionario *) malloc(sizeof(Funcionario));

        strcpy(vet[i]->nome, linha);

        // ----- Lê valor_hora e horas_mes -----
        if (fgets(linha, sizeof(linha), f) == NULL)
            break;

        sscanf(linha, "%f %d", &vet[i]->valor_hora, &vet[i]->horas_mes);

        i++;
    }

    fclose(f);
}
