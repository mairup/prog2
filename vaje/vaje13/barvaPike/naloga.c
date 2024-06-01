#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *vhod = fopen(argv[1], "rb");
    int vrstica = atoi(argv[2]);
    int stolpec = atoi(argv[3]);

    int sirina, visina;
    char *temp = malloc(10 * sizeof(char));
    fgets(temp, 10, vhod);
    fscanf(vhod, "%d%d\n", &sirina, &visina);
    fgets(temp, 10, vhod);
    free(temp);

    int slikaSize = sirina * visina * 3;
    unsigned char *slika = malloc(slikaSize * sizeof(unsigned char));
    fread(slika, sizeof(unsigned char), slikaSize, vhod);
    int i = (vrstica * sirina + stolpec) * 3;
    printf("%d %d %d\n", slika[i], slika[i + 1], slika[i + 2]);
    fclose(vhod);
    return 0;
}