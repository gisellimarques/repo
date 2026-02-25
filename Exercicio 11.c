/* Questão 13 - Lista 3 __ Giselli Carolini Marques */

#include <stdio.h>

int main(){
    int a = 1, b = 2, c = 3, d = 4;
    float e = 5.0, f = 6.0, g = 7.0, h = 8.0;
    char v[10] = "abcdefghi";
    int x = 9;
    void *p = &a;

    for (int i = 0; i <= 10; i++){
        printf("Endereço atual: %p \n", p);

        if (p == &a) printf("Igual o endereco de A. \n");
        if (p == &b) printf("Igual o endereco de B. \n");
        if (p == &c) printf("Igual o endereco de C. \n");
        if (p == &d) printf("Igual o endereco de D: \n");
        if (p == &e) printf("Igual o endereco de E: \n");
        if (p == &f) printf("Igual o endereco de F: \n");
        if (p == &g) printf("Igual o endereco de G: \n");
        if (p == &h) printf("Igual o endereco de H: \n");
        if (p == &x) printf("Igual o endereco de X: \n");
        p = (char*)p + 1;
    }
    return 0;
}
