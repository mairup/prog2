#include <stdio.h>
#include <stdlib.h>

char fileNames[10][100];

int getMinNum(int n, int *buffer, int *activeFiles, int *nOfActiveFiles)
{
    int minN = buffer[0];
    int minIndex = 0;
    while (buffer[minIndex] == 0 && minIndex < n - 1)
    {
        minIndex++;
        minN = buffer[minIndex];
    }

    for (int i = minIndex + 1; i < n; i++)
    {
        if (activeFiles[i] == -1)
        {
            continue;
        }

        if (buffer[i] == 0)
        {
            continue;
        }

        if (buffer[i] < minN && buffer[i] != 0)
        {
            minN = buffer[i];
            minIndex = i;
        }
    }
    buffer[minIndex] = 0;
    return minN;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    FILE **files = (FILE **)malloc(n * sizeof(FILE *));
    for (int i = 0; i <= n; i++)
    {
        scanf("%s", fileNames[i]);
    }

    FILE *output = fopen(fileNames[n], "wt");
    int *buffer = (int *)calloc(n, sizeof(int));
    int nOfActiveFiles = n;
    int *activeFiles = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        files[i] = fopen(fileNames[i], "rt");
    }

    while (nOfActiveFiles > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (activeFiles[i] == -1)
            {
                continue;
            }
            if (buffer[i] != 0)
            {
                continue;
            }

            int abc = fscanf(files[i], "%d", &buffer[i]);
            if (abc < 1)
            {
                activeFiles[i] = -1;
                nOfActiveFiles--;
                continue;
            }
        }
        int minN = getMinNum(n, buffer, activeFiles, &nOfActiveFiles);
        if (minN == 0)
        {
            continue;
        }

        fprintf(output, "%d\n", minN);
    }
    for (int i = 1; i < n; i++)
    {
        fclose(files[i]);
    }

    fclose(output);
    free(files);
    free(buffer);
    free(activeFiles);
    return 0;
}