#include <stdio.h>
#include <stdlib.h>

// /long memo[100000][100];
long nacini(int orig_n, int n, int k)
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

    return nacini(orig_n, n - k, k) + nacini(orig_n, n, k - 1);
}

long naciniMemo(int n, int k, long **memo)
{
    if (n == 0 || k == 1)
    {
        return 1;
    }
    else if (n < 0 || k < 1)
    {
        return 0;
    }
    if (memo[n][k] != 0)
    {
        return memo[n][k];
    }
    // printf("n: %d, k: %d\n", n, k);
    memo[n][k] = naciniMemo(n - k, k, memo) + naciniMemo(n, k - 1, memo);
    return memo[n][k];
}

int main()
{
    int n;
    int k;

    scanf("%d %d", &n, &k);

    printf("%ld\n", nacini(n, n, k));
    return 0;
}