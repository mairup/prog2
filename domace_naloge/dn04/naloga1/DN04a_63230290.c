#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    static int tab1[1000];
    static int tab2[1000];
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tab1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tab2[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < (n + i); j++)
        {

            if (j >= n)
            {
                // printf("ROW %d : ", i);
                // printf("%d %d\n", tab1[j - n], tab2[j - i]);
                if (tab1[j - n] != tab2[j - i])
                {
                    //  printf("x2");
                    goto end;
                }
            }
            else
            {
                // printf("ROW %d : ", i);
                // printf("%d %d\n", tab1[j], tab2[j - i]);
                if (tab1[j] != tab2[j - i])
                {
                    // printf("x1");
                    goto end;
                }
            }

            if (j == (n + i - 1))
            {
                // printf("%d %d %d\n", j, (n + i - 1), i);
                goto realEnd;
            }
        }
    end:
        counter++;
    }
realEnd:

    printf("%d\n", counter);
    return 0;
}