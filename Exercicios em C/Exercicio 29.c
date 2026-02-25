#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Elemento* copia(Elemento* lst) {
    if (lst == NULL) {
        return NULL;
    }
    Elemento *novaLst = NULL;
    Elemento *ultimo = NULL;
    while (lst != NULL) {
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
        if (novo == NULL) {
            return NULL;
        }
        novo->info = lst->info;
        novo->prox = NULL;
        if (novaLst == NULL) {
            novaLst = novo;
        } else {
            ultimo->prox = novo;
        }
        ultimo = novo;
        lst = lst->prox;
    }
    return novaLst;
}

int main() {
    Elemento e3 = {3, NULL};
    Elemento e2 = {2, &e3};
    Elemento e1 = {1, &e2};

    Elemento *copiaLst = copia(&e1);

    for (Elemento *p = copiaLst; p; p = p->prox)
        printf("%d ", p->info);
    printf("\n");

    return 0;
}
