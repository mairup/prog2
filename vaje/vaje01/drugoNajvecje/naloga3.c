#include <stdio.h>
#include <stdbool.h>

int main()
{

    int n = getchar() - '0';
    int max = 0;
    int secMax = 0;
    getchar();
    for (int i = 0; i < n; i++)
    {
        int current = getchar() - '0';
        if (i == 0)
        {
            max = current;
            secMax = current;
        }

        if (secMax <= current && current <= max)
        {
            secMax = current;
        }

        if (current > max)
        {
            max = current;
        }
        getchar();
    }
    putchar(secMax + '0');

    return 0;
}