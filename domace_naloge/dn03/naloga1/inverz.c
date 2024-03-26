
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c inverz.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>

#include "inverz.h"

long inverz(long y, long a, long b)
{
    for (long i = a; i <= b; i++)
    {
        if (f(i) == y)
        {
            return i;
        }
    }
    return -1;
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.
