#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *vhod = fopen(argv[1], "rb");
    FILE *izhod = fopen(argv[2], "wb");
    int sirina, visina;
    char *temp = malloc(100);
    fscanf(vhod, "%s\n%d %d\n", temp, &sirina, &visina);
    fgets(temp, 100, vhod);
    free(temp);

    int slikaRGBSize = sirina * visina * 3;
    int slikaSivaSize = slikaRGBSize / 3;
    unsigned char *slika = malloc(slikaRGBSize * sizeof(char));
    fread(slika, 1, slikaRGBSize, vhod);
    unsigned char *slika2 = (unsigned char *)malloc((slikaSivaSize) * sizeof(char));

    char pixel;
    for (int i = 0; i < slikaSivaSize; i++)
    {
        pixel = (slika[3 * i] * 30 + slika[3 * i + 1] * 59 + slika[3 * i + 2] * 11) / 100;
        slika2[i] = pixel;
    }
    fprintf(izhod, "P5\n%d %d\n255\n", sirina, visina);
    fwrite(slika2, 1, slikaSivaSize, izhod);

    free(slika);
    free(slika2);
    fclose(vhod);
    fclose(izhod);
    return 0;
}