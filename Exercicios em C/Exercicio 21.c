#include <stdio.h>
#include <string.h>

#define TAM 3

typedef struct {
    int dd, mm, aa;
} Data;

typedef struct {
    char descricao[81];
    Data dta;
} Compromisso;

Compromisso* busca(int n, Compromisso** vet, int d, int m, int a);
void imprime_resultado(Compromisso* resultado);

int main() {
    Compromisso c1 = {"Dentista", {10, 11, 2025}};
    Compromisso c2 = {"Reunião", {15, 11, 2025}};
    Compromisso c3 = {"Aniversário", {20, 11, 2025}};
    Compromisso* agenda[TAM] = {&c1, &c2, &c3};

    int dia = 15, mes = 11, ano = 2025;
    Compromisso* resultado = busca(TAM, agenda, dia, mes, ano);
    imprime_resultado(resultado);
    return 0;
}

Compromisso* busca(int n, Compromisso** vet, int d, int m, int a) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        Data atual = vet[meio]->dta;

        if (a < atual.aa || (a == atual.aa && m < atual.mm) || (a == atual.aa && m == atual.mm && d < atual.dd)) {
            fim = meio - 1;
        } else if (a > atual.aa || (a == atual.aa && m > atual.mm) || (a == atual.aa && m == atual.mm && d > atual.dd)) {
            inicio = meio + 1;
        } else {
            return vet[meio];
        }
    }
    return NULL;
}

void imprime_resultado(Compromisso* resultado) {
    if (resultado != NULL) {
        printf("Compromisso encontrado:\n");
        printf("Descrição: %s\n", resultado->descricao);
        printf("Data: %02d/%02d/%04d\n", resultado->dta.dd, resultado->dta.mm, resultado->dta.aa);
    } else {
        printf("Nenhum compromisso encontrado.\n");
    }
}
