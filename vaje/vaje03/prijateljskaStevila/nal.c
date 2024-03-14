#include <stdio.h>
// #include<math.h>

int getFrend(int n)
{
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int a;
    scanf("%d", &a);

    int aFrend = getFrend(a);

    int bFrend = getFrend(aFrend);

    // printf("%d\n", aFrend);

    if (a == bFrend)
    {
        printf("%d\n", aFrend);
    }
    else
    {
        printf("NIMA\n");
    }

    return 0;
}