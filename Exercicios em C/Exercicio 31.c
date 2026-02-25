/* A questão é um teste de mesa que usa o algoritmo de euclides para descobrir o
mdc de 2 numeros. Quando ele passa 32 e 18 como argumentos pra função recursiva,
como a condição 32 % 18 != 0, ele vai voltar a executar a função mdc_recursiva,
porém agora com os valores 18 e 14 ( que é o resto a % b ). Depois de executar dessa
vez, teremos novamente 18 % 14 != 0 , entao ele retornará a executar com 14 e 4,
que também sera != 0, então retornará com 4 e 2, que finalmente o resto será 0 e
então ele retornará o B em questão, que era 2. Portanto, o resultado será:
32 e 18
18 e 14
14 e 4
4 e 2
Resultado=2
*/

