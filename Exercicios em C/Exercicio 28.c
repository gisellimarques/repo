#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[81];
    float nota1, nota2;
} ALUNO;

#define ARQ "alunos.bin"

void incluir() {
    FILE *f = fopen(ARQ, "ab");
    if (!f) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    ALUNO a;

    printf("Nome: ");
    fflush(stdin);
    fgets(a.nome, 81, stdin);
    a.nome[strcspn(a.nome, "\n")] = 0;

    printf("Nota 1: ");
    scanf("%f", &a.nota1);

    printf("Nota 2: ");
    scanf("%f", &a.nota2);

    fwrite(&a, sizeof(ALUNO), 1, f);
    fclose(f);

    printf("Aluno incluído.\n");
}

void consultar() {
    FILE *f = fopen(ARQ, "rb");
    if (!f) {
        printf("Arquivo não encontrado.\n");
        return;
    }

    char nome[81];
    printf("Nome do aluno: ");
    fflush(stdin);
    fgets(nome, 81, stdin);
    nome[strcspn(nome, "\n")] = 0;

    ALUNO a;
    int achou = 0;

    while (fread(&a, sizeof(ALUNO), 1, f)) {
        if (strcmp(a.nome, nome) == 0) {
            printf("\nNome: %s\nNota1: %.2f\nNota2: %.2f\n",
                   a.nome, a.nota1, a.nota2);
            achou = 1;
        }
    }

    if (!achou)
        printf("Aluno não encontrado.\n");

    fclose(f);
}

void alterar() {
    FILE *f = fopen(ARQ, "rb+");
    if (!f) {
        printf("Arquivo não encontrado.\n");
        return;
    }

    char nome[81];
    printf("Nome do aluno a alterar: ");
    fflush(stdin);
    fgets(nome, 81, stdin);
    nome[strcspn(nome, "\n")] = 0;

    ALUNO a;
    int achou = 0;

    while (fread(&a, sizeof(ALUNO), 1, f)) {
        if (strcmp(a.nome, nome) == 0) {
            achou = 1;

            printf("Novo nome: ");
            fflush(stdin);
            fgets(a.nome, 81, stdin);
            a.nome[strcspn(a.nome, "\n")] = 0;

            printf("Nova nota 1: ");
            scanf("%f", &a.nota1);

            printf("Nova nota 2: ");
            scanf("%f", &a.nota2);

            fseek(f, -sizeof(ALUNO), SEEK_CUR);
            fwrite(&a, sizeof(ALUNO), 1, f);

            printf("Aluno alterado.\n");
            break;
        }
    }

    if (!achou)
        printf("Aluno não encontrado.\n");

    fclose(f);
}

void excluir() {
    FILE *f = fopen(ARQ, "rb");
    if (!f) {
        printf("Arquivo não encontrado.\n");
        return;
    }

    FILE *temp = fopen("temp.bin", "wb");
    char nome[81];
    ALUNO a;
    int achou = 0;

    printf("Nome do aluno a excluir: ");
    fflush(stdin);
    fgets(nome, 81, stdin);
    nome[strcspn(nome, "\n")] = 0;

    while (fread(&a, sizeof(ALUNO), 1, f)) {
        if (strcmp(a.nome, nome) == 0) {
            achou = 1;
            continue;
        }
        fwrite(&a, sizeof(ALUNO), 1, temp);
    }

    fclose(f);
    fclose(temp);

    remove(ARQ);
    rename("temp.bin", ARQ);

    if (achou)
        printf("Aluno excluído.\n");
    else
        printf("Aluno não encontrado.\n");
}

void aprovados() {
    FILE *f = fopen(ARQ, "rb");
    if (!f) {
        printf("Arquivo não encontrado.\n");
        return;
    }

    ALUNO a;
    printf("\nAlunos com média maior que 6\n");

    while (fread(&a, sizeof(ALUNO), 1, f)) {
        float m = (a.nota1 + a.nota2) / 2.0;
        if (m > 6.0)
            printf("%s (%.2f)\n", a.nome, m);
    }

    fclose(f);
}

int menu() {
    int op;

    printf("\n1 - Incluir aluno\n");
    printf("2 - Consultar aluno\n");
    printf("3 - Alterar aluno\n");
    printf("4 - Excluir aluno\n");
    printf("5 - Mostrar aprovados\n");
    printf("0 - Sair\n");
    printf("Opção: ");
    scanf("%d", &op);

    return op;
}

int main() {
    int op;

    do {
        op = menu();

        switch (op) {
            case 1: incluir(); break;
            case 2: consultar(); break;
            case 3: alterar(); break;
            case 4: excluir(); break;
            case 5: aprovados(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }

    } while (op != 0);

    return 0;
}
