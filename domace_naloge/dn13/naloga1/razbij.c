#include <stdio.h>
#include <stdlib.h>
static char stevilka[1000];

void appendNum(char *s,int n){
    int x = 0;
    if (n == 0)
    {
        stevilka[0]='0';
        x=1;
        goto skip;
    }

    
    while (n>0)
    {
      s[x] = n % 10 + '0';
        n = n / 10;
        x++;
    }
    skip:

for(int i=0;i<100;i++){
    if (s[i]=='.')
    {
        --x;

        while (x>=0)
        {
            s[i]=s[x];
            x--;
        }
    }
}
}

int main(int argc, char *argv[])
{
    FILE *dat = fopen(argv[1], "rb");
    int k = atoi(argv[2]);
    FILE* temp;
    unsigned char block;
    char ime[100]="datoteka.";
    int n = 0;

    while (fread(&block, k, 1, dat) >=k)
    {
        appendNum(stevilka,n);
        temp = fopen(ime, "wb");
        fwrite(&block, k, 1, temp);
        fclose(temp);
    }
    fclose(dat);
    return 0;
}