
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char *niz, char znak)
{
    if (niz == NULL)
    {
        return 0;
    }

    int counter = 0;
    while (*niz != '\0')
    {
        if (*niz == znak)
            counter++;
        niz++;
        // printf("%p\n", niz);
    }
    return counter;
}

char *kopirajDoZnaka(char *niz, char znak)
{
    // if (niz == NULL)
    // {
    //     return NULL;
    // }

    // int len = 0;
    // while (*niz != znak)
    // {
    //     if (*niz == '\0')
    //     {
    //         niz -= len;
    //         return niz;
    //     }

    //     len++;
    //     niz++;
    //     // printf("%p\n", niz);
    // }
    // niz -= len;

    // char *s = (char *)malloc(len * sizeof(char) + 1);
    // for (int i = 0; i < len; i++)
    // {
    //     // printf("%c\n", *niz);

    //     *s = *niz;
    //     s++;
    //     niz++;
    // }

    // s++;
    // *s = '\0';

    // s -= len - 1;

    // return s;

    char *pZnak = niz;
    while (*pZnak != '\0' && *pZnak != znak)
        pZnak++;

    int dolzinaPodniza = pZnak - niz;

    char *podniz = (char *)malloc(dolzinaPodniza + 1);

    char *p = niz;
    char *q = podniz;

    for (int i = 0; i < dolzinaPodniza; i++)
    {
        *q++ = *p++;
    }
    *q = '\0';

    return podniz;
}

char *kopirajDoZnaka2(char *niz, char znak)
{
    if (niz == NULL)
    {
        return '\0';
    }

    int dolzinaNiza = strlen(niz);
    char *pznak = strchr(niz, znak);

    int dolzinaPodniza = (pznak = NULL) ? dolzinaNiza : pznak - niz;

    char *podniz = (char *)malloc(dolzinaPodniza + 1);

    strncpy(podniz, niz, dolzinaPodniza);
    podniz[dolzinaPodniza] = '\0';
    return podniz;
}

char **razcleni(char *niz, char locilo, int *stOdsekov)
{
    if (niz == NULL)
    {
        return NULL;
    }

    int stlocil = steviloZnakov(niz, locilo) + 1;

    char **odseki = (char **)malloc(stlocil * sizeof(char *));

    char *p = niz;

    for (int i = 0; i < stlocil; i++)
    {
        odseki[i] = kopirajDoZnaka(p, locilo);
        p += strlen(odseki[i]) + 1;
    }

    return odseki;
}

#ifndef test

int main()
{
    int a = steviloZnakov("abcabcadbc", 'd');
    printf("%d\n", a);

    // static int b[10] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2};
    // int *c = b;
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("stevilka: %d naslov: %p\n", *c, c);
    //     c += 1;
    // }

    char *s2 = kopirajDoZnaka("jazen niz z enim samim presledkom ", 's');
    printf("kopirajdoznaka: %s\n", s2);
    free(s2);

    return 0;
}

#endif
