#include <stdio.h>
#include <stdlib.h>

char currentString[10000000];

void izpisiCurrentString(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", currentString[i]);
    }
    printf("\n");
}

void rekurzija(char **tab, int index, int n)
{
    if (index == n)
    {
        izpisiCurrentString(n);
        return;
    }

    int i = 0;

    while (tab[index][i] != '\0')
    {
        currentString[index] = tab[index][i];
        rekurzija(tab, index + 1, n);
        i++;
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    char **tab = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        tab[i] = (char *)malloc(50 * sizeof(char));
        scanf("%s", tab[i]);
        // printf("%p\n", tab[i]);
    }

    rekurzija(tab, 0, n);

    free(tab);
    return 1;
}