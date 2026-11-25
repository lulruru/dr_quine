#include <stdio.h>
/* comment */
#define N "Grace_kid.c"
#define S "#include <stdio.h>%1$c/* comment */%1$c#define N %2$cGrace_kid.c%2$c%1$c#define S %2$c%3$s%2$c%1$c#define FT(x) int main(void){FILE *f=fopen(N,%2$cw%2$c);if(!f)return 1;fprintf(f,x,10,34,x);fclose(f);return 0;}%1$cFT(S)%1$c"
#define FT(x) int main(void){FILE *f=fopen(N,"w");if(!f)return 1;fprintf(f,x,10,34,x);fclose(f);return 0;}
FT(S)