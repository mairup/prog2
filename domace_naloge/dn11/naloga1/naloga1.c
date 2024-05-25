
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

Vozlisce *dodajNaKonec(Vozlisce *zacetek, Vozlisce *vozlisce)
{
    vozlisce->naslednje = NULL;
    Vozlisce *temp = zacetek;
    if (temp == NULL)
    {
        return vozlisce;
    }

    while (temp->naslednje != NULL)
    {
        temp = temp->naslednje;
    }

    temp->naslednje = vozlisce;
    return zacetek;
}

Vozlisce *zdesetkaj(Vozlisce *zacetek, int k)
{
    Vozlisce *voz = zacetek;
    Vozlisce *temp = zacetek;
    Vozlisce *novo = NULL;
    int n = k;

    while (voz != NULL)
    {
        if (n == 0)
        {
            n = k;
        }

        if (n == 1)
        {
            Vozlisce *tempNext = voz->naslednje;
            novo = dodajNaKonec(novo, voz);
            if (tempNext != NULL)
            {
                voz = tempNext;
            }
            else
            {
                return novo;
            }
        }
        else
        {
            temp = voz;
            if (voz->naslednje != NULL)
            {
                voz = voz->naslednje;
                free(temp);
            }
            else
            {
                free(temp);
                return novo;
            }
        }
        if (voz->naslednje == NULL)
            return novo;
        n--;
    }
    return novo;
}

#ifndef test

int main()
{
    return 0;
}

#endif
