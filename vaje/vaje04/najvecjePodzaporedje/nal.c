#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);
    int vsota = 0;
    int najVsota = INT_MIN;
    // int *tab = (int *)calloc(n, sizeof(int));
    int clen;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &clen);
        vsota += clen;

        if (vsota > najVsota)
        {
            najVsota = vsota;
        }

        if (vsota < 0)
        {
            vsota = 0;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         if (i == 0 && j == 0)
    //         {
    //             max = tab[i];
    //         }

    //         int sum = 0;

    //         for (int k = 0; k < n - j; k++)
    //         {
    //             sum += tab[j + k];
    //             if (sum < 0)
    //             {
    //                 break;
    //             }
    //                     }

    //         if (sum > max)
    //         {
    //             max = sum;
    //         }
    //     }
    // }

    printf("%d\n", najVsota);

    return 0;
}