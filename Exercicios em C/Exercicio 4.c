#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char entrada[81];
    char limpa[81];
    int i, j = 0;

    printf("Digite a frase (maximo de 80 caracteres): ");
    fgets(entrada, 81, stdin);

    for (i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] != ' ' && entrada[i] != '\n') {
            limpa[j] = toupper(entrada[i]);
            j++;
        }
    }
    limpa[j] = '\0';

    for (i = 0; i < j; i++) {
        int salto = (i % 5) + 1;
        char letraOriginal = limpa[i];
        if (letraOriginal >= 'A' && letraOriginal <= 'Z') {
            limpa[i] = ((letraOriginal - 'A' + salto) % 26) + 'A';
        }
    }

    printf("%s\n", limpa);

    return 0;
}
