#include <stdio.h>
#include <stdlib.h>

// int tab[100000];

int main()
{
    int n;
    scanf("%d", &n);

    int b = 1;
    int it = 0;

    int *ntab = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &it);
        ntab[it] = 1;
        // printf("%d\n", ntab[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (ntab[i] == 0)
        {
            b = 0;
            break;
        }
        // printf("%d\n", ntab[i]);
    }

    printf("%s\n", b == 1 ? "DA" : "NE");

    free(ntab);
    return 0;
}