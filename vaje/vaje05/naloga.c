
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int *zac, int *kon)
{
    int *p = zac;
    int vsota = 0;
    while (p <= kon)
    {
        vsota += *p;
        p++;
    }
    return vsota;
}

void indeksInKazalec(int *t, int *indeks, int **kazalec)
{
    if (*indeks == -1)
    {
    }
}

void frekvenceCrk(char *niz, int **frekvence)
{
    // dopolnite ...
}

#ifndef test

int main()
{
    int *t = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        t[i] = 5;
    }

    printf("vsota : %d\n", vsota(t, t + 9));

    return 0;
}

#endif
