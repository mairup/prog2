
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
static char nazivi[1000][1000];
static char naziviAll[1000][1000];
static char vrstica[1000][1000];
static int iNaziva[1000];

// po potrebi dopolnite ...

int main(int argc, char **argv)
{
    FILE *vhod = fopen(argv[1], "r");
    FILE *izhod = fopen(argv[2], "w");
    int m = atoi(argv[3]);
    int indNaziva = 0;
    for (int i = 4; i < argc; i++)
    {
        strcpy(nazivi[indNaziva], argv[i]);
        indNaziva++;
    }

    char *currentNaziv = malloc(100);
    for (int i = 0; i < m; i++)
    {
        fscanf(vhod, "%s ", currentNaziv);
        strcpy(naziviAll[i], currentNaziv);

        for (int j = 0; j < indNaziva; j++)
        {
            if (strcmp(naziviAll[i], nazivi[j]) == 0)
            {
                iNaziva[j] = i;
                goto endInner;
            }
        }
    endInner:
        m = m; // compiler retarded
    }
    for (int i = 0; i < indNaziva; i++)
    {
        if (i == (indNaziva - 1))
        {
            fprintf(izhod, "%s\n", nazivi[i]);
        }
        else
            fprintf(izhod, "%s,", nazivi[i]);
    }

loop:
    for (int i = 0; i < m; i++)
    {
        if (fscanf(vhod, "%s ", vrstica[i]) != 1)
        {
            goto end;
        }
    }

    for (int i = 0; i < indNaziva; i++)
    {
        if (i == (indNaziva - 1))
        {
            fprintf(izhod, "%s\n", vrstica[iNaziva[i]]);
        }
        else
            fprintf(izhod, "%s,", vrstica[iNaziva[i]]);
    }

    goto loop;

end:
    // fprintf(izhod, "%s", "\n");
    fclose(izhod);
    fclose(vhod);
    free(currentNaziv);
    return 0;
}
