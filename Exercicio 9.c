/* Questão 10 - Lista 5 __ Giselli Carolini Marques */

#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX 8

int correto(char texto[]){
    for (int i = 0; texto[i] != '\0'; i++){
        if (!((texto[i] >= 'A' && texto[i] <= 'Z') ||
              (texto[i] >= 'a' && texto[i] <= 'z') ||
              (texto[i] >= '0' && texto[i] <= '9'))){
                return 0;
        }
    }
    return 1;
}

void ler_senha(char senha[], int max) {
    int i = 0;
    char ch;

    while (1) {
        ch = getch();

        if (ch == 13) {
            break;
        }
        if (i < max) {
            senha[i] = ch;
            i++;
            printf("*");
        }
    }
    senha[i] = '\0';
    printf("\n");
}

int main(){
    char nome_cadastro[MAX], senha_cadastro[MAX];
    char login[MAX], senha[MAX];

    printf("xxxxxxx  CADASTRO  xxxxxxx  \n");

    printf("Digite o nome de usuario (Aa1 _ ate 8 caracteres): ");
    scanf(" %8s", nome_cadastro);

    if (!correto(nome_cadastro)){
        printf("Digite apenas letras maiusculas, minusculas e numeros dentro de 8 caracteres. \n");
        return 1;
    }

    printf("Digite a senha de seguranca (Aa1 _ ate 8 caracteres): ");
    ler_senha(senha_cadastro, MAX);

    if (!correto(senha_cadastro)){
        printf("Digite apenas letras maiusculas, minusculas e numeros dentro de 8 caracteres. \n");
        return 1;
    }

    printf("\nxxxxxxx  LOGIN  xxxxxxx \n");

    printf("Usuario: ");
    scanf(" %8s", login);

    printf("Senha: ");
    ler_senha(senha, MAX);

    if (strcmp(login, nome_cadastro) == 0 && strcmp(senha, senha_cadastro) == 0) {
        printf("OK! \n");
    }else{
        printf("ACESSO NEGADO! \n");
    }


    return 0;
}
