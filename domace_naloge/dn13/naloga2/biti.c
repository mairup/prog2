#include <stdio.h>
#include <stdlib.h>
static char tempS[1000];

int main(int argc, char* argv[]){
    FILE* dat = fopen(argv[1], "rb");
    int p = atoi(argv[2]);
    int q = atoi(argv[3]);

    fread(&tempS, p/8, 1,dat);
    int len = ((q-p)/8)+8;
    fread(&tempS, len, 1,dat);

    int bit = p%8;
    unsigned char st;
    for (int i = 0; p<q ; i++)
    {
        st = tempS[i];
        bit = p%8;
        while (bit < 8&& p<q)
        {
            printf("%d", (st >> (7-bit)) & 1);
            bit++;
            p++;
        }
    }
    return 0;
}