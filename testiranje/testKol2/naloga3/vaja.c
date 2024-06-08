
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
static int sahovnica[21][21];
static int skoki[10000][2];
static int najSkoki[10000][2];
static int najL;
// po potrebi dopolnite ...

void skakac(int ix, int x, int y, int n)
{
    ix++;
    skoki[ix - 1][0] = x;
    skoki[ix - 1][1] = y;
    if (sahovnica[x][y] == 1)
    {
        if (--ix > najL)
        {
            najL = ix;
            for (int i = 0; i < ix; i++)
            {
                najSkoki[i][0] = skoki[i][0];
                najSkoki[i][1] = skoki[i][1];
            }
        }

        return;
    }

    sahovnica[x][y] = 1;

    int tPos;
    int d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d = ((i - x) * (j - y));
            if (d == 2 || d == -2)
            {
                tPos = sahovnica[i][j];
                skakac(ix, i, j, n);
                sahovnica[i][j] = tPos;
            }
        }
    }
}

int main()
{
    int n, k;
    scanf("%d\n%d\n", &n, &k);

    int v, s;
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &v, &s);
        sahovnica[v][s] = 1;
    }

    skakac(0, 0, 0, n);

    for (int i = 1; i < najL; i++)
    {
        printf("%d/%d\n", najSkoki[i][0], najSkoki[i][1]);
    }

    return 0;
}
