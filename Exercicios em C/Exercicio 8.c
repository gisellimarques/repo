#include <stdio.h>

int main() {
    int tabuleiro[8][8] = {
        {1, 3, 0, 5, 4, 0, 2, 1},
        {1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 6, 0},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {0, 1, 0, 4, 0, 0, 1, 0},
        {0, 0, 3, 1, 0, 0, 1, 1},
        {1, 0, 6, 6, 0, 0, 1, 0},
        {1, 0, 5, 0, 1, 1, 0, 6}
    };

    int i, j;
    int contPeoes = 0;
    int contTorres = 0;
    int contReis = 0;
    int contCavalos = 0;
    int contBispos = 0;
    int contRainhas = 0;
    int contAusencia = 0;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (tabuleiro[i][j] == 1) {
                contPeoes++;
            } else if (tabuleiro[i][j] == 2) {
                contCavalos++;
            } else if (tabuleiro[i][j] == 3) {
                contTorres++;
            } else if (tabuleiro[i][j] == 4) {
                contBispos++;
            } else if (tabuleiro[i][j] == 5) {
                contReis++;
            } else if (tabuleiro[i][j] == 6) {
                contRainhas++;
            } else if (tabuleiro[i][j] == 0) {
                contAusencia++;
            }
        }
    }

    int soma = contPeoes + contBispos;

    printf("\nA soma total de Peoes com Bispos: %d\n", soma);
    printf("A quantidade de posicoes com ausencia de pecas: %d\n", contAusencia);
    printf("A quantidade de pecas peoes: %d\n", contPeoes);
    printf("A quantidade de pecas cavalos: %d\n", contCavalos);
    printf("A quantidade de pecas torres: %d\n", contTorres);
    printf("A quantidade de pecas bispos: %d\n", contBispos);
    printf("A quantidade de pecas reis: %d\n", contReis);
    printf("A quantidade de pecas rainhas: %d\n", contRainhas);

    return 0;
}

