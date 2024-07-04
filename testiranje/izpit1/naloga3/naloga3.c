
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
static int zapPoteza = 1;
static int littlePos = 'A';

// po potrebi dopolnite ...

void hanoi(int n, char a, char b, char c, int k)
{

        if (n == 1)
    {
        if (zapPoteza > k && littlePos == a && c == 'B')
        {
            printf("%d\n", zapPoteza);
        }
        zapPoteza++;
        // printf("%c -> %c,", a, c);
        if (a == littlePos)
        {
            littlePos = c;
        }
        return;
    }

    hanoi(n - 1, a, c, b, k);
    if (zapPoteza > k && littlePos == a && c == 'B')
    {
        printf("%d\n", zapPoteza);
    }
    zapPoteza++;
    if (a == littlePos)
    {
        littlePos = c;
    }
    // printf("%c -> %c,", a, c);
    hanoi(n - 1, b, a, c, k);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    hanoi(n, 'A', 'B', 'C', k);
    return 0;
}
