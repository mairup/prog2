#include <stdio.h>
#include <math.h>

int preberiSt()
{
    int st = 0;
    int predznak = 0;

    char current = getchar();
    if (current == '-')
    {
        predznak = -1;
        current = getchar();
    }

    else
        predznak = 1;

    while (current != ' ' && current != '\n')
    {
        if (current == '0' && st == 0)
        {
            current = getchar();
            continue;
        }

        st = st * 10 + (int)current - '0';
        current = getchar();
    }

    return predznak * st;
}

void izpisiSt(int st)
{
    if (st / 10 == 0)
    {
        putchar(st + '0');
    }
    else
    {
        izpisiSt(st / 10);
        putchar(st % 10 + '0');
    }
}

int main()
{

    int prvoSt = preberiSt();
    int drugoSt = preberiSt();

    prvoSt += drugoSt;

    if (prvoSt < 0)
    {
        putchar('-');
        prvoSt = -prvoSt;
    }

    izpisiSt(prvoSt);
    putchar('\n');
    return 0;
}
