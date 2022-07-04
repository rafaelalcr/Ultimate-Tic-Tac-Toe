#ifndef TP2022_MATDIN_H
#define TP2022_MATDIN_H

#include <stdlib.h>
#include <stdio.h>

void libertaMat(char** p, int nLin);
char** criaMat(int nLin, int nCol);
void mostraMat(char **p, int nLin, int nCol);
void setPos(char **p, int x, int y, char c);
void mostraMatFinal(char **p, int nLin, int nCol);

#endif //TP2022_MATDIN_H
