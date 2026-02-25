#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo;
    FILE *novoArquivo;
    char nomeArquivo[80];
    char informacao[100];

    printf("Digite o nome do arquivo.c: ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    novoArquivo = fopen("novo_arquivo.c", "w");
    if (novoArquivo == NULL) {
        printf("Erro ao criar novo arquivo\n");
        fclose(arquivo);
        exit(1);
    }

    while (fgets(informacao, sizeof(informacao), arquivo) != NULL) {
        char *comentario = strstr(informacao, "//");
        if (comentario) {
            *comentario = '\0';
        }
        fprintf(novoArquivo, "%s", informacao);
    }

    fclose(arquivo);
    fclose(novoArquivo);

    printf("Comentários removidos com sucesso!\n");

    return 0;
}
