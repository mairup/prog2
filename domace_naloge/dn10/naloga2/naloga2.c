
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

Tocka projekcija(Tocka t, Premica p)
{
    Ulomek x = (Ulomek){0, 0};
    Ulomek y = (Ulomek){0, 0};

    x.st = t.y.st / t.y.im + t.x.st / (p.k.st / p.k.im) - p.n.st / p.n.im;
    x.im = p.k.st / p.k.im + 1 / (p.n.st / p.n.im);

    y.st = t.y.st / t.y.im - t.x.st / (p.n.st / p.n.im) - p.k.st / p.k.im;

    return (Tocka){x, y};
}

#ifndef test

int main()
{
    return 0;
}

#endif
