#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _PO
{                    // par predmet-ocena
    char predmet[4]; // enolična oznaka predmeta
    int ocena;       // ocena pri tem predmetu
} PO;
typedef struct _Student
{               // podatki o študentu
    int vpisna; // vpisna številka
    PO *po;     // kazalec na začetek tabele parov predmet-ocena
    int stPO;   // število parov predmet-ocena
} Student;

int poisciStudenta(Student **studentje, int stStudentov, int vpisna)
{
    for (int i = 0; i < stStudentov; i++)
    {
        if (studentje[i]->vpisna == vpisna)
        {
            return i;
        }
    }
    return -1;
}

int poisciPO(Student *student, char *predmet)
{
    for (int i = 0; i < student->stPO; i++)
    {
        if (strcmp(student->po[i].predmet, predmet) == 0)
        {
            return i;
        }
    }
    return -1;
}

Student *ustvariStudenta(int vpisna, int stPO)
{
    Student *s = (Student *)malloc(sizeof(Student));
    s->vpisna = vpisna;
    s->po = NULL;
    s->stPO = stPO;
    return s;
}

void dodajOceno(Student *student, char *predmet, int ocena, int n)
{
    if (n == 0)
    {
        student->po = (PO *)malloc(sizeof(PO) * 10);
    }

    student->po[n].ocena = ocena;
    strcpy(student->po[n].predmet, predmet);
}

int dodaj(Student **studentje, int stStudentov, int vpisna, char *predmet, int ocena)
{
    if (poisciStudenta(studentje, stStudentov, vpisna) == -1)
    {
        stStudentov++;
        studentje[stStudentov - 1] = ustvariStudenta(vpisna, 1);
        dodajOceno(studentje[stStudentov - 1], predmet, ocena, 0);
    }

    int studentN = poisciStudenta(studentje, stStudentov, vpisna);
    int poN = poisciPO(studentje[studentN], predmet);
    if (poN == -1)
    {
        studentje[studentN]->stPO++;
        dodajOceno(studentje[studentN], predmet, ocena, studentje[studentN]->stPO - 1);
    }
    else
    {
        studentje[studentN]->po[poN].ocena = ocena;
    }
    return stStudentov;
}
#ifndef test

void izpisi(Student **studentje, int stStudentov)
{
    for (int i = 0; i < stStudentov; i++)
    {
        printf("%d: [", studentje[i]->vpisna);
        int stPO = studentje[i]->stPO;
        PO *po = studentje[i]->po;
        for (int j = 0; j < stPO; j++)
        {
            if (j > 0)
            {
                printf(", ");
            }
            printf("%s/%d", po[j].predmet, po[j].ocena);
        }
        printf("]\n");
    }
    printf("\n");
}

void pocisti(Student **studentje, int stStudentov)
{
    for (int i = 0; i < stStudentov; i++)
    {
        free(studentje[i]->po);
        free(studentje[i]);
    }
}
int main()
{
    Student *studentje[10];
    int stStudentov = 0;

    stStudentov = dodaj(studentje, stStudentov, 333, "ARS", 8);
    stStudentov = dodaj(studentje, stStudentov, 222, "ODV", 10);
    stStudentov = dodaj(studentje, stStudentov, 999, "P1", 6);

    izpisi(studentje, stStudentov);
    pocisti(studentje, stStudentov);

    return 0;
    return 0;
}
#endif