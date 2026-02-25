#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct local {
    char ender[81];  // endereço do local de provas
    int sala;        // número da sala
} Local;

typedef struct notas {
    float geral;       // prova de conhecimentos gerais
    float especifica;  // prova de conhecimentos específicos
} Notas;

typedef struct candidato {
    int inscr;         // número de inscrição
    char nome[81];     // nome do candidato
    Data nasc;         // data de nascimento
    Local *loc;        // ponteiro para local de prova
    Notas nt;          // notas
} Candidato;


void lerCandidatos(Candidato **vet, int n) {
    for (int i = 0; i < n; i++) {
        vet[i] = (Candidato*) malloc(sizeof(Candidato));
        vet[i]->loc = (Local*) malloc(sizeof(Local));  // LOCAL TAMBÉM É DINÂMICO

        printf("\n--- Candidato %d ---\n", i + 1);

        printf("Número de inscrição: ");
        scanf("%d", &vet[i]->inscr);

        printf("Nome: ");
        scanf(" %[^\n]", vet[i]->nome);

        printf("Data de nascimento (dia mes ano): ");
        scanf("%d %d %d", &vet[i]->nasc.dia, &vet[i]->nasc.mes, &vet[i]->nasc.ano);

        printf("Endereço do local de prova: ");
        scanf(" %[^\n]", vet[i]->loc->ender);

        printf("Sala: ");
        scanf("%d", &vet[i]->loc->sala);

        printf("Nota de conhecimentos gerais: ");
        scanf("%f", &vet[i]->nt.geral);

        printf("Nota de conhecimentos específicos: ");
        scanf("%f", &vet[i]->nt.especifica);
    }
}


void imprimirCandidatos(Candidato **vet, int n) {
    printf("\n===== LISTA DE CANDIDATOS =====\n\n");
    for (int i = 0; i < n; i++) {
        printf("Candidato %d\n", i + 1);
        printf("Inscrição: %d\n", vet[i]->inscr);
        printf("Nome: %s\n", vet[i]->nome);
        printf("Nascimento: %02d/%02d/%04d\n",
               vet[i]->nasc.dia, vet[i]->nasc.mes, vet[i]->nasc.ano);
        printf("Local de prova: %s\n", vet[i]->loc->ender);
        printf("Sala: %d\n", vet[i]->loc->sala);
        printf("Nota Geral: %.2f\n", vet[i]->nt.geral);
        printf("Nota Específica: %.2f\n\n", vet[i]->nt.especifica);
    }
}


void alterarLocal(Candidato **vet, int n) {
    int inscricao;
    printf("\nDigite o número de inscrição do candidato: ");
    scanf("%d", &inscricao);

    for (int i = 0; i < n; i++) {
        if (vet[i]->inscr == inscricao) {
            printf("Novo endereço: ");
            scanf(" %[^\n]", vet[i]->loc->ender);

            printf("Nova sala: ");
            scanf("%d", &vet[i]->loc->sala);

            printf("Alteração realizada com sucesso.\n");
            return;
        }
    }

    printf("Candidato não encontrado.\n");
}


int main() {
    int n, opcao;
    Candidato **vet = NULL;

    printf("Quantos candidatos deseja cadastrar? ");
    scanf("%d", &n);

    vet = (Candidato**) malloc(n * sizeof(Candidato*));

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Ler dados dos candidatos\n");
        printf("2 - Imprimir informações\n");
        printf("3 - Alterar local de prova de um candidato\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                lerCandidatos(vet, n);
                break;
            case 2:
                imprimirCandidatos(vet, n);
                break;
            case 3:
                alterarLocal(vet, n);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);


    // libera memória
    for (int i = 0; i < n; i++) {
        free(vet[i]->loc);
        free(vet[i]);
    }
    free(vet);

    return 0;
}
