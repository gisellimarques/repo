#include <stdio.h>

int main(){
    int matriz[5][5] = {
        {00, 15, 30, 05, 12},
        {15, 00, 10, 17, 28},
        {30, 10, 00, 03, 11},
        {05, 17, 03, 00, 80},
        {12, 28, 11, 80, 00}
    };
    int c1 = -1, c2 = -1;

    while(c1 != 0 || c2 != 0){
        printf("Digite as cidades (de 1 ao 5) ou 0 0 para sair: ");
        scanf("%d %d", &c1, &c2);

        if (c1 == 0 && c2 == 0){

        }else if(c1 < 1 || c1 > 5 || c2 < 1 || c2 > 5){
            printf("Cidade invalida! \n");
        }else{
            printf("A distancia entre %d e %d = %d km\n", c1, c2, matriz[c1-1][c2-1]);
        }
    }

    printf("\nTabela de cidades e suas distâncias: \n");
    printf("=================\n");
    for (int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            printf("Cidade %d -> Cidade %d = %d km\n", i+1, j+1, matriz[i][j]);
        }
    printf("\n");
    }
    int n;
    int total = 0;
    int trajeto[100];

    printf("O trajeto passa por quantas cidades: ");
    scanf("%d", &n);

    printf("Digite o trajeto: \n");

    for (int i = 0; i < n; i++){
        scanf("%d", &trajeto[i]);
    }
    for (int i = 0; i < n - 1; i++){
        int a = trajeto[i] - 1;
        int b = trajeto[i+1] -1;
        total += matriz[a][b];
    }
    printf("\n O caminho percorrido tem %d km\n", total);

    return 0;
}
