#include <stdio.h>

int main()
{

    int a = getchar();
    getchar();
    int b = getchar();
    a = a - '0';
    b = b - '0';

    char c = (a + b) % 10 + '0';

    putchar(c);
    putchar('\n');
    return 0;
}