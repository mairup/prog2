#include <stdio.h>
#include <math.h>

int main()
{

    int spMeja, zgMeja;
    scanf("%d %d", &spMeja, &zgMeja);

    int res = 79;
    int ugib;

    while (res != 0)
    {
        ugib = (spMeja + zgMeja) / 2;
        // printf("%d\n", ugib);
        scanf("%d", &res);
        if (res == 1)
        {
            spMeja = ugib + 1;
        }
        else if (res == -1)
        {
            zgMeja = ugib - 1;
        }
        else if (res == 0)
        {
            if (spMeja == zgMeja)
            {
                printf("%d\n", (spMeja + zgMeja) / 2);
            }
            else
                printf("%d %d\n", spMeja, zgMeja);
        }
        if (spMeja > zgMeja)
        {
            printf("PROTISLOVJE");
            return 0;
        }
    }

    // printf("%d\n", ugib);

    return 0;
}
