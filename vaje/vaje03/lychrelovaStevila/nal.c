#include <stdio.h>

long getReverse(long int n)
{
    long int reverse = 0;
    while (n != 0)
    {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    return reverse;
}

int isLychrel(long int n, int k)
{
    // long int temp = n;
    do
    {
        n += getReverse(n);
        // if (temp == 176)
        //     printf("%ld\n", n);

        if (n == getReverse(n))
        {

            return 0;
        }
        k--;
    } while (k > 0 && n <= 100000000000000000L);
    // printf("%ld\n", temp);
    return k < 0 ? 0 : 1;
}

int main()
{
    int k, a, b;
    scanf("%d %d %d", &k, &a, &b);
    int count = 0;

    for (long int i = a; i < b; i++)
    {
        count += isLychrel(i, k);
    }

    printf("%d\n", count);

    return 0;
}