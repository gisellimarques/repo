#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct endereco {
    char rua[100];
    int numero;
}Endereco;

typedef struct notas{
    float p1, p2, p3;
}Notas;

typedef struct aluno{
    int mat;
    char nome[81];
    Notas nota;
    Endereco *end;
}Aluno;
Aluno **alocaAlunos(int n){
    Aluno **vet = (Aluno **) malloc(n * sizeof(Aluno *));
    if(vet == NULL){printf("Falta memoria!\n"); exit(1);}

    for(int i = 0; i < n; i++){
        vet[i] = (Aluno *) malloc(sizeof(Aluno));
        if(vet[i] == NULL) {printf("Falta memoria!\n"); exit(1);}

        vet[i] ->end = (Endereco *) malloc(sizeof(Endereco));
        if(vet[i]->end == NULL){printf("Falta memoria!\n"); exit(1);}
    }
    return vet;
}

void atribui(Aluno **a, int indice, int matricula, char *nome, float nota1, float nota2, float nota3, char *nomeRua, int numero){
    a[indice]->mat = matricula;

    strcpy(a[indice]->nome, nome);

    a[indice]->nota.p1 = nota1;
    a[indice]->nota.p2 = nota2;
    a[indice]->nota.p3 = nota3;

    strcpy(a[indice]->end->rua, nomeRua);
    a[indice]->end->numero = numero;
}
int main(){
    Aluno **alunos;
    alunos = alocaAlunos(3);
    atribui(alunos,0,10,"Um",1,1,1,"Getulio Vargas",100);
    atribui(alunos,1,20,"Dois",8,8,8,"Amaral Peixoto",200);
    atribui(alunos,2,30,"Tres",9,9,9,"Ouro Verde",300);

    for (int i = 0; i <3; i++){
        printf("\nAluno %d\n", i);
        printf("Matricula: %d\n", alunos[i]->mat);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Notas: %.1f %.1f %.1f\n", alunos[i]->nota.p1, alunos[i]->nota.p2, alunos[i]->nota.p3);
        printf("Endereco: %s, %d\n", alunos[i]->end->rua, alunos[i]->end->numero);
    }
    for(int i = 0; i <3; i++){
        free(alunos[i]->end);
        free(alunos[i]);
    }
    free(alunos);
    return 0;
}
