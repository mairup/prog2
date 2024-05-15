#include <stdio.h>

int tab[10000];
int tab2[10000][10000];
int tabStPotez[10000];
int stIzpisov = 0;
int count = 0;

void vpisiPoteze(int stPotez)
{
    for (int j = 0; j < stPotez; j++)
        tab2[count][j] = tab[j];

    tabStPotez[count] = stPotez;
}

void izpisiPoteze(int stPotez)
{
    stIzpisov += count;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < tabStPotez[i]; j++)
        {
            printf("%d ", tab2[i][j]);
        }
        printf("\n");
    }
}

int vzemiZetone(int n, int k, int poteza, int zetoni)
{
    int gahhh = 1;
    // printf("n %d k %d poteza %d zetoni %d\n", n, k, poteza, zetoni);
    if (n - zetoni <= k && poteza % 2 == 0)
    {
        tab[poteza] = n - zetoni;
        vpisiPoteze(poteza + 1);
        count++;
        return 1;
    }
    else if (n - zetoni <= k && poteza % 2 == 1)
    {
        return 0;
    }

    for (int i = 1; i <= k; i++)
    {
        tab[poteza] = i;
        int vzemiZetoneNizje = vzemiZetone(n, k, poteza + 1, zetoni + i);
        //(vzemiZetone(n, k, poteza + 1, zetoni + i) == 1);
        if (vzemiZetoneNizje == 0)
            gahhh = 0;
        if (vzemiZetoneNizje == 1 && poteza == 0)
            izpisiPoteze(poteza + 1);
        if (poteza == 0)
            count = 0;
    }
    return gahhh;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vzemiZetone(n, k, 0, 0);
    if (stIzpisov == 0)
    {
        printf("CRNI\n");
    }
    return 0;
}