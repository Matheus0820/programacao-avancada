int i=3,j=5;
int *p, *q;
p = &i;
q = &j;

p == &i; // Valor: True 
// Justificativa: O valor será verdadeiro (True) ou 1 pois p é o ponteiro de i.
// O que é o que essa comparação faz é vé se o endereço de i (&i) corresponde ao valor de endereço que ta em p

*p - *q; // Vlaor: -2
// Justificativa: o "*" resgata o valor dos ponteiro. Nesse caso vira a subtração de 3 - 5, que será igual a -2


**&p; // Valor: 3
// Justificativa &p é o endereço de p, o primeiro "*" resgarará o valor de "p", que é o endereço de "i", 
// e o segundo resgatará o valor do que ta no endereço que "p" ta guardando, que, nesse caso, será 2.


3 - *p/(*q) + 7; // Valor: 3 - 3/5 + 7 = 10
// Justificativa: Como "*" resgata o valor de do ponteiro então a expressão acima vira um expressão algébrica, 
// onde 3/5 será igual a zero, pois é uma divisão inteira, resultando assim como valor o 10
