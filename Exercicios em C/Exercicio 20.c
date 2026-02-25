// 2. Tendo o seguinte código:
// typedef struct data {
// int dia;
// int mes;
// char nomeMes[12];
// } Data;
// main()
// {
// Data aniversarios[3] = { {5,1,"JANEIRO"},
// {4,2,"FEVEREIRO"},{10,3,"MAIO"} };
// int a;
// Data *p_dt;
// p_dt=&aniversarios[2];
// printf("Nome do mês %d é: %s.", p_dt->mes, p_dt->nomeMes);
// strcpy(p_dt->nomeMes, "MARÇO");
// printf("\nNúmero de letras : %d=", strlen(p_dt->nomeMes));
// Data p_dt2 = (Data *) malloc(sizeof(Data));
// p_dt2 = &aniversarios[0];
// }



// a. O programa acima pode ter no máximo 1 erro. Caso tiver, explique qual é o erro.
//     resposta: o programa tem sim um erro. o erro está em "Data p_dt2 = (Data *) malloc(sizeof(Data));"
//     porque o malloc retorna um ponteiro, mas a variável foi declarada como struct.



// b. Qual o valor mostrado na tela no segundo (último) printf?
//    rsposta: valor mostrado "Numero de letras: 5="
