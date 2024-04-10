#include <stdio.h>

long nacini(int n, int k)
{
    // printf("n: %d, k: %d\n", n, k);
    if (n == 0 || k == 1)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }

    return nacini(n - k, k) + nacini(n, k - 1);
}

int main()
{
    int n;
    int k;

    scanf("%d %d", &n, &k);

    printf("%ld\n", nacini(n, k));
    return 0;
}