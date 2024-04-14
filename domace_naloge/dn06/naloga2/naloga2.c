
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
    int(*tab)[N] = calloc((*ciljnoStVrstic * N), sizeof(int));
    int tabI = 0;
    int tabJ = 0;

    // printf("avb\n");

    for (int i = 0; i < izvornoStVrstic; i++)
    {
        int j = 0;
        while (kazalec[i][j])
        {
            // printf("i = %d; j = %d\n", tabI, tabJ);

            tab[tabI][tabJ] = kazalec[i][j];
            // printf("tab[i][j] = %d\n", tab[tabI][tabJ]);
            if (tabJ == (N - 1))
            {
                tabI++;
                tabJ = 0;
            }
            else
                tabJ++;
            j++;
        }
    }

    return tab;
}

#ifndef test

int *TABELA[] = {
    (int[]){7, 0},
    (int[]){3, 12, 16, 1, 0},
    (int[]){2, 8, 11, 0},
    (int[]){5, 13, 9, 0},
    (int[]){14, 4, 0},
    (int[]){15, 6, 10, 0},
};

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

    printf("F2: \n");
    int izvornoStVrstic = sizeof(TABELA) / sizeof(TABELA[0]);
    int ciljnoStVrstic = 4;
    int(*rezultat)[N] = pp2ap(TABELA, izvornoStVrstic, &ciljnoStVrstic);

    for (int i = 0; i < ciljnoStVrstic; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d", rezultat[i][j]);
        }
        printf("\n");
    }
    free(rezultat);
    return 0;
}

#endif
