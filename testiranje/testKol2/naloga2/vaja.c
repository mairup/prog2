#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int iNaz[1000];
static char vrstica[1000][1000];
static char beseda[1000];

int main(int argc, char *argv[])
{
    FILE *vhod = fopen(argv[1], "r");
    FILE *izhod = fopen(argv[2], "w");
    int m = atoi(argv[3]);

    for (int i = 0; i < m; i++)
    {
        fscanf(vhod, "%s ", beseda);
        for (int j = 4; j < argc; j++)
        {

            if (strcmp(beseda, argv[j]) == 0)
            {
                iNaz[j] = i;
            }
        }
    }
    for (int i = 4; i < argc; i++)
    {
        if (i == (argc - 1))
        {
            fprintf(izhod, "%s\n", argv[i]);
        }
        else
        {
            fprintf(izhod, "%s,", argv[i]);
        }
    }

    // fprintf(izhod, "--%s--", beseda);
    int x = 0;
    while (1)
    {
        if (fscanf(vhod, "%s ", vrstica[x]) != 1)
        {
            break;
        }

        if (x < (m - 1))
        {
            x++;
            continue;
        }

        for (int i = 4; i < argc; i++)
        {
            if (i == (argc - 1))
            {
                fprintf(izhod, "%s\n", vrstica[iNaz[i]]);
            }
            else
                fprintf(izhod, "%s,", vrstica[iNaz[i]]);
        }
        x = 0;
    }

    fclose(vhod);
    fclose(izhod);
    return 0;
}