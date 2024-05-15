
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga1.c
./a.out

*/

#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

int *poisci(int *t, int *dolzina, int **konec)
{
    int *min = t;
    int *max = t;

MINSET:
    if (*min != 0)
    {
        min--;
        goto MINSET;
    }

MAXSET:

    if (*max != 0)
    {
        max++;
        goto MAXSET;
    }

    *konec = max - 1;
    *dolzina = max - min - 1;

    return ++min;
}

#ifndef test

int main()
{
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
