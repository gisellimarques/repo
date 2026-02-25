#include <stdio.h>
#define TAM 26

void vetor_alfabeto(char vetor[]);
void imprime_vetor(char vetor[]);

int main() {
    char alfabeto[TAM];

    vetor_alfabeto(alfabeto);
    imprime_vetor(alfabeto);

    return 0;
}
void vetor_alfabeto(char vetor[]) {
    for (int i = 0; i < TAM; i++) {
        vetor[i] = 'a' + i;
    }
}
void imprime_vetor(char vetor[]) {
    for (int i = 0; i < TAM; i++) {
        printf("%c ", vetor[i]);
    }
    printf("\n");
}
