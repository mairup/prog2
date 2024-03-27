
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

    // printf("indeks : %d\n", *indeks);
    // printf("kazalec : %d\n", **kazalec);
    if (*indeks == -1)
    {
        *indeks = *kazalec - t;
    }

    else
    {
        *kazalec = t + *indeks;
    }

    // printf("indeks : %d\n", *indeks);
    // printf("kazalec : %d\n", **kazalec);
}

void frekvenceCrk(char *niz, int **frekvence)
{
    // dopolnite ...
}

#ifndef test

int main()
{
    // int *t = (int *)malloc(10 * sizeof(int));

    // for (int i = 0; i < 10; i++)
    // {
    //     t[i] = 5;
    // }

    // printf("vsota : %d\n", vsota(t, t + 9));
    // t[5] = -1;
    // int a = -1;
    // int *b = &a;
    // int *d = &t[5];
    // int **c = &d;
    // indeksInKazalec(t, b, c);

    // printf("\n");

    // a = 4;

    // indeksInKazalec(t, b, c);

    return 0;
}

#endif
