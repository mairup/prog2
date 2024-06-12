#include <stdio.h>
long long memo[10000];

long long fibn(int n1, int n2, int k)
{
    if (k == 0)
    {
        return n1;
    }
    else if (k == 1)
    {
        return n2;
    }
    if (memo[k] != 0)
    {
        return memo[k];
    }

    else
    {
        memo[k] = (fibn(n1, n2, k - 1) + fibn(n1, n2, k - 2));
        return memo[k];
    }
}

int main()
{
    int n1, n2, k;
    scanf("%d%d%d", &n1, &n2, &k);
    for (int i = 0; i < k; i++)
    {
        printf("fibn(%d) = [%lld]\n", i, fibn(n1, n2, i));
    }

    return 0;
}