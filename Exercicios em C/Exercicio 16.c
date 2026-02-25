#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

struct aluno{
    char nome[50];
    float nota1, nota2, nota3, media;
};

void le(struct aluno *turma){
    for(int i = 0; i < MAX; i++){
        printf("Insira os dados (%d):\n", i+1);
        printf("Nome: ");
        scanf("%s", turma[i].nome);

        printf("Nota 1: ");
        scanf("%f", &turma[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &turma[i].nota2);
        printf("Nota 3: ");
        scanf("%f", &turma[i].nota3);

        turma[i].media = (turma[i].nota1 + turma[i].nota2 + turma[i].nota3) / 3;
    }
}

void imprime(struct aluno *turma){
    for(int i = 0; i < MAX; i++){
        printf("Nome: %s\n", turma[i].nome);
        printf("Notas: %.2f, %.2f, %.2f\n", turma[i].nota1, turma[i].nota2, turma[i].nota3);
        printf("Media: %.2f\n\n", turma[i].media);
    }
}

void ordena_medias(struct aluno *turma){
    struct aluno temp;

    if(turma[0].media > turma[1].media){
        temp = turma[0];
        turma[0] = turma[1];
        turma[1] = temp;
    }

    if(turma[0].media > turma[2].media){
        temp = turma[0];
        turma[0] = turma[2];
        turma[2] = temp;
    }

    if(turma[1].media > turma[2].media){
        temp = turma[1];
        turma[1] = turma[2];
        turma[2] = temp;
    }
}

int main(void) {
    struct aluno turma[MAX];
    le(turma);
    puts("Imprimindo dados lidos da turma.");
    puts("Digite qualquer coisa para continuar.");
    getchar();
    getchar();
    imprime(turma);
    ordena_medias(turma);
    puts("Imprimindo dados ordenados da turma.");
    getchar();
    imprime(turma);
    getchar();
}
