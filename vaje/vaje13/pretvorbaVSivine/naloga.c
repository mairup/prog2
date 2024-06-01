#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *vhod = fopen(argv[1], "rb");
    FILE *izhod = fopen(argv[2], "wb");
    FILE *test = fopen("test.a", "wt");
    int sirina, visina;
    char *temp = malloc(10 * sizeof(char));
    fgets(temp, 10, vhod);
    fscanf(vhod, "%d%d\n", &sirina, &visina);
    fgets(temp, 10, vhod);
    free(temp);
    int slikaSize = sirina * visina * 3;
    unsigned char *slika = malloc(slikaSize * sizeof(unsigned char));
    fread(slika, sizeof(unsigned char), slikaSize, vhod);
    unsigned char *slikaSiva = malloc(slikaSize / 3 * sizeof(unsigned char));
    fprintf(izhod, "P5\n%d %d\n255\n", sirina, visina);
    for (int i = 0; i < slikaSize; i += 3)
    {
        slikaSiva[i / 3] = slika[i] * 30 + slika[i + 1] * 59 + slika[i + 2] * 11;
        slikaSiva[i / 3] /= 100;
        fprintf(test, "%d %d %d\n", slika[i + 0], slika[i + 1], slika[i + 2]);
        fprintf(test, "%d\n", slikaSiva[i / 3]);
    }
    fwrite(slikaSiva, sizeof(unsigned char), slikaSize / 3, izhod);
    fclose(izhod);
    fclose(test);
    fclose(vhod);
    return 0;
}