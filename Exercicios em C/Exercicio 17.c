#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Livro {
    int ano;
    char titulo[100];
    char autor[100];
    int nVolume;
    float preco;
} Livro;

typedef struct Biblioteca {
    Livro **V;
    int nLivros;
} Biblioteca;

// (A) Criar uma função Livro * fillLivro() que preenche os campos da estrutura
// Livro e retorna esse novo livro.

Livro * fillLivro() {

    Livro *novo = (Livro*) malloc(sizeof(Livro));

    // verificando se a memoria foi alocada corretamente
    if (novo == NULL) {
        printf("Erro de memoria (livro)!\n");
        exit(1);
    }

    // o scanf com espaço antes (" %...") serve para limpar o buffer do teclado
    printf("Digite o titulo: ");
    scanf(" %[^\n]s", novo->titulo);

    printf("Digite o autor: ");
    scanf(" %[^\n]s", novo->autor);

    printf("Digite o ano: ");
    scanf("%d", &novo->ano);

    printf("Digite o numero de exemplares: ");
    scanf("%d", &novo->nVolume);

    printf("Digite o preco: ");
    scanf("%f", &novo->preco);

    return novo;
}

// (B) Criar uma função Biblioteca * fillBiblioteca(int numLivros) que
// preenche os campos da estrutura do tipo Biblioteca realizando chamadas a
// função fillLivro em um número de vezes igual ao número contido na variável
// numLivros.

Biblioteca * fillBiblioteca(int numLivros) {
    Biblioteca *bib = (Biblioteca*) malloc(sizeof(Biblioteca));

    // checando se deu certo alocar a struct biblioteca
    if (bib == NULL) {
        printf("Erro de memoria (biblioteca)!\n");
        exit(1);
    }

    bib->nLivros = numLivros;

    bib->V = (Livro**) malloc(numLivros * sizeof(Livro*));

    // checando se deu certo alocar o vetor
    if (bib->V == NULL) {
        printf("Erro de memoria (vetor)!\n");
        exit(1);
    }

    for (int i = 0; i < numLivros; i++) {
        printf("\n--- Cadastro do Livro %d ---\n", i + 1);
        bib->V[i] = fillLivro();
    }

    return bib;
}

// (C) Criar uma função void valorBiblioteca(Biblioteca * b1, int
// numLivros) que fornece o montante gasto para se comprar todos os
// exemplares existentes na biblioteca.

void valorBiblioteca(Biblioteca * b1, int numLivros) {
    float total = 0.0;

    for (int i = 0; i < numLivros; i++) {
        total = total + (b1->V[i]->preco * b1->V[i]->nVolume);
    }

    printf("\nMontante total gasto na biblioteca: R$ %.2f\n", total);
}

// (D) Criar uma função Livro * maiorBiblioteca(Biblioteca * b1, int
// numLivros) que retorna o livro com maior número de exemplares.

Livro * maiorBiblioteca(Biblioteca * b1, int numLivros) {
    // assume que o primeiro é o maior pra começar
    Livro *maior = b1->V[0];

    for (int i = 1; i < numLivros; i++) {
        if (b1->V[i]->nVolume > maior->nVolume) {
            maior = b1->V[i];
        }
    }

    return maior;
}

// Função auxiliar para limpar a memoria (free)
void liberaTudo(Biblioteca *b) {
    if (b != NULL) {
        // primeiro libera cada livro individualmente
        for(int i = 0; i < b->nLivros; i++) {
            free(b->V[i]);
        }
        // depois libera o vetor que guardava os livros
        free(b->V);
        // por fim libera a biblioteca em si
        free(b);
    }
}

// (E) Criar um programa que ilustra o funcionamento das funções anteriores

int main() {
    int qtd;

    printf("Quantos livros deseja cadastrar na biblioteca? ");
    scanf("%d", &qtd);


    Biblioteca *minhaBib = fillBiblioteca(qtd);


    valorBiblioteca(minhaBib, qtd);


    Livro *livroTop = maiorBiblioteca(minhaBib, qtd);

    printf("\nO livro com maior numero de exemplares eh:\n");
    printf("Titulo: %s\n", livroTop->titulo);
    printf("Quantidade: %d\n", livroTop->nVolume);

    // liberando a memoria usada antes de encerrar
    liberaTudo(minhaBib);

    return 0;
}
