#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        size_t buf_size = 32;
        char *buf;
        getline(&buf, &buf_size, stdin);
        buf[strcspn(buf, "\n")] = 0;
        printf("%s\n", buf);
}
