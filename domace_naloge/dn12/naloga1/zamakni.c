#include <stdio.h>
#include <stdlib.h>
static char vrstica[1000];

void izpisiVrstico(FILE *izhod, int z)
{
    for (int i = 0; i < z; i++)
    {
        fputc(' ', izhod);
    }
    int n = 0;
    int flag = 0;
    while (vrstica[n] != '\0')
    {
        if (vrstica[n] == ' ' && flag == 0)
        {
            n++;
            continue;
        }
        else
        {
            flag = 1;
        }

        fputc(vrstica[n], izhod);
        n++;
    }
    fflush(izhod);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Uporaba: %s vhodna_datoteka izhodna_datoteka\n", argv[0]);
        return 0;
    }

    int n;
    FILE *vhod = fopen(argv[1], "r");
    FILE *izhod = fopen(argv[2], "w");
    int z = 0;
    int zOld = 0;

    while (fgets(vrstica, 1000, vhod) != NULL)
    {

        n = 0;
        int isStart = 1;
        while (vrstica[n] != '\0')
        {
            while (vrstica[n] == ' ' && isStart == 1)
            {
                n++;
            }
            isStart = 0;

            if (vrstica[n] == '}')
            {
                z -= 4;
                zOld -= 4;
            }

            if (vrstica[n] == '{' && n < 1000 && vrstica[n + 1] == '\n')
            {
                z += 4;
            }

            n++;
        }
        izpisiVrstico(izhod, zOld);
        zOld = z;
    }
    fclose(vhod);
    fclose(izhod);
    return 0;
}