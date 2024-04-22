#include <stdio.h>
#include <stdlib.h>

int preglejOtroke(int **tab, int index)
{
    printf("index: %d\n", index);
    if (tab[index][0] == 0 && tab[index][1] == 0)
    {
        return 0;
    }

    if (tab[index][0] == 0)
    {
        return preglejOtroke(tab, index + tab[index][1]) + 1;
    }

    if (tab[index][1] == 0)
    {
        return preglejOtroke(tab, index + tab[index][0]) + 1;
    }

    int lHeight = preglejOtroke(tab, index + tab[index][0]) + 1;
    int rHeight = preglejOtroke(tab, index + tab[index][1]) + 1;

    return lHeight > rHeight ? lHeight : rHeight;
}

int main()
{
    int n;
    scanf("%d", &n);
    int **tab = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        tab[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d %d", &tab[i][0], &tab[i][1]);
    }

    printf("%d\n", preglejOtroke(tab, 0));

    free(tab);
    return 1;
}