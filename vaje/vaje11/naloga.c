
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce *zacetek)
{
    Vozlisce *temp = zacetek;
    if (temp == NULL)
    {
        return 0;
    }

    int vsota = 0;

    while (temp->naslednje != NULL)
    {
        vsota += temp->podatek;
        temp = temp->naslednje;
    }

    vsota += temp->podatek;

    return vsota;
}

int vsotaR(Vozlisce *zacetek)
{
    if (zacetek == NULL)
    {
        return 0;
    }

    return zacetek->podatek + vsotaR(zacetek->naslednje);
}

Vozlisce *vrniVozlisce(int element)
{
    Vozlisce *newZacetek = malloc(sizeof(Vozlisce));
    newZacetek->podatek = element;
    newZacetek->naslednje = NULL;
    return newZacetek;
}

Vozlisce *vstaviUrejenoI(Vozlisce *zacetek, int element)
{
    Vozlisce *temp = zacetek;

    if (temp == NULL)
    {
        return vrniVozlisce(element);
    }

    while (temp->podatek < element)
    {
        if (temp->naslednje != NULL)
        {
            if (temp->naslednje->podatek >= element)
            {
                Vozlisce *tempNext = temp->naslednje;
                temp->naslednje = vrniVozlisce(element);
                temp->naslednje->naslednje = tempNext;
                return zacetek;
            }
            if (temp->naslednje->podatek < element)
            {
                vstaviUrejenoR(temp->naslednje, element);
                return zacetek;
            }
        }
        else
        {
            temp->naslednje = vrniVozlisce(element);
            return zacetek;
        }
        temp = temp->naslednje;
    }
    Vozlisce *newZacetek = vrniVozlisce(element);
    newZacetek->naslednje = zacetek;
    return newZacetek;

    return zacetek;
}

Vozlisce *vstaviUrejenoR(Vozlisce *zacetek, int element)
{
    Vozlisce *temp = zacetek;
    if (temp == NULL)
    {
        return vrniVozlisce(element);
    }
    if (temp->podatek < element)
    {
        if (temp->naslednje != NULL)
        {
            if (temp->naslednje->podatek >= element)
            {
                Vozlisce *tempNext = temp->naslednje;
                temp->naslednje = vrniVozlisce(element);
                temp->naslednje->naslednje = tempNext;
                return zacetek;
            }
            if (temp->naslednje->podatek < element)
            {
                vstaviUrejenoR(temp->naslednje, element);
                return zacetek;
            }
        }
        else
        {
            temp->naslednje = vrniVozlisce(element);
            return zacetek;
        }
    }
    Vozlisce *newZacetek = vrniVozlisce(element);
    newZacetek->naslednje = zacetek;
    return newZacetek;
}

Vozlisce *create_reverse(Vozlisce *zacetek)
{
    Vozlisce *temp = zacetek;
    if (temp->naslednje == NULL)
    {
        return temp;
    }
    Vozlisce *tt = create_reverse(temp->naslednje);
    Vozlisce *ttt = tt;

    while (ttt->naslednje != NULL)
    {
        ttt = ttt->naslednje;
    }
    ttt->naslednje = temp;
    ttt->naslednje->naslednje = NULL;
    return tt;
}

void izpisi(Vozlisce *zacetek)
{
    Vozlisce *temp = zacetek;
    int i = 0;
    while (temp != NULL)
    {
        printf("%d -> ", temp->podatek);
        temp = temp->naslednje;

        i++;
        if (i > 10)
        {
            printf("CYCLE\n");
            return;
        }
    }
    printf("NULL\n");
}

#ifndef test

int main()
{
    Vozlisce *zacetek = NULL;
    zacetek = vstaviUrejenoI(zacetek, 5);
    zacetek = vstaviUrejenoI(zacetek, 3);
    zacetek = vstaviUrejenoI(zacetek, 1);
    zacetek = vstaviUrejenoI(zacetek, 2);
    zacetek = vstaviUrejenoI(zacetek, 4);

    izpisi(zacetek);

    Vozlisce *reverse = create_reverse(zacetek);

    izpisi(reverse);

    return 0;
}

#endif
