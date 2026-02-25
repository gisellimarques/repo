#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int matricula;
    char nome[50];
    float n1, n2, n3;
    struct aluno *prox;
} Aluno;

Aluno* inserir(Aluno *lista, int mat, char *nome, float n1, float n2, float n3) {
    Aluno *novo = (Aluno*) malloc(sizeof(Aluno));
    if (!novo) {printf("Falta memória!\n"); exit(1);}

    novo->matricula = mat;
    strcpy(novo->nome, nome);
    novo->n1 = n1;
    novo->n2 = n2;
    novo->n3 = n3;
    novo->prox = lista;

    return novo;
}

void imprimir(Aluno *lista) {
    if (!lista) {
        printf("\nLista vazia!\n");
        return;
    }

    printf("\nLISTA DE ALUNOS:\n");
    while (lista) {
        printf("Matricula: %d\n", lista->matricula);
        printf("Nome: %s\n", lista->nome);
        printf("Notas: %.1f %.1f %.1f\n", lista->n1, lista->n2, lista->n3);
        printf("------------------------\n");
        lista = lista->prox;
    }
}

Aluno* buscar(Aluno *lista, int mat) {
    while (lista) {
        if (lista->matricula == mat)
            return lista;
        lista = lista->prox;
    }
    return NULL;
}

void alterar(Aluno *lista, int mat) {
    Aluno *a = buscar(lista, mat);

    if (!a) {
        printf("Aluno não encontrado!\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %s", a->nome);
    printf("Nova nota 1: ");
    scanf("%f", &a->n1);
    printf("Nova nota 2: ");
    scanf("%f", &a->n2);
    printf("Nova nota 3: ");
    scanf("%f", &a->n3);

    printf("Aluno atualizado!\n");
}

Aluno* removerAluno(Aluno *lista, int mat) {
    Aluno *ant = NULL;
    Aluno *p = lista;

    while (p && p->matricula != mat) {
        ant = p;
        p = p->prox;
    }

    if (!p) {
        printf("Aluno não encontrado!\n");
        return lista;
    }

    if (!ant)
        lista = p->prox;
    else
        ant->prox = p->prox;

    free(p);
    printf("Aluno removido com sucesso!\n");

    return lista;
}

Aluno* carregarArquivo(char *nomeArq) {
    FILE *f = fopen(nomeArq, "r");
    if (!f) {printf("Erro ao abrir arquivo!\n"); exit(1);}

    Aluno *lista = NULL;
    int mat;
    char nome[50];
    float n1, n2, n3;

    while (fscanf(f, "%d %s %f %f %f", &mat, nome, &n1, &n2, &n3) == 5) {
        lista = inserir(lista, mat, nome, n1, n2, n3);
    }

    fclose(f);
    return lista;
}

int main() {
    Aluno *lista;
    char nomeArquivo[50];
    int opc, mat;

    printf("Nome do arquivo de alunos: ");
    scanf("%s", nomeArquivo);

    lista = carregarArquivo(nomeArquivo);

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Imprimir lista\n");
        printf("2 - Incluir aluno\n");
        printf("3 - Excluir aluno\n");
        printf("4 - Alterar aluno\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        if (opc == 1) {
            imprimir(lista);
        }
        else if (opc == 2) {
            char nome[50];
            float n1, n2, n3;

            printf("Matricula: ");
            scanf("%d", &mat);

            printf("Nome: ");
            scanf("%s", nome);

            printf("Notas (n1 n2 n3): ");
            scanf("%f %f %f", &n1, &n2, &n3);

            lista = inserir(lista, mat, nome, n1, n2, n3);
        }
        else if (opc == 3) {
            printf("Matricula a remover: ");
            scanf("%d", &mat);
            lista = removerAluno(lista, mat);
        }
        else if (opc == 4) {
            printf("Matricula a alterar: ");
            scanf("%d", &mat);
            alterar(lista, mat);
        }

    } while (opc != 0);

    return 0;
}
