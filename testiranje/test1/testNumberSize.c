#include <stdio.h>
#include <stdlib.h>
static int perc[2];
static int arrSize = 1000;

int addUp(int **mommy)
{
    int sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            // printf("%d i:%d j:%d\n", mommy[i][j], i, j);
            // fflush(stdout);
            if (sum < 0)
            {
                sum += mommy[i][j];
                perc[0]++;
            }
            else
            {
                sum -= mommy[i][j];
                perc[1]++;
            }
        }
    }

    return sum;
}

void doStuff(int rand)
{
    int n;
    int temp;
    int **mommy = (int **)malloc(arrSize * sizeof(int *));
    for (int i = 0; i < arrSize; i++)
    {
        mommy[i] = (int *)malloc(arrSize * sizeof(int));
        for (int j = 0; j < arrSize; j++)
        {
            temp = j + 333 * rand;
            mommy[i][j] = temp * 99 + (temp + 2) * 3 - (temp + 3) * 50;
        }
    }
    n = addUp(mommy);

    for (int i = 0; i < arrSize; i++)
    {
        free(mommy[i]);
    }
    free(mommy);
}

int main()
{
    for (int i = 0; i < 1000; i++)
    {
        doStuff(i);
    }
    printf("posiVibes:[%d] negVibes:[%d]\n", perc[0], perc[1]);
    return 0;
}