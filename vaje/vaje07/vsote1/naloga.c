#include <stdio.h>
#include <stdlib.h>

long memo[100000][100];
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

    // printf("%ld\n", nacini(n, k));

    long **memo = malloc((n + 1) * sizeof(long *));
    for (int i = 0; i <= n; i++)
    {
        memo[i] = calloc(k + 1, sizeof(long));
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         memo[i][j] = 0;
    //     }
    // }

    printf("%ld\n", naciniMemo(n, k, memo));

    for (int i = 0; i < n; i++)
    {
        free(memo[i]);
    }
    free(memo);

    printf("%ld\n", sizeof(long));
    return 0;
}