
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int **ap2pp(int (*kazalec)[N], int izvornoStVrstic, int ciljnoStVrstic)
{
    int(*tab)[N] = kazalec;
    int **newT = (int **)malloc(ciljnoStVrstic * sizeof(int *));
    int vrstLen = ((N * izvornoStVrstic) / ciljnoStVrstic) + 1;
    int tabI = 0;

    for (int i = 0; i < ciljnoStVrstic; i++)
    {
        newT[i] = (int *)malloc(vrstLen * sizeof(int));
        for (int j = 0; j < vrstLen; j++)
        {
            newT[i][j] = (*tab)[tabI];
            tabI++;
        }
    }

    return newT;
}

int (*pp2ap(int **kazalec, int izvornoStVrstic, int *ciljnoStVrstic))[N]
{
    // popravite / dopolnite
    return NULL;
}

#ifndef test

int main()
{
    static int tab[][N] = {
        {5, 3, 2, 1, 7},
        {33, 8, 2, 9, 3},
        {4, 5, 5, 21, 5}};

    int **get = ap2pp(tab, 2, 5);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%3d", get[i][j]);
        }
        printf("\n");
        free(get[i]);
    }
    free(get);

    return 0;
}

#endif
