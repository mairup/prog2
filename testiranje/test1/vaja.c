#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    int age;
    char name[100];
};

typedef struct person person;

int main()
{
    printf("Hello, World!\n");
    person p;
    p.age = 2;
    printf("p age = %2d\n", p.age);
    return 0;
}