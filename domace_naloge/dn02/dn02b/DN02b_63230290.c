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

int readDecimal()
{
    char current = getchar();

    if (current == ' ')
    {
        return 0;
    }

    if (current == '\n')
    {
        putchar('0');
        return -1;
    }

    while (current != ' ' && current != '\n')
    {
        if (current < '0' || current > '9')
        {
            if (readUntilSpace(current) == 1)
            {
                putchar('0');
                return -1;
            }
            else
                return 0;
        }
        current = getchar();
    }

    if (current == '\n')
    {
        putchar('1');
        return -1;
    }
    return 1;
}

int readHex()
{
    char current = getchar();

    if (current == ' ')
    {
        return 0;
    }

    if (current == '\n')
    {
        putchar('0');
        return -1;
    }

    while (current != ' ' && current != '\n')
    {
        if ((current >= '0' && current <= '9') || (current >= 'A' && current <= 'F'))
        {
        }
        else
        {
            if (readUntilSpace(current) == 1)
            {
                putchar('0');
                return -1;
            }
            else
                return 0;
        }
        current = getchar();
    }

    if (current == '\n')
    {
        putchar('1');
        return -1;
    }
    return 1;
}

int readBinary()
{
    char current = getchar();

    if (current == ' ')
    {
        return 0;
    }

    if (current == '\n')
    {
        putchar('0');
        return -1;
    }

    while (current != ' ' && current != '\n')
    {
        if (current == '0' || current == '1')
        {
        }
        else
        {
            if (readUntilSpace(current) == 1)
            {
                putchar('0');
                return -1;
            }
            else
                return 0;
        }
        current = getchar();
    }

    if (current == '\n')
    {
        putchar('1');
        return -1;
    }
    return 1;
}

int readOctal(char current)
{
    // printf("\ncurrent: %c\n", current);

    if (current == ' ')
    {
        return 1;
    }

    if (current == '\n')
    {
        putchar('1');
        return -1;
    }

    if (current < '0' || current > '7')
    {
        if (readUntilSpace(current) == 1)
        {
            putchar('0');
            return -1;
        }
        else
            return 0;
    }

    while (current != ' ' && current != '\n')
    {
        if (current >= '0' && current <= '7')
        {
        }
        else
        {
            if (readUntilSpace(current) == 1)
            {
                putchar('0');
                return -1;
            }
            else
                return 0;
        }
        current = getchar();
    }

    if (current == '\n')
    {
        putchar('1');
        return -1;
    }
    return 1;
}

int preberiTypeOfNum(char current)
{
    // printf("\ncurrent: %c\n", current);
    if (current == '0')
    {
        current = getchar();
        if (current == 'x')
        {
            return readHex();
        }
        else if (current == 'b')
        {
            return readBinary();
        }
        else
        {
            return readOctal(current);
        }
    }
    else if (current >= '1' && current <= '9')
    {
        return readDecimal();
    }
    else
    {
        if (readUntilSpace(current) == 1)
        {
            putchar('0');
            return -1;
        }
        else
            return 0;
    }
}

int main()
{
    int st = 0;
    char c = getchar();
    while (c != '\n')
    {
        st = preberiTypeOfNum(c);
        if (st == -1)
        {
            break;
        }
        else
        {
            putchar(st + '0');
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