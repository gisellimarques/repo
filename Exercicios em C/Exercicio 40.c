#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    int matricula;
    float *vNotas;
    char nome[100];
} Aluno;

typedef struct Materia {
    Aluno *V;
    float media[5];
    int nAlunos;
} Materia;

Aluno* fillAluno() {
    Aluno *a = (Aluno*) malloc(sizeof(Aluno));
    if (a == NULL) { printf("Falta memoria!\n"); exit(1); }

    printf("\nNome do aluno: ");
    scanf(" %s", a->nome);

    printf("Matricula: ");
    scanf("%d", &a->matricula);

    a->vNotas = (float*) malloc(5 * sizeof(float));
    if (a->vNotas == NULL) { printf("Falta memoria!\n"); exit(1); }

    for (int i = 0; i < 5; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &a->vNotas[i]);
    }

    return a;
}
Materia* fillMateria(int numAlunos) {
    Materia *m = (Materia*) malloc(sizeof(Materia));
    if (m == NULL) { printf("Falta memoria!\n"); exit(1); }

    m->nAlunos = numAlunos;

    m->V = (Aluno*) malloc(numAlunos * sizeof(Aluno));
    if (m->V == NULL) { printf("Falta memoria!\n"); exit(1); }

    for (int i = 0; i < numAlunos; i++) {
        printf("\n--- Cadastro do aluno %d ---\n", i + 1);

        Aluno *temp = fillAluno();

        m->V[i] = *temp;
        m->V[i].vNotas = temp->vNotas;
        free(temp);
    }

    return m;
}
void mediaMateria(Materia *m1) {
    for (int i = 0; i < 5; i++) {
        float soma = 0;

        for (int j = 0; j < m1->nAlunos; j++) {
            soma += m1->V[j].vNotas[i];
        }
        m1->media[i] = soma / m1->nAlunos;
    }
}
void mostraMateria(Materia *m1) {

    printf("\nALUNOS: \n");
    for (int i = 0; i < m1->nAlunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", m1->V[i].nome);
        printf("Matricula: %d\n", m1->V[i].matricula);

        printf("Notas: ");
        for (int j = 0; j < 5; j++)
            printf("%.1f ", m1->V[i].vNotas[j]);
        printf("\n");
    }
    printf("\nMEDIAS DAS 5 PROVAS: \n");
    for (int i = 0; i < 5; i++)
        printf("Prova %d: %.2f\n", i + 1, m1->media[i]);
}

int main(){
    int n;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);

    Materia *m = fillMateria(n);
    mediaMateria(m);
    mostraMateria(m);

    for (int i = 0; i < m->nAlunos; i++){
        free(m->V[i].vNotas);
   }
    free(m->V);
    free(m);

    return 0;
}
