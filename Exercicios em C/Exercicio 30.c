#include <stdio.h>
#include <stdlib.h>

struct elemento {
    float info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Elemento* filtra(Elemento *lst, float min, float max) {
    Elemento *ant = NULL;
    Elemento *p = lst;

    while (p != NULL) {
        if (p->info < min || p->info > max) {
            Elemento *temp = p;

            if (ant == NULL) {
                lst = p->prox;
            } else {
                ant->prox = p->prox;
            }

            p = p->prox;
            free(temp);
        }
        else {
            ant = p;
            p = p->prox;
        }
    }
    return lst;
}

Elemento* insere(Elemento* lst, float val) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = val;
    novo->prox = lst;
    return novo;
}

void imprime(Elemento* lst) {
    Elemento* p;
    if (lst == NULL) {
        printf("Lista Vazia\n");
        return;
    }
    printf("Lista: ");
    for (p = lst; p != NULL; p = p->prox) {
        printf("[%.1f] -> ", p->info);
    }
    printf("NULL\n");
}

int main() {
    Elemento *lista = NULL;
    int qtd, i;
    float valor, min_val, max_val;

    printf("Quantos numeros voce deseja inserir na lista? ");
    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++) {
        printf("Digite o %d%c numero: ", i + 1, 167);
        scanf("%f", &valor);
        lista = insere(lista, valor);
    }

    printf("\nLista:\n");
    imprime(lista);

    printf("\nAgora vamos filtrar.\n");
    printf("Digite o valor MINIMO permitido: ");
    scanf("%f", &min_val);

    printf("Digite o valor MAXIMO permitido: ");
    scanf("%f", &max_val);

    lista = filtra(lista, min_val, max_val);

    printf("\n--- Resultado Final ---\n");
    imprime(lista);

    while(lista != NULL) {
        Elemento *t = lista;
        lista = lista->prox;
        free(t);
    }

    return 0;
}
