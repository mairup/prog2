#include <stdio.h>
#include <math.h>

int getSt(int min, int max)
{

    int st = 0;

    for (int i = min; i <= max; i++)
    {
        for (int j = 1; j < max; j++)
        {
            if (sqrt(i * i - j * j) == (int)sqrt(i * i - j * j) && (sqrt(i * i - j * j) != 0))
            {
                st++;
                // printf("%d %d %f\n", i, j, sqrt(i * i - j * j));
                break;
            }
        }
    }

    return st;
}

int main()
{

    int a, b;
    scanf("%d %d", &a, &b);

    int st = getSt(a, b);

    printf("%d\n", st);

    return 0;
}
