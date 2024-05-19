
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga1.h"

VO **opravili(Student **studentje, int stStudentov, char *predmet, int *stVO)
{
    int stStud = 0;
    for (int i = 0; i < stStudentov; i++)
    {
        for (int j = 0; j < studentje[i]->stPO; j++)
        {
            if (strcmp(studentje[i]->po[j].predmet, predmet) == 0 && studentje[i]->po[j].ocena > 5)
            {
                stStud++;
            }
        }
    }
    *stVO = stStud;
    VO **tabOcene = (VO **)malloc(stStud * sizeof(VO *));
    int indexVO = 0;

    for (int i = 0; i < stStudentov; i++)
    {
        for (int j = 0; j < studentje[i]->stPO; j++)
        {
            if (strcmp(studentje[i]->po[j].predmet, predmet) == 0 && studentje[i]->po[j].ocena > 5)
            {
                tabOcene[indexVO] = (VO *)malloc(sizeof(VO));
                tabOcene[indexVO]->vpisna = studentje[i]->vpisna;
                tabOcene[indexVO]->ocena = studentje[i]->po[j].ocena;
                indexVO += 1;
            }
        }
    }
    // sortiranje
    for (int i = 0; i < stStud; i++)
    {
        for (int j = 0; j < stStud - 1 - i; j++)
        {
            if (tabOcene[j]->ocena < tabOcene[j + 1]->ocena)
            {
                VO *temp = tabOcene[j];
                tabOcene[j] = tabOcene[j + 1];
                tabOcene[j + 1] = temp;
            }
            else if (tabOcene[j]->ocena == tabOcene[j + 1]->ocena)
            {
                if (tabOcene[j]->vpisna > tabOcene[j + 1]->vpisna)
                {
                    VO *temp = tabOcene[j];
                    tabOcene[j] = tabOcene[j + 1];
                    tabOcene[j + 1] = temp;
                }
            }
        }
    }
    // endsortiranje
    return tabOcene;
}

#ifndef test

int main()
{
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
