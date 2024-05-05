#include <stdio.h>

int tab[10];

int tabIsSorted(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", tab[i]);
        if (tab[i] > tab[i + 1])
        {
            printf("%d ", tab[i + 1]);
            printf("\n");
            return 0;
        }
    }
    printf("%d ", tab[n - 1]);
    printf("\n");
    return 1;
}

int stZamenjav(int n, int k, int r, int stPremikov, int pos)
{
    int stResitev = 0;
    if (tabIsSorted(n) == 1)
    {
        stResitev++;
        if (stPremikov == k)
        {
            return 1;
        }
    }
    if (stPremikov > k)
    {
        return 0;
    }

    int temp = 0;
    stPremikov++;
    printf("r %d \n", r);
    for (int rtemp = r; rtemp <= n - r; rtemp++)
    {
        for (int i = pos; i < r; i++)
        {
            printf("%d \n", tabIsSorted(n));
            temp = tab[pos + i];
            tab[pos + i] = tab[pos + i + rtemp];
            tab[pos + i + rtemp] = temp;
            stResitev += stZamenjav(n, k, r, stPremikov, pos + 1);
        }
    }

    return stResitev;
}

int main()
{
    int n, k, r;
    scanf("%d %d %d", &n, &k, &r);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tab[i]);
    }

    printf("st resitev: %d\n", stZamenjav(n, k, r, 0, 0));

    return 0;
}