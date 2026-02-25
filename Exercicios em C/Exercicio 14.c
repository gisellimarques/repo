#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definindo a struct igual da questao
struct pessoa {
    int codigo;
    char nome[81];
};
typedef struct pessoa Pessoa;


Pessoa* busca(int n, Pessoa** vet, int codigo) {
    int inicio = 0;
    int fim = n - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        // tem quer usar -> por ser vetor de ponteiros
        if (vet[meio]->codigo == codigo) {
            return vet[meio];
        }
        else if (vet[meio]->codigo < codigo) {
            // metade da direita
            inicio = meio + 1;
        }
        else {
            // metade da esquerda
            fim = meio - 1;
        }
    }

    // se saiu do while, nao encontrou ninguem
    return NULL;
}

int main() {
    Pessoa p1 = {10, "Joao"};
    Pessoa p2 = {25, "Maria"};
    Pessoa p3 = {40, "Pedro"};
    Pessoa p4 = {55, "Ana"};
    Pessoa p5 = {70, "Lucas"};


    Pessoa* cadastro[5];
    Pessoa* resultado;
    int codigoProcurado;


    cadastro[0] = &p1;
    cadastro[1] = &p2;
    cadastro[2] = &p3;
    cadastro[3] = &p4;
    cadastro[4] = &p5;

    // primeiro teste: procurando um codigo que existe => 40
    codigoProcurado = 40;
    resultado = busca(5, cadastro, codigoProcurado);

    if (resultado != NULL) {
        printf("Encontrado: %s com codigo %d\n", resultado->nome, resultado->codigo);
    } else {
        printf("Codigo %d nao encontrado.\n", codigoProcurado);
    }

    printf("------------------\n");

    // segundo teste: procurando um codigo que nao existe => 99
    codigoProcurado = 99;
    resultado = busca(5, cadastro, codigoProcurado);

    if (resultado != NULL) {
        printf("Encontrado: %s com codigo %d\n", resultado->nome, resultado->codigo);
    } else {
        printf("Codigo %d nao encontrado.\n", codigoProcurado);
    }

    return 0;
}
