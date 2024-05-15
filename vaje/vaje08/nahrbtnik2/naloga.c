#include <stdio.h>
#include <stdlib.h>

int napolni_memo[1001][1001][11];

// int napolni(int *volumni, int *cene, int k, int volN, int n, int ix)
// {
//     int najCena = 0;
//     int cena = 0;
//     if (ix == 0)
//     {
//         return 0;
//     }

//     if (k == 0 && (volumni[ix - 1] % 2 == 1))
//     {
//         return napolni(volumni, cene, k, volN, n, ix - 1);
//     }

//     if (napolni_memo[volN][ix - 1] != 0)
//     {

//         return napolni_memo[volN][ix - 1];
//     }

//     if (volN >= volumni[ix - 1])
//     {
//         int tempK = k;
//         if (volumni[ix - 1] % 2 == 1)
//         {
//             tempK--;
//         }
//         najCena = cene[ix - 1] + napolni(volumni, cene, tempK, volN - volumni[ix - 1], n, ix - 1);
//     }

//     cena = napolni(volumni, cene, k, volN, n, ix - 1);

//     najCena = najCena > cena ? najCena : cena;

//     napolni_memo[volN][ix - 1] = najCena;

//     return najCena;
// }

int napolni(int *volumni, int *cene, int k, int volN, int n, int ix)
{
    int najCena = 0;
    int cena = 0;
    if (ix == n)
    {
        return 0;
    }

    if (k == 0 && (volumni[ix] % 2 == 1))
    {
        return napolni(volumni, cene, k, volN, n, ix + 1);
    }

    if (napolni_memo[volN][ix][k] != 0)
    {
        return napolni_memo[volN][ix][k];
    }

    if (volN >= volumni[ix])
    {
        int tempK = k;
        if (volumni[ix] % 2 == 1)
        {
            tempK--;
        }
        najCena = cene[ix] + napolni(volumni, cene, tempK, volN - volumni[ix], n, ix + 1);
    }

    cena = napolni(volumni, cene, k, volN, n, ix + 1);

    najCena = najCena > cena ? najCena : cena;

    napolni_memo[volN][ix][k] = najCena;

    return najCena;
}

int main()
{

    int v;
    int n;
    int k;

    scanf("%d %d %d", &v, &n, &k);

    int *volumni = malloc(n * sizeof(int));
    int *cene = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &volumni[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cene[i]);
    }

    printf("%d\n", napolni(volumni, cene, k, v, n, 0));

    return 0;
}