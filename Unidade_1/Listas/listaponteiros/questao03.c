p = &i; \\ Não causa erro;

*q = &j; \\ Causa erro -> *q tem tipo int, enquanto &j tem tipo de ponteiro para int

p = &*&i; \\ Não causa erro

i = (*&)j; \\ Causa erro -> O perenteces, como é execultado primeiro e não tem nenhuma váriavél após o &, ele vai causa erro pois tenta acessar uma variável e não há nenhuma para acessar
i = *&j; \\ Não causa erro

i = *&*&j; \\ Não causa erro

q = *p; \\ Causa erro -> q tem tipo ponteiro para int e está recebendo um valor de tipo inteiro

i = (*p)++ + *q; \\ Não causa erro  
