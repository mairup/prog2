#include <stdio.h>
#include <math.h>

int main()
{
    for (long long unsigned i = 100; i > 0; i += i / 100)
    {
        printf("%llu\n", i);
    }
    return 0;
}