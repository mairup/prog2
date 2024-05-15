#include <stdio.h>

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
    char c = getchar();
    int flag = 0;
    int flag2 = 0;
    int flag3 = 0;
    int out = 0;

    while (c != '\n')
    {
        c == '1' ? flag = 1 : c;
        c == '0' && (flag == 1) ? flag2 = 1 : c;
        c == '1' && (flag2 == 1) ? flag3 = 1 : c;

        if (flag == 1)
        {
            out++;
        }

        c = getchar();
    }

    if (flag3 != 1)
    {
        out -= 1;
    }

    izpisiSt(out);
    putchar('\n');
    return 0;
}