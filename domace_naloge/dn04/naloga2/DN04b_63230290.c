#include <stdio.h>

int main()
{

    int n, k;
    scanf("%d %d", &n, &k);
    static int tab[1000000000];
    static int tabn[1000000000];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tab[i]);
    }

    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        tabn[i] = 0;
        int sum = 0;
        if (i > 0)
        {
            if ((tab[i] == tab[i - 1]))
            {
                if ((tab[i] + tab[i - 1]) == k && tabn[i - 1] != 0)
                {
                    tabn[i] = tabn[i - 1] - 1;
                }
                else
                    tabn[i] = tabn[i - 1];

                goto skipLoop;
            }
        }
        int tempCounter = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum = tab[j] + tab[i];
            if (sum == k)
            {
                tempCounter++;
            }
        }
        tabn[i] = tempCounter;
    skipLoop:
        counter += tabn[i];
    }

    printf("%d\n", counter);

    return 0;
}