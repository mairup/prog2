#include <stdio.h>
#include <stdlib.h>

int napolni_memo[1001][1001];

// int nahrbtnik(int n, int *volumni, int *cene, int v)
// {

//     if (n == 0 || v == 0)
//     {
//         return 0;
//     }

//     if (v >= volumni[n - 1])
//     {
//         return cene[n - 1] + nahrbtnik(n - 1, volumni, cene, v - volumni[n - 1]);
//     }
//     else
//     {
//         return nahrbtnik(n - 1, volumni, cene, v);
//     }
// }

int napolni(int *volumni, int *cene, int volN, int n, int ix)
{
    int najCena = 0;
    if (ix == 0)
    {
        return 0;
    }

    if (napolni_memo[volN][ix - 1] != 0)
    {
        return napolni_memo[volN][ix - 1];
    }

    if (volN >= volumni[ix - 1])
    {
        najCena = cene[ix - 1] + napolni(volumni, cene, volN - volumni[ix - 1], n, ix - 1);
    }

    int cena = napolni(volumni, cene, volN, n, ix - 1);

    najCena = najCena > cena ? najCena : cena;

    napolni_memo[volN][ix - 1] = najCena;

    return najCena;
}

int main()
{

    int v;
    int n;

    scanf("%d %d", &v, &n);

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

    printf("%d\n", napolni(volumni, cene, v, n, n));

    return 0;
}