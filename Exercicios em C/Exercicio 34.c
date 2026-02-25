#include < stdio.h >

/* Da forma que está escrito < stdio.h > com espaço, aparece o seguinte erro:
"fatal error: stdio.h: No such file or directory" */
/**/
/*caso a linha #include < stdio.h > seja escrita da forma correta (sem os espaços),
será impresso o seguinte:
f1 = 2
  f2 = 2
  f3 = 3
  main = 3
*/
void f1 ( int v) {
v = v + 1;
printf (" f1 = %d\n " , v );
}
void f2 ( int *v) {
*v = *v + 1;
printf (" f2 = %d\n " , *v );
}
int f3 ( int v) {
v = v + 1;
printf (" f3 = %d\n " , v );
return v;
}
int main (void) {
int v = 1;
f1 ( v );
f2 (&v );
v = f3 ( v );
printf (" main = %d \n" , v );
return 0;
}
