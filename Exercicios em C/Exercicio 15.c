#include <string.h>

int compara(Prova *p1, Prova *p2) {
    float nota1 = p1->q1 + p1->q2 + p1->q3 + p1->q4;
    float nota2 = p2->q1 + p2->q2 + p2->q3 + p2->q4;

    // ordenar em ordem DECRESCENTE de nota:
    if (nota1 < nota2)
        return 1;   // troca (p1 deve vir depois)

    if (nota1 > nota2)
        return 0;   // não troca

    // empate: ordenar em ordem ALFABÉTICA crescente do nome
    if (strcmp(p1->a.nome, p2->a.nome) > 0)
        return 1;   // troca

    return 0;       // não troca
}

void troca(Prova **p1, Prova **p2) {
    Prova *tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
