#include <stdio.h>

/*
    Outside comment
*/

void print_source(void)
{
    char *s = "#include <stdio.h>%1$c%1$c/*%1$c    Outside comment%1$c*/%1$c%1$cvoid print_source(void)%1$c{%1$c    char *s = %2$c%3$s%2$c;%1$c    printf(s, 10, 34, s);%1$c}%1$c%1$cint main(void)%1$c{%1$c    /*%1$c        Inside comment%1$c    */%1$c    print_source();%1$c    return (0);%1$c}%1$c";
    printf(s, 10, 34, s);
}

int main(void)
{
    /*
        Inside comment
    */
    print_source();
    return (0);
}
