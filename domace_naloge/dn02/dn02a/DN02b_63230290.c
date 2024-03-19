#include <stdio.h>

int readUntilSpace(char current)
{
    while (current != ' ' && current != '\n')
    {
        current = getchar();
    }

    if (current == '\n')
        return 1;

    else
        return 0;
}

int preberiSt(char current)
{
    int flagForZero = 0;
    int st = 0;

    if (current == '-' || current == '+')
    {
        current = getchar();
        goto uwu;
    }

    while (current != ' ')
    {
    uwu:

        if (current == '\n')
        {
            putchar('0');
            return -2;
        }

        if (current > '9' || current < '0')
        {
            if (current != ' ')
            {
                if (readUntilSpace(current) == 1)
                {
                    putchar('0');
                    return -2;
                }
                else
                    return 0;
            }
            else
                return 0;
        }

        if (current == '0' && st == 0)
        {
            if (flagForZero == 1)
            {
                return 0;
            }
            else
            {
                flagForZero = 1;
                current = getchar();
                if (current == ' ')
                {
                    return 1;
                }
                else if (current == '\n')
                {
                    putchar('1');
                    return -2;
                }
                else
                {
                    if (readUntilSpace(current) == 1)
                    {
                        putchar('0');
                        return -2;
                    }
                    else
                        return 0;
                }
            }

            flagForZero = 1;
            continue;
        }

        st = st * 10 + (int)current - '0';
        current = getchar();

        if (current == '\n')
        {
            putchar('1');
            return -2;
        }

        // printf("current: %c\n", current);
        // printf("st: %d\n", st);
    }

    if (flagForZero == 1 && st == 0)
        return 1;

    else if (st == 0)
    {
        return 0;
    }

    return 1;
}

int main()
{
    int st = 0;
    char c = getchar();
    while (c != '\n')
    {
        st = preberiSt(c);
        if (st != -2)
        {
            putchar(st + '0');
        }
        else if (st == -2)
        {
            break;
        }

        c = getchar();
        if (c == '\n')
        {
            break;
        }
    }
    putchar('\n');

    return 0;
}