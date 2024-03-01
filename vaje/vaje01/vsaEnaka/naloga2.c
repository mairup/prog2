#include <stdio.h>

int main()
{
    int b = 1;
    int n = getchar() - '0';
    getchar();
    int number = getchar() - '0';
    getchar();
    // putchar(number + '0');
    for (int i = 1; i < n; i++)
    {
        int current = getchar() - '0';
        if (current != number)
        {
            b = 0;
            // printf("\n%d %d\n", current, number);
        }
        getchar();
    }
    putchar(b + '0');
    putchar('\n');

    return 0;
}