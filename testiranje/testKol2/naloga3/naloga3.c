
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
static int mSkoki[10000][2];
static int maxL = 0;
// FILE *izhod;

// po potrebi dopolnite ...

int skakac(int ix, int x, int y, int n)
{

    if (sahovnica[x][y] == 1)
    {
        if (ix >= maxL)
        {
            // fprintf(izhod, "ix-%d\n", ix);
            for (int i = 0; i < ix; i++)
            {
                // fprintf(izhod, "%d %d\n", skoki[i][0], skoki[i][1]);
                mSkoki[i][0] = skoki[i][0];
                mSkoki[i][1] = skoki[i][1];
            }
        }

        return ix;
    }
    skoki[ix][0] = x;
    skoki[ix][1] = y;
    sahovnica[x][y] = 1;
    int d = 0;
    int nextL = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d = ((i - x) * (j - y));
            if (d == 2 || d == -2)
            {
                if (i >= 0 && j >= 0)
                {
                    int temp = sahovnica[i][j];
                    nextL = skakac(ix + 1, i, j, n);
                    maxL = maxL > nextL ? maxL : nextL;
                    sahovnica[i][j] = temp;
                }

                // fprintf(izhod, "==D%d i%d j%d x%d y%d\n", d, i, j, x, y);
            }
        }
    }
    return maxL;
}

int main()
{
    // izhod = fopen("test", "wt");
    int n, k;
    scanf("%d\n%d\n", &n, &k);
    int v, s;
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &v, &s);
        sahovnica[v][s] = 1;
    }

    int stSkokov = skakac(0, 0, 0, n);
    for (int i = 1; i < stSkokov; i++)
    {
        printf("%d/%d\n", mSkoki[i][0], mSkoki[i][1]);
    }
    // fclose(izhod);
    return 0;
}
