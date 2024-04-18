#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    int value;
    struct _node *next;
} Node;

typedef struct oseba
{
    char ime[20];
    char priimek[20];
} Oseba;

int main()
{
    Node *head = NULL;
    head = malloc(sizeof(Node));

    head->value = 1;
    head->next = NULL;

    printf("Value: %d\n", head->value);

    free(head);

    Oseba o1;
    strcpy(o1.ime, "Janez");
    strcpy(o1.priimek, "Novak");

    printf("Ime: %s\n", o1.ime);
    printf("Priimek: %s\n", o1.priimek);

    free(o1);

    return 0;
}