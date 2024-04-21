#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int **tab = (int *)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        tab[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d %d", &tab[i][0], &tab[i][1]);
    }

    free(tab);
    return 1;
}