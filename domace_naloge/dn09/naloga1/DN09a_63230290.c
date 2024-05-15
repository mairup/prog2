#include <stdio.h>

int tab[20];

void izpisi(int **tab, int n, int k)
{
    printf("{");
    for (int i = 0; i < k; i++)
    {
        printf("{");

        for (int j = 0; j < n; j++)
        {
            if (j)
            {
                /* code */
            }
            
            printf("%d ", tab[i][j]);
        }

        printf("}");
        if (i != k - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}

void razporedi(int **tab2, int n, int k) {}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tab[i]);
    }
    int **tab2 = (int **)malloc(k * sizeof(int *));
    for (int i = 0; i < k; i++)
    {
        tab2[i] = (int *)malloc(n * sizeof(int));
    }

    razporedi(tab2, n, k);
    return 0;
}