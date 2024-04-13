
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

char *zdruzi(char **nizi, char *locilo)
{
    char **niziCount = nizi;
    int newSize = 0;
    int index = 0;
    int lociloLen = 0;
    while (locilo[0] != '\0')
    {
        lociloLen++;
        locilo++;
    }

    locilo -= lociloLen;

    while (niziCount[index] != NULL)
    {
        // printf("ime -> %s\n", niziCount[index]);
        for (int i = 0; niziCount[index][i] != '\0'; i++)
        {
            newSize++;
        }
        newSize += lociloLen;
        index++;
    }

    char *zdruzenString = (char *)malloc(newSize * sizeof(char));

    index = 0;
    int zdruzenStringIndex = 0;
    while (niziCount[index] != NULL)
    {

        for (int i = 0; niziCount[index][i] != '\0'; i++)
        {
            zdruzenString[zdruzenStringIndex] = niziCount[index][i];
            zdruzenStringIndex++;
        }
        if (niziCount[index + 1] != NULL)
            while (*locilo != '\0')
            {
                zdruzenString[zdruzenStringIndex] = *locilo;
                zdruzenStringIndex++;
                locilo++;
            }
        locilo -= lociloLen;
        index++;
    }

    return zdruzenString;
}

#ifndef test

int main()
{
    static char *NIZI[] = {"Radko", "Milena", "Boris", NULL};
    char *niz = zdruzi(NIZI, ", ");
    printf("<%s>\n", niz);
    free(niz);
    return 0;
}

#endif
