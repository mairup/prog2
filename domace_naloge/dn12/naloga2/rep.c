#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// static int x = 0;
static char finalIzpis[100000000];
static char tempIzpis[100000000];

int passInt(char *niz)
{
    int n = 0;
    int i = 0;
    while (niz[i] != '\0')
    {
        n = n * 10 + niz[i] - '0';
        i++;
    }
    return n;
}

int izpisiRek(FILE *vhod, int n)
{
    // x++;
    //  int x1 = x;
    char *vrstica = (char *)malloc(100 * sizeof(char));
    if (fgets(vrstica, 100, vhod) == NULL)
    {
        return 0;
    }
    // printf("    TEST x: [%d]: {%s", x1, vrstica);
    int i = izpisiRek(vhod, n);
    if (i < n)
    {
        strcpy(tempIzpis, finalIzpis);
        sprintf(finalIzpis, "%s%s", vrstica, tempIzpis);
        // printf("x: [%d] i: [%d]: {%s", x1, i, vrstica);
        return i + 1;
    }
    else
    {
        free(vrstica);
        return n;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        return 0;
    }

    FILE *vhod = fopen(argv[1], "r");
    izpisiRek(vhod, passInt(argv[2]));
    printf("%s", finalIzpis);
    fclose(vhod);
    return 0;
}