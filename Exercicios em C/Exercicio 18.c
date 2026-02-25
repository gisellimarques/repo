#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lista_estados[27] = {
    "AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT","PA",
    "PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"
};

typedef struct assalariados {
    char nome[51];
    char sexo;
    int idade;
    float salario;
    char estado[3];
} Assalariados;

Assalariados *cadastra(char *nome, char sexo, int idade, float salario, char *estado);
void relatorio(Assalariados **ptr, int numAssalariados);
void imprime(Assalariados **ptr, int numAssalariados);

// a) Implementação da função cadastra
Assalariados *cadastra(char *nome, char sexo, int idade, float salario, char *estado) {
    Assalariados *novo = (Assalariados *) malloc(sizeof(Assalariados));

    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->sexo = sexo;
        novo->idade = idade;
        novo->salario = salario;
        strcpy(novo->estado, estado);
    }

    return novo;
}

// b) Implementação da função imprime
void imprime(Assalariados **ptr, int numAssalariados) {
    int i;
    printf("\nLista de Funcionarios:\n");
    for (i = 0; i < numAssalariados; i++) {
        printf("Nome: %-20s | Sexo: %c | Idade: %d | Salario: R$ %.2f | Estado: %s\n",
               ptr[i]->nome, ptr[i]->sexo, ptr[i]->idade, ptr[i]->salario, ptr[i]->estado);
    }
    printf("-----------------------------\n");
}

// c) Implementação da função relatório
void relatorio(Assalariados **ptr, int numAssalariados) {
    int i, j;
    int contador;

    printf("\nRelatorio por Estado:\n");
    for (i = 0; i < 27; i++) {
        contador = 0;
        for (j = 0; j < numAssalariados; j++) {
            if (strcmp(ptr[j]->estado, lista_estados[i]) == 0 &&
                ptr[j]->sexo == 'M' &&
                ptr[j]->idade > 40 &&
                ptr[j]->salario > 1000.0) {

                contador++;
            }
        }
        if (contador > 0) {
            printf("Estado=%s com %d homens maiores de 40 anos e salario maior que R$ 1000,00\n",
                   lista_estados[i], contador);
        }
    }
}

int main(void) {
    Assalariados **pessoas;
    int numAssalariados = 3;

    pessoas = (Assalariados **) malloc(numAssalariados * sizeof(Assalariados *));
    pessoas[0] = cadastra("Fulano de tal", 'M', 45, 1500.00, "RJ");
    pessoas[1] = cadastra("Ciclano", 'M', 50, 2500.00, "RS");
    pessoas[2] = cadastra("Beltrano", 'M', 42, 500.00, "RS");

    imprime(pessoas, numAssalariados);
    relatorio(pessoas, numAssalariados);

    for(int k=0; k<numAssalariados; k++) free(pessoas[k]);
    free(pessoas);

    return 0;
}
