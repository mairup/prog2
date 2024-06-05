#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *vhodDat = fopen(argv[1], "rb");
    int vrstica = atoi(argv[2]);
    int stolpec = atoi(argv[3]);
    char *temp = (char *)malloc(100);
    int sirina;
    int visina;
    fscanf(vhodDat, "%s\n", temp);
    fscanf(vhodDat, "%d %d", &sirina, &visina);
    // printf("sirina:%d visina:%d\n", sirina, visina);
    fscanf(vhodDat, "%s\n", temp);

    char *vsebina = (char *)malloc(sirina * visina * 3);
    fread(vsebina, 1, sirina * visina * 3, vhodDat);
    // for (int i = 0; i < sirina * visina * 3; i++)
    // {
    //     printf("pixel:%d %d %d\n", vsebina[i], vsebina[i + 1], vsebina[i + 2]);
    // }

    char red, green, blue;
    int index = sirina * vrstica * 3 + stolpec * 3;
    red = vsebina[index];
    green = vsebina[index + 1];
    blue = vsebina[index + 2];
    printf("R:[%d] B:[%d] G:[%d]\n", red, green, blue);

    fclose(vhodDat);
    free(temp);
    free(vsebina);
    return 0;
}