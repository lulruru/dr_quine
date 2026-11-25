#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i = 1;
    char filename[64];
    char command[256];
    const char *name = strrchr(__FILE__, '/');
    const char *s = "#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <string.h>%1$c%1$cint main(void)%1$c{%1$c    int i = %4$d;%1$c    char filename[64];%1$c    char command[256];%1$c    const char *name = strrchr(__FILE__, '/');%1$c    const char *s = %2$c%3$s%2$c;%1$c    FILE *file;%1$c    int written;%1$c    int closed;%1$c%1$c    name = name ? name + 1 : __FILE__;%1$c    if (strcmp(name, %2$cSully.c%2$c) != 0)%1$c        i--;%1$c    if (i < 0)%1$c        return (0);%1$c    snprintf(filename, sizeof(filename), %2$cSully_%%d.c%2$c, i);%1$c    file = fopen(filename, %2$cw%2$c);%1$c    if (!file)%1$c        return (1);%1$c    written = fprintf(file, s, 10, 34, s, i);%1$c    closed = fclose(file);%1$c    if (written < 0 || closed != 0)%1$c        return (1);%1$c    snprintf(command, sizeof(command), %2$cgcc -Wall -Wextra -Werror %%s -o Sully_%%d && ./Sully_%%d%2$c, filename, i, i);%1$c    return (system(command) == 0 ? 0 : 1);%1$c}%1$c";
    FILE *file;
    int written;
    int closed;

    name = name ? name + 1 : __FILE__;
    if (strcmp(name, "Sully.c") != 0)
        i--;
    if (i < 0)
        return (0);
    snprintf(filename, sizeof(filename), "Sully_%d.c", i);
    file = fopen(filename, "w");
    if (!file)
        return (1);
    written = fprintf(file, s, 10, 34, s, i);
    closed = fclose(file);
    if (written < 0 || closed != 0)
        return (1);
    snprintf(command, sizeof(command), "gcc -Wall -Wextra -Werror %s -o Sully_%d && ./Sully_%d", filename, i, i);
    return (system(command) == 0 ? 0 : 1);
}
