#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char najdVrstica[10000000];

int main(int argc, char *argv[])
{
    FILE *vhod = fopen(argv[1], "rt");
    FILE *izhod = fopen(argv[2], "wt");

    int maxL = 0;
    char *temp = (char *)malloc(10000000 * sizeof(char));

    while (fgets(temp, 10000000, vhod) != NULL)
    {
        int i = 0;
        while (temp[i] != '\0')
        {
            i++;
        }

        if (i > maxL)
        {
            maxL = i;
            strcpy(najdVrstica, temp);
        }
    }

    fprintf(izhod, "%s", najdVrstica);

    fclose(vhod);
    fclose(izhod);
    return 0;
}