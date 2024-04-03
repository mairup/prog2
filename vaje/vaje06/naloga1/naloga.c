
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
    int len = 0;
    while (*niz != znak)
    {
        if (*niz == '\0')
        {
            niz -= len;
            return niz;
        }

        len++;
        niz++;
        // printf("%p\n", niz);
    }
    niz -= len;

    char *s = (char *)malloc(len * sizeof(char) + 1);
    for (int i = 0; i < len; i++)
    {
        // printf("%c\n", *niz);

        *s = *niz;
        s++;
        niz++;
    }

    s -= len;

    return s;
}

char **razcleni(char *niz, char locilo, int *stOdsekov)
{
    // popravite / dopolnite ...
    return NULL;
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
    return 0;
}

#endif
