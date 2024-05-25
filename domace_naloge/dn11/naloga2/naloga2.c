
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int izpisiA(A *a, char *cilj);
int izpisiB(B *b, char *cilj);

int izpisiC(C *c, char *cilj)
{
    int r = 0;
    if (c == NULL)
    {
        r += sprintf(cilj, "NULL");
    }
    else
    {
        r += sprintf(cilj, "{%s, ", c->r == true ? "true" : "false");
        r += izpisiA(c->a, cilj + r);
        r += sprintf(cilj + r, ", ");
        r += izpisiB(c->b, cilj + r);
        r += sprintf(cilj + r, "}");
    }

    return r;
}

int izpisiB(B *b, char *cilj)
{
    int r = 0;
    if (b == NULL)
    {
        r += sprintf(cilj, "NULL");
    }
    else
    {
        r += sprintf(cilj, "{%s, ", b->q);
        r += izpisiC(b->c, cilj + r);
        r += sprintf(cilj + r, "}");
    }

    return r;
}

int izpisiA(A *a, char *cilj)
{
    int r = 0;
    if (a == NULL)
    {
        r += sprintf(cilj, "NULL");
    }
    else
    {
        r += sprintf(cilj, "{%d, ", a->p);
        r += izpisiB(a->b, cilj + r);
        r += sprintf(cilj + r, "}");
    }

    return r;
}

#ifndef test

int main()
{
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
